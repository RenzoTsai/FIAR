#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 15
#define CHARSIZE 2
#define MAXLEN 100
void initRecordBorard(void);
void recordtoDisplayArray(void);
void displayBoard(void);
void myscanf();
int isWinning(int s[SIZE][SIZE]);
char cquit[5];
int lci=0;
char lcj=0;
char cd[10];


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
char p1[]="★";

char play2Pic[]="◎";//白棋子;
char play2CurrentPic[]="△";
char p2[]="☆";

//此数组用于记录棋盘格局 
int aRecordBoard[SIZE][SIZE];
int aRecordBoard2[SIZE][SIZE];


int main()

{
	int li,lj,i=1;
	initRecordBorard();
    recordtoDisplayArray();
    displayBoard();
    printf("Please enter any char to start. Or input \"quit\" to quit.\n");
	scanf("%s",cquit);
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //每局开局前输入一串字符，若为quit则退出程序
	{
		printf("Player%d,please enter a location. Or input \"quit\" to quit.\n",(i+1)%2+1); 
		b1:myscanf();									//玩家输入位置
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;										
		while(lci>=SIZE||lcj>=SIZE+'a'){
		printf("Out of size! please enter again! Or input \"quit\" to quit.\n");				
		myscanf();									//若位置超出棋盘范围，则重新输入
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;
		}

		lj=lcj-'a';			
		li=15-lci;			//将输入的参量转化为对应数组的序号
		printf("aRecordBoard[%d][%d]=%d\n",li,lj,aRecordBoard[li][lj]);
		if(aRecordBoard[li][lj]==0){
			if(i%2!=0)
				aRecordBoard2[li][lj]=1;
			else
				aRecordBoard2[li][lj]=2;
		}
		else{
			printf("error!please enter again!\n");
			goto b1; //若输入的位置已有棋子，提示错误，并要求重新输入。
		}
		
		recordtoDisplayArray();
   		displayBoard();
    	i++;
   		cd[0]='o';

	}

    return 0;

    
}

//初始化棋盘格局 
void initRecordBorard(void){
	int i,j;
	for(i=0;i<SIZE;i++)//通过双重循环，将aRecordBoard清0
		for(j=0;j<SIZE;j++){
			aRecordBoard2[i][j]=0;
			aRecordBoard[i][j]=0;
		}
}

//将aRecordBoard中记录的棋子位置，转化到aDisplayBoardArray中
void recordtoDisplayArray(void){
	int i,j;
	for(i=0;i<SIZE;i++)						//第一步：将aInitDisplayBoardArray中记录的空棋盘，复制到aDisplayBoardArray中
		for(j=0;j<SIZE*CHARSIZE+1;j++)
			aDisplayBoardArray[i][j]=aInitDisplayBoardArray[i][j];
	for(i=0;i<SIZE;i++)							//第二步：扫描aRecordBoard，当遇到非0的元素，将●或者◎复制到aDisplayBoardArray的相应位置上
		for(j=0;j<SIZE;j++){
			if(aRecordBoard2[i][j]==1&&(aRecordBoard2[i][j]==aRecordBoard[i][j])){ 			//若同一位置的数没有改变，代表该位置是之前的落子状态
				aDisplayBoardArray[i][j*CHARSIZE]=play1Pic[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=play1Pic[1];
			}
			else if(aRecordBoard2[i][j]==2&&aRecordBoard2[i][j]==aRecordBoard[i][j]){
				aDisplayBoardArray[i][j*CHARSIZE]=play2Pic[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=play2Pic[1];
			}
			else if(aRecordBoard2[i][j]==1&&aRecordBoard2[i][j]!=aRecordBoard[i][j]&&(!strcmp(cd,"crz")||!strcmp(cd,"ghr"))){		//若同一位置的数改变，代表该位置是本轮落子的位置
				aDisplayBoardArray[i][j*CHARSIZE]=p1[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=p1[1];
			}
			else if(aRecordBoard2[i][j]==2&&aRecordBoard2[i][j]!=aRecordBoard[i][j]&&(!strcmp(cd,"crz")||!strcmp(cd,"ghr"))){
				aDisplayBoardArray[i][j*CHARSIZE]=p2[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=p2[1];
			}
			else if(aRecordBoard2[i][j]==1&&aRecordBoard2[i][j]!=aRecordBoard[i][j]){		//若同一位置的数改变，代表该位置是本轮落子的位置
				aDisplayBoardArray[i][j*CHARSIZE]=play1CurrentPic[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=play1CurrentPic[1];
			}
			else if(aRecordBoard2[i][j]==2&&aRecordBoard2[i][j]!=aRecordBoard[i][j]){
				aDisplayBoardArray[i][j*CHARSIZE]=play2CurrentPic[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=play2CurrentPic[1];
			}
		}
			for(i=0;i<SIZE;i++)
				for(j=0;j<SIZE;j++)
					aRecordBoard[i][j]=aRecordBoard2[i][j];									//总状态和本轮读取状态同步	
				
}


//显示棋盘格局 
void displayBoard(void){
	int i,j;
	//第一步：清屏
	system("clear");   //清屏

	for(i=0;i<SIZE;i++){				//第二步：将aDisplayBoardArray输出到屏幕上
		printf("%2d ",15-i);			//输出降序行数
		for(j=0;j<SIZE*CHARSIZE+1;j++)
			printf("%c",aDisplayBoardArray[i][j]);
		printf("\n");
	}													
	
	printf("   A B C D E F G H I J K L O P Q\n");//第三步：输出最下面的一行字母A B .... 
} 


void myscanf(){
	
	s1:scanf("%s",cquit);									//玩家输入位置
		
		if(isalpha(cquit[0])&&isdigit(cquit[1])&&isdigit(cquit[2])){
			lcj=cquit[0];
			lci=(cquit[1]-'0')*10+(cquit[2]-'0');
			
		}
		else if(isalpha(cquit[2])&&isdigit(cquit[0])&&isdigit(cquit[1])){
			lcj=cquit[2];
			lci=(cquit[0]-'0')*10+(cquit[1]-'0');
			
		}
		else if(isalpha(cquit[1])&&isdigit(cquit[0])){
			lcj=cquit[1];
			lci=(cquit[0]-'0');
			
		}
		else if(!strcmp(cquit,"crz")||!strcmp(cquit,"ghr")){
			printf("★ He is a cool boy ☆ Hhh~ And please input the location again!\n");
			cd[0]=cquit[0];
			cd[1]=cquit[1];
			cd[2]=cquit[2];
			cd[3]=cquit[3];
			cd[4]=cquit[4];
			goto s1;
		}																								//彩蛋
		else if(!strcmp(cquit,"fyf")||!strcmp(cquit,"ghr")){
			printf("%s is the smartest boy! Hhh~ And please input the location again!\n",cquit);
			goto s1;
		}																							//彩蛋

		else{
			lcj=cquit[0];
			lci=(cquit[1]-'0');
		}

}
