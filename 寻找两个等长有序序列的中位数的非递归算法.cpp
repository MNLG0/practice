#include<stdio.h>
void prepart(int& s, int& t)//ȡa[s,t]���е�ǰ��������
{
	int m = (s + t) / 2;
	t = m;
}
void postpart(int& s, int& t)//ȡa[s,t]���еĺ��������
{
	int m = (s + t) / 2;
	if ((s + t) % 2 == 0)//��������������Ԫ��
		s = m;
	else       //��������ż����Ԫ��
		s = m + 1;
}
//��������������a[s1,t1]��b[s2,t2]����λ��
int midnum(int a[], int b[], int n)
{
	int s1, t1, m1, s2, t2, m2;
	s1 = 0; t1 = n - 1;
	s2 = 0; t2 = n - 1;
	while (s1 != t1 || s2 != t2)
	{
		m1 = (s1 + t1) / 2;//��a����λ��
		m2 = (s2 + t2) / 2;//��b����λ��
		if (a[m1] == b[m2])//������λ�����ʱ���ظ���λ��
			return a[m1];
		if (a[m1] < b[m2])
		{
			postpart(s1, t1);//aȡ��벿��
			prepart(s2, t2);//bȡǰ�벿��
		}
		else
		{
			prepart(s1, t1);//aȡǰ�벿��
			postpart(s2, t2);//bȡ��벿��
		}
	}
	return a[s1] < b[s2] ? a[s1] : b[s2];//��������ֻ��һ��Ԫ��ʱ���ؽ�С��
}
int main()
{
	int a[] = { 11,13,15,17,19 };
	int b[] = { 2,5,6,8,20 };
	printf("��λ��:%d\n", midnum(a, b, 5));
}
