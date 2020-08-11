#include<stdio.h>
void disp(int a[], int n)//���a�е�����Ԫ��
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
//���־��Ǹ��ݻ�׼��������С�ڻ�׼��Ԫ�ط�����ǰ�������У������д��ڻ�׼��Ԫ�ط��ں���������
int Partition(int a[], int s, int t)//�����㷨
{
	int i = s, j = t;
	int tmp = a[s];//�����еĵ�һ��Ԫ����Ϊ��׼
	while (i != j)//���������˽������м�ɨ�裬ֱ��i=jΪֹ
	{
		while (j > i&& a[j] >= tmp)
			j--;//��������ɨ�裬�ҵ���1���ؼ���С��tmp��a[j]
		a[i] = a[j];//��a[j]ǰ�Ƶ�a[i]��λ��
		while (i < j && a[i] <= tmp)
			i++;//��������ɨ�裬�ҵ�1���ؼ��ִ���tmp��a[i]
		a[j] = a[i];//��a[i]���Ƶ�a[j]��λ��
	}
	a[i] = tmp;
	return i;
}
//���ϻ��֣������ֵ�������ֻ��һ����0��Ԫ��ʱ���������м�Ϊ�����������
void QuickSort(int a[], int s, int t)//��a[s,t]���н�������
{
	if (s < t)//���������ٴ�������Ԫ�ص����
	{
		int i = Partition(a, s, t);
		QuickSort(a, s, i - 1);//���������е�������
		QuickSort(a, i + 1, t);//���������е�������
	}
}
int main()
{
	int n = 10;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	printf("����ǰ:"); disp(a, n);
	QuickSort(a, 0, n - 1);
	printf("�����:"); disp(a, n);
}
