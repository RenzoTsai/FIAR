#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define SIZE 15
#define CHARSIZE 2
#define MAXLEN 100
void initRecordBorard(void);
void recordtoDisplayArray(void);
void displayBoard(void);
void myscanf();
int isWinning(int s[SIZE][SIZE],int li,int lj,int n);
char cquit[5];
int lci=0;
char lcj=0;
void mode1();
void mode2();
void mode3();
void mode4();
void mode5();
int isSurrounded(int s[SIZE][SIZE],int li,int lj,int n);
int isFour(int s[SIZE][SIZE],int li,int lj,int n);
int isThree(int s[SIZE][SIZE],int li,int lj,int n);
int isTwo(int s[SIZE][SIZE],int li,int lj,int n);
int isHThree(int s[SIZE][SIZE],int li,int lj,int n);
int isDHThree(int s[SIZE][SIZE],int li,int lj,int n);
int isDFour(int s[SIZE][SIZE],int li,int lj,int n);
int isLongRow(int s[SIZE][SIZE],int li,int lj,int n);
int isForbidden(int s[SIZE][SIZE],int li,int lj,int n);
int WFive(int s[SIZE][SIZE],int li,int lj,int num);
int isOne(int s[SIZE][SIZE],int li,int lj,int n);
void printloc(int,int);
int li,lj,count=1,chosen_total=0,chosen2_total=0,chosen_deep_total=0;
int test4=0,test2=0,test3=0,test1=0,anti3=0,anti4=0,antia4=0,antia3=0;
void givingGrades(int s[SIZE][SIZE]);
void choosePlace(int s[SIZE][SIZE],int i,int j);
void giving2Grades(int s[SIZE][SIZE]);
void choose2Place(int s[SIZE][SIZE],int i,int j);
struct grades{
	int five;
	int h3;
	int four;
	int three;
	int two;
	int a5;
	int a4;
	int a3;
	int a2;
	int ah3;

	int total;
	int total2;
}board[15][15],board2[15][15];


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
int aRecordBoard2[SIZE][SIZE];
int aRecordBoard3[SIZE][SIZE];
int aRecordBoard4[SIZE][SIZE];


int main(){
	int li,lj,i=1,mode;
	initRecordBorard();
    recordtoDisplayArray();
    displayBoard();
    printf("CRZ\n");
    printf("Please press a number to choose the mode: \n\"1\" for person to person, \"2\"for person to computer,\"3\"for computer to person.\n");
	scanf("%s",cquit);
	mode=cquit[0]-'0';															//选择模式
	if(mode==1)
		mode1();
	else if(mode==2)
		mode2();
	else if(mode==3)
		mode3();
	else if(mode==4)
		mode4();
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
	system("clear");   //第一步：清屏

	for(i=0;i<SIZE;i++){				//第二步：将aDisplayBoardArray输出到屏幕上
		printf("%2d ",15-i);			//输出降序行数
		for(j=0;j<SIZE*CHARSIZE+1;j++)
			printf("%c",aDisplayBoardArray[i][j]);
		printf("\n");
	}													
	
	printf("   A B C D E F G H I J K L M N O\n");//第三步：输出最下面的一行字母A B .... 
} 


void myscanf(){
		scanf("%s",cquit);									//玩家输入位置
		
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
		else{
			lcj=cquit[0];
			lci=(cquit[1]-'0');
		}
}

void printloc(int li,int lj){
		lcj=lj+'a';			
		lci=15-li;
		printf("%d%c\n",lci,lcj);	
}

int isWinning(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==4||jw[1]==4||jw[2]==4||jw[3]==4)
		return 1;
	else
		return 0;
}


