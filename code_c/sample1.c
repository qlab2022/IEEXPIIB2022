/*
 *   sample1.c
 *   画像の横の画素数(幅)を取得して表示するサンプルプログラム
 */

#include "jpegio.h"

int main()
{
  char *filename = "mandrill.jpg";
  int imageWidth = 0;

  imageWidth  = readHeader(filename, IMAGE_WIDTH);

  printf("Image Width:%d\n", imageWidth);
  
  return 0;
}
