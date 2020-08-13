#include<stdio.h>
int max3(int a, int b, int c)//����������е����ֵ
{
	if (a < b)//��a����a��b�����ֵ
		a = b;
	if (a > c)//�ȽϷ���a��c�е����ֵ
		return a;
	else
		return c;
}
//��a[left,right]�����е�������������к�
int maxSubSum(int a[], int left ,int right)
{
	//�����ߵ��������������֮�ͺ��ұߵ��������������֮��
	int maxLeftSum, maxRightSum;
	//��ſ�ֽ��ߵĽ��
	int maxLeftBorderSum, maxRightBorderSum;
	//��ſ�ֽ��߽������ʱ����
	int leftBorderSum, rightBorderSum;
	if (left == right)
	{
		if (a[left] > 0)
			return a[left];
		else
			return 0;
	}
	int mid = (left + right) / 2;
	
	//����ߵ��������������֮��
	maxLeftSum = maxSubSum(a, left, mid);
	
	//���ұߵ��������������֮��
	maxRightSum = maxSubSum(a, mid + 1, right);

	//���ֽ��ߵ��������������֮��
	maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = mid; i >= left; i--)//����������ɨ��
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}//���ɨ�����

	maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = mid + 1; j <= right; j++)//����������ɨ��
	{
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}//�ұ�ɨ�����

	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}
int main()
{
	int a[] = { -2,11,-4,13,-5,-2 };
	int n = 6;
	int b[] = { -6,2,4,-7,5,3,2,-1,6,-9,10,-2 };
	int m = 12;
	printf("a���е�������������еĺ�:%d\n", maxSubSum(a, 0, n - 1));
	printf("b���е�������������еĺ�:%d\n", maxSubSum(b, 0, m - 1));
}
