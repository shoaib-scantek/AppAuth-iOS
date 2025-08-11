/*! @file SCTKClientMetadataParameters.h
    @brief AppAuth iOS SDK
    @copyright
        Copyright 2016 The AppAuth for iOS Authors. All Rights Reserved.
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

NS_ASSUME_NONNULL_BEGIN

/*! @brief Parameter name for the token endpoint authentication method.
 */
extern NSString *const SCTKTokenEndpointAuthenticationMethodParam;

/*! @brief Parameter name for the application type.
 */
extern NSString *const SCTKApplicationTypeParam;

/*! @brief Parameter name for the redirect URI values.
 */
extern NSString *const SCTKRedirectURIsParam;

/*! @brief Parameter name for the response type values.
 */
extern NSString *const SCTKResponseTypesParam;

/*! @brief Parameter name for the grant type values.
 */
extern NSString *const SCTKGrantTypesParam;

/*! @brief Parameter name for the subject type.
 */
extern NSString *const SCTKSubjectTypeParam;

/*! @brief Application type that indicates this client is a native (not a web) application.
 */
extern NSString *const SCTKApplicationTypeNative;

NS_ASSUME_NONNULL_END
