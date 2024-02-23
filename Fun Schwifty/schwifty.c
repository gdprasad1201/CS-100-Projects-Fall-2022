#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void left(char word[]); //declarations
void right(char word[]);
void inc(char word[]);
void dec(char word[]);

int main(int argc, char** argv) {
  if (argc != 3){
    printf("Invalid number of arguments\n"); //check for number of arguments
    return 0;
  }
  
  FILE *inFile = fopen(argv[1], "r") ; //file opening failed
  if (inFile == NULL) {
    printf("Could not open file '%s'\n", argv[1]);
    return 0;
  }
  
  int i;
  for (i = 0; i < strlen(argv[2]); i++) {
    if (argv[2][i] != 'L' && argv[2][i] != 'R' && argv[2][i] != 'I' && argv[2][i] != 'D') { //if wrong char in input
      printf("You threw off my schwiftiness with schwifty '%c'!\n", argv[2][i]);
      return 0;
    }
  }
  
  char str[1001];
  while (fgets(str, 1000, inFile)) {
    char* word = strtok(str, " \n"); //split each word from the line sparated by newline or space
    while (word != NULL) {
    //printf("%s\n", word);
      for (i = 0; i < strlen(argv[2]); i++) { 
        if (argv[2][i] == 'L') {
          left(word);
        }
        if (argv[2][i] == 'R') {
          right(word);
        }
        if (argv[2][i] == 'I') {
          inc(word);
        }
        if (argv[2][i] == 'D') {
          dec(word);
        }
      }
    printf("%s\n", word); //print output for that word after all operations are completed
    word = strtok(NULL, " \n"); //find next word from the line
    }
  }
  fclose(inFile);
  return 0;
}

void left(char word[]) {
  int i;
  char output[100]; //create output array
  int out_i = 0;
  for(i = 1; i < strlen(word); i++) { //second char to last
    output[out_i++] = word[i];
  }
  output[out_i++] = word[0]; //first char
  output[out_i] = '\0'; //place null char at the end
  strcpy(word, output); //update word with output array value
}

void right(char word[]) {
  char output[100];
  int out_i = 0;
  output[out_i++] = word[strlen(word) - 1]; //last char
  int i;
  for (i = 0; i < strlen(word) - 1; i++){
    output[out_i++] = word[i]; //1st chat to last but one char
  }
  output[out_i] = '\0';
  strcpy(word, output);
}

void inc(char word[]) {
  char output[100];
  int out_i = 0;
  int i;
  for(i = 0; i < strlen(word); i++) {
    if (word[i] == 'Z') //special cases
      output[out_i++] = 'A';
    else if (word[i] == 'z')
      output[out_i++] = 'a';
    else if (word[i] == '9')
      output[out_i++] = '0';
    else if (word[i] >= 'A' && word[i] <= 'Y') //A-Y char
      output[out_i++] = word[i] + 1;
    else if (word[i] >= 'a' && word[i] <= 'y') //a-y char
      output[out_i++] = word[i] + 1;
    else if (word[i] >= '0' && word[i] <= '8') //0-8 char
      output[out_i++] = word[i] + 1;
    else
      output[out_i++] = word[i]; //remaining chars are not altered
  }
  output[out_i] = '\0';
  strcpy(word, output);
}

void dec(char word[]) {
  char output[100];
  int out_i = 0;
  int i;
  for (i = 0; i < strlen(word); i++){
    if (word[i] == 'A') //special cases
      output[out_i++] = 'Z';
    else if (word[i] == 'a')
      output[out_i++] = 'z';
    else if (word[i] == '0')
      output[out_i++] = '9';
    else if (word[i] >= 'B' && word[i] <= 'Z') //B-Y
      output[out_i++] = word[i] - 1;
    else if (word[i] >= 'b' && word[i] <= 'z') //b-y
      output[out_i++] = word[i] - 1;
    else if (word[i] >= '1' && word[i] <= '9') //1-9
      output[out_i++] = word[i] - 1;
    else
      output[out_i++] = word[i]; //remaining chars are not altered
  }
  output[out_i] = '\0';
  strcpy(word, output);
}
