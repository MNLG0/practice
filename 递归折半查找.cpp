#include<stdio.h>
//�ݹ��۰�����㷨
int BinSearch(int a[], int low, int high, int k)
{
	int mid;
	if (low <= high)//��ǰ�������Ԫ��ʱ
	{
		mid = (low + high) / 2;//�����������м�λ��
		if (a[mid] == k)
			return mid;//�ҵ��󷵻��������±�mid
		if (a[mid] > k)
			return BinSearch(a, low, mid - 1, k);//��a[mid]>kʱ��a[low,mid-1]�еݹ����
		else
			return BinSearch(a, mid + 1, high, k);//��a[mid]<kʱ��a[mid+1,high]�еݹ����
	}
	else
		return -1;//��ǰ��������û��Ԫ��ʱ����-1
}
int main()
{
	int n = 10, i;
	int k = 6;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	i = BinSearch(a, 0, n - 1, k);
	if (i >= 0)
		printf("a[%d]=%d\n", i, k);
	else
		printf("δ�ҵ�%dԪ��\n", k);
}
