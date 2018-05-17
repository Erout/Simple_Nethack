#include<iostream>
#include <ctime>
#include <cstdlib>
#define K1 20
#define K2 40
#define L1 50
#define up 0
#define down 1
#define left 2
#define right 3
#define size1 61
#define size2 101
using std::cout;
using std::endl;
int arr[size1][size2];
void constructRoad(int poi, int poj);
void printMap();
int main(){
  //int arr[size1][size2];
  srand(time(0));
  int len1 = rand()%10 + 25;
  int len2 = rand()%10 + 25;
  int len3 = rand()%10 + 25;
  int len4 = rand()%10 + 25;
  int len5 = rand()%10 + 25;
  int len6 = rand()%10 + 25;
  int wid1 = rand()%5 + 10;
  int wid2 = rand()%5 + 10;
  int wid3 = rand()%5 + 10;
  int wid4 = rand()%5 + 10;
  int wid5 = rand()%5 + 10;
  int wid6 = rand()%5 + 10;
  //for loop to constructRoom
  for(int i = 0;i < size1; i++){
    for(int j = 0; j < size2; j++){
      if((i >= 0)&&(i <= wid1)&&(j >= 0)&&(j <= len1)){
         if(((i == 0)||(i == wid1)) && (j > 0) &&(j < len1))
          arr[i][j] = 1;
         else if(((j == 0)||(j == len1)) && (i > 0) &&(i < wid1))
          arr[i][j] = 1;
         else if(((j == 0)||(j == len1))&&((i == 0)||(i == wid1)))
          arr[i][j] = 0;
         else
          arr[i][j] = 2;
      }//room1
      else if((i >= 0)&&(i <= wid2)&&(j >= L1)&&(j <= L1+len2)){
        if(((i == 0)||(i == wid2))&&(j > L1)&&(j < L1+len2))
          arr[i][j] = 1;
        else if(((j == L1)||(j == L1+len2))&&(i > 0)&&(i < wid2))
          arr[i][j] = 1;
        else if(((j == L1)||(j == L1+len2))&&((i == 0)||(i == wid2)))
          arr[i][j] = 0;
        else
          arr[i][j] = 2;
      }//room2
      else if((i >= K1)&&(i <= K1+wid3)&&(j >= 0)&&(j <= len3)){
        if(((i == K1)||(i == K1+wid3))&&(j > 0)&&(j < len3))
          arr[i][j] = 1;
        else if(((j == 0)||(j == len3))&&(i >K1)&&(i < K1+wid3))
          arr[i][j] = 1;
        else if(((j == 0)||(j == len3))&&((i == K1)||(i == K1+wid3)))
          arr[i][j] = 0;//去除四个角
        else
          arr[i][j] = 2;
      }//room3
      else if((i >= K1)&&(i <= K1+wid3)&&(j >= L1)&&(j <= L1+len4)){
        if(((i == K1)||(i == K1+wid3))&&(j > L1)&&(j < L1+len4))
          arr[i][j] = 1;
        else if(((j == L1)||(j == L1+len4))&&(i > K1)&&(i < K1+wid3))
          arr[i][j] = 1;
        else if(((j == L1)||(j == L1+len4))&&((i == K1)||(i == K1+wid3)))
          arr[i][j] =0;
        else
          arr[i][j] = 2;
      }//room4
      else if((i >= K2)&&(i <= K2+wid5)&&(j >=0)&&(j <= len5)){
        if(((i == K2)||(i == K2+wid5))&&(j > 0)&&(j < len5))
          arr[i][j] = 1;
        else if(((j == 0)||(j == len5))&&(i > K2)&&(i < K2+wid5))
          arr[i][j] = 1;
        else if(((j == 0)||(j == len5))&&((i == K2)||(i == K2+wid5)))
          arr[i][j] = 0;
        else
          arr[i][j] = 2;
      }//room5
      else if((i >= K2)&&(i <= K2+wid6)&&(j >=L1)&&(j <= L1+len6)){
        if(((i == K2)||(i == K2+wid6))&&(j > L1)&&(j <L1+len6))
          arr[i][j] = 1;
        else if(((j == L1)||(j == L1+len6))&&(i > K2)&&(i < K2+wid6))
          arr[i][j] = 1;
        else if(((j == L1)||(j == L1+len6))&&((i == K2)||(i == K2+wid6)))
          arr[i][j] = 0;
        else
          arr[i][j] = 2;
      }//room6
      else
        arr[i][j] = 0;
    }
  }
    //construct a road from room1
    int dir = rand()%4;
  	while((dir == up)||(dir == left))
  		dir = rand()%4;
  	int open;
  	if(dir == right){
  		open = rand()%(wid1-1)+1;
  		arr[open][len1] = 2;
  		constructRoad(open,len1+1);
  	}
  	else if(dir == down){
  		open = rand()%(len1	-1)+1;
  		arr[wid1][open] = 2;
  		constructRoad(wid1+1,open);
  	}
    printMap();
    return 0;
}

void constructRoad(int poi,int poj){
	int dir = rand()%4;
	int toi,toj;
  arr[poi][poj] = 3;
	while(arr[poi][poj] != 1){
		if(dir == up){
			toi = poi - 1;
			toj = poj;
			if((toi >= 0)&&(arr[toi][toj] == 0)){
				arr[toi][toj] = 3;
				poi = toi;
				poj = toj;
			}
			else if((toi >= 0)&&(arr[toi][toj] == 1)){
				poi = toi;
				poj = toj;
				break;
			}
		}
		else if(dir == down){
			toi = poi +1;
			toj = poj;
			if((toi <= 60)&&(arr[toi][toj] == 0)){
				arr[toi][toj] = 3;
				poi = toi;
				poj = toj;
			}
			else if((toi <= 60)&&(arr[toi][toj] == 1)){
				poi = toi;
				poj = toj;
				break;
			}
		}
		else if(dir == right){
			toi = poi;
			toj = poj +1;
			if((toj <= 100) &&(arr[toi][toj] == 0)){
				arr[toi][toj] = 3;
				poi = toi;
				poj = toj;
			}
			else if((toj <= 100)&&(arr[toi][toj] == 1)){
				poi = toi;
				poj = toj;
				break;
			}
		}
		else if(dir == left){
			toi = poi;
			toj = poj -1;
			if((toj >= 0)&&(arr[toi][toj] == 0)){
				arr[toi][toj] = 3;
				poi = toi;
				poj = toj;
			}
			else if((toj >= 0)&&(arr[toi][toj] ==1)){
				poi = toi;
				poj = toj;
				break;
			}
		}
		dir = rand() % 4;
	}
	arr[poi][poj] = 2;
}

void printMap(){
	int a;
	for(int i = 0; i < size1; i++){
		for(int j = 0; j < size2; j++){
			a = arr[i][j];
			switch(a){
				case 0:cout<<" ";
				break;
				case 1:cout<<"X";
				break;
				case 2:cout<<".";
				break;
				case 3:cout<<"#";
				break;
				case 4:cout<<"M";
				break;
				case 5:cout<<"E";
				break;
				case 6:cout<<"I";
				break;
				case 7:cout<<"@";
				break;
			}
		}
		cout<<endl;
	}
}
