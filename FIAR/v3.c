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
int isSurrounded(int s[SIZE][SIZE],int li,int lj,int n);
int isFour(int s[SIZE][SIZE],int li,int lj,int n);
int isThree(int s[SIZE][SIZE],int li,int lj,int n);
int isTwo(int s[SIZE][SIZE],int li,int lj,int n);
int isOne(int s[SIZE][SIZE],int li,int lj,int n);
int WFive(int s[SIZE][SIZE],int li,int lj,int num);
void printloc(int,int);
int jw[4]={0,0,0,0};
//����ʹ�õ���GBK���룬ÿһ�������ַ�ռ��2���ֽڡ�
//���̻���ģ�� 
char aInitDisplayBoardArray[SIZE][SIZE*CHARSIZE+1] = 
{
		"���өөөөөөөөөөөөө�",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"�ĩ��������������",
		"���۩۩۩۩۩۩۩۩۩۩۩۩۩�"
};
//������������ʾ���� 
char aDisplayBoardArray[SIZE][SIZE*CHARSIZE+1];
 
char play1Pic[]="��";//������;
char play1CurrentPic[]="��"; 


char play2Pic[]="��";//������;
char play2CurrentPic[]="��";


//���������ڼ�¼���̸�� 
int aRecordBoard[SIZE][SIZE];
int aRecordBoard2[SIZE][SIZE];


