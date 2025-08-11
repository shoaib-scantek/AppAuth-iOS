/*! @file SCTKAuthorizationService+IOS.m
    @brief AppAuth iOS SDK
    @copyright
        Copyright 2016 Google Inc. All Rights Reserved.
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

#import <TargetConditionals.h>

#if TARGET_OS_IOS || TARGET_OS_MACCATALYST

#import "SCTKAuthorizationService+IOS.h"
#import "SCTKExternalUserAgentIOS.h"
#import "SCTKExternalUserAgentCatalyst.h"

NS_ASSUME_NONNULL_BEGIN

@implementation SCTKAuthorizationService (IOS)

+ (id<SCTKExternalUserAgentSession>) presentAuthorizationRequest:(SCTKAuthorizationRequest *)request
    presentingViewController:(UIViewController *)presentingViewController
                    callback:(OIDAuthorizationCallback)callback {
  id<SCTKExternalUserAgent> externalUserAgent;
#if TARGET_OS_MACCATALYST
  externalUserAgent = [[SCTKExternalUserAgentCatalyst alloc]
      initWithPresentingViewController:presentingViewController];
#else // TARGET_OS_MACCATALYST
  externalUserAgent = [[SCTKExternalUserAgentIOS alloc] initWithPresentingViewController:presentingViewController];
#endif // TARGET_OS_MACCATALYST
  return [self presentAuthorizationRequest:request externalUserAgent:externalUserAgent callback:callback];
}

+ (id<SCTKExternalUserAgentSession>) presentAuthorizationRequest:(SCTKAuthorizationRequest *)request
    presentingViewController:(UIViewController *)presentingViewController
     prefersEphemeralSession:(BOOL)prefersEphemeralSession
                    callback:(OIDAuthorizationCallback)callback {
  id<SCTKExternalUserAgent> externalUserAgent;
#if TARGET_OS_MACCATALYST
  externalUserAgent = [[SCTKExternalUserAgentCatalyst alloc]
      initWithPresentingViewController:presentingViewController
                       prefersEphemeralSession:prefersEphemeralSession];
#else // TARGET_OS_MACCATALYST
  externalUserAgent = [[SCTKExternalUserAgentIOS alloc] initWithPresentingViewController:presentingViewController
               prefersEphemeralSession:prefersEphemeralSession];
#endif // TARGET_OS_MACCATALYST
  return [self presentAuthorizationRequest:request externalUserAgent:externalUserAgent callback:callback];
}

@end

NS_ASSUME_NONNULL_END

#endif // TARGET_OS_IOS || TARGET_OS_MACCATALYST
