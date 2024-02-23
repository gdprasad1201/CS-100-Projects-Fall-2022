#include <stdio.h>
#include <string.h>
int main() {
  int width;
  char result[10000]; 
  char word[10000];
  int idx, len, lineStart, lineEnd, j;
  printf("Enter the width of an output line:\n");
  scanf("%d", &width);
  printf("Enter your text (control-d to exit):\n");
  lineStart = 0;
  lineEnd = width;
  idx = lineEnd - 1;
  while(scanf("%s", word) != EOF) {
    len = strlen(word);
    if (idx - len + 1 < lineStart) {
      while (idx >= lineStart) {
        result[idx--] = ' ';
      }
      result[lineEnd] = '\n'; 
      lineStart = lineEnd + 1; 
      lineEnd = lineStart + width; 
      idx = lineEnd - 1; 
    }
    for (j = 0; j < len; j++) {
      result[idx--] = word[j];
      }
    if (idx > lineStart) {
      result[idx--] = ' ';
    }
  }
  while (idx >= lineStart) {
    result[idx--] = ' ';
  }
  result[lineEnd] = '\0'; 
  printf("\n%s\n", result);
  int array[width];
  for (int i = 1; i <= width; ++i) {
    array[i - 1] = i % 10;
    printf("%d", array[i - 1]);
  }
  printf("\n");
  return 0;
}