int main(){
	int li,lj,i=1,mode;
	initRecordBorard();
    recordtoDisplayArray();
    displayBoard();

    printf("Please press a number to choose the mode: \n\"1\" for person to person, \"2\"for person to computer.\n");
	scanf("%s",cquit);
	mode=cquit[0]-'0';															//ѡ��ģʽ
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

//��ʼ�����̸�� 
void initRecordBorard(void){
	int i,j;
	for(i=0;i<SIZE;i++)//ͨ��˫��ѭ������aRecordBoard��0
		for(j=0;j<SIZE;j++){
			aRecordBoard2[i][j]=0;
			aRecordBoard[i][j]=0;
		}
}

//��aRecordBoard�м�¼������λ�ã�ת����aDisplayBoardArray��
void recordtoDisplayArray(void){
	int i,j;
	for(i=0;i<SIZE;i++)						//��һ������aInitDisplayBoardArray�м�¼�Ŀ����̣����Ƶ�aDisplayBoardArray��
		for(j=0;j<SIZE*CHARSIZE+1;j++)
			aDisplayBoardArray[i][j]=aInitDisplayBoardArray[i][j];
	for(i=0;i<SIZE;i++)							//�ڶ�����ɨ��aRecordBoard����������0��Ԫ�أ�������ߡ��Ƶ�aDisplayBoardArray����Ӧλ����
		for(j=0;j<SIZE;j++){
			if(aRecordBoard2[i][j]==1&&(aRecordBoard2[i][j]==aRecordBoard[i][j])){ 			//��ͬһλ�õ���û�иı䣬�����λ����֮ǰ������״̬
				aDisplayBoardArray[i][j*CHARSIZE]=play1Pic[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=play1Pic[1];
			}
			else if(aRecordBoard2[i][j]==2&&aRecordBoard2[i][j]==aRecordBoard[i][j]){
				aDisplayBoardArray[i][j*CHARSIZE]=play2Pic[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=play2Pic[1];
			}
			
			else if(aRecordBoard2[i][j]==1&&aRecordBoard2[i][j]!=aRecordBoard[i][j]){		//��ͬһλ�õ����ı䣬�����λ���Ǳ������ӵ�λ��
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
					aRecordBoard[i][j]=aRecordBoard2[i][j];									//��״̬�ͱ��ֶ�ȡ״̬ͬ��	
				
}


//��ʾ���̸�� 
void displayBoard(void){
	int i,j;
	//��һ��������
	system("clear");   //����

	for(i=0;i<SIZE;i++){				//�ڶ�������aDisplayBoardArray�������Ļ��
		printf("%2d ",15-i);			//�����������
		for(j=0;j<SIZE*CHARSIZE+1;j++)
			printf("%c",aDisplayBoardArray[i][j]);
		printf("\n");
	}													
	
	printf("   A B C D E F G H I J K L M N O\n");//������������������һ����ĸA B .... 
} 


void myscanf(){
	
		scanf("%s",cquit);									//�������λ��
		
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

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //�жϺ���
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //�ж�����
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //�ж�����-����
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //�ж�����-����
		jw[3]++;
	for(i=1,j=1;s[li+i][lj-j]==num&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]==4||jw[1]==4||jw[2]==4||jw[3]==4)
		return 1;
	else
		return 0;
}


void mode1(){
	int li,lj,i=1;
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //ÿ�ֿ���ǰ����һ���ַ�����Ϊquit���˳�����
	{
		printf("Player%d,please enter a location. Or input \"quit\" to quit.\n",(i+1)%2+1); 
	 b1:myscanf();									//�������λ��
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;										
		while(lci>SIZE||lcj>SIZE+'a'){
		printf("Out of size! please enter again! Or input \"quit\" to quit.\n");				
		myscanf();									//��λ�ó������̷�Χ������������
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;
		}

		lj=lcj-'a';			
		li=15-lci;					//������Ĳ���ת��Ϊ��Ӧ��������
		printf("aRecordBoard[%d][%d]=%d\n",li,lj,aRecordBoard[li][lj]);
		if(aRecordBoard[li][lj]==0){
			if(i%2!=0)
				aRecordBoard2[li][lj]=1;
			else
				aRecordBoard2[li][lj]=2;
		}
		else{
			printf("error!please enter again!\n");
			goto b1; 				//�������λ���������ӣ���ʾ���󣬲�Ҫ���������롣
		}
		
		recordtoDisplayArray();
   		displayBoard();

   		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
   			printf("player%d is winner\n",(i+1)%2+1);
   			break;
   		}
    	i++;
	}

}

void mode2(){
	int li,lj,i=1,count=0,test1=0,test2=0,test3=0,test4=0,anti4=0,anti3=0,antia3=0,antia4=0;
	
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //ÿ�ֿ���ǰ����һ���ַ�����Ϊquit���˳�����
	{
		printf("Player%d,please enter a location. Or input \"quit\" to quit.\n",(i+1)%2+1); 
	 b2:myscanf();									//�������λ��
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;										
		while(lci>SIZE||lcj>SIZE+'a'){
		printf("Out of size! please enter again! Or input \"quit\" to quit.\n");				
		myscanf();									//��λ�ó������̷�Χ������������
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;
		}

		lj=lcj-'a';			
		li=15-lci;					//������Ĳ���ת��Ϊ��Ӧ��������
		
		if(aRecordBoard[li][lj]==0){
			if(i%2!=0)
				aRecordBoard2[li][lj]=1;
			else
				aRecordBoard2[li][lj]=2;
		}
		else{
			printf("error!please enter again!\n");
			goto b2; 				//�������λ���������ӣ���ʾ���󣬲�Ҫ���������롣
		}
		
		recordtoDisplayArray();
   		displayBoard();
   		printloc(li,lj);
   		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
   			printf("player%d is winner\n",(i+1)%2+1);
   			break;
   		}
    	i++;
///////////////////////////////////////////////////////
    	srand(time(NULL));
    	li=rand()%15;
    	lj=rand()%15;
    	printf("initial:\n");
    	printloc(li,lj);
    	
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isFour(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    	}
    	if(isFour(aRecordBoard2,li,lj,(i+1)%2+1))
    		test4=1;
    	printf("After isFour:\n");
    	printloc(li,lj);

    	if(test4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isFour(aRecordBoard2,li,lj,i%2+1))&&count<=2550000;count++){
    		    li=rand()%15;
    			lj=rand()%15;
    		}
    		if(isFour(aRecordBoard2,li,lj,i%2+1))
    		anti4=1;
		}
		printf("After isAFour:\n");
		printloc(li,lj);

    	if(test4!=1&&anti4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,(i+1)%2+1)||!WFive(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    			li=rand()%15;
    			lj=rand()%15;	
    		}
    		if(isThree(aRecordBoard2,li,lj,(i+1)%2+1))
    		test3=1;
		}
		printf("After isThree:\n");
		printloc(li,lj);

		if(test3!=1&&test4!=1&&anti4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,i%2+1)||!isOne(aRecordBoard2,li,lj,i%2+1)||!WFive(aRecordBoard2,li,lj,(i)%2+1))&&count<=1550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isThree(aRecordBoard2,li,lj,i%2+1))
    		antia3=1;
		}
		printf("After isAAThree:\n");
		printloc(li,lj);

		if(test3!=1&&test4!=1&&anti4!=1&&antia3!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,i%2+1)||!WFive(aRecordBoard2,li,lj,i%2+1))&&count<=2550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isThree(aRecordBoard2,li,lj,i%2+1))
    		anti3=1;
		}
		printf("After isAThree:\n");
		printloc(li,lj);
    	
    	if(test3!=1&&test4!=1&&anti3!=1&&anti4!=1&&antia3!=1){
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isTwo(aRecordBoard2,li,lj,(i+1)%2+1)||!WFive(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isTwo(aRecordBoard2,li,lj,(i+1)%2+1))
    		test2=1;
    	}
    	printf("After isTwo:\n");
    	printloc(li,lj);
    	
    	if(test2!=1&&test4!=1&&test3!=1&&anti3!=1&&anti4!=1&&antia3!=1){
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isOne(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isOne(aRecordBoard2,li,lj,(i+1)%2+1))
    		test1=1;
    	}
    	printf("After isOne:\n");
    	printloc(li,lj);

    	if(i==1||i==2){
    		li=7;lj=7;
     		if(aRecordBoard2[li][lj]!=0){
    		li=7;
    		lj=6;
    	}
    }
    	printf("i=%d After 1||2:\n",i);
    	printloc(li,lj);

    	// while(aRecordBoard[li][lj]!=0||!isSurrounded(aRecordBoard2,li,lj,i)){
    	// li=rand()%15;
    	// lj=rand()%15;
    	// }
    	printf("After while:\n");
    	printloc(li,lj);

		if(i%2!=0)
			aRecordBoard2[li][lj]=1;
		else
			aRecordBoard2[li][lj]=2;



		recordtoDisplayArray();
   		displayBoard();

   		printloc(li,lj);

   		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
   			printf("player%d is winner\n",(i+1)%2+1);
   			break;
   		}

    	
    	printf("%d\n",i);
    	printf("%d %d %d %d %d %d\n",test4,test3,test2,test1,anti4,anti3);
    	
    	test4=test2=test3=test1=anti3=anti4=antia4=antia3=0;
    	i++;
    }
    
}

