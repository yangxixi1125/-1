#include<stdio.h>
#include<stdlib.h>

#define K 10
//���������
int a[K] = { 10,15,958,-52,63,-1000,2,0,10,45 };

//����������������,���������鶼�洢������a��a(i,I)  a(j,J)����õ�����洢��a��
void XLpaixu(int a[], int p, int I, int q, int J)
{
	int temp[K];
	int k = 0, h, i = p, j = q;
	//���������С����Ƚϣ�С��д��temp
	//�������鶼����
	while((i <= I) && (j <= J))
	{
		if (a[i] > a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	//һ����������,��һ��˳��д��
	if(i > I)
		for(;j<=J;)
			temp[k++] = a[j++];
	else
		if(j > J)
			for (; i <= I;)
				temp[k++] = a[i++];
	//�������
	//temp��ֵд��a
	for (h = 0, i = p; h < k;)
		a[i++] = temp[h++];
	return;
}

//�鲢������---����a��Ԫ�ش�i��j��С��������
void GBpaixu(int a[] , int i , int j)
{
	//�жϵݹ����---�����ֻ��һ��Ԫ��ʱ�������������ֽ�
	if (i < j)
	{
		GBpaixu(a, i, (i + j) / 2);
		GBpaixu(a, (i + j) / 2+1, j);
		//�����������кϲ�Ϊһ��---�ֽ�����������
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