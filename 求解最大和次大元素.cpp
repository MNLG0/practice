#include<stdio.h>
#define INF 10000
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

void solve(int a[], int low, int high, int& max1, int& max2)
{
	if (low == high)//����ֻ��һ��Ԫ��
	{
		max1 = a[low];
		max2 = -INF;
	}
	else if (low == high - 1)//������ֻ������Ԫ��
	{
		max1 = max(a[low], a[high]);
		max2 = min(a[low], a[high]);
	}
	else//����������������Ԫ��
	{
		int mid = (low + high) / 2;
		int lmax1, lmax2;
		solve(a, low, mid, lmax1, lmax2);//��������lmax1��lmax2
		int rmax1, rmax2;
		solve(a, mid + 1, high, rmax1, rmax2);//��������rmax1��rmax2
		if (lmax1 > rmax1)
		{
			max1 = lmax1;
			max2 = max(lmax2, rmax1);
		}
		else
		{
			max1 = rmax1;
			max2 = max(lmax1, rmax2);
		}
	}
}
int main()
{
	int a[] = { 5,2,1,4,3 };
	int n = 5;
	int max1, max2;
	solve(a, 0, n - 1,max1,max2);
	printf("������Ϊ%d,�δ����Ϊ%d", max1, max2);
	return 0;
}
