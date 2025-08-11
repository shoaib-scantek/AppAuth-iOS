/*! @file SCTKError.h
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

NS_ASSUME_NONNULL_BEGIN

/*! @brief The error domain for all NSErrors returned from the AppAuth library.
 */
extern NSString *const SCTKGeneralErrorDomain;

/*! @brief The error domain for OAuth specific errors on the authorization endpoint.
    @discussion This error domain is used when the server responds to an authorization request
        with an explicit OAuth error, as defined by RFC6749 Section 4.1.2.1. If the authorization
        response is invalid and not explicitly an error response, another error domain will be used.
        The error response parameter dictionary is available in the
        \NSError_userInfo dictionary using the @c ::OIDOAuthErrorResponseErrorKey key.
        The \NSError_code will be one of the @c ::OIDErrorCodeOAuthAuthorization enum values.
    @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
 */
extern NSString *const SCTKOAuthAuthorizationErrorDomain;

/*! @brief The error domain for OAuth specific errors on the token endpoint.
    @discussion This error domain is used when the server responds with HTTP 400 and an OAuth error,
        as defined RFC6749 Section 5.2. If an HTTP 400 response does not parse as an OAuth error
        (i.e. no 'error' field is present or the JSON is invalid), another error domain will be
        used. The entire OAuth error response dictionary is available in the \NSError_userInfo
        dictionary using the @c ::OIDOAuthErrorResponseErrorKey key. Unlike transient network
        errors, errors in this domain invalidate the authentication state, and either indicate a
        client error or require user interaction (i.e. reauthentication) to resolve.
        The \NSError_code will be one of the @c ::OIDErrorCodeOAuthToken enum values.
    @see https://tools.ietf.org/html/rfc6749#section-5.2
 */
extern NSString *const SCTKOAuthTokenErrorDomain;

/*! @brief The error domain for dynamic client registration errors.
    @discussion This error domain is used when the server responds with HTTP 400 and an OAuth error,
         as defined in OpenID Connect Dynamic Client Registration 1.0 Section 3.3. If an HTTP 400
         response does not parse as an OAuth error (i.e. no 'error' field is present or the JSON is
         invalid), another error domain will be  used. The entire OAuth error response dictionary is
         available in the \NSError_userInfo dictionary using the @c ::OIDOAuthErrorResponseErrorKey
         key. Unlike transient network errors, errors in this domain invalidate the authentication
         state, and indicates a client error.
         The \NSError_code will be one of the @c ::OIDErrorCodeOAuthToken enum values.
     @see https://openid.net/specs/openid-connect-registration-1_0.html#RegistrationError
 */
extern NSString *const SCTKOAuthRegistrationErrorDomain;

/*! @brief The error domain for authorization errors encountered out of band on the resource server.
 */
extern NSString *const SCTKResourceServerAuthorizationErrorDomain;

/*! @brief An error domain representing received HTTP errors.
 */
extern NSString *const SCTKHTTPErrorDomain;

/*! @brief An error key for the original OAuth error response (if any).
 */
extern NSString *const SCTKOAuthErrorResponseErrorKey;

/*! @brief The key of the 'error' response field in a RFC6749 Section 5.2 response.
    @remark error
    @see https://tools.ietf.org/html/rfc6749#section-5.2
 */
extern NSString *const SCTKOAuthErrorFieldError;

/*! @brief The key of the 'error_description' response field in a RFC6749 Section 5.2 response.
    @remark error_description
    @see https://tools.ietf.org/html/rfc6749#section-5.2
 */
extern NSString *const SCTKOAuthErrorFieldErrorDescription;

/*! @brief The key of the 'error_uri' response field in a RFC6749 Section 5.2 response.
    @remark error_uri
    @see https://tools.ietf.org/html/rfc6749#section-5.2
 */
extern NSString *const SCTKOAuthErrorFieldErrorURI;

/*! @brief The various error codes returned from the AppAuth library.
 */
typedef NS_ENUM(NSInteger, SCTKErrorCode) {
  /*! @brief Indicates a problem parsing an OpenID Connect Service Discovery document.
   */
  SCTKErrorCodeInvalidDiscoveryDocument = -2,

  /*! @brief Indicates the user manually canceled the OAuth authorization code flow.
   */
  SCTKErrorCodeUserCanceledAuthorizationFlow = -3,

  /*! @brief Indicates an OAuth authorization flow was programmatically cancelled.
   */
  OIDErrorCodeProgramCanceledAuthorizationFlow = -4,

  /*! @brief Indicates a network error or server error occurred.
   */
  SCTKErrorCodeNetworkError = -5,

  /*! @brief Indicates a server error occurred.
   */
  SCTKErrorCodeServerError = -6,

  /*! @brief Indicates a problem occurred deserializing the response/JSON.
   */
  SCTKErrorCodeJSONDeserializationError = -7,

  /*! @brief Indicates a problem occurred constructing the token response from the JSON.
   */
  SCTKErrorCodeTokenResponseConstructionError = -8,

  /*! @brief @c UIApplication.openURL: returned NO when attempting to open the authorization
          request in mobile Safari.
   */
  SCTKErrorCodeSafariOpenError = -9,

  /*! @brief @c NSWorkspace.openURL returned NO when attempting to open the authorization
          request in the default browser.
   */
  OIDErrorCodeBrowserOpenError = -10,

  /*! @brief Indicates a problem when trying to refresh the tokens.
   */
  SCTKErrorCodeTokenRefreshError = -11,

  /*! @brief Indicates a problem occurred constructing the registration response from the JSON.
   */
  SCTKErrorCodeRegistrationResponseConstructionError = -12,

  /*! @brief Indicates a problem occurred deserializing the response/JSON.
   */
  OIDErrorCodeJSONSerializationError = -13,

  /*! @brief The ID Token did not parse.
   */
  SCTKErrorCodeIDTokenParsingError = -14,

  /*! @brief The ID Token did not pass validation (e.g. issuer, audience checks).
   */
  SCTKErrorCodeIDTokenFailedValidationError = -15,
};

