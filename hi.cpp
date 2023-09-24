// トリミング処理
// https://daeudaeu.com/trimming/
// RGBかBGRか、面順次(RRRRGGGGBBBB)か点順次(RGBRGB)か
  for(y = 0; y < trimmedBitmap.height; y++){
    for(x = 0; x < trimmedBitmap.width; x++){
      for(c = 0; c < trimmedBitmap.ch; c++){
        trimmedBitmap.data[((y * trimmedBitmap.width) + x) * trimmedBitmap.ch + c]
        = bitmap.data[(((y + sy) * bitmap.width) + (x + sx)) * bitmap.ch + c];
      }
    }
  }

// https://webkaru.net/clang/matrix-subtraction/
// https://daeudaeu.com/c-mat-sum/#i-4
// c++ 配列同士の引き算
np_sum_abs
{
	// 11個の配列に対して各画素で実施
	a[11][3];
	b[900][3];
	c;
	test[900][11];
	for(k=0;k<900;++k)
	{
		for(i=0;i<11;++i)
		{
			c = 0;
			for(j=0;j<3;++j)
			{
				c += abs(a[i][j] - b[k][j]);
			}
			test[k][i] = c;
		}
	}
}
