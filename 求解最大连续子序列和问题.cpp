#include<stdio.h>
int max3(int a, int b, int c)//求出三个数中的最大值
{
	if (a < b)//用a保存a、b的最大值
		a = b;
	if (a > c)//比较返回a、c中的最大值
		return a;
	else
		return c;
}
//求a[left,right]序列中的最大连续子序列和
int maxSubSum(int a[], int left ,int right)
{
	//存放左边的最大连续子序列之和和右边的最大连续子序列之和
	int maxLeftSum, maxRightSum;
	//存放跨分界线的结果
	int maxLeftBorderSum, maxRightBorderSum;
	//存放跨分界线结果的临时变量
	int leftBorderSum, rightBorderSum;
	if (left == right)
	{
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}
	int mid = (left + right) / 2;
	
	//求左边的最大连续子序列之和
	maxLeftSum = maxSubSum(a, left, mid);
	
	//求右边的最大连续子序列之和
	maxRightSum = maxSubSum(a, mid + 1, right);

	//求跨分界线的最大连续子序列之和
	maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = mid; i >= left; i--)//从中线向左扫描
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}//左边扫描结束

	maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = mid + 1; j <= right; j++)//从中线向右扫描
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}//右边扫描结束

	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}
int main()
{
	int a[] = { -2,11,-4,13,-5,-2 };
	int n = 6;
	int b[] = { -6,2,4,-7,5,3,2,-1,6,-9,10,-2 };
	int m = 12;
	printf("a序列的最大连续子序列的和:%d\n", maxSubSum(a, 0, n - 1));
	printf("b序列的最大连续子序列的和:%d\n", maxSubSum(b, 0, m - 1));
}
