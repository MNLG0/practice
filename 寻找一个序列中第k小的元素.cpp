#include<stdio.h>
//��a[s,t]�������ҵ�kС��Ԫ��
int QuickSelect(int a[], int s, int t, int k)
{
	int i = s, j = t;
	int tmp;
	if (s < t)
	{
		tmp = a[s];
		while (i != j)
		{
			while (i < j && a[j] >= tmp)
				j--;
			a[i] = a[j];
			while (i < j && a[i] <= tmp)
				i++;
			a[j] = a[i];
		}
		a[i] = tmp;
		if (k - 1 == i)
			return a[i];
		else if (k - 1 < i)
			return QuickSelect(a, s, i - 1, k);//����ߵ�����ݹ����
		else
			return QuickSelect(a, i + 1, t, k);//���ұߵ�����ݹ����
	}
	else
		if (s == t && s == k - 1)//������ֻ��һ��Ԫ����Ϊa[k-1]
			return a[k - 1];
}
int main()
{
	int n = 10;
	int i;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	for (int k = 1; k <= n; k++)
	{
		i = QuickSelect(a, 0, n - 1, k);
		printf("��%dС��Ԫ��:%d\n", k, i);
	}
}
