#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
#define CHARSIZE 2
void initRecordBorard(void);
void recordtoDisplayArray(void);
void displayBoard(void);


//棋盘使用的是GBK编码，每一个中文字符占用2个字节。

//棋盘基本模板 
char aInitDisplayBoardArray[SIZE][SIZE*CHARSIZE+1] = 
{
		"┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
		"┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛"
};
//此数组用于显示棋盘 
char aDisplayBoardArray[SIZE][SIZE*CHARSIZE+1];
 
char play1Pic[]="●";//黑棋子;
char play1CurrentPic[]="▲"; 

char play2Pic[]="◎";//白棋子;
char play2CurrentPic[]="△";

//此数组用于记录棋盘格局 
int aRecordBoard[SIZE][SIZE];


int main()

{
    initRecordBorard();
    aRecordBoard[5][8]=1;
    aRecordBoard[5][9]=2;
    recordtoDisplayArray();
    displayBoard();
    getchar();
    aRecordBoard[3][4]=2;
    recordtoDisplayArray();
    displayBoard();
    getchar();

    aRecordBoard[6][1]=1;
    recordtoDisplayArray();
    displayBoard();
    getchar();

    aRecordBoard[9][4]=2;
    recordtoDisplayArray();
    displayBoard();
    getchar();
    return 0;
}

//初始化棋盘格局 
void initRecordBorard(void){
	int i,j;
	for(i=0;i<SIZE;i++)//通过双重循环，将aRecordBoard清0
		for(j=0;j<SIZE;j++)
			aRecordBoard[i][j]=0;
}

//将aRecordBoard中记录的棋子位置，转化到aDisplayBoardArray中
void recordtoDisplayArray(void){
	int i,j;
	for(i=0;i<SIZE;i++)						//第一步：将aInitDisplayBoardArray中记录的空棋盘，复制到aDisplayBoardArray中
		for(j=0;j<SIZE*CHARSIZE+1;j++)
			aDisplayBoardArray[i][j]=aInitDisplayBoardArray[i][j];
	for(i=0;i<SIZE;i++)	
		for(j=0;j<SIZE;j++)
			if(aRecordBoard[i][j]==1){
				aDisplayBoardArray[i][j*CHARSIZE]=play1Pic[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=play1Pic[1];
			}
			else if(aRecordBoard[i][j]==2){
				aDisplayBoardArray[i][j*CHARSIZE]=play2Pic[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=play2Pic[1];
			}
				//第二步：扫描aRecordBoard，当遇到非0的元素，将●或者◎复制到aDisplayBoardArray的相应位置上
				//注意：aDisplayBoardArray所记录的字符是中文字符，每个字符占2个字节。●和◎也是中文字符，每个也占2个字节。
}


//显示棋盘格局 
void displayBoard(void){
	int i,j;
	//第一步：清屏
	system("clear");   //清屏

	for(i=0;i<SIZE;i++){
		printf("%2d ",15-i);			//第二步：将aDisplayBoardArray输出到屏幕上
		for(j=0;j<SIZE*CHARSIZE+1;j++)
			printf("%c",aDisplayBoardArray[i][j]);
		printf("\n");
	}													
	
	printf("   A B C D E F G H I J K L O P Q\n");//第三步：输出最下面的一行字母A B .... 
} 

