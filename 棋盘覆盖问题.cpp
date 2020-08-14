#include<stdio.h>
#define MAX 1025
//�����ʾ
int k;//���̴�С
int x, y;//���ⷽ���λ��
//��������ʾ
int board[MAX][MAX];
int tile = 1;//L�ι��Ƶı�ţ���1��ʼ
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)//�ݹ����
		return;
	int t = tile++;//ȡһ��L�ι��ƣ����ƺ�Ϊtile
	int s = size / 2;//�ָ�����
	//�������Ͻ�����
	if (dr < tr + s && dc < tc + s)//���ⷽ���ڴ�������
		ChessBoard(tr, tc, dr, dc, s);//�ݹ���øú��������Ͻ�size��С1/2��ֱ��size==1ʱΪ�ݹ����
	else   //�������������ⷽ��
	{
		board[tr + s - 1][tc + s - 1] = t;//��t��L�ι��Ƹ������½�
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);//�����½���Ϊ���ⷽ��������������
	}
	//�������Ͻ�����
	if (dr < tr + s && dc >= tc + s)//���ⷽ���ڴ�������
		ChessBoard(tr, tc + s, dr, dc, s);
	else            //�������������ⷽ��
	{
		board[tr + s - 1][tc + s] = t;//��t��L�ι��Ƹ������½�
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);//�����½���Ϊ���ⷽ��������������
	}
	//�������½�����
	if (dr >= tr + s && dc < tc + s)//���ⷽ���ڴ�������
		ChessBoard(tr + s, tc, dr, dc, s);
	else               //�������������ⷽ��
	{
		board[tr + s][tc + s - 1] = t;//��t��L�ι��Ƹ������Ͻ�
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);//�����Ͻ���Ϊ���ⷽ��������������
	}
	//�������½�����
	if (dr >= tr + s && dc >= tc + s)//���ⷽ���ڴ�������
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else                  //�������������ⷽ��
	{
		board[tr + s][tc + s] = t;//��t��L�ι��Ƹ������Ͻ�
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);//�����Ͻ���Ϊ���ⷽ��������������
	}
}
int main()
{
	k = 3;//���̵ĳ�����2^3
	x = 1; y = 2;//���ⷽ���λ��Ϊ��1��2��
	int size = 1 << k;//size=8
	ChessBoard(0, 0, x, y, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%4d", board[i][j]);
		printf("\n");
	}
}
