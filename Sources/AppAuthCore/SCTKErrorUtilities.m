/*! @file SCTKErrorUtilities.m
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

#import "SCTKErrorUtilities.h"

@implementation SCTKErrorUtilities

+ (NSError *)errorWithCode:(SCTKErrorCode)code
           underlyingError:(NSError *)underlyingError
               description:(NSString *)description {
  NSMutableDictionary *userInfo = [NSMutableDictionary dictionary];
  if (underlyingError) {
    userInfo[NSUnderlyingErrorKey] = underlyingError;
  }
  if (description) {
    userInfo[NSLocalizedDescriptionKey] = description;
  }
  // TODO: Populate localized description based on code.
  NSError *error = [NSError errorWithDomain:SCTKGeneralErrorDomain
                                       code:code
                                   userInfo:userInfo];
  return error;
}

+ (BOOL)isOAuthErrorDomain:(NSString *)errorDomain {
  return errorDomain == SCTKOAuthRegistrationErrorDomain
      || errorDomain == SCTKOAuthAuthorizationErrorDomain
      || errorDomain == SCTKOAuthTokenErrorDomain;
}

+ (NSError *)resourceServerAuthorizationErrorWithCode:(NSInteger)code
      errorResponse:(nullable NSDictionary *)errorResponse
    underlyingError:(nullable NSError *)underlyingError {
  // builds the userInfo dictionary with the full OAuth response and other information
  NSMutableDictionary *userInfo = [NSMutableDictionary dictionary];
  if (errorResponse) {
    userInfo[SCTKOAuthErrorResponseErrorKey] = errorResponse;
  }
  if (underlyingError) {
    userInfo[NSUnderlyingErrorKey] = underlyingError;
  }
  NSError *error = [NSError errorWithDomain:SCTKResourceServerAuthorizationErrorDomain
                                       code:code
                                   userInfo:userInfo];
  return error;
}

+ (NSError *)OAuthErrorWithDomain:(NSString *)oAuthErrorDomain
                    OAuthResponse:(NSDictionary *)errorResponse
                  underlyingError:(NSError *)underlyingError {
  // not a valid OAuth error
  if (![self isOAuthErrorDomain:oAuthErrorDomain]
      || !errorResponse
      || !errorResponse[SCTKOAuthErrorFieldError]
      || ![errorResponse[SCTKOAuthErrorFieldError] isKindOfClass:[NSString class]]) {
    return [[self class] errorWithCode:SCTKErrorCodeNetworkError
                       underlyingError:underlyingError
                           description:underlyingError.localizedDescription];
  }

  // builds the userInfo dictionary with the full OAuth response and other information
  NSMutableDictionary *userInfo = [NSMutableDictionary dictionary];
  userInfo[SCTKOAuthErrorResponseErrorKey] = errorResponse;
  if (underlyingError) {
    userInfo[NSUnderlyingErrorKey] = underlyingError;
  }

  NSString *oauthErrorCodeString = errorResponse[SCTKOAuthErrorFieldError];
  NSString *oauthErrorMessage = nil;
  if ([errorResponse[SCTKOAuthErrorFieldErrorDescription] isKindOfClass:[NSString class]]) {
    oauthErrorMessage = errorResponse[SCTKOAuthErrorFieldErrorDescription];
  } else {
    oauthErrorMessage = [errorResponse[SCTKOAuthErrorFieldErrorDescription] description];
  }
  NSString *oauthErrorURI = nil;
  if ([errorResponse[SCTKOAuthErrorFieldErrorURI] isKindOfClass:[NSString class]]) {
    oauthErrorURI = errorResponse[SCTKOAuthErrorFieldErrorURI];
  } else {
    oauthErrorURI = [errorResponse[SCTKOAuthErrorFieldErrorURI] description];
  }

  // builds the error description, using the information supplied by the server if possible
  NSMutableString *description = [NSMutableString string];
  [description appendString:oauthErrorCodeString];
  if (oauthErrorMessage) {
    [description appendString:@": "];
    [description appendString:oauthErrorMessage];
  }
  if (oauthErrorURI) {
    if ([description length] > 0) {
      [description appendString:@" - "];
    }
    [description appendString:oauthErrorURI];
  }
  if ([description length] == 0) {
    // backup description
    [description appendFormat:@"OAuth error: %@ - https://tools.ietf.org/html/rfc6749#section-5.2",
                              oauthErrorCodeString];
  }
  userInfo[NSLocalizedDescriptionKey] = description;

  // looks up the error code based on the "error" response param
  SCTKErrorCodeOAuth code = [[self class] OAuthErrorCodeFromString:oauthErrorCodeString];

  NSError *error = [NSError errorWithDomain:oAuthErrorDomain
                                       code:code
                                   userInfo:userInfo];
  return error;
}

+ (NSError *)HTTPErrorWithHTTPResponse:(NSHTTPURLResponse *)HTTPURLResponse
                                  data:(nullable NSData *)data {
  NSMutableDictionary *userInfo = [NSMutableDictionary dictionary];
  if (data) {
    NSString *serverResponse =
        [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
    if (serverResponse) {
      userInfo[NSLocalizedDescriptionKey] = serverResponse;
    }
  }
  NSError *serverError =
      [NSError errorWithDomain:SCTKHTTPErrorDomain
                          code:HTTPURLResponse.statusCode
                      userInfo:userInfo];
  return serverError;
}

+ (SCTKErrorCodeOAuth)OAuthErrorCodeFromString:(NSString *)errorCode {
  NSDictionary *errorCodes = @{
      @"invalid_request": @(SCTKErrorCodeOAuthInvalidRequest),
      @"unauthorized_client": @(SCTKErrorCodeOAuthUnauthorizedClient),
      @"access_denied": @(SCTKErrorCodeOAuthAccessDenied),
      @"unsupported_response_type": @(SCTKErrorCodeOAuthUnsupportedResponseType),
      @"invalid_scope": @(SCTKErrorCodeOAuthInvalidScope),
      @"server_error": @(SCTKErrorCodeOAuthServerError),
      @"temporarily_unavailable": @(SCTKErrorCodeOAuthTemporarilyUnavailable),
      @"invalid_client": @(SCTKErrorCodeOAuthInvalidClient),
      @"invalid_grant": @(SCTKErrorCodeOAuthInvalidGrant),
      @"unsupported_grant_type": @(SCTKErrorCodeOAuthUnsupportedGrantType),
      };
  NSNumber *code = errorCodes[errorCode];
  if (code) {
    return [code integerValue];
  } else {
    return SCTKErrorCodeOAuthOther;
  }
}

+ (void)raiseException:(NSString *)name {
  [[self class] raiseException:name message:name];
}

+ (void)raiseException:(NSString *)name message:(NSString *)message {
  [NSException raise:name format:@"%@", message];
}

@end