/*! @brief Enum of all possible OAuth error codes as defined by RFC6749
    @discussion Used by @c ::OIDErrorCodeOAuthAuthorization and @c ::OIDErrorCodeOAuthToken
        which define endpoint-specific subsets of OAuth codes. Those enum types are down-castable
        to this one.
    @see https://tools.ietf.org/html/rfc6749#section-11.4
    @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
    @see https://tools.ietf.org/html/rfc6749#section-5.2
 */
typedef NS_ENUM(NSInteger, SCTKErrorCodeOAuth) {

  /*! @remarks invalid_request
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  SCTKErrorCodeOAuthInvalidRequest = -2,

  /*! @remarks unauthorized_client
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  SCTKErrorCodeOAuthUnauthorizedClient = -3,

  /*! @remarks access_denied
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  SCTKErrorCodeOAuthAccessDenied = -4,

  /*! @remarks unsupported_response_type
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  SCTKErrorCodeOAuthUnsupportedResponseType = -5,

  /*! @remarks invalid_scope
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  SCTKErrorCodeOAuthInvalidScope = -6,

  /*! @remarks server_error
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  SCTKErrorCodeOAuthServerError = -7,

  /*! @remarks temporarily_unavailable
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  SCTKErrorCodeOAuthTemporarilyUnavailable = -8,

  /*! @remarks invalid_client
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  SCTKErrorCodeOAuthInvalidClient = -9,

  /*! @remarks invalid_grant
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  SCTKErrorCodeOAuthInvalidGrant = -10,

  /*! @remarks unsupported_grant_type
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  SCTKErrorCodeOAuthUnsupportedGrantType = -11,

  /*! @remarks invalid_redirect_uri
      @see https://openid.net/specs/openid-connect-registration-1_0.html#RegistrationError
   */
  SCTKErrorCodeOAuthInvalidRedirectURI = -12,

  /*! @remarks invalid_client_metadata
      @see https://openid.net/specs/openid-connect-registration-1_0.html#RegistrationError
   */
  SCTKErrorCodeOAuthInvalidClientMetadata = -13,

  /*! @brief An authorization error occurring on the client rather than the server. For example,
        due to a state mismatch or misconfiguration. Should be treated as an unrecoverable
        authorization error.
   */
  SCTKErrorCodeOAuthClientError = -0xEFFF,

  /*! @brief An OAuth error not known to this library
      @discussion Indicates an OAuth error as per RFC6749, but the error code was not in our
          list. It could be a custom error code, or one from an OAuth extension. See the "error" key
          of the \NSError_userInfo property. Such errors are assumed to invalidate the
          authentication state
   */
  SCTKErrorCodeOAuthOther = -0xF000,
};

/*! @brief The error codes for the @c ::OIDOAuthAuthorizationErrorDomain error domain
    @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
 */
typedef NS_ENUM(NSInteger, SCTKErrorCodeOAuthAuthorization) {
  /*! @remarks invalid_request
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  OIDErrorCodeOAuthAuthorizationInvalidRequest = SCTKErrorCodeOAuthInvalidRequest,

  /*! @remarks unauthorized_client
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  OIDErrorCodeOAuthAuthorizationUnauthorizedClient = SCTKErrorCodeOAuthUnauthorizedClient,

  /*! @remarks access_denied
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  OIDErrorCodeOAuthAuthorizationAccessDenied =
      SCTKErrorCodeOAuthAccessDenied,

  /*! @remarks unsupported_response_type
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  OIDErrorCodeOAuthAuthorizationUnsupportedResponseType =
      SCTKErrorCodeOAuthUnsupportedResponseType,

  /*! @brief Indicates a network error or server error occurred.
      @remarks invalid_scope
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  OIDErrorCodeOAuthAuthorizationAuthorizationInvalidScope = SCTKErrorCodeOAuthInvalidScope,

  /*! @brief Indicates a server error occurred.
      @remarks server_error
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  OIDErrorCodeOAuthAuthorizationServerError = SCTKErrorCodeOAuthServerError,

  /*! @remarks temporarily_unavailable
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  OIDErrorCodeOAuthAuthorizationTemporarilyUnavailable = SCTKErrorCodeOAuthTemporarilyUnavailable,

  /*! @brief An authorization error occurring on the client rather than the server. For example,
        due to a state mismatch or client misconfiguration. Should be treated as an unrecoverable
        authorization error.
   */
  SCTKErrorCodeOAuthAuthorizationClientError = SCTKErrorCodeOAuthClientError,

  /*! @brief An authorization OAuth error not known to this library
      @discussion this indicates an OAuth error as per RFC6749, but the error code was not in our
          list. It could be a custom error code, or one from an OAuth extension. See the "error" key
          of the \NSError_userInfo property. We assume such errors are not transient.
      @see https://tools.ietf.org/html/rfc6749#section-4.1.2.1
   */
  OIDErrorCodeOAuthAuthorizationOther = SCTKErrorCodeOAuthOther,
};


