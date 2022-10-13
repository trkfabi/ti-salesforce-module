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

@class LCState;
@class LCManager;

/**
 *  Delegate Protocol for the SOS Session Life-Cycle state machine.
 */
@protocol LifeCycleDelegate<NSObject>
@required

/**
 *  Delegate method fired when the current <LCState> changes.
 *
 *  @param lifeCycle The LifeCycle instance.
 *  @param current   The new current state.
 *  @param previous  The old state.
 */
- (void)lifeCycle:(__weak LCManager *)lifeCycle stateDidChange:(__weak LCState *)current previous:(__weak LCState *)previous;
@end

/**
 *  Singleton Life-Cycle state machine.
 *  This class is responsible for consuming events from all components of the SDK and then determining
 *  The proper current state.
 *
 *  Changes in the state are communicated from messages delivered via the <SOSLifeCycleDelegate> messages.
 */
@interface LCManager : NSObject

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 *  Shared Singleton <LCManager> instance.
 *
 *  @return singleton <LCManager> instance.
 */
+ (instancetype)sharedInstance;

/**
 *  Returns the <LCState> associated with the State ID.
 *
 *  @param id The state id registered with the LCManager.
 *
 *  @return The <LCState> which is associated with this id.
 */
- (__weak LCState *)state:(NSUInteger)id;

/**
 *  Forces the LCManager to re-calculate it's current state.
 */
- (void)update;

/**
 *  Adds a state to the state machine.
 */
- (void)addState:(LCState *)state;

///---------------------------------
/// @name Delegate Management
///---------------------------------

/**
 *  Add an instance of an NSObject implementing the <LifeCycleDelegate> protocol to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to add.
 */
- (void)addDelegate:(id<LifeCycleDelegate>)delegate;

/**
 *  Remove an instance of an NSObject implementing the <LifeCycleDelegate> protocol to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to remove.
 */
- (void)removeDelegate:(id<LifeCycleDelegate>)delegate;

///---------------------------------
/// @name Properties
///---------------------------------

/**
 *  Returns the current state of the LifeCycle.
 */
@property (nonatomic, readonly) NSUInteger currentState;

/**
 *  Alows one to set a gating state which will prevent the lifecycle
 *  from regressing to any state lower in the state machine.
 *
 *  By default the first provided state is set as the base, however if
 *  you set a state to be the gate, once it is satisfied it will prevent
 *  the LCManager from returning.
 *
 *  For example if you have a post session set of states for cleanup,
 *  you may want to prevent the life cycle from returning to any state used
 *  during an active session. Once the life cycle satisfies the gating state
 *  it will guarantee that it does not drop to any previous state until the
 *  state machine has reached the final terminal state.
 */
@property (nonatomic) NSUInteger gate;

@end

