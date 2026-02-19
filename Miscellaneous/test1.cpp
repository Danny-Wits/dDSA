#include <stdio.h>

typedef enum {
  BIG = 123412341234,
  BIGGER,
  BIGGEST,
} BigNumbers;

typedef enum {
  HTTP_BAD_REQUEST = 400,
  HTTP_UNAUTHORIZED = 401,
  HTTP_NOT_FOUND = 404,
  HTTP_I_AM_A_TEAPOT = 418,
  HTTP_INTERNAL_SERVER_ERROR = 500
} HttpErrorCode;

int main() {
  size_t s = sizeof(BigNumbers);
  size_t si = sizeof(HttpErrorCode);

  printf("%zu\n",sizeof(BigNumbers));
  printf("%zu\n",si);
  return 0;
}