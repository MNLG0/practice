#include<stdio.h>
//�ǵݹ��۰�����㷨
int BinSearch(int a[], int n, int k)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)//��ǰ�������Ԫ��ʱѭ��
	{
		mid = (low + high) / 2;//�����������м�λ��
		if (a[mid] == k)
			return mid;//�ҵ��󷵻��������±�mid
		if (a[mid] > k)
			high = mid - 1;//������a[low,mid-1]�в���
		else
			low = mid + 1;//������a[mid+1,high]�в���
	}
	return -1;//��ǰ��������û��Ԫ��ʱ����-1
}
int main()
{
	int n = 10, i;
	int k = 6;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	i = BinSearch(a,n, k);
	if (i >= 0)
		printf("a[%d]=%d\n", i, k);
	else
		printf("δ�ҵ�%dԪ��\n", k);
}
