/*! @file SCTKTokenResponseTests.h
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

@class SCTKTokenResponse;

NS_ASSUME_NONNULL_BEGIN

/*! @brief Unit tests for @c OIDAuthorizationResponse.
 */
@interface SCTKTokenResponseTests : XCTestCase

/*! @brief Creates a new @c SCTKTokenResponse for testing.
 */
+ (SCTKTokenResponse *)testInstance;

/*! @brief Creates a new @c OIDTokenRequest for testing the code exchange.
    @see https://tools.ietf.org/html/rfc6749#section-4.1.4
 */
+ (SCTKTokenResponse *)testInstanceCodeExchange;

/*! @brief Creates a new @c OIDTokenRequest for testing the token refresh.
    @see https://tools.ietf.org/html/rfc6749#section-5.1
 */
+ (SCTKTokenResponse *)testInstanceRefresh;

@end

NS_ASSUME_NONNULL_END