void mode1(){
	int li,lj,count=1;
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //每局开局前输入一串字符，若为quit则退出程序
	{
		printf("Player%d,please enter a location. Or input \"quit\" to quit.\n",(count+1)%2+1); 
	 b1:myscanf();									//玩家输入位置
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;										
		while(lci>SIZE||lcj>SIZE+'a'){
		printf("Out of size! please enter again! Or input \"quit\" to quit.\n");				
		myscanf();									//若位置超出棋盘范围，则重新输入
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;
		}

		lj=lcj-'a';			
		li=15-lci;					//将输入的参量转化为对应数组的序号
		printf("aRecordBoard[%d][%d]=%d\n",li,lj,aRecordBoard[li][lj]);
		if(aRecordBoard[li][lj]==0){
			if(count%2!=0)
				aRecordBoard2[li][lj]=1;
			else
				aRecordBoard2[li][lj]=2;
		}
		else{
			printf("error!please enter again!\n");
			goto b1; 				//若输入的位置已有棋子，提示错误，并要求重新输入。
		}
		
		recordtoDisplayArray();
   		displayBoard();

   		if(isWinning(aRecordBoard2,li,lj,(count+1)%2+1)){
   			printf("player%d is winner\n",(count+1)%2+1);
   			break;
   		}
    	count++;
	}

}

void mode2(){
	int i=0,j=0;
		
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //每局开局前输入一串字符，若为quit则退出程序
	{
		
		b2:printf("Player%d,please enter a location. Or input \"quit\" to quit.\n",(count+1)%2+1); 
	 	myscanf();								//玩家输入位置
	 	if(!strcmp(cquit,"r")){
	 		for(i=0;i<SIZE;i++)
				for(j=0;j<SIZE;j++)
					aRecordBoard2[i][j]=aRecordBoard4[i][j];
			recordtoDisplayArray();
   			displayBoard();
   			goto b2;	
	 	}
	 	 for(i=0;i<SIZE;i++)
			for(j=0;j<SIZE;j++)
			aRecordBoard4[i][j]=aRecordBoard2[i][j];	
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;										
		while(lci>SIZE||lcj>SIZE+'a'){
		printf("Out of size! please enter again! Or input \"quit\" to quit.\n");				
		myscanf();									//若位置超出棋盘范围，则重新输入
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;
		}

		lj=lcj-'a';			
		li=15-lci;					//将输入的参量转化为对应数组的序号
		if(isForbidden(aRecordBoard2,li,lj,1))
			printf("isForbidden!\n");
		if(aRecordBoard[li][lj]==0){
			if(count%2!=0)
				aRecordBoard2[li][lj]=1;
			else
				aRecordBoard2[li][lj]=2;
		}
		else{
			printf("error!please enter again!\n");
			goto b2; 				//若输入的位置已有棋子，提示错误，并要求重新输入。
		}
		
		recordtoDisplayArray();
   		displayBoard();
   		printloc(li,lj);
   		if(isWinning(aRecordBoard2,li,lj,(count+1)%2+1)){
   			printf("player%d is winner\n",(count+1)%2+1);
   			break;
   		}
    	count++;
///////////////////////////////////////////////////////
    	for(i=0;i<SIZE;i++)
				for(j=0;j<SIZE;j++)
					aRecordBoard3[i][j]=aRecordBoard2[i][j];	
    	i=j=0;
		giving2Grades(aRecordBoard2);
		choose2Place(aRecordBoard2,i,j);
		

		if(count%2!=0)
			aRecordBoard2[li][lj]=1;
		else
			aRecordBoard2[li][lj]=2;

		recordtoDisplayArray();
   		displayBoard();


   		if(isWinning(aRecordBoard2,li,lj,(count+1)%2+1)){
   			printf("player%d is winner\n",(count+1)%2+1);
   			break;
   		}

    	lcj=lj+'a';			
		lci=15-li;
		printf("%d%c\n",lci,lcj );
    	printf("%d\n",count);
		printf("total:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board[li][lj].total,board[li][lj].five,board[li][lj].a4,board[li][lj].four,board[li][lj].a3,board[li][lj].h3,board[li][lj].ah3,board[li][lj].three,board[li][lj].a2,board[li][lj].two);
    	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++){
    			board[li][lj].total2=board[li][lj].total=board[li][lj].five=board[li][lj].a5=board[li][lj].a2=board[li][lj].h3=board[li][lj].four=board[li][lj].ah3=board[li][lj].a4=board[li][lj].three=board[li][lj].a3=board[li][lj].two=chosen_total=chosen_deep_total=0;;
							
			}

    	count++;

    }
    
}

