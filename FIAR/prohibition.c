

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


int isDHFour(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int allrow=0;
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

	if(jw[0]==4||jw[1]==4||jw[2]==4||jw[3]==4){
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
			
			if(s[li-i][lj-j]==0&&li-i>=0&&lj+j<=14)
				jw[3]++;
			for(i=1,j=1;(s[li+i][lj-j]==num)&&li+i<=14&&lj-j>=0;i++,j++);  //判断右上-左下
			
			if(s[li+i][lj+j]==0&&li+i<=14&&lj-j>=0)
				jw[3]++;
		}
	}

	if(jw[0]>=5||jw[1]>=5||jw[2]>=5||jw[3]>=5)
		for(i=0;i<=3;i++)
			if(jw[i]>=5)
				allrow++
	if(allrow>=2)
		return 1;
	else
		return 0;
}

int isDHFour(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0;
	int allrow=0;
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

	if(jw[0]==4||jw[1]==4||jw[2]==4||jw[3]==4){
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
			
			if(s[li-i][lj-j]==0&&li-i>=0&&lj+j<=14)
				jw[3]++;
			for(i=1,j=1;(s[li+i][lj-j]==num)&&li+i<=14&&lj-j>=0;i++,j++);  //判断右上-左下
			
			if(s[li+i][lj+j]==0&&li+i<=14&&lj-j>=0)
				jw[3]++;
		}
	}

	if(jw[0]>=5||jw[1]>=5||jw[2]>=5||jw[3]>=5)
		for(i=0;i<=3;i++)
			if(jw[i]>=5)
				allrow++
	if(allrow>=2)
		return 1;
	else
		return 0;
}

int isDFour(int s[SIZE][SIZE],int li,int lj,int num){
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
	}
	if(jw[0]>=4||jw[1]>=4||jw[2]>=4||jw[3]>=4)
		for(i=0;i<=3;i++)
			if(jw[i]>=4)
				allrow++;
	if(allrow>=2&&num==1)
		return 1;
	else
		return 0;
}

int isDHThree(int s[SIZE][SIZE],int li,int lj,int num){//备用
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
			

	if(allrow>=2&&num==1)
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

	if((jw[0]>=5||jw[1]>=5||jw[2]>=5||jw[3]>=5)&&num==1)
		return 1;
	else
		return 0;
}


int isForbidden(int s[SIZE][SIZE],int li,int lj,int num){
	if(s[li][lj]==0&&(isDHThree(s,li,lj,num)||isDFour(s,li,lj,num)||isLongRow(s,li,lj,num)))
		return 1;
	else
		return 0;
}

int isDFour(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0,allrow=0,lim=0;
	int jw[8][2]={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};

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

	if(jw[0][0]>=3||jw[1][0]>=3||jw[2][0]>=3||jw[3][0]>=3||jw[4][0]>=3||jw[5][0]>=3||jw[6][0]>=3||jw[7][0]>=3){
		for(i=0;i<=7;i++)
			if(jw[i][0]>=3&&jw[i][1]==2)
				allrow++;
		if(jw[0][0]>=3&&jw[1][0]>=3&&jw[0][1]!=2&&jw[1][1]!=2){
			if(jw[0][1]+jw[1][1]==2)
					allrow++;}
		if(jw[2][0]>=3&&jw[3][0]>=3&&jw[2][1]!=2&&jw[3][1]!=2){
			if(jw[2][1]+jw[3][1]==2)
					allrow++;
			}
		if(jw[4][0]>=3&&jw[5][0]>=3&&jw[4][1]!=2&&jw[5][1]!=2){
			if(jw[4][1]+jw[5][1]==2)
					allrow++;
			}
		if(jw[6][0]>=3&&jw[7][0]>=3&&jw[6][1]!=2&&jw[7][1]!=2){
			if(jw[6][1]+jw[7][1]==2)
					allrow++;
			}
	}
			

	if(allrow>=2)
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
		if(jw[0]==2&&s[li][lj-1]==num&&s[li][lj+1]==num){
			jw[0]=0;
			for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++){
				if(s[li][lj-j]==0&&s[li][lj-j-1]==0)
					break;
				jw[0]++;
			}
			
			for(j=1;(s[li][lj+j]==num||s[li][lj+j]==0)&&lj+j<=14;j++){
				if(s[li][lj+j]==0&&s[li][lj+j+1]==0)
					break;
				jw[0]++;
			}
		}
		if(jw[1]==3){
			jw[1]=0;
			for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++) //判断竖向
			jw[1]++;
			for(i=1;(s[li+i][lj]==num||s[li+i][lj]==0)&&li+i<=14;i++)
			jw[1]++;
		}

		if(jw[1]==2&&s[li-1][lj]==num&&s[li+1][lj]==num){
			jw[1]=0;
			for(i=1;(s[li-i][lj]==num||s[li-i][lj]==0)&&li-i>=0;i++){
				if(s[li-i][lj]==0&&s[li-i-1][lj]==0)
					break;
				jw[1]++;
			}
			for(i=1;(s[li+i][lj]==num||s[li+i][lj]==0)&&li+i<=14;i++){
				if(s[li+i][lj]==0&&s[li+i+1][lj]==0)
					break;
				jw[1]++;
			}

		}
		if(jw[2]==3){
			jw[2]=0;
			for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++)  //判断左上-右下
			jw[2]++;
			for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++)
			jw[2]++;
		}
		if(jw[2]==2&&s[li-1][lj-1]==num&&s[li+1][lj+1]==num){
			jw[2]=0;
			for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==0)&&li-i>=0&&lj-j>=0;i++,j++){  
				if(s[li-i][lj-j]==0&&s[li-i-1][lj-j-1]==0)
					break;
				jw[2]++;
			} 
			
			for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==0)&&li+i<=14&&lj+j<=14;i++,j++){
				if(s[li+i][lj+j]==0&&s[li+i+1][lj+j+1]==0)
					break;
				jw[2]++;
			}
			
		}

		if(jw[3]==3){
			jw[3]=0;
			for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++) 
			jw[3]++;
			for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++)
			jw[3]++;
		}
		if(jw[3]==3&&s[li-1][lj+1]==num&&s[li+1][lj-1]==num){
			jw[3]=0;
			for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i-1][lj+j+1]==0)&&li-i>=0&&lj+j<=14;i++,j++)  //判断右上-左下
			jw[3]++;
			for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i+1][lj-j-1]==0)&&li+i<=14&&lj-j>=0;i++,j++)
			jw[3]++;
		}

		
		if(jw[0]>=4||jw[1]>=4||jw[2]>=4||jw[3]>=4)
			for(i=0;i<=3;i++)
				if(jw[i]>=4)
					allrow++;
	}
	if(allrow>=2)
		return 1;
	else
		return 0;
}