/*! @brief The error codes for the @c ::OIDOAuthTokenErrorDomain error domain
    @see https://tools.ietf.org/html/rfc6749#section-5.2
 */
typedef NS_ENUM(NSInteger, SCTKErrorCodeOAuthToken) {
  /*! @remarks invalid_request
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  OIDErrorCodeOAuthTokenInvalidRequest = SCTKErrorCodeOAuthInvalidRequest,

  /*! @remarks invalid_client
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  OIDErrorCodeOAuthTokenInvalidClient = SCTKErrorCodeOAuthInvalidClient,

  /*! @remarks invalid_grant
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  OIDErrorCodeOAuthTokenInvalidGrant = SCTKErrorCodeOAuthInvalidGrant,

  /*! @remarks unauthorized_client
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  OIDErrorCodeOAuthTokenUnauthorizedClient = SCTKErrorCodeOAuthUnauthorizedClient,

  /*! @remarks unsupported_grant_type
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  OIDErrorCodeOAuthTokenUnsupportedGrantType = SCTKErrorCodeOAuthUnsupportedGrantType,

  /*! @remarks invalid_scope
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  OIDErrorCodeOAuthTokenInvalidScope = SCTKErrorCodeOAuthInvalidScope,

  /*! @brief An unrecoverable token error occurring on the client rather than the server.
   */
  OIDErrorCodeOAuthTokenClientError = SCTKErrorCodeOAuthClientError,

  /*! @brief A token endpoint OAuth error not known to this library
      @discussion this indicates an OAuth error as per RFC6749, but the error code was not in our
          list. It could be a custom error code, or one from an OAuth extension. See the "error" key
          of the \NSError_userInfo property. We assume such errors are not transient.
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  OIDErrorCodeOAuthTokenOther = SCTKErrorCodeOAuthOther,
};

/*! @brief The error codes for the @c ::OIDOAuthRegistrationErrorDomain error domain
    @see https://openid.net/specs/openid-connect-registration-1_0.html#RegistrationError
 */
typedef NS_ENUM(NSInteger, SCTKErrorCodeOAuthRegistration) {
  /*! @remarks invalid_request
      @see http://tools.ietf.org/html/rfc6750#section-3.1
   */
  OIDErrorCodeOAuthRegistrationInvalidRequest = SCTKErrorCodeOAuthInvalidRequest,

  /*! @remarks invalid_redirect_uri
      @see https://openid.net/specs/openid-connect-registration-1_0.html#RegistrationError
   */
  OIDErrorCodeOAuthRegistrationInvalidRedirectURI = SCTKErrorCodeOAuthInvalidRedirectURI,

  /*! @remarks invalid_client_metadata
      @see https://openid.net/specs/openid-connect-registration-1_0.html#RegistrationError
   */
  OIDErrorCodeOAuthRegistrationInvalidClientMetadata = SCTKErrorCodeOAuthInvalidClientMetadata,

  /*! @brief An unrecoverable token error occurring on the client rather than the server.
   */
  OIDErrorCodeOAuthRegistrationClientError = SCTKErrorCodeOAuthClientError,

  /*! @brief A registration endpoint OAuth error not known to this library
      @discussion this indicates an OAuth error, but the error code was not in our
          list. It could be a custom error code, or one from an OAuth extension. See the "error" key
          of the \NSError_userInfo property. We assume such errors are not transient.
      @see https://tools.ietf.org/html/rfc6749#section-5.2
   */
  OIDErrorCodeOAuthRegistrationOther = SCTKErrorCodeOAuthOther,
};


/*! @brief The exception text for the exception which occurs when a
        @c SCTKExternalUserAgentSession receives a message after it has already completed.
 */
extern NSString *const SCTKOAuthExceptionInvalidAuthorizationFlow;

/*! @brief The text for the exception which occurs when a Token Request is constructed
        with a null redirectURL for a grant_type that requires a nonnull Redirect
 */
extern NSString *const SCTKOAuthExceptionInvalidTokenRequestNullRedirectURL;

NS_ASSUME_NONNULL_END