void mode3(){
	int i=0,j=0;
    while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //每局开局前输入一串字符，若为quit则退出程序
    {
	  for(i=0;i<SIZE;i++)
				for(j=0;j<SIZE;j++)
					aRecordBoard3[i][j]=aRecordBoard2[i][j];	
    	i=j=0;
		giving2Grades(aRecordBoard2);
		choose2Place(aRecordBoard2,i,j);
		

		if(count%2!=0)
			aRecordBoard2[li][lj]=1;
		else
			aRecordBoard2[li][lj]=2;

		recordtoDisplayArray();
   		displayBoard();


   		if(isWinning(aRecordBoard2,li,lj,(count+1)%2+1)){
   			printf("player%d is winner\n",(count+1)%2+1);
   			break;
   		}

    	lcj=lj+'a';			
		lci=15-li;
		printf("%d%c\n",lci,lcj );
    	printf("%d\n",count);
		printf("total:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board[li][lj].total,board[li][lj].five,board[li][lj].a4,board[li][lj].four,board[li][lj].a3,board[li][lj].h3,board[li][lj].ah3,board[li][lj].three,board[li][lj].a2,board[li][lj].two);
    	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++){
    			board[li][lj].total2=board[li][lj].total=board[li][lj].five=board[li][lj].a5=board[li][lj].a2=board[li][lj].h3=board[li][lj].four=board[li][lj].ah3=board[li][lj].a4=board[li][lj].three=board[li][lj].a3=board[li][lj].two=chosen_total=chosen_deep_total=0;;
							
			}

    	count++;


///////////////////////////////////////////////////
    	printf("Player%d,please enter a location. Or input \"quit\" to quit.\n",(count+1)%2+1); 
	 b2:myscanf();	
	 	if(!strcmp(cquit,"r")){
	 		for(i=0;i<SIZE;i++)
				for(j=0;j<SIZE;j++)
					aRecordBoard2[i][j]=aRecordBoard4[i][j];
			recordtoDisplayArray();
   			displayBoard();
   			goto b2;	
	 	}
	 	 for(i=0;i<SIZE;i++)
			for(j=0;j<SIZE;j++)
			aRecordBoard4[i][j]=aRecordBoard2[i][j];							//玩家输入位置
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;										
		while(lci>SIZE||lcj>SIZE+'a'){
		printf("Out of size! please enter again! Or input \"quit\" to quit.\n");				
		myscanf();									//若位置超出棋盘范围，则重新输入
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;
		}

		lj=lcj-'a';			
		li=15-lci;					//将输入的参量转化为对应数组的序号
		
		if(aRecordBoard[li][lj]==0){
			if(count%2!=0)
				aRecordBoard2[li][lj]=1;
			else
				aRecordBoard2[li][lj]=2;
		}
		else{
			printf("error!please enter again!\n");
			goto b2; 				//若输入的位置已有棋子，提示错误，并要求重新输入。
		}
		
		recordtoDisplayArray();
   		displayBoard();

   		if(isWinning(aRecordBoard2,li,lj,(count+1)%2+1)){
   			printf("player%d is winner\n",(count+1)%2+1);
   			break;
   		}
    	count++;
    }
}


