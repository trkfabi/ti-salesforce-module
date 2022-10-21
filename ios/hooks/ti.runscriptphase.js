/* global __dirname */

const path = require('path');

exports.id = 'ti.runscriptphase.salesforce';
exports.cliVersion = '>=5.0';

exports.init = function (logger, _, cli, appc) {
	cli.on('build.ios.xcodeproject', {
		pre: function (data) {
			
			const __ = appc.i18n(__dirname).__;
			const appName = cli.tiapp.name;
			const dsymPaths = path.join(cli.argv['project-dir'], 'build', 'iphone', 'build', 'Products', 'Release-iphoneos');
			const scriptsFolder = path.join(cli.argv['project-dir'], 'scripts');
			const scriptArgs = `"${scriptsFolder}/salesforce-strip-framework"`;
			const xcodeProject = data.args[0];

			const builder = this;
			logger.debug(__('Salesforce strip custom script …'));
			if (data.ctx.deployType !== 'production') {
				logger.debug(__('Skipping Salesforce stripping for non-production build …'));
				return;
			}

			var xobjs = xcodeProject.hash.project.objects;

			if (typeof builder.generateXcodeUuid !== 'function') {

				let uuidIndex = 1;
				const uuidRegExp = /^(0{18}\d{6})$/;
				const lpad = appc.string.lpad;

				Object.keys(xobjs).forEach(function (section) {
					Object.keys(xobjs[section]).forEach(function (uuid) {
						const m = uuid.match(uuidRegExp);
						const n = m && parseInt(m[1]);
						if (n && n > uuidIndex) {
							uuidIndex = n + 1;
						}
					});
				});

				builder.generateXcodeUuid = function generateXcodeUuid() {
					return lpad(uuidIndex++, 24, '0');
				};
			}

			if (builder.forceRebuild === false) {
				logger.debug(__('Skipping Salesforce stripping for incremental build …'));
				return;
			}

			addScriptBuildPhase(builder, xobjs, scriptArgs);
		}
	});
};

function addScriptBuildPhase(builder, xobjs, scriptArgs) {
	if (!scriptArgs) {
		return;
	}

	const script_uuid = builder.generateXcodeUuid();
	const shell_script = scriptArgs;
	const input_paths = '(\n\t"$(BUILT_PRODUCTS_DIR)/$(INFOPLIST_PATH)"\n)';

	createPBXRunShellScriptBuildPhase(xobjs, script_uuid, shell_script, input_paths);
	createPBXRunScriptNativeTarget(xobjs, script_uuid);
}

function createPBXRunShellScriptBuildPhase(xobjs, script_uuid, shell_script, input_paths) {
	xobjs.PBXShellScriptBuildPhase = xobjs.PBXShellScriptBuildPhase || {};

	xobjs.PBXShellScriptBuildPhase[script_uuid] = {
		isa: 'PBXShellScriptBuildPhase',
		buildActionMask: '2147483647',
		files: '(\n)',
		inputPaths: input_paths,
		outputPaths: '(\n)',
		runOnlyForDeploymentPostprocessing: 0,
		shellPath: '/bin/sh',
		name: '"[Ti] Salesforce"',
		shellScript: JSON.stringify(shell_script)
	};
}

function createPBXRunScriptNativeTarget(xobjs, script_uuid) {
	for (const key in xobjs.PBXNativeTarget) {
		xobjs.PBXNativeTarget[key].buildPhases.push({
			value: script_uuid + '',
			comment: '[Ti] Salesforce'
		});
		return;
	}
}
