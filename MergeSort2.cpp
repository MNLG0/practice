#include<stdio.h>
#include<malloc.h>
void disp(int a[], int n)//���a�е�����Ԫ��
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
//�Զ����µĶ�·�鲢���� 
//��a[low,mid]��a[mid+1,high]�������ڵ����������й鲢Ϊһ������������a[low,high]
void Merge(int a[], int low, int mid, int high)
{
	int i = low, j = mid + 1, k = 0;//i,j�ֱ�Ϊ�����ӱ���±꣬k��tmpa���±�
	int* tmpa;//tmpa��һ��ָ�룬ָ��������Ԫ�صĵ�ַ����Ϊ��֪������ϲ�֮���ж��ٸ�Ԫ�أ����Բ�������������ʾ
	tmpa = (int*)malloc((high - low + 1) * sizeof(int));
   //�ڵ�һ���ӱ�͵ڶ����ӱ��δɨ����ʱѭ��
	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])//����һ���ӱ��е�Ԫ�ؽ�С���������tmpa��
		{
			tmpa[k] = a[i];
			i++;
			k++;
		}
		else//���򣬵ڶ����ӱ��е�Ԫ�ؽ�С���������tmpa��
		{
			tmpa[k] = a[j];
			j++;
			k++;
		}
	}
    //�ڶ����ӱ��Ѿ�ɨ����ɣ�����һ���ӱ����µĲ��ָ��Ƶ�tmpa��
	while (i <= mid)
	{
		tmpa[k] = a[i];
		i++;
		k++;
	}
   //��һ���ӱ��Ѿ�ɨ����ɣ����ڶ����ӱ����µĲ��ָ��Ƶ�tmpa��
	while (j <= high)
	{
		tmpa[k] = a[j];
		j++;
		k++;
	}
	for (k = 0, i = low; i <= high; k++, i++)//��tmpa�е�Ԫ��������ƻ�tmpa��
		a[i] = tmpa[k];
	free(tmpa);//�ͷ���ʱ�ռ�
}
//һ�˶�·�鲢����
void MergePass(int a[], int length, int n)
{
	int i;
   //�鲢����length�������������ӱ�
	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)
		Merge(a, i, i + length - 1, i + 2 * length - 1);
   //���������ӱ����ߵĳ���С��length���鲢�������ӱ�
	if (i + length - 1 < n)
		Merge(a, i, i + length - 1, n - 1);
}
//��·�鲢�����㷨
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
	printf("����ǰ:"); disp(a, n);
	MergeSort(a, 0, n - 1);
	printf("�����:"); disp(a, n);
}
