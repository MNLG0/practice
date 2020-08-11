#include<stdio.h>
#include<malloc.h>
void disp(int a[], int n)//输出a中的所有元素
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
//自顶向下的二路归并排序 
//将a[low,mid]和a[mid+1,high]两个相邻的有序子序列归并为一个有序子序列a[low,high]
void Merge(int a[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = 0;//i,j分别为两个子表的下标，k是tmpa的下标
	int* tmpa;//tmpa是一个指针，指向数组首元素的地址，因为不知道具体合并之后有多少个元素，所以不能用数组来表示
	tmpa = (int*)malloc((high - low + 1) * sizeof(int));
   //在第一个子表和第二个子表均未扫描完时循环
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])//若第一个子表中的元素较小，则将其放入tmpa中
		{
			tmpa[k] = a[i];
			i++;
			k++;
		}
		else//否则，第二个子表中的元素较小，将其放入tmpa中
		{
			tmpa[k] = a[j];
			j++;
			k++;
		}
	}
    //第二个子表已经扫描完成，将第一个子表余下的部分复制到tmpa中
	while (i <= mid)
	{
		tmpa[k] = a[i];
		i++;
		k++;
	}
   //第一个子表已经扫描完成，将第二个子表余下的部分复制到tmpa中
	while (j <= high)
	{
		tmpa[k] = a[j];
		j++;
		k++;
	}
	for (k = 0, i = low; i <= high; k++, i++)//将tmpa中的元素逐个复制回tmpa中
		a[i] = tmpa[k];
	free(tmpa);//释放临时空间
}
//一趟二路归并排序
void MergePass(int a[], int length, int n)
{
	int i;
   //归并两个length长的两个相邻子表
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
		Merge(a, i, i + length - 1, i + 2 * length - 1);
   //余下两个子表，后者的长度小于length，归并这两个子表
	if (i + length - 1 < n)
		Merge(a, i, i + length - 1, n - 1);
}
//二路归并排序算法
void MergeSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
}
int main()
{
	int n = 10;
	int a[] = { 2,5,1,7,10,6,9,4,3,8 };
	printf("排序前:"); disp(a, n);
	MergeSort(a, 0, n - 1);
	printf("排序后:"); disp(a, n);
}
