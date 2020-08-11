#include<stdio.h>
//非递归折半查找算法
int BinSearch(int a[], int n, int k)
{
	int low = 0, high = n - 1, mid;
	while (low <= high)//当前区间存在元素时循环
	{
		mid = (low + high) / 2;//求查找区间的中间位置
		if (a[mid] == k)
			return mid;//找到后返回其物理下标mid
		if (a[mid] > k)
			high = mid - 1;//继续在a[low,mid-1]中查找
		else
			low = mid + 1;//继续在a[mid+1,high]中查找
	}
	return -1;//当前查找区间没有元素时返回-1
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
		printf("未找到%d元素\n", k);
}
