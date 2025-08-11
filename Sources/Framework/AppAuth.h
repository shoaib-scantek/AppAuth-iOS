/*! @file AppAuth.h
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

#import <Foundation/Foundation.h>

//! Project version number for AppAuthFramework-iOS.
FOUNDATION_EXPORT double AppAuthVersionNumber;

//! Project version string for AppAuthFramework-iOS.
FOUNDATION_EXPORT const unsigned char AppAuthVersionString[];

#import <AppAuth/SCTKAuthState.h>
#import <AppAuth/SCTKAuthStateChangeDelegate.h>
#import <AppAuth/SCTKAuthStateErrorDelegate.h>
#import <AppAuth/SCTKAuthorizationRequest.h>
#import <AppAuth/SCTKAuthorizationResponse.h>
#import <AppAuth/SCTKAuthorizationService.h>
#import <AppAuth/SCTKError.h>
#import <AppAuth/SCTKErrorUtilities.h>
#import <AppAuth/SCTKExternalUserAgent.h>
#import <AppAuth/SCTKExternalUserAgentRequest.h>
#import <AppAuth/SCTKExternalUserAgentSession.h>
#import <AppAuth/SCTKGrantTypes.h>
#import <AppAuth/SCTKIDToken.h>
#import <AppAuth/SCTKRegistrationRequest.h>
#import <AppAuth/SCTKRegistrationResponse.h>
#import <AppAuth/SCTKResponseTypes.h>
#import <AppAuth/SCTKScopes.h>
#import <AppAuth/SCTKScopeUtilities.h>
#import <AppAuth/SCTKServiceConfiguration.h>
#import <AppAuth/SCTKServiceDiscovery.h>
#import <AppAuth/SCTKTokenRequest.h>
#import <AppAuth/SCTKTokenResponse.h>
#import <AppAuth/SCTKTokenUtilities.h>
#import <AppAuth/SCTKURLSessionProvider.h>
#import <AppAuth/SCTKEndSessionRequest.h>
#import <AppAuth/SCTKEndSessionResponse.h>

#if TARGET_OS_TV
#elif TARGET_OS_WATCH
#elif TARGET_OS_IOS || TARGET_OS_MACCATALYST
#import <AppAuth/SCTKAuthState+IOS.h>
#import <AppAuth/SCTKAuthorizationService+IOS.h>
#import <AppAuth/SCTKExternalUserAgentIOS.h>
#import <AppAuth/SCTKExternalUserAgentIOSCustomBrowser.h>
#import "AppAuth/SCTKExternalUserAgentCatalyst.h"
#elif TARGET_OS_OSX
#import <AppAuth/SCTKAuthState+Mac.h>
#import <AppAuth/SCTKAuthorizationService+Mac.h>
#import <AppAuth/SCTKExternalUserAgentMac.h>
#import <AppAuth/SCTKRedirectHTTPHandler.h>
#else
#error "Platform Undefined"
#endif

