#include<stdio.h>
#include<stdlib.h>

#define K 10
//排序的数组
int a[K] = { 10,15,958,-52,63,-1000,2,0,10,45 };

//两个有序数组排序,这两个数组都存储在数组a中a(i,I)  a(j,J)排序好的数组存储在a中
void XLpaixu(int a[], int p, int I, int q, int J)
{
	int temp[K];
	int k = 0, h, i = p, j = q;
	//两个数组从小到大比较，小的写入temp
	//两个数组都有数
	while((i <= I) && (j <= J))
	{
		if (a[i] > a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	//一个数组排完,另一个顺序写入
	if(i > I)
		for(;j<=J;)
			temp[k++] = a[j++];
	else
		if(j > J)
			for (; i <= I;)
				temp[k++] = a[i++];
	//排列完毕
	//temp的值写入a
	for (h = 0, i = p; h < k;)
		a[i++] = temp[h++];
	return;
}

//归并排序函数---数组a中元素从i到j从小到大排序
void GBpaixu(int a[] , int i , int j)
{
	//判断递归结束---排序的只有一个元素时结束，完成任务分解
	if (i < j)
	{
		GBpaixu(a, i, (i + j) / 2);
		GBpaixu(a, (i + j) / 2+1, j);
		//两个有序序列合并为一个---分解任务结果整合
		XLpaixu(a, i, (i + j) / 2, (i + j) / 2 + 1, j);
	}
	return;
}

void main()
{
	int i, j;
	printf("\n");
	for (i = 0; i < K; i++)
		printf("%d\t", a[i]);
	printf("\n");
	GBpaixu(a, i = 0, j = K - 1);
	for (i = 0; i < K; i++)
		printf("%d\t", a[i]);
	printf("\n");
	system("pause");
	return;
}