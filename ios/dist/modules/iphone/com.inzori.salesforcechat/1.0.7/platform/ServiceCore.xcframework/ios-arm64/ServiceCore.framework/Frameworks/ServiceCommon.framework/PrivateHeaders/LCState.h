/*
 * Copyright © salesforce.com, inc. 2014-2016
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of salesforce.com nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>

@interface LCState: NSObject

/**
 *  Initializes an SOSState object with a provided set of metrics
 *
 *  @param name    The name of this state.
 *  @param metrics An array consisting of metrics, the status of which are set to NO by default.
 *
 *  @return The SOSState object
 */
- (instancetype)initWithName:(NSString *)name metrics:(NSArray *)metrics sid:(NSUInteger)sid;

/**
 *  Provides a single, boolean status for all metrics
 *
 *  @return The status for all metrics
 */
- (BOOL)satisfied;

/**
 *  Update the status for a particular metric
 *
 *  @param metric The metric to update.
 *  @param status The status to update it with.
 */
- (void)updateMetric:(NSUInteger)metric status:(BOOL)status;

/**
 *  Method used to reset the metrics of the state back to a base value.
 *  Intended for use ONLY by <LCManager>
 *
 *  @param status The status in which to set all metrics.
 */
- (void)updateAllMetrics:(BOOL)status;

/**
 *  Returns the current metric status
 *
 *  @param metric The metric to check.
 *
 *  @return The current status of the metric.
 */
- (BOOL)metric:(NSInteger)metric;

/**
 *  The name of this state.
 */
@property (strong, readonly, nonatomic) NSString *name;

/**
 *  The numerical ID of this state.
 *  states are handled by increasing order of ID;
 */
@property (nonatomic) NSUInteger sid;
@end