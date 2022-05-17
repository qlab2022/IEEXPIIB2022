/*
 *   sample2.c
 *   画像左上10画素のRGB値を表示するプログラム
 */

#include "jpegio.h"


/* -----------------------------------------------
 * メイン関数
 */
int main()
{
	char *filename = "image.jpg"; /* 画像ファイル名 */
	BYTE *data = NULL; /* 中身の無いポインタはNULL(=0)にしておく */
	int imageSize = 0;     /* 画像データのサイズ */
	int i;                 /* 繰り返し用 */
	
	/* 画像データの読み込み */
	imageSize = readJpeg(filename, &data);

	/* 読み込み成功したかどうかの確認 */
	if (imageSize == 0) return 1;
	
	/* 画像データの表示 */
	for(i=0; i<30; i+=3)
	{
		fprintf(stdout, "R:%3d  G:%3d  B:%3d\n", 
			data[i], data[i+1], data[i+2]);
	}
	
	/* 画像データ領域の解放 */
	free(data);
	
	return 0;
}