void mode3(){
	int li,lj,i=1,count=0,test1=0,test2=0,test3=0,test4=0,anti4=0,antia3=0,antia4=0,anti3=0;
	
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //ÿ�ֿ���ǰ����һ���ַ�����Ϊquit���˳�����
	{
    	srand(time(NULL));
    	li=rand()%15;
    	lj=rand()%15;
    	printf("initial:\n");
    	printloc(li,lj);
    	
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isFour(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    	}
    	if(isFour(aRecordBoard2,li,lj,(i+1)%2+1))
    		test4=1;
    	printf("After isFour:\n");
    	printloc(li,lj);

    	if(test4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isFour(aRecordBoard2,li,lj,i%2+1))&&count<=2550000;count++){
    		    li=rand()%15;
    			lj=rand()%15;
    		}
    		if(isFour(aRecordBoard2,li,lj,i%2+1))
    		anti4=1;
		}
		printf("After isAFour:\n");
		printloc(li,lj);

    	if(test4!=1&&anti4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,(i+1)%2+1)||!WFive(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    			li=rand()%15;
    			lj=rand()%15;	
    		}
    		if(isThree(aRecordBoard2,li,lj,(i+1)%2+1))
    		test3=1;
		}
		printf("After isThree:\n");
		printloc(li,lj);

		if(test3!=1&&test4!=1&&anti4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,i%2+1)||!isOne(aRecordBoard2,li,lj,i%2+1)||!WFive(aRecordBoard2,li,lj,(i)%2+1))&&count<=1550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isThree(aRecordBoard2,li,lj,i%2+1))
    		antia3=1;
		}
		printf("After isAAThree:\n");
		printloc(li,lj);

		if(test3!=1&&test4!=1&&anti4!=1&&antia3!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,i%2+1)||!WFive(aRecordBoard2,li,lj,i%2+1))&&count<=2550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isThree(aRecordBoard2,li,lj,i%2+1))
    		anti3=1;
		}
		printf("After isAThree:\n");
		printloc(li,lj);
    	
    	if(test3!=1&&test4!=1&&anti3!=1&&anti4!=1&&antia3!=1){
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isTwo(aRecordBoard2,li,lj,(i+1)%2+1)||!WFive(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isTwo(aRecordBoard2,li,lj,(i+1)%2+1))
    		test2=1;
    	}
    	printf("After isTwo:\n");
    	printloc(li,lj);
    	
    	if(test2!=1&&test4!=1&&test3!=1&&anti3!=1&&anti4!=1&&antia3!=1){
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isOne(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isOne(aRecordBoard2,li,lj,(i+1)%2+1))
    		test1=1;
    	}
    	printf("After isOne:\n");
    	printloc(li,lj);

    	if(i==1||i==2){
    		li=7;lj=7;
     		if(aRecordBoard2[li][lj]!=0){
    		li=7;
    		lj=6;
    	}
    }
    	printf("i=%d After 1||2:\n",i);
    	printloc(li,lj);

    	// while(aRecordBoard[li][lj]!=0||!isSurrounded(aRecordBoard2,li,lj,i)){
    	// li=rand()%15;
    	// lj=rand()%15;
    	// }
    	printf("After while:\n");
    	printloc(li,lj);

		if(i%2!=0)
			aRecordBoard2[li][lj]=1;
		else
			aRecordBoard2[li][lj]=2;



		recordtoDisplayArray();
   		displayBoard();

   		printloc(li,lj);

   		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
   			printf("player%d is winner\n",(i+1)%2+1);
   			break;
   		}

    	
    	printf("%d\n",i);
    	printf("%d %d %d %d %d %d\n",test4,test3,test2,test1,anti4,anti3);
    	
    	test4=test2=test3=test1=anti3=anti4=antia4=antia3=0;
    	i++;
