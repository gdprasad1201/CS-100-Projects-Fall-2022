#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "image.h"

// open the file, create an ImagePPM, and return the pointer
// return NULL if the file cannot be opened

ImagePPM *readPPM(char *filename) {
  FILE* inFile = fopen(filename, "r");

  if (inFile == NULL) {
    return NULL;
  }
  
  int red, green, blue;
  ImagePPM* baldur = (ImagePPM*)malloc(sizeof(ImagePPM));
  fscanf(inFile, "%s", baldur->magic);
  fscanf(inFile, "%d %d %d", &baldur->numCols, &baldur->numRows, &baldur->maxVal);
  baldur->pixels = malloc(sizeof(Pixel*) * baldur->numRows);

  for (int i = 0; i < baldur->numRows; i++) {
    baldur->pixels[i] = malloc(sizeof(Pixel) * baldur->numCols);
    for (int j = 0; j < baldur->numCols; j++) {
      fscanf(inFile, "%d %d %d", &red, &green, &blue);
      baldur->pixels[i][j].red = red;
      baldur->pixels[i][j].green = green;
      baldur->pixels[i][j].blue = blue;
    }
  }

  return baldur;
}

// open the file and write the ImagePPM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePPM(ImagePPM *pImagePPM, char *filename) {
  FILE* output = fopen(filename, "w");

  if (output == NULL) {
    return 0;
  }

  fprintf(output, "%s\n", pImagePPM->magic);
  fprintf(output, "%d %d\n", pImagePPM->numCols, pImagePPM->numRows);
  fprintf(output, "%d\n", pImagePPM->maxVal);

  for (int i = 0; i < pImagePPM->numRows; i++) {
    fprintf(output," ");
    for (int j = 0; j < pImagePPM->numCols; j++) {
      fprintf(output, "%d %d %d	", pImagePPM->pixels[i][j].red, pImagePPM->pixels[i][j].green, pImagePPM->pixels[i][j].blue);
    }
    fprintf(output,"\n");
  }

  fclose(output);

  return 1;
}

// free the ImagePPM and its pixels
// everything with a malloc needs a free

void freePPM(ImagePPM *pImagePPM) {
  for (int i = 0; i < pImagePPM->numRows; i++) {
    free(pImagePPM->pixels[i]);
  }

  free(pImagePPM->pixels);
  free(pImagePPM);
}

// open the file, create an ImagePGM, and return the pointer
// return NULL if the file cannot be opened

ImagePGM *readPGM(char *filename) {
  FILE* inFile = fopen(filename, "r");

  if (inFile == NULL) {
    return NULL;
  }

  int gray;
  ImagePGM* pointer = (ImagePGM*)malloc(sizeof(ImagePGM));

  fscanf(inFile, "%s", pointer->magic);
  fscanf(inFile, "%d %d %d", &pointer->numCols, &pointer->numRows, &pointer->maxVal);

  pointer->pixels = malloc(sizeof(int*) * pointer->numRows);

  for (int i = 0; i < pointer->numRows; i++) {
    pointer->pixels[i] = malloc(sizeof(int) * pointer->numCols);
    for (int j = 0; j < pointer->numCols; j++) {
      fscanf(inFile, "%d", &gray);
      pointer->pixels[i][j] = gray;
    }
  }

  return pointer;
}

// open the file and write the ImagePGM to the file
// return 1 on success
// return 0 if the file cannot be opened

int writePGM(ImagePGM *pImagePGM, char *filename) {
  FILE* output = fopen(filename, "w");

  if (output == NULL) {
    return 0;
  }

  fprintf(output, "%s\n", pImagePGM->magic);
  fprintf(output, "%d %d\n", pImagePGM->numCols, pImagePGM->numRows);
  fprintf(output, "%d\n", pImagePGM->maxVal);

  //printf("Made it here!\n");
  for (int i = 0; i < pImagePGM->numRows; i++) {
    fprintf(output, " ");
    for (int j = 0; j < pImagePGM->numCols; j++) {
      fprintf(output, "%d ", pImagePGM->pixels[i][j]);
    }
    fprintf(output,"\n");
  }

  fclose(output);

  return 1;
}

// free the ImagePGM and its pixels
// everything with a malloc needs a free

void freePGM(ImagePGM *pImagePGM) {
  for (int i = 0; i < pImagePGM->numRows; i++) {
    free(pImagePGM->pixels[i]);
  }
  free(pImagePGM->pixels);
  free(pImagePGM);
  return;
}
// R' = floor(0.393R + 0.769G + 0.189B)
// G' = floor(0.349R + 0.686G + 0.168B)
// B' = floor(0.272R + 0.534G + 0.131B)
    
ImagePGM *convertToPGM(ImagePPM *pImagePPM) { 
  ImagePGM* convert = (ImagePGM*)malloc(sizeof(ImagePGM));

  strcpy(convert->magic, "P2");
  convert->numRows = pImagePPM->numRows;
  convert->numCols = pImagePPM->numCols;
  convert->maxVal = pImagePPM->maxVal;
  convert->pixels = malloc(sizeof(int*) * pImagePPM->numRows);

  for (int i = 0; i < pImagePPM->numRows; i++) {
    convert->pixels[i] = malloc(sizeof(int) * pImagePPM->numCols);
    for (int j = 0; j < pImagePPM->numCols; j++) {
      int red = pImagePPM->pixels[i][j].red;
      int green = pImagePPM->pixels[i][j].green;
      int blue = pImagePPM->pixels[i][j].blue;
      convert->pixels[i][j] = (red + green + blue) / 3;
    }
  }
  
  return convert;
}

ImagePGM *shrinkPGM(ImagePGM *pImagePGM) { 
    ImagePGM* shrink = (ImagePGM*)malloc(sizeof(ImagePGM));
    strcpy(shrink->magic, pImagePGM->magic);
    shrink->numRows = pImagePGM->numRows / 2;
    shrink->numCols = pImagePGM->numCols / 2;
    shrink->maxVal = pImagePGM->maxVal;
    shrink->pixels = malloc(sizeof(int*) * shrink->numRows);

    for (int z = 0; z < shrink->numRows; z++) {
      shrink->pixels[z] = malloc(sizeof(int) * shrink->numCols);
    }
    
    for (int i = 0; i < pImagePGM->numRows - 1; i += 2) {
      for (int j = 0; j < pImagePGM->numCols - 1; j += 2) {
        shrink->pixels[i / 2][j / 2] = (pImagePGM->pixels[i][j] + pImagePGM->pixels[i][j + 1] + pImagePGM->pixels[i + 1][j] + pImagePGM->pixels[i + 1][j + 1]) / 4;
      }
    }
    
  return shrink;
}
