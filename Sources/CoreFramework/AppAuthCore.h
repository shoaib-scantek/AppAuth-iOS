/*! @file AppAuthCore.h
    @brief AppAuth iOS SDK
    @copyright
        Copyright 2018 The AppAuth Authors. All Rights Reserved.
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
FOUNDATION_EXPORT double AppAuthCoreVersionNumber;

//! Project version string for AppAuthCoreFramework.
FOUNDATION_EXPORT const unsigned char AppAuthCoreVersionString[];

#import <AppAuthCore/SCTKAuthState.h>
#import <AppAuthCore/SCTKAuthStateChangeDelegate.h>
#import <AppAuthCore/SCTKAuthStateErrorDelegate.h>
#import <AppAuthCore/SCTKAuthorizationRequest.h>
#import <AppAuthCore/SCTKAuthorizationResponse.h>
#import <AppAuthCore/SCTKAuthorizationService.h>
#import <AppAuthCore/SCTKError.h>
#import <AppAuthCore/SCTKErrorUtilities.h>
#import <AppAuthCore/SCTKExternalUserAgent.h>
#import <AppAuthCore/SCTKExternalUserAgentRequest.h>
#import <AppAuthCore/SCTKExternalUserAgentSession.h>
#import <AppAuthCore/SCTKGrantTypes.h>
#import <AppAuthCore/SCTKIDToken.h>
#import <AppAuthCore/SCTKRegistrationRequest.h>
#import <AppAuthCore/SCTKRegistrationResponse.h>
#import <AppAuthCore/SCTKResponseTypes.h>
#import <AppAuthCore/SCTKScopes.h>
#import <AppAuthCore/SCTKScopeUtilities.h>
#import <AppAuthCore/SCTKServiceConfiguration.h>
#import <AppAuthCore/SCTKServiceDiscovery.h>
#import <AppAuthCore/SCTKTokenRequest.h>
#import <AppAuthCore/SCTKTokenResponse.h>
#import <AppAuthCore/SCTKTokenUtilities.h>
#import <AppAuthCore/SCTKURLSessionProvider.h>
#import <AppAuthCore/SCTKEndSessionRequest.h>
#import <AppAuthCore/SCTKEndSessionResponse.h>

