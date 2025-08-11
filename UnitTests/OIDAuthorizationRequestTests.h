/*! @file SCTKAuthorizationRequestTests.h
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

@class SCTKAuthorizationRequest;

NS_ASSUME_NONNULL_BEGIN

/*! @brief Unit tests for @c SCTKAuthorizationRequest.
 */
@interface SCTKAuthorizationRequestTests : XCTestCase

/*! @brief Creates a new @c SCTKAuthorizationRequest for testing.
 */
+ (SCTKAuthorizationRequest *)testInstance;

/*! @brief Creates a new @c SCTKAuthorizationRequest testing a code flow request.
 */
+ (SCTKAuthorizationRequest *)testInstanceCodeFlow;

/*! @brief Creates a new @c SCTKAuthorizationRequest testing a code flow request
        with client authentication.
 */
+ (SCTKAuthorizationRequest *)testInstanceCodeFlowClientAuth;

@end

NS_ASSUME_NONNULL_END