///////////////////////////////////////////////////
    	printf("Player%d,please enter a location. Or input \"quit\" to quit.\n",(i+1)%2+1); 
	 b2:myscanf();									//�������λ��
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;										
		while(lci>SIZE||lcj>SIZE+'a'){
		printf("Out of size! please enter again! Or input \"quit\" to quit.\n");				
		myscanf();									//��λ�ó������̷�Χ������������
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;
		}

		lj=lcj-'a';			
		li=15-lci;					//������Ĳ���ת��Ϊ��Ӧ��������
		
		if(aRecordBoard[li][lj]==0){
			if(i%2!=0)
				aRecordBoard2[li][lj]=1;
			else
				aRecordBoard2[li][lj]=2;
		}
		else{
			printf("error!please enter again!\n");
			goto b2; 				//�������λ���������ӣ���ʾ���󣬲�Ҫ���������롣
		}
		
		recordtoDisplayArray();
   		displayBoard();

   		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
   			printf("player%d is winner\n",(i+1)%2+1);
   			break;
   		}
    	i++;
    }
}

void mode4(){
	int li,lj,i=1,count=0,test1=0,test2=0,test3=0,test4=0,anti4=0,anti3=0,antia4=0,antia3=0;
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //ÿ�ֿ���ǰ����һ���ַ�����Ϊquit���˳�����
	{
  //   	srand(time(NULL));
  //   	li=rand()%15;
  //   	lj=rand()%15;
  //    	while(aRecordBoard[li][lj]!=0||!isSurrounded(aRecordBoard2,li,lj,i)){
  //   	li=rand()%15;
  //   	lj=rand()%15;
  //   	}
		// if(i%2!=0)
		// 	aRecordBoard2[li][lj]=1;
		// else
		// 	aRecordBoard2[li][lj]=2;

		// recordtoDisplayArray();
  //  		displayBoard();

  //  		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
  //  			printf("player%d is winner\n",(i+1)%2+1);
  //  			break;
  //  		}
  //   	i++;

    	srand(time(NULL));
    	li=rand()%15;
    	lj=rand()%15;
    	printf("initial:\n");
    	printloc(li,lj);
    	
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isFour(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    	}
    	if(isFour(aRecordBoard2,li,lj,(i+1)%2+1))
    		test4=1;
    	printf("After isFour:\n");
    	printloc(li,lj);

    	if(test4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isFour(aRecordBoard2,li,lj,i%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isFour(aRecordBoard2,li,lj,i%2+1))
    		anti4=1;
		}
		printf("After isAFour:\n");
		printloc(li,lj);

    	if(test4!=1&&anti4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isThree(aRecordBoard2,li,lj,(i+1)%2+1))
    		test3=1;
		}
		printf("After isThree:\n");
		printloc(li,lj);

		if(test3!=1&&test4!=1&&anti4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,i%2+1)||!isOne(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isThree(aRecordBoard2,li,lj,i%2+1))
    		antia3=1;
		}
		printf("After isAAThree:\n");
		printloc(li,lj);

		if(test3!=1&&test4!=1&&anti4!=1&&antia3!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,i%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isThree(aRecordBoard2,li,lj,i%2+1))
    		anti3=1;
		}
		printf("After isAThree:\n");
		printloc(li,lj);
    	
    	if(test3!=1&&test4!=1&&anti3!=1&&anti4!=1&&antia3!=1){
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isTwo(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isTwo(aRecordBoard2,li,lj,(i+1)%2+1))
    		test2=1;
    	}
    	printf("After isTwo:\n");
    	printloc(li,lj);
    	
    	if(test2!=1&&test4!=1&&test3!=1&&anti3!=1&&anti4!=1&&antia3!=1){
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isOne(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isOne(aRecordBoard2,li,lj,(i+1)%2+1))
    		test1=1;
    	}
    	printf("After isOne:\n");
    	printloc(li,lj);

    	if(i==1||i==2){
    		li=7;lj=7;
     		if(aRecordBoard2[li][lj]!=0){
    		li=7;
    		lj=6;
    	}
    }
    	printf("i=%d After 1||2:\n",i);
    	printloc(li,lj);

    	// while(aRecordBoard[li][lj]!=0||!isSurrounded(aRecordBoard2,li,lj,i)){
    	// li=rand()%15;
    	// lj=rand()%15;
    	// }
    	printf("After while:\n");
    	printloc(li,lj);

		if(i%2!=0)
			aRecordBoard2[li][lj]=1;
		else
			aRecordBoard2[li][lj]=2;



		recordtoDisplayArray();
   		displayBoard();

   		printloc(li,lj);

   		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
   			printf("player%d is winner\n",(i+1)%2+1);
   			break;
   		}

    	
    	printf("%d\n",i);
    	printf("%d %d %d %d %d %d\n",test4,test3,test2,test1,anti4,anti3);
    	
    	test4=test2=test3=test1=anti3=anti4=antia4=antia3=0;
    	i++;

  //   	srand(time(NULL));
  //    	while(aRecordBoard[li][lj]!=0||!isSurrounded(aRecordBoard2,li,lj,i)){
  //   	li=rand()%15;
  //   	lj=rand()%15;
  //   	}

		// if(i%2!=0)
		// 	aRecordBoard2[li][lj]=1;
		// else
		// 	aRecordBoard2[li][lj]=2;

		// recordtoDisplayArray();
  //  		displayBoard();

  //  		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
  //  			printf("player%d is winner\n",(i+1)%2+1);
  //  			break;
  //  		}
  //   	i++;
    	////////////////////////////////
