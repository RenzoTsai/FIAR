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
char p1[]="��";

char play2Pic[]="��";//������;
char play2CurrentPic[]="��";
char p2[]="��";

//���������ڼ�¼���̸�� 
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
	while(strcmp(cquit,"quit")&&strcmp(cquit,"q")) //ÿ�ֿ���ǰ����һ���ַ�����Ϊquit���˳�����
	{
		printf("Player%d,please enter a location. Or input \"quit\" to quit.\n",(i+1)%2+1); 
		b1:myscanf();									//�������λ��
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;										
		while(lci>=SIZE||lcj>=SIZE+'a'){
		printf("Out of size! please enter again! Or input \"quit\" to quit.\n");				
		myscanf();									//��λ�ó������̷�Χ������������
		if(!strcmp(cquit,"quit")||!strcmp(cquit,"q"))
			break;
		}

		lj=lcj-'a';			
		li=15-lci;			//������Ĳ���ת��Ϊ��Ӧ��������
		printf("aRecordBoard[%d][%d]=%d\n",li,lj,aRecordBoard[li][lj]);
		if(aRecordBoard[li][lj]==0){
			if(i%2!=0)
				aRecordBoard2[li][lj]=1;
			else
				aRecordBoard2[li][lj]=2;
		}
		else{
			printf("error!please enter again!\n");
			goto b1; //�������λ���������ӣ���ʾ���󣬲�Ҫ���������롣
		}
		
		recordtoDisplayArray();
   		displayBoard();
    	i++;
   		cd[0]='o';

	}

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
			else if(aRecordBoard2[i][j]==1&&aRecordBoard2[i][j]!=aRecordBoard[i][j]&&(!strcmp(cd,"crz")||!strcmp(cd,"ghr"))){		//��ͬһλ�õ����ı䣬�����λ���Ǳ������ӵ�λ��
				aDisplayBoardArray[i][j*CHARSIZE]=p1[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=p1[1];
			}
			else if(aRecordBoard2[i][j]==2&&aRecordBoard2[i][j]!=aRecordBoard[i][j]&&(!strcmp(cd,"crz")||!strcmp(cd,"ghr"))){
				aDisplayBoardArray[i][j*CHARSIZE]=p2[0];
				aDisplayBoardArray[i][j*CHARSIZE+1]=p2[1];
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
	
	printf("   A B C D E F G H I J K L O P Q\n");//������������������һ����ĸA B .... 
} 


void myscanf(){
	
	s1:scanf("%s",cquit);									//�������λ��
		
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
			printf("�� He is a cool boy �� Hhh~ And please input the location again!\n");
			cd[0]=cquit[0];
			cd[1]=cquit[1];
			cd[2]=cquit[2];
			cd[3]=cquit[3];
			cd[4]=cquit[4];
			goto s1;
		}																								//�ʵ�
		else if(!strcmp(cquit,"fyf")||!strcmp(cquit,"ghr")){
			printf("%s is the smartest boy! Hhh~ And please input the location again!\n",cquit);
			goto s1;
		}																							//�ʵ�

		else{
			lcj=cquit[0];
			lci=(cquit[1]-'0');
		}

}
