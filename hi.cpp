def makeHist(img):
{
	hist[11] = {0};
	img = img.reshape(-1,3)
	stats = np.sum (abs (ColorName[None,:,:] - img[:,None,:]),axis=2)
	colorIDs = np.argmin(stats,axis=1)
	for c in colorIDs
	{
		hist[c] = hist [c] +1;
	}
	norm_hist = hist/(np.sum(hist)+10**-6)
	return norm_hist
}
diff(hist1,hist2)
{
	dot(hist1,hist2)/((norm(hist1) * norm(hist2))+10.**(-6))
}
likelihood(x, y, m_template, image, w, h)
{
	x1 = max(0, x - w / 2)
	y1 = max(0, y - h / 2)
	x2 = min(画像端, x + w / 2)
	y2 = min(画像端, y + h / 2)
	region = //★切り出し
	region_hist= makeHist(region)
	diff = diff(m_template.region_hist)
	return diff;
}
init_AAAAA (image, initPos, numOfpartiles=50,AAAAA,template_hist)
{
	weight = 1.0
	//★ランダムまたはbin入力
	x1 = max(0, initPos[0])
	y1 = max(0, initPos[1])
	x2 = min(画像端, initPos [0] + initPos [2])
	y2 = min(画像端, initPos [1] + initPos [3])
	m_template  = //★切り出し
	template_hist = makeHist(m_template)
}
resample(AAAAA)
{
	average = average(AAAAA[i][2]);
	good = AAAAA[i][2]でargmax();
	for i in range (AAAAA.shape[0])
	{
		th = random_normal(average);
		th = clip(th.0.,1.);
		//上記もしくはbin入力
		if(AAAAA [i][2] < th)
		{
			AAAAA[i] = good;
		}
	}
}
move(AAAAA, variance=10.0)
{
	//データ入力と処理
}
weight (AAAAA, m_template, image)
{
	for i =0;i<range;i++
	{
		AAAAA[i][2] = likelihood (AAAAA[i][0], AAAAA[i][1], m_template, image)
	}
}
measure(AAAAA, array)
{
	for()
	{
		x += (AAAAA[i][0] * AAAAA[i][2]);
		y += (AAAAA[i][1] * AAAAA[i][2]);
		weight += AAAAA[i][2]
	}
	array[0] = x / weight;
	array[1] = y / weight;
	for()
	{
		if(AAAAA[i][2] > 0.9)
		{
			// ★ifもう一つ必要そう
			array[2] = min(AAAAA[i][0]);
			array[3] = min(AAAAA[i][1]);
			array[4] = max(AAAAA[i][0]);
			array[5] = max(AAAAA[i][1]);
		}
	}
}

particle_filter (AAAAA, m_template, image, x, y, (xmin,ymin,xmax,ymax))//★まとめる
{
	resample (AAAAA);
	move (AAAAA);
	weight(AAAAA, m_template, image);
	measure(AAAAA, x, y,xmin,ymin, xmax,ymax);
}

{
	AAAAA = NULL;
	B = 0;
	C = NULL;
	while(1)
	{
		//★imgBin読み取り処理追加
		//★NULLの場合は終了
		if(AAAAA == NULL)
		{
			//★inputPos bin読み込み
			init_AAAAA (imgBin, inputPos, 50,AAAAA,template_hist)
		}
		AAAAA_filter(AAAAA, template_hist, imgBin, x, y, xy );//★
		print (x,y);
		print ("ave %d",average (AAAAA [:,2])★forループで出す);
		if(weight_average < 0.5)
		{
			AAAAA = NULL;
		}
	}
}