srand(time(NULL));
    	li=rand()%15;
    	lj=rand()%15;
    	printf("initial:\n");
    	printloc(li,lj);
    	
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isFour(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    	}
    	if(isFour(aRecordBoard2,li,lj,(i+1)%2+1))
    		test4=1;
    	printf("After isFour:\n");
    	printloc(li,lj);

    	if(test4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isFour(aRecordBoard2,li,lj,i%2+1))&&count<=2550000;count++){
    		    li=rand()%15;
    			lj=rand()%15;
    		}
    		if(isFour(aRecordBoard2,li,lj,i%2+1))
    		anti4=1;
		}
		printf("After isAFour:\n");
		printloc(li,lj);

    	if(test4!=1&&anti4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,(i+1)%2+1)||!WFive(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    			li=rand()%15;
    			lj=rand()%15;	
    		}
    		if(isThree(aRecordBoard2,li,lj,(i+1)%2+1))
    		test3=1;
		}
		printf("After isThree:\n");
		printloc(li,lj);

		if(test3!=1&&test4!=1&&anti4!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,i%2+1)||!isOne(aRecordBoard2,li,lj,i%2+1)||!WFive(aRecordBoard2,li,lj,(i)%2+1))&&count<=1550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isThree(aRecordBoard2,li,lj,i%2+1))
    		antia3=1;
		}
		printf("After isAAThree:\n");
		printloc(li,lj);

		if(test3!=1&&test4!=1&&anti4!=1&&antia3!=1){
    		for(count=0;(aRecordBoard2[li][lj]!=0||!isThree(aRecordBoard2,li,lj,i%2+1)||!WFive(aRecordBoard2,li,lj,i%2+1))&&count<=2550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isThree(aRecordBoard2,li,lj,i%2+1))
    		anti3=1;
		}
		printf("After isAThree:\n");
		printloc(li,lj);
    	
    	if(test3!=1&&test4!=1&&anti3!=1&&anti4!=1&&antia3!=1){
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isTwo(aRecordBoard2,li,lj,(i+1)%2+1)||!WFive(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		
    			li=rand()%15;
    			lj=rand()%15;
    			
    		}
    		if(isTwo(aRecordBoard2,li,lj,(i+1)%2+1))
    		test2=1;
    	}
    	printf("After isTwo:\n");
    	printloc(li,lj);
    	
    	if(test2!=1&&test4!=1&&test3!=1&&anti3!=1&&anti4!=1&&antia3!=1){
    	for(count=0;(aRecordBoard2[li][lj]!=0||!isOne(aRecordBoard2,li,lj,(i+1)%2+1))&&count<=2550000;count++){
    		li=rand()%15;
    		lj=rand()%15;
    		}
    		if(isOne(aRecordBoard2,li,lj,(i+1)%2+1))
    		test1=1;
    	}
    	printf("After isOne:\n");
    	printloc(li,lj);

    	if(i==1||i==2){
    		li=7;lj=7;
     		if(aRecordBoard2[li][lj]!=0){
    		li=7;
    		lj=6;
    	}
    }
    	printf("i=%d After 1||2:\n",i);
    	printloc(li,lj);

    	// while(aRecordBoard[li][lj]!=0||!isSurrounded(aRecordBoard2,li,lj,i)){
    	// li=rand()%15;
    	// lj=rand()%15;
    	// }
    	printf("After while:\n");
    	printloc(li,lj);

		if(i%2!=0)
			aRecordBoard2[li][lj]=1;
		else
			aRecordBoard2[li][lj]=2;



		recordtoDisplayArray();
   		displayBoard();

   		printloc(li,lj);

   		if(isWinning(aRecordBoard2,li,lj,(i+1)%2+1)){
   			printf("player%d is winner\n",(i+1)%2+1);
   			break;
   		}

    	
    	printf("%d\n",i);
    	printf("%d %d %d %d %d %d\n",test4,test3,test2,test1,anti4,anti3);
    	
    	test4=test2=test3=test1=anti3=anti4=antia4=antia3=0;
    	i++;

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

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //�жϺ���
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //�ж�����
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //�ж�����-����
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //�ж�����-����
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

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //�жϺ���
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //�ж�����
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //�ж�����-����
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //�ж�����-����
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

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //�жϺ���
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //�ж�����
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //�ж�����-����
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //�ж�����-����
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

	for(j=1;s[li][lj-j]==num&&lj-j>=0;j++) //�жϺ���
		jw[0]++;
	for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;s[li-i][lj]==num&&li-i>=0;i++) //�ж�����
		jw[1]++;
	for(i=1;s[li+i][lj]==num&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;s[li-i][lj-j]==num&&li-i>=0&&lj-j>=0;i++,j++)  //�ж�����-����
		jw[2]++;
	for(i=1,j=1;s[li+i][lj+j]==num&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;s[li-i][lj+j]==num&&li-i>=0&&lj+j<=14;i++,j++)  //�ж�����-����
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

	for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++) //�жϺ���
		jw[0]++;
	for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++)
		jw[0]++;

	for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //�ж�����
		jw[1]++;
	for(i=1;(s[li+i][lj]==num||s[li+i][lj]==0)&&li+i<=14;i++)
		jw[1]++;

	for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //�ж�����-����
		jw[2]++;
	for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
		jw[2]++;

	for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //�ж�����-����
		jw[3]++;
	for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
		jw[3]++;

	if(jw[0]>=4||jw[1]>=4||jw[2]>=4||jw[3]>=4)
		return 1;
	else
		return 0;
}