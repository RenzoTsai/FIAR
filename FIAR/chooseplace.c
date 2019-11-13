void giving2Grades(int s[SIZE][SIZE]){
	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++){
				if(s[li][lj]==0&&isFour(s,li,lj,(count+1)%2+1))
					board[li][lj].five=1000;

				if(s[li][lj]==0&&isFour(s,li,lj,(count)%2+1))
					board[li][lj].a4=999;

				if(s[li][lj]==0&&isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1)&&!isHThree(s,li,lj,(count+1)%2+1))
					board[li][lj].four=200;

				if(s[li][lj]==0&&isHThree(s,li,lj,(count)%2+1))
					board[li][lj].ah3=900;

				if(s[li][lj]==0&&isThree(s,li,lj,(count)%2+1)&&!isHThree(s,li,lj,(count)%2+1))
					board[li][lj].a3=93;

				if(s[li][lj]==0&&isHThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1))
					board[li][lj].h3=998;

				if(s[li][lj]==0&&isTwo(s,li,lj,(count+1)%2+1)&&!isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1))
					board[li][lj].three=190;

				if(s[li][lj]==0&&isTwo(s,li,lj,count%2+1))
					board[li][lj].a2=94;

				if(s[li][lj]==0&&isOne(s,li,lj,(count+1)%2+1)&&!isTwo(s,li,lj,(count+1)%2+1)&&!isThree(s,li,lj,(count+1)%2+1)&&!isFour(s,li,lj,(count+1)%2+1))
					board[li][lj].two=95;

				board[li][lj].total=board[li][lj].five+board[li][lj].a2+board[li][lj].four+board[li][lj].a4+board[li][lj].three+board[li][lj].a3+board[li][lj].two+board[li][lj].h3+board[li][lj].ah3;
				
				if(count%2!=0)
				aRecordBoard3[li][lj]=1;
				else
				aRecordBoard3[li][lj]=2;
				
				count++;
			for(li=0;li<=14;li++)
				for(lj=0;lj<=14;lj++){
				if(aRecordBoard3[li][lj]==0&&isFour(aRecordBoard3,li,lj,(count+1)%2+1))
					board2[li][lj].five=1000;

				if(aRecordBoard3[li][lj]==0&&isFour(aRecordBoard3,li,lj,(count)%2+1))
					board2[li][lj].a4=999;

				if(aRecordBoard3[li][lj]==0&&isThree(aRecordBoard3,li,lj,(count+1)%2+1)&&!isFour(aRecordBoard3,li,lj,(count+1)%2+1)&&!isHThree(aRecordBoard3,li,lj,(count+1)%2+1))
					board2[li][lj].four=200;

				if(aRecordBoard3[li][lj]==0&&isHThree(aRecordBoard3,li,lj,(count)%2+1))
					board2[li][lj].ah3=900;

				if(aRecordBoard3[li][lj]==0&&isThree(aRecordBoard3,li,lj,(count)%2+1)&&!isHThree(aRecordBoard3,li,lj,(count)%2+1))
					board2[li][lj].a3=93;

				if(aRecordBoard3[li][lj]==0&&isHThree(aRecordBoard3,li,lj,(count+1)%2+1)&&!isFour(aRecordBoard3,li,lj,(count+1)%2+1))
					board2[li][lj].h3=998;

				if(aRecordBoard3[li][lj]==0&&isTwo(aRecordBoard3,li,lj,(count+1)%2+1)&&!isThree(aRecordBoard3,li,lj,(count+1)%2+1)&&!isFour(aRecordBoard3,li,lj,(count+1)%2+1))
					board2[li][lj].three=190;

				if(aRecordBoard3[li][lj]==0&&isTwo(aRecordBoard3,li,lj,count%2+1))
					board2[li][lj].a2=94;

				if(aRecordBoard3[li][lj]==0&&isOne(aRecordBoard3,li,lj,(count+1)%2+1)&&!isTwo(aRecordBoard3,li,lj,(count+1)%2+1)&&!isThree(aRecordBoard3,li,lj,(count+1)%2+1)&&!isFour(aRecordBoard3,li,lj,(count+1)%2+1))
					board2[li][lj].two=95;

				board2[li][lj].total=board2[li][lj].five+board2[li][lj].a2+board2[li][lj].four+board2[li][lj].a4+board2[li][lj].three+board2[li][lj].a3+board2[li][lj].two+board2[li][lj].h3+board2[li][lj].ah3;
				board[li][lj].total2=board[li][lj].total-board2[li][lj].total;
				}

				if(board[li][lj].total2){
				lcj=lj+'a';			
				lci=15-li;
				printf("%d%c\n",lci,lcj );
				printf("total:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board[li][lj].total2,board[li][lj].five,board[li][lj].a4,board[li][lj].four,board[li][lj].a3,board[li][lj].h3,board[li][lj].ah3,board[li][lj].three,board[li][lj].a2,board[li][lj].two);
				}
			}

}

void choose2Place(int s[SIZE][SIZE],int i,int j){
	srand(time(NULL));
	for(li=0;li<=14;li++)
			for(lj=0;lj<=14;lj++){
				if(((rand()%2==1)?(board[li][lj].total2>chosen_total):(board[li][lj].total2>=chosen_total))){
					chosen_total=board[li][lj].total2;
					i=li;j=lj;
					lcj=lj+'a';			
				lci=15-li;
				if(chosen_total>0){
				printf("for2:\n");
				printf("%d%c\n",lci,lcj );
				printf("total2:%d five:%d a4:%d four:%d a3:%d h3:%d ah3:%d three:%d a2:%d two:%d\n",board[li][lj].total2,board[li][lj].five,board[li][lj].a4,board[li][lj].four,board[li][lj].a3,board[li][lj].h3,board[li][lj].ah3,board[li][lj].three,board[li][lj].a2,board[li][lj].two);
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
