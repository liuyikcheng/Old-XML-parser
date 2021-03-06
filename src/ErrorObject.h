#ifndef ErrorObject_H
#define ErrorObject_H

typedef enum {
  ERR_NO_OPEN_BRACKET,
  ERR_NO_CLOSING_BRACKET,
  ERR_NO_SLASH,
  ERR_WRONG_TAG,
  ERR_NO_TAG,
  ERR_TOKEN_TYPE
} ErrorCode;

typedef struct{
  char *errorMsg;
  ErrorCode errorCode;
} ErrorObject;


void throwError(char *message, ErrorCode errCode);
// void freeError(ErrorObject *errObject);

#endif // ErrorObject_H
