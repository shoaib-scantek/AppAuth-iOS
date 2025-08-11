/*! @file SCTKAuthStateTests.h
    @brief AppAuth iOS SDK
    @copyright
        Copyright 2015 Google Inc. All Rights Reserved.
    @copydetails
        Licensed under the Apache License, Version 2.0 (the "License");
        you may not use this file except in compliance with the License.
        You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

        Unless required by applicable law or agreed to in writing, software
        distributed under the License is distributed on an "AS IS" BASIS,
        WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
        See the License for the specific language governing permissions and
        limitations under the License.
 */

#import <XCTest/XCTest.h>

#if SWIFT_PACKAGE
@import AppAuthCore;
#else
#import "Sources/AppAuthCore/SCTKAuthStateChangeDelegate.h"
#import "Sources/AppAuthCore/SCTKAuthStateErrorDelegate.h"
#endif

@class SCTKAuthState;

NS_ASSUME_NONNULL_BEGIN

/*! @brief Unit tests for @c SCTKAuthState.
 */
@interface SCTKAuthStateTests : XCTestCase

/*! @brief Creates a new @c SCTKAuthState for testing.
 */
+ (SCTKAuthState *)testInstance;

@end

NS_ASSUME_NONNULL_END