void mode4(){
	int i=0,j=0;
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")&&count<=225) //每局开局前输入一串字符，若为quit则退出程序
	{
		for(i=0;i<SIZE;i++)
				for(j=0;j<SIZE;j++)
					aRecordBoard3[i][j]=aRecordBoard2[i][j];	
    	i=j=0;
		giving2Grades(aRecordBoard2);
		choose2Place(aRecordBoard2,i,j);
		while(aRecordBoard2[li][lj]!=0){
   		i=0;j=0;
		givingGrades(aRecordBoard2);
		choosePlace(aRecordBoard2,i,j);    	
	}

		if(count%2!=0)
			aRecordBoard2[li][lj]=1;
		else
			aRecordBoard2[li][lj]=2;

		recordtoDisplayArray();
   		displayBoard();


   		if(isWinning(aRecordBoard2,li,lj,(count+1)%2+1)){
   			printf("player%d is winner\n",(count+1)%2+1);
   			break;
   		}

    	lcj=lj+'a';			
		lci=15-li;
		printf("%d%c\n",lci,lcj );
    	printf("%d\n",count);
		printf("total:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board[li][lj].total,board[li][lj].five,board[li][lj].a4,board[li][lj].four,board[li][lj].a3,board[li][lj].h3,board[li][lj].ah3,board[li][lj].three,board[li][lj].a2,board[li][lj].two);
    	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++)
    			board[li][lj].total2=board[li][lj].total=board[li][lj].five=board[li][lj].a5=board[li][lj].a2=board[li][lj].h3=board[li][lj].four=board[li][lj].ah3=board[li][lj].a4=board[li][lj].three=board[li][lj].a3=board[li][lj].two=chosen_total=chosen_deep_total=0;;
    	count++;

		//////////
		i=j=0;
		givingGrades(aRecordBoard2);
		choosePlace(aRecordBoard2,i,j);
		

		if(count%2!=0)
			aRecordBoard2[li][lj]=1;
		else
			aRecordBoard2[li][lj]=2;

		recordtoDisplayArray();
   		displayBoard();


   		if(isWinning(aRecordBoard2,li,lj,(count+1)%2+1)){
   			printf("player%d is winner\n",(count+1)%2+1);
   			break;
   		}

    	lcj=lj+'a';			
		lci=15-li;
		printf("%d%c\n",lci,lcj );
    	printf("%d\n",count);
		printf("total:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board[li][lj].total,board[li][lj].five,board[li][lj].a4,board[li][lj].four,board[li][lj].a3,board[li][lj].h3,board[li][lj].ah3,board[li][lj].three,board[li][lj].a2,board[li][lj].two);
    	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++)
    			board[li][lj].total2=board[li][lj].total=board[li][lj].five=board[li][lj].a5=board[li][lj].a2=board[li][lj].h3=board[li][lj].four=board[li][lj].ah3=board[li][lj].a4=board[li][lj].three=board[li][lj].a3=board[li][lj].two=chosen_total=0;
    	count++;
    	/////
    	
	}	
}


int isSurrounded(int s[SIZE][SIZE],int li,int lj,int i){
	int num=(i+1)%2+1;
	if((s[li+1][lj]==num||s[li-1][lj]==num||s[li][lj+1]==num||s[li][lj-1]==num||s[li-1][lj-1]==num||s[li-1][lj+1]==num||s[li+1][lj-1]==num||s[li+1][lj+1]==num||i==2||i==1)&&li<=13&&0<=li&&lj<=13&&lj>=0)
		return 1;
	else
		return 0;
}

int isFour(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==4||jw[1]==4||jw[2]==4||jw[3]==4)
		return 1;
	else
		return 0;
}

int isThree(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==3||jw[1]==3||jw[2]==3||jw[3]==3){
		if(jw[0]==3){
			jw[0]=0;
			for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++) //判断横向
			jw[0]++;
			for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++)
			jw[0]++;
		}
		if(jw[1]==3){
			jw[1]=0;
			for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //判断竖向
			jw[1]++;
			for(i=1;(s[li+i][lj]==num||s[li+i][lj]==0)&&li+i<=14;i++)
			jw[1]++;
		}
		if(jw[2]==3){
			jw[2]=0;
			for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
			jw[2]++;
			for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
			jw[2]++;
		}
		if(jw[3]==3){
			jw[3]=0;
			for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
			jw[3]++;
			for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
			jw[3]++;
		}
		if(jw[0]>=4||jw[1]>=4||jw[2]>=4||jw[3]>=4)
		return 1;
	}
	
		return 0;
}

int isTwo(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==2||jw[1]==2||jw[2]==2||jw[3]==2){
		if(jw[0]==2){
			jw[0]=0;
			for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++) //判断横向
			jw[0]++;
			for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++)
			jw[0]++;
		}
		if(jw[1]==2){
			jw[1]=0;
			for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //判断竖向
			jw[1]++;
			for(i=1;(s[li+i][lj]==num||s[li+i][lj]==0)&&li+i<=14;i++)
			jw[1]++;
		}
		if(jw[2]==2){
			jw[2]=0;
			for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
			jw[2]++;
			for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
			jw[2]++;
		}
		if(jw[3]==2){
			jw[3]=0;
			for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
			jw[3]++;
			for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
			jw[3]++;
		}
		if(jw[0]>=4||jw[1]>=4||jw[2]>=4||jw[3]>=4)
		return 1;
	}
	
		return 0;
}

