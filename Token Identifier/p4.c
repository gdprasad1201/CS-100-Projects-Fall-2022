#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPositiveInteger(char token[]) {
  for (int i = 0; i < strlen(token); ++i) {
    if (token[i] >= '0' && token[i] <= '9') {
      continue;
    }
    else {
      return 0;
    }
  }
  return 1;
}

int isNegativeInteger(char token[]) {
  if (strlen(token) < 2) {
    return 0;
  }
  if (token[0] == '-') {
    for (int i = 1; i < strlen(token); ++i) {
      if (token[i] >= '0' && token[i] <= '9') {
        continue;
      }
      else {
        return 0;
      }
    }
  }
  else {
    return 0;
  }
  return 1;
}

int isBinaryNumber(char token[]) {
  if (strlen(token) < 3) {
    return 0;
  }
  if (token[0] == '0' && token[1] == 'b') {
    for (int i = 2; i < strlen(token); ++i) {
      if (token[i] == '0' || token[i] == '1') {
        continue;
      }
      else {
        return 0;
      }
    }
  }
  else {
    return 0;
  }
  return 1;
}

int isGuid(char token[]) {
  if (strlen(token) < 36) {
    return 0;
  }
  char guid[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
  for (int i = 0; i < strlen(token); ++i) {
    int flag = 0;
    if (i == 8 || i == 13 || i == 18 || i == 23) {
      if (token[i] == '-') {
        continue;
      }
      else {
        return 0;
      }
    }
    for (int j = 0; j < 22; ++j) {
      if (token[i] == guid[j]) {
        flag = 1;
      }
    }
    if (flag == 0) {
      return 0;
    }
  }
  return 1;
}

int isPositiveFloatingPoint(char token[]) {
  int period_found = 0;
  int cnt = 0;
  if (token[0] == '.') {
    return 0;
  }
  for (int a = 0; a < strlen(token); a++) {
    if (isalpha(token[a])) {
      return 0;
    }
  }
  if (token[0] == '-') {
    return 0;
  }
  for (int j = 0; j < strlen(token); j++) {
    if (token[j] == '.' ) {
      cnt++;
      if (cnt !=1 ) {
        return 0;
      }
    }
  }
  for (int i = 1; i < strlen(token); ++i) {
    if (token[i] == '.') {
      period_found = i;
    }
  }
  if ((token[period_found - 1] >= '0' && token[period_found - 1] <= '9') && (token[period_found + 1] >= '0' && token[period_found + 1] <= '9')) {
    return 1;
  }
  else {
    return 0;
  }
}

int isNegativeFloatingPoint(char token[]) {
  int period_found = 0;
  int cnt = 0;
  int cnt2 = 0;
  if (token[0] == '.' || token[1] == '.') {
    return 0;
  }
  for (int a = 0; a < strlen(token); a++) {
    if (isalpha(token[a])) {
      return 0;
    }
  }
  for (int j = 0; j < strlen(token); j++) {
    if (token[j] == '.' ) {
      cnt++;
      if (cnt != 1 ) {
        return 0;
      }
    }
  }
  for (int k = 0; k < strlen(token); k++) {
    if (token[k] == '-' ) {
      cnt2++;
      if (cnt2 != 1 ) {
        return 0;
      }
    }
  } 
  if (token[0] == '-') {
    for (int i = 2; i < strlen(token); ++i) {
      if (token[i] == '.') {
        period_found = i;
      }
    }
  }
  else {
    return 0;
  }
  if ((token[period_found - 1] >= '0' && token[period_found - 1] <= '9') && (token[period_found + 1] >= '0' && token[period_found + 1] <= '9')) {
    return 1;
  }
  else {
    return 0;
  }
}

int main(void) {
  char token[100]; 
  printf("Enter a token to identify, EOF to stop:\n");
  while (scanf("%s", token) != EOF) {
    if (isPositiveInteger(token)) {
      printf("The token is a positive integer\n");
    }
    else if (isNegativeInteger(token)) {
      printf("The token is a negative integer\n");
    }
    else if (isBinaryNumber(token)) {
      printf("The token is a binary number\n");
    }
    else if (isGuid(token)) {
      printf("The token is a guid\n");
    }
    else if (isPositiveFloatingPoint(token)) {
      printf("The token is a positive floating-point number\n");
    }
    else if (isNegativeFloatingPoint(token)) {
      printf("The token is a negative floating-point number\n");
    }
    else {
      printf("The token cannot be identified\n");
    }
    printf("Enter a token to identify, EOF to stop:\n");
  }
  return 0;
}
