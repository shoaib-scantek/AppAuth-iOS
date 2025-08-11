/*! @file OIDTokenUtilities.m
 @brief AppAuth iOS SDK
 @copyright
        Copyright 2018 The AppAuth for iOS Authors. All Rights Reserved.
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
#import "Sources/AppAuthCore/SCTKTokenUtilities.h"
#endif

@interface OIDTokenUtilitiesTests : XCTestCase
@end
@implementation OIDTokenUtilitiesTests

- (void)testRedact {
  XCTAssertEqualObjects([SCTKTokenUtilities redact:@"0123456789"], @"012345...[redacted]", @"");
}

- (void)testRedactWithNilParamater {
  XCTAssertEqualObjects([SCTKTokenUtilities redact:nil], nil, @"");
}

- (void)testRedactWithEmptyString {
    XCTAssertEqualObjects([SCTKTokenUtilities redact:@""], @"", @"");
}

- (void)testRedactWithShortInput {
  XCTAssertEqualObjects([SCTKTokenUtilities redact:@"01234"], @"[redacted]", @"");
}

- (void)testFormUrlEncode {
  XCTAssertEqualObjects([SCTKTokenUtilities formUrlEncode:@"t _9V-F*I+Z1Lk.u7:2/8L+w="],
                        @"t+_9V-F*I%2BZ1Lk.u7%3A2%2F8L%2Bw%3D", @"");
}

- (void)testFormUrlEncodeEmptyString {
  XCTAssertEqualObjects([SCTKTokenUtilities formUrlEncode:@""], @"", @"");
}

@end