int isOne(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==1||jw[1]==1||jw[2]==1||jw[3]==1)
		return 1;
	else
		return 0;
}

int isHThree(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};
	
	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==3||jw[1]==3||jw[2]==3||jw[3]==3){
		if(jw[0]==3){
			for(j=1;(s[li][lj-j]==num)&&lj-j>=0;j++)  //判断横向
				;
			
			if(s[li][lj-j]==0&&lj-j>=0)
				jw[0]++;
			for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
				;
			 
			if(s[li][lj+j]==0&&lj+j<=14)
				jw[0]++;
		}
		if(jw[1]==3){
			for(i=1;(s[li-i][lj]==num)&&li-i>=0;i++); //判断竖向
			
			if(s[li-i][lj]==0&&li-i>=0)
			jw[1]++;
			for(i=1;(s[li+i][lj]==num)&&li+i<=14;i++); //判断竖向
			
			if(s[li+i][lj]==0&&li+i<=14)
			jw[1]++;
		}
		if(jw[2]==3){
			for(i=1,j=1;(s[li-i][lj-j]==num)&&li-i>=0&&lj-j>=0;i++,j++);  //判断左上-右下
			
			if(s[li-i][lj-j]==0&&li-i>=0&&lj-j>=0)
				jw[2]++;
			for(i=1,j=1;(s[li+i][lj+j]==num)&&li+i<=14&&lj+j<=14;i++,j++);  //判断左上-右下
			
			if(s[li+i][lj+j]==0&&li+i<=14&&lj+j<=14)
				jw[2]++;
		}
		if(jw[3]==3){
			for(i=1,j=1;(s[li-i][lj+j]==num)&&li-i>=0&&lj+j<=14;i++,j++);  //判断右上-左下
			
			if(s[li-i][lj+j]==0&&li-i>=0&&lj+j<=14)
				jw[3]++;
			for(i=1,j=1;(s[li+i][lj-j]==num)&&li+i<=14&&lj-j>=0;i++,j++);  //判断右上-左下
			
			if(s[li+i][lj-j]==0&&li+i<=14&&lj-j>=0)
				jw[3]++;
		}
	}
	if(jw[0]>=5||jw[1]>=5||jw[2]>=5||jw[3]>=5)
		return 1;
	else
		return 0;
}

int isDFour(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0,allrow=0;
	int jw[4]={0,0,0,0};

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==3||jw[1]==3||jw[2]==3||jw[3]==3){
		if(jw[0]==3){
			jw[0]=0;
			for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++) //判断横向
			jw[0]++;
			for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++)
			jw[0]++;
		}
		if(jw[1]==3){
			jw[1]=0;
			for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //判断竖向
			jw[1]++;
			for(i=1;(s[li+i][lj]==num||s[li+i][lj]==0)&&li+i<=14;i++)
			jw[1]++;
		}
		if(jw[2]==3){
			jw[2]=0;
			for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
			jw[2]++;
			for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
			jw[2]++;
		}
		if(jw[3]==3){
			jw[3]=0;
			for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
			jw[3]++;
			for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
			jw[3]++;
		}
	}
	if(jw[0]>=4||jw[1]>=4||jw[2]>=4||jw[3]>=4)
		for(i=0;i<=3;i++)
			if(jw[i]>=4)
				allrow++;
	if(allrow>=2)
		return 1;
	else
		return 0;
}