int isDFour(int s[SIZE][SIZE],int li,int lj,int num){
	int i=0,j=0,allrow=0;
	int jw[4]={0,0,0,0};

			for(j=1;(s[li][lj-j]==num||s[li][lj-j]==0)&&lj-j>=0;j++){
				
				jw[0]++;
				if(s[li][lj-j]==0&&s[li][lj-j-1]==0)
					break;
			}
			
			for(j=1;(s[li][lj+j]==num||s[li][lj+j]==num)&&lj+j<=14;j++){
				
				jw[0]++;
				if(s[li][lj+j]==0&&s[li][lj+j+1]==0)
					break;
			}
		
		

			for(i=1;(s[li-i][lj]==num||s[li-i][lj]==num)&&li-i>=0;i++){
				
				jw[1]++;
				if(s[li-i][lj]==0&&s[li-i-1][lj]==0)
					break;
			}
			for(i=1;(s[li+i][lj]==num||s[li+i][lj]==num)&&li+i<=14;i++){
				
				jw[1]++;
				if(s[li+i][lj]==0&&s[li+i+1][lj]==0)
					break;
			}

		

			for(i=1,j=1;(s[li-i][lj-j]==num||s[li-i][lj-j]==num)&&li-i>=0&&lj-j>=0;i++,j++){  
				
				jw[2]++;
				if(s[li-i][lj-j]==0&&s[li-i-1][lj-j-1]==0)
					break;
			} 
			
			for(i=1,j=1;(s[li+i][lj+j]==num||s[li+i][lj+j]==num)&&li+i<=14&&lj+j<=14;i++,j++){
				
				jw[2]++;
				if(s[li+i][lj+j]==0&&s[li+i+1][lj+j+1]==0)
					break;
			}
			

			for(i=1,j=1;(s[li-i][lj+j]==num||s[li-i][lj+j]==0)&&li-i>=0&&lj+j<=14;i++,j++){
				
				jw[3]++;
				if(s[li-i-1][lj+j+1]==0&&s[li-i-1][lj+j+1]==0)
					break;
			}  
			
			for(i=1,j=1;(s[li+i][lj-j]==num||s[li+i][lj-j]==0)&&li+i<=14&&lj-j>=0;i++,j++){
				
				jw[3]++;
				if(s[li+i][lj-j]==0&&s[li+i+1][lj-j-1]==0)
					break;
			}

		
		if(jw[0]>=4||jw[1]>=4||jw[2]>=4||jw[3]>=4)
			for(i=0;i<=3;i++)
				if(jw[i]>=4)
					allrow++;
	
	if(allrow>=2&&num==1)
		return 1;
	else
		return 0;
}

int isHTwo(int s[SIZE][SIZE],int li,int lj,int num){
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
			for(j=1;(s[li][lj-j]==num)&&lj-j>=0;j++)  //判断横向
				;
			
			if(s[li][lj-j]==0&&lj-j>=0)
				jw[0]++;
			for(j=1;s[li][lj+j]==num&&lj+j<=14;j++)
				;
			 
			if(s[li][lj+j]==0&&lj+j<=14)
				jw[0]++;
		}
		if(jw[1]==2){
			for(i=1;(s[li-i][lj]==num)&&li-i>=0;i++); //判断竖向
			
			if(s[li-i][lj]==0&&li-i>=0)
			jw[1]++;
			for(i=1;(s[li+i][lj]==num)&&li+i<=14;i++); //判断竖向
			
			if(s[li+i][lj]==0&&li+i<=14)
			jw[1]++;
		}
		if(jw[2]==2){
			for(i=1,j=1;(s[li-i][lj-j]==num)&&li-i>=0&&lj-j>=0;i++,j++);  //判断左上-右下
			
			if(s[li-i][lj-j]==0&&li-i>=0&&lj-j>=0)
				jw[2]++;
			for(i=1,j=1;(s[li+i][lj+j]==num)&&li+i<=14&&lj+j<=14;i++,j++);  //判断左上-右下
			
			if(s[li+i][lj+j]==0&&li+i<=14&&lj+j<=14)
				jw[2]++;
		}
		if(jw[3]==2){
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