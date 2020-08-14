#include<stdio.h>
#define MAX 1025
//问题表示
int k;//棋盘大小
int x, y;//特殊方格的位置
//求解问题表示
int board[MAX][MAX];
int tile = 1;//L形骨牌的编号，从1开始
void ChessBoard(int tr, int tc, int dr, int dc, int size)
{
	if (size == 1)//递归出口
		return;
	int t = tile++;//取一个L形骨牌，其牌号为tile
	int s = size / 2;//分割棋盘
	//考虑左上角象限
	if (dr < tr + s && dc < tc + s)//特殊方格在此象限内
		ChessBoard(tr, tc, dr, dc, s);//递归调用该函数，不断将size缩小1/2，直到size==1时为递归出口
	else   //此象限中无特殊方格
	{
		board[tr + s - 1][tc + s - 1] = t;//用t号L形骨牌覆盖右下角
		ChessBoard(tr, tc, tr + s - 1, tc + s - 1, s);//将右下角作为特殊方格继续处理该象限
	}
	//考虑右上角象限
	if (dr < tr + s && dc >= tc + s)//特殊方格在此象限中
		ChessBoard(tr, tc + s, dr, dc, s);
	else            //此象限中无特殊方格
	{
		board[tr + s - 1][tc + s] = t;//用t号L形骨牌覆盖左下角
		ChessBoard(tr, tc + s, tr + s - 1, tc + s, s);//将左下角作为特殊方格继续处理该象限
	}
	//考虑左下角象限
	if (dr >= tr + s && dc < tc + s)//特殊方格在此象限中
		ChessBoard(tr + s, tc, dr, dc, s);
	else               //此象限中无特殊方格
	{
		board[tr + s][tc + s - 1] = t;//用t号L形骨牌覆盖右上角
		ChessBoard(tr + s, tc, tr + s, tc + s - 1, s);//将右上角作为特殊方格继续处理该象限
	}
	//处理右下角象限
	if (dr >= tr + s && dc >= tc + s)//特殊方格在此象限中
		ChessBoard(tr + s, tc + s, dr, dc, s);
	else                  //此象限中无特殊方格
	{
		board[tr + s][tc + s] = t;//用t号L形骨牌覆盖左上角
		ChessBoard(tr + s, tc + s, tr + s, tc + s, s);//将左上角作为特殊方格继续处理该象限
	}
}
int main()
{
	k = 3;//棋盘的长宽都是2^3
	x = 1; y = 2;//特殊方格的位置为（1，2）
	int size = 1 << k;//size=8
	ChessBoard(0, 0, x, y, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%4d", board[i][j]);
		printf("\n");
	}
}