int isDHThree(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0,allrow=0,lim=0;
	int jw[8][2]={{0,0},{0,0},{0,0},{0,0}};

	for(j=1,lim=3;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0&&j<=lim;j++){ //判断横向
		if(s[li][lj-1]==0)
			lim=4;
		jw[0][0]++;
		if(s[li][lj-j]==num&&j<=3)
			jw[0][1]++;
	}
	if(s[li][lj-1]==0)
		jw[0][0]--;

	for(j=1,lim=3;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14&&j<=lim;j++){
		if(s[li][lj+1]==0)
			lim=4;
		jw[1][0]++;
		if(s[li][lj+j]==num&&j<=3)
		jw[1][1]++;
	}
	if(s[li][lj+1]==0)
		jw[1][0]--;

	for(i=1,lim=3;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0&&i<=lim;i++){ //判断竖向
		if(s[li-1][lj]==0)
			lim=4;
		jw[2][0]++;
		if(s[li-i][lj]==num&&i<=3)
		jw[2][1]++;
	}
	if(s[li-1][lj]==0)
		jw[2][0]--;

	for(i=1,lim=3;(s[li+i][lj]==num||s[li+i][lj]==0)&&li+i<=14&&i<=lim;i++){ //判断竖向
		if(s[li+1][lj]==0)
			lim=4;
		jw[3][0]++;
		if(s[li+i][lj]==num&&i<=3)
		jw[3][1]++;
	}
	if(s[li+1][lj]==0)
		jw[3][0]--;

	for(i=1,j=1,lim=3;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0&&i<=lim;i++,j++){  //判断左上-右下
		if(s[li-1][lj-1]==0)
			lim=4;
		jw[4][0]++;
		if(s[li-i][lj-j]==num&&j<=3)
		jw[4][1]++;
	}
	if(s[li-1][lj-1]==0)
		jw[4][0]--;

	for(i=1,j=1,lim=3;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14&&i<=lim;i++,j++){  //判断左上-右下
		if(s[li+1][lj+1]==0)
			lim=4;
		jw[5][0]++;
		if(s[li+i][lj+j]==num&&j<=3)
		jw[5][1]++;
	}
	if(s[li+1][lj+1]==0)
		jw[5][0]--;

	for(i=1,j=1,lim=3;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14&&i<=lim;i++,j++){  //判断右上-左下
		if(s[li-1][lj+1]==0)
			lim=4;
		jw[6][0]++;
		if(s[li-i][lj+j]==num&&j<=3)
		jw[6][1]++;
	}
	if(s[li-1][lj+1]==0)
		jw[6][0]--;

	for(i=1,j=1,lim=3;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0&&i<=lim;i++,j++){  //判断右上-左下
		if(s[li+1][lj-1]==0)
			lim=4;
		jw[7][0]++;
		if(s[li+i][lj-j]==num&&j<=3)
		jw[7][1]++;
	}
	if(s[li+1][lj-1]==0)
		jw[7][0]--;

	if(jw[0][0]>=3||jw[1][0]>=3||jw[2][0]>=3||jw[3][0]>=3||jw[4][0]>=3||jw[4][0]>=3||jw[6][0]>=3||jw[7][0]>=3){
		for(i=0;i<=7;i++)
			if(jw[i][0]>=3&&jw[i][1]==2)
				allrow++;
		if(jw[0][1]!=2&&jw[1][1]!=2&&jw[2][1]!=2&&jw[3][1]!=2&&jw[4][1]!=2&&jw[5][1]!=2&&jw[6][1]!=2&&jw[7][1]!=2){
				if(jw[0][1]+jw[1][1]==2)
					allrow++;
				if(jw[2][1]+jw[3][1]==2)
					allrow++;
				if(jw[4][1]+jw[5][1]==2)
					allrow++;
				if(jw[6][1]+jw[7][1]==2)
					allrow++;
			}
	}
			

	if(allrow>=2)
		return 1;
	else
		return 0;
}


int isLongRow(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if((jw[0]>=5||jw[1]>=5||jw[2]>=5||jw[3]>=5))
		return 1;
	else
		return 0;
}


int isForbidden(int s[SIZE][SIZE],int li,int lj,int num){
	if(s[li][lj]==0&&(isDHThree(s,li,lj,num)||isDFour(s,li,lj,num)||isLongRow(s,li,lj,num))&&num==1)
		return 1;
	else
		return 0;
}

