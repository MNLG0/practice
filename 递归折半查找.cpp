#include<stdio.h>
//递归折半查找算法
int BinSearch(int a[], int low, int high, int k)
{
	int mid;
	if (low <= high)//当前区间存在元素时
	{
		mid = (low + high) / 2;//求查找区间的中间位置
		if (a[mid] == k)
			return mid;//找到后返回其物理下标mid
		if (a[mid] > k)
			return BinSearch(a, low, mid - 1, k);//当a[mid]>k时在a[low,mid-1]中递归查找
		else
			return BinSearch(a, mid + 1, high, k);//当a[mid]<k时在a[mid+1,high]中递归查找
	}
	else
		return -1;//当前查找区间没有元素时返回-1
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
		printf("未找到%d元素\n", k);
}
