#include <stdio.h>

struct grades
{
	int five;
	int four;
	int three;
	int two;
	int a5;
	int a4;
	int a3;
	int a2;
	int total;
}board[15][15];

if(aRecordBoard2[li][lj]==0&&isFour(aRecordBoard2,li,lj,(i+1)%2+1))
	board[li][lj].five=100;

if(aRecordBoard2[li][lj]==0&&isFour(aRecordBoard2,li,lj,(i+1)%2))
	board[li][lj].a5=99;

if(aRecordBoard2[li][lj]==0&&isThree(aRecordBoard2,li,lj,(i+1)%2+1))
	board[li][lj].four=98;

if(aRecordBoard2[li][lj]==0&&isThree(aRecordBoard2,li,lj,(i+1)%2)&&WFive(aRecordBoard2,li,lj,(i+1)%2))
	board[li][lj].a4=97;

if(aRecordBoard2[li][lj]==0&&isTwo(aRecordBoard2,li,lj,(i+1)%2+1))
	board[li][lj].three=98;

if(aRecordBoard2[li][lj]==0&&isTwo(aRecordBoard2,li,lj,(i+1)%2)&&WFive(aRecordBoard2,li,lj,(i+1)%2))
	board[li][lj].a3=97;

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

	if(jw[0]==3||jw[1]==3||jw[2]==3||jw[3]==3)
		return 1;
	else
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

	if(jw[0]==2||jw[1]==2||jw[2]==2||jw[3]==2)
		return 1;
	else
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

int WFive(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==4||jw[1]==4||jw[2]==4||jw[3]==4)
		return 1;
	else
		return 0;
}

int WFour(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==3||jw[1]==3||jw[2]==3||jw[3]==3)
		return 1;
	else
		return 0;
}

int WThree(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==2||jw[1]==2||jw[2]==2||jw[3]==2)
		return 1;
	else
		return 0;
}

int WTwo(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int jw[4]={0,0,0,0};

	for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++) //判断横向
		jw[0]++;
	for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //判断竖向
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
		jw[2]++;
	for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
		jw[3]++;
	for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==1||jw[1]==1||jw[2]==1||jw[3]==1)
		return 1;
	else
		return 0;
}