void givingGrades(int s[SIZE][SIZE]){
	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++){
				if(s[li][lj]==0&&isForbidden(s,li,lj,(count+1)%2+1))
					printf("isForbidden!\n");

				if(s[li][lj]==0&&isFour(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].five=1000;

				if(s[li][lj]==0&&isFour(s,li,lj,(count)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].a4=999;

				if(s[li][lj]==0&&isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isHThree(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].four=200;

				if(s[li][lj]==0&&isHThree(s,li,lj,(count)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].ah3=900;

				if(s[li][lj]==0&&isThree(s,li,lj,(count)%2+1)&&!isHThree(s,li,lj,(count)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].a3=93;

				if(s[li][lj]==0&&isHThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].h3=998;

				if(s[li][lj]==0&&isTwo(s,li,lj,(count+1)%2+1)&&!isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].three=190;

				if(s[li][lj]==0&&isTwo(s,li,lj,count%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].a2=94;

				if(s[li][lj]==0&&isOne(s,li,lj,(count+1)%2+1)&&!isTwo(s,li,lj,(count+1)%2+1)&&!isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].two=95;

				board[li][lj].total=board[li][lj].five+board[li][lj].a2+board[li][lj].four+board[li][lj].a4+board[li][lj].three+board[li][lj].a3+board[li][lj].two+board[li][lj].h3+board[li][lj].ah3;
				if(board[li][lj].total){
				lcj=lj+'a';			
				lci=15-li;
				}
			}

}

void choosePlace(int s[SIZE][SIZE],int i,int j){
	srand(time(NULL));
	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++){
				if(((rand()%2==1)?(board[li][lj].total>chosen_total):(board[li][lj].total>=chosen_total))){
					chosen_total=board[li][lj].total;
					i=li;j=lj;
					lcj=lj+'a';			
				lci=15-li;
			}
			}
		li=i;lj=j;

		if(count==1||count==2){
    		li=7;lj=7;
     		if(aRecordBoard2[li][lj]!=0){
    		li=7;
    		lj=6;
    	}
    }

}
void giving2Grades(int s[SIZE][SIZE]){
	int m,n;
	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++){

				if(s[li][lj]==0&&isFour(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].five=1000;

				if(s[li][lj]==0&&isFour(s,li,lj,(count)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].a4=999;

				if(s[li][lj]==0&&isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isHThree(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].four=200;

				if(s[li][lj]==0&&isHThree(s,li,lj,(count)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].ah3=900;

				if(s[li][lj]==0&&isThree(s,li,lj,(count)%2+1)&&!isHThree(s,li,lj,(count)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].a3=93;

				if(s[li][lj]==0&&isHThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].h3=998;

				if(s[li][lj]==0&&isTwo(s,li,lj,(count+1)%2+1)&&!isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].three=190;

				if(s[li][lj]==0&&isTwo(s,li,lj,count%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].a2=94;

				if(s[li][lj]==0&&isOne(s,li,lj,(count+1)%2+1)&&!isTwo(s,li,lj,(count+1)%2+1)&&!isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isForbidden(s,li,lj,(count+1)%2+1))
					board[li][lj].two=95;

				board[li][lj].total=board[li][lj].five+board[li][lj].a2+board[li][lj].four+board[li][lj].a4+board[li][lj].three+board[li][lj].a3+board[li][lj].two+board[li][lj].h3+board[li][lj].ah3;
				
				if(count%2!=0)
				aRecordBoard3[li][lj]=1;
				else
				aRecordBoard3[li][lj]=2;
				
				count++;
			for(m=0;m<=14;m++)
				for(n=0;n<=14;n++){
				if(aRecordBoard3[m][n]==0&&isFour(aRecordBoard3,m,n,(count+1)%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].five=1000;

				if(aRecordBoard3[m][n]==0&&isFour(aRecordBoard3,m,n,(count)%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].a4=999;

				if(aRecordBoard3[m][n]==0&&isThree(aRecordBoard3,m,n,(count+1)%2+1)&&!isFour(aRecordBoard3,m,n,(count+1)%2+1)&&!isHThree(aRecordBoard3,m,n,(count+1)%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].four=200;

				if(aRecordBoard3[m][n]==0&&isHThree(aRecordBoard3,m,n,(count)%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].ah3=900;

				if(aRecordBoard3[m][n]==0&&isThree(aRecordBoard3,m,n,(count)%2+1)&&!isHThree(aRecordBoard3,m,n,(count)%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].a3=93;

				if(aRecordBoard3[m][n]==0&&isHThree(aRecordBoard3,m,n,(count+1)%2+1)&&!isFour(aRecordBoard3,m,n,(count+1)%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].h3=998;

				if(aRecordBoard3[m][n]==0&&isTwo(aRecordBoard3,m,n,(count+1)%2+1)&&!isThree(aRecordBoard3,m,n,(count+1)%2+1)&&!isFour(aRecordBoard3,m,n,(count+1)%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].three=190;

				if(aRecordBoard3[m][n]==0&&isTwo(aRecordBoard3,m,n,count%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].a2=94;

				if(aRecordBoard3[m][n]==0&&isOne(aRecordBoard3,m,n,(count+1)%2+1)&&!isTwo(aRecordBoard3,m,n,(count+1)%2+1)&&!isThree(aRecordBoard3,m,n,(count+1)%2+1)&&!isFour(aRecordBoard3,m,n,(count+1)%2+1)&&!isForbidden(aRecordBoard3,m,n,(count+1)%2+1))
					board2[m][n].two=95;

				board2[m][n].total=board2[m][n].five+board2[m][n].a2+board2[m][n].four+board2[m][n].a4+board2[m][n].three+board2[m][n].a3+board2[m][n].two+board2[m][n].h3+board2[m][n].ah3;
				if(board2[m][n].total){
				lcj=n+'a';			
				lci=15-m;
				// printf("%d%c\n",lci,lcj );
				// printf("count:%d\n",count);
				// printf("board2.total:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board2[m][n].total,board2[m][n].five,board2[m][n].a4,board2[m][n].four,board2[m][n].a3,board2[m][n].h3,board2[m][n].ah3,board2[m][n].three,board2[m][n].a2,board2[m][n].two);
				 }
				}
				for(m=0;m<=14;m++)
					for(n=0;n<=14;n++)
						if(((rand()%2==1)?(board2[m][n].total>chosen2_total):(board2[li][lj].total>=chosen2_total)))
							chosen2_total=board2[m][n].total;
				for(m=0;m<=14;m++)
					for(n=0;n<=14;n++)
						board2[m][n].total=board2[m][n].five=board2[m][n].a2=board2[m][n].four=board2[m][n].a4=board2[m][n].three=board2[m][n].a3=board2[m][n].two=board2[m][n].h3=board2[m][n].ah3=0;
				aRecordBoard3[li][lj]=0;
				board[li][lj].total2=chosen2_total;
				// printf("chosen2_total=%d\n",chosen2_total);
				chosen2_total=0;
				count--;

				if(board[li][lj].total2){
				lcj=lj+'a';			
				lci=15-li;
				// printf("%d%c\n",lci,lcj );
				// printf("total:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board[li][lj].total,board[li][lj].five,board[li][lj].a4,board[li][lj].four,board[li][lj].a3,board[li][lj].h3,board[li][lj].ah3,board[li][lj].three,board[li][lj].a2,board[li][lj].two);
				 }
			}
// 
}

void choose2Place(int s[SIZE][SIZE],int i,int j){
	btime:srand(time(NULL));
	chosen_deep_total=board[0][0].total2;
	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++){
				if(board[li][lj].total>=chosen_total-190){
					if(board[li][lj].total>chosen_total){
					i=li;j=lj;
					chosen_total=board[li][lj].total;
					chosen_deep_total=board[li][lj].total2;
					}
					lcj=lj+'a';			
					lci=15-li;
					if(chosen_total>0){
					// printf("for2:\n");
					// printf("%d%c\n",lci,lcj );
					// printf("total:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board[li][lj].total,board[li][lj].five,board[li][lj].a4,board[li][lj].four,board[li][lj].a3,board[li][lj].h3,board[li][lj].ah3,board[li][lj].three,board[li][lj].a2,board[li][lj].two);
					}
					else if(board[li][lj].total2<chosen_deep_total-600){
						chosen_total=board[li][lj].total;
						chosen_deep_total=board[li][lj].total2;
						i=li;j=lj;						
						lcj=lj+'a';			
						lci=15-li;
						if(chosen_total>0){
						printf("deep searching...\n");
						printf("deep loc:\n");
						printf("%d%c\n",lci,lcj );
						}				
						}
			}
			}
		li=i;lj=j;
		if(count==1||count==2){
    		li=7;lj=7;
     		if(aRecordBoard2[li][lj]!=0){
    		li=7;
    		lj=6;
    	}
    }
}

