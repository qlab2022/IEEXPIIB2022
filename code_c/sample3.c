/*
 *   sample3.c
 *   縞々模様の画像を作成するサンプルプログラム
 */

#include "jpegio.h"

#define QUALITY 100

int main()
{
  char *filename = "output.jpg"; /* 出力するファイル名 */
  BYTE *data = NULL;  /* 画像データ配列 */
  int width  = 300;   /* 画像の幅       */
  int height = 300;   /* 画像の高さ     */
  int bpp    = 3;     /* Byte Per Pixel */
  int x      = 0;     /* 座標指定用     */
  int y      = 0;     /* 座標指定用     */
  int addr   = 0;     /* アドレス変換用 */

  /* 画像データ領域の確保 */
  data = (BYTE*)malloc(width * height * bpp);
  if (data == NULL)
    {
      fprintf(stderr, "Can't allocate memory\n");
      return 1;
    }

  /* 縞々模様を作る */
  for(y=0; y<height; y++)
    {
      for(x=0; x<width; x++)
	{
	  /* 画像の(x,y)座標に相当する
             配列の先頭からの場所を計算 */
	  addr = (y * width + x) * bpp;

	  /* x 座標を10で割った余りが4以下なら青色
            5以上なら白色にする */
	  if (x%10 <= 4)
	    {
	      data[addr  ] = 0;    /* Red   */
	      data[addr+1] = 0;    /* Green */
	      data[addr+2] = 255;  /* Blue  */
	    }
	  else
	    {
	      data[addr  ] = 255;  /* Red   */
	      data[addr+1] = 255;  /* Green */
	      data[addr+2] = 255;  /* Blue  */
	    }
	}
    }

  /* ファイルに出力する */
  writeJpeg(filename, data, width, height, bpp, QUALITY);

  /* 画像データ領域の解放 */
  free(data);
  
  return 0;
}
