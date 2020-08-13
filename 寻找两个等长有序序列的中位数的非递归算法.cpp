#include<stdio.h>
void prepart(int& s, int& t)//取a[s,t]序列的前半子序列
{
	int m = (s + t) / 2;
	t = m;
}
void postpart(int& s, int& t)//取a[s,t]序列的后半子序列
{
	int m = (s + t) / 2;
	if ((s + t) % 2 == 0)//序列中有奇数个元素
		s = m;
	else       //序列中有偶数个元素
		s = m + 1;
}
//求两个有序序列a[s1,t1]和b[s2,t2]的中位数
int midnum(int a[], int b[], int n)
{
	int s1, t1, m1, s2, t2, m2;
	s1 = 0; t1 = n - 1;
	s2 = 0; t2 = n - 1;
	while (s1 != t1 || s2 != t2)
	{
		m1 = (s1 + t1) / 2;//求a的中位数
		m2 = (s2 + t2) / 2;//求b的中位数
		if (a[m1] == b[m2])//两个中位数相等时返回该中位数
			return a[m1];
		if (a[m1] < b[m2])
		{
			postpart(s1, t1);//a取后半部分
			prepart(s2, t2);//b取前半部分
		}
		else
		{
			prepart(s1, t1);//a取前半部分
			postpart(s2, t2);//b取后半部分
		}
	}
	return a[s1] < b[s2] ? a[s1] : b[s2];//两个序列只有一个元素时返回较小者
}
int main()
{
	int a[] = { 11,13,15,17,19 };
	int b[] = { 2,5,6,8,20 };
	printf("中位数:%d\n", midnum(a, b, 5));
}
