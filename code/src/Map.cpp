#include "Map.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include<Windows.h>
#define K1 10
#define K2 20
#define L1 50
#define up 1
#define down 7
#define Leftt 3
#define Rightt 5
#define here 4
#define LefttUp 0
#define LefttDown 6
#define RighttUp 2
#define RighttDown 8
#define seeRange 2
#define ATTACK 12580
#define Yen 666
#define DEBUG 1
using std::cout;
using std::endl;
using namespace std;
Map::Map(){
	srand(time(0));
	len1 = rand()%10 + 25;
	len2 = rand()%10 + 25;
	len3 = rand()%10 + 25;
	len4 = rand()%10 + 25;
	len5 = rand()%10 + 25;
	len6 = rand()%10 + 25;
	wid1 = rand()%2 + 5;
	wid2 = rand()%2 + 6;
	wid3 = rand()%3 + 6;
	wid4 = rand()%5 + 5;
	wid5 = rand()%5 + 5;
	wid6 = rand()%5 + 5;
	randomRoom();
	setRoad();
	//constructRoad();
	Ypoi = K2 + rand()%(wid6-1) + 1;
	Ypoj = L1 + rand()%22 + 1;
	arr[Ypoi][Ypoj] = Yen;
}
void Map::randomRoom(){
 	for(int i = 0;i < size1; i++){
 		for(int j = 0; j < size2; j++){
 			if((i >= 0)&&(i <= wid1)&&(j >= 0)&&(j <= len1)){
 				 if(((i == 0)||(i == wid1)) && (j > 0) &&(j < len1)){
					 arr[i][j] = 1;
					 road[i][j] = 0;
				 }
 				 else if(((j == 0)||(j == len1)) && (i > 0) &&(i < wid1)){
					arr[i][j] = 1;
					road[i][j] = 0;
				 }
 				 else if(((j == 0)||(j == len1))&&((i == 0)||(i == wid1))){
					 arr[i][j] = 0;
					 road[i][j] = 0;
				 }
 				 else{
 				 	arr[i][j] = 2;
 				 	road[i][j] = 1;
 				 }
 			}//room1
 			else if((i >= 0)&&(i <= wid2)&&(j >= L1)&&(j <= L1+len2)){
 				if(((i == 0)||(i == wid2))&&(j > L1)&&(j < L1+len2)){
 					arr[i][j] = 1;
 					road[i][j] = 0;
 				}
 				else if(((j == L1)||(j == L1+len2))&&(i > 0)&&(i < wid2)){
					arr[i][j] = 1;
					road[i][j] = 0;
				}
 				else if(((j == L1)||(j == L1+len2))&&((i == 0)||(i == wid2))){
					arr[i][j] = 0;
					road[i][j] = 0;
				}
 				else{
						road[i][j] = 1;
	 					arr[i][j] = 2;
				}
 			}//room2
 			else if((i >= K1)&&(i <= K1+wid3)&&(j >= 0)&&(j <= len3)){
 				if(((i == K1)||(i == K1+wid3))&&(j > 0)&&(j < len3)){
			 			road[i][j] = 0;
	 					arr[i][j] = 1;
				}
 				else if(((j == 0)||(j == len3))&&(i >K1)&&(i < K1+wid3)){
					arr[i][j] = 1;
					road[i][j] = 0;
				}
 				else if(((j == 0)||(j == len3))&&((i == K1)||(i == K1+wid3))){
					arr[i][j] = 0;
					road[i][j] = 0;
				}	//去除四个角
 				else{
					arr[i][j] = 2;
					road[i][j] = 1;
				}
 			}//room3
 			else if((i >= K1)&&(i <= K1+wid3)&&(j >= L1)&&(j <= L1+len4)){
 				if(((i == K1)||(i == K1+wid3))&&(j > L1)&&(j < L1+len4)){
						arr[i][j] = 1;
						road[i][j] = 0;
				}
 				else if(((j == L1)||(j == L1+len4))&&(i > K1)&&(i < K1+wid3)){
					arr[i][j] = 1;
					road[i][j] = 0;
				}
 				else if(((j == L1)||(j == L1+len4))&&((i == K1)||(i == K1+wid3))){
					arr[i][j] =0;
					road[i][j] = 0;
				}
 				else{
					arr[i][j] = 2;
					road[i][j] = 1;
				}
 			}//room4
 			else if((i >= K2)&&(i <= K2+wid5)&&(j >=0)&&(j <= len5)){
 				if(((i == K2)||(i == K2+wid5))&&(j > 0)&&(j < len5)){
					arr[i][j] = 1;
					road[i][j] = 0;
				}
 				else if(((j == 0)||(j == len5))&&(i > K2)&&(i < K2+wid5)){
					arr[i][j] = 1;
					road[i][j] = 0;
				}
 				else if(((j == 0)||(j == len5))&&((i == K2)||(i == K2+wid5))){
					arr[i][j] = 0;
					road[i][j] = 0;
				}
 				else{
					arr[i][j] = 2;
					road[i][j] = 1;
				}
 			}//room5
 			else if((i >= K2)&&(i <= K2+wid6)&&(j >=L1)&&(j <= L1+len6)){
 				if(((i == K2)||(i == K2+wid6))&&(j > L1)&&(j <L1+len6)){
					arr[i][j] = 1;
					road[i][j] = 0;
				}
 				else if(((j == L1)||(j == L1+len6))&&(i > K2)&&(i < K2+wid6)){
					arr[i][j] = 1;
					road[i][j] = 0;
				}
 				else if(((j == L1)||(j == L1+len6))&&((i == K2)||(i == K2+wid6))){
					arr[i][j] = 0;
					road[i][j] = 0;
				}
 				else{
					arr[i][j] = 2;
					road[i][j] = 1;
				}
 			}//room6
			else{
				arr[i][j] = 0;
				road[i][j] = 0;
			}
				view[i][j] = 0;
				IorE[i][j] = 0;
 		}
 	}
}

void Map::constructRoad(){
	int openw = rand()%3+1;
	int openl = rand()%25+1;
	randomRoad(openw,len1+1,Rightt,down);
	randomRoad(wid1+1,openl,down,Leftt);
	openw = rand()%3+1;
	openl = rand()%25+1;
	//randomRoad(openw,L1-1,Leftt,LefttDown);
	randomRoad(wid2+1,L1+openl,down,RighttDown);
	openw = rand()%3+1;
	openl = rand()%25+1;
	randomRoad(K1-1,openl,up,LefttUp);
	randomRoad(K1+wid3+1,openl,down,LefttDown);
	//randomRoad(K1+openw,len3+1,Rightt,RighttUp);
	openw = rand()%3+1;
	openl = rand()%25+1;
	randomRoad(K1-1,L1+openl,up,LefttUp);
	randomRoad(K1+wid4+1,L1+openl,down,down);
	randomRoad(K1+openw,L1-1,Leftt,LefttUp);
	openw = rand()%3+1;
	openl = rand()%25+1;
	randomRoad(K2-1,openl,up,LefttUp);
	randomRoad(K2+openw,len5+1,Rightt,Rightt);
}

void Map::setRoad(){
	srand(time(0));
	int k = 0;
	int o1 = rand()%4 + 1;
	for(k= len1; k <= L1; k++){
		arr[o1][k] = 3;
		road[o1][k] = 2;
	}
	int o2 = K1+rand()%3 + 1;
	for(k = len3; k <= L1; k++){
		arr[o2][k] = 3;
		road[o2][k] = 2;
	}
	int o3 = K2 + rand()%3 + 1;
	for(k = len5; k <= L1; k++){
		arr[o3][k] = 3;
		road[o3][k] = 2;
	}
	int h1 = 23;
	for(k = wid1; k <= K1; k++){
	 	arr[k][h1] = 3;
	 	road[k][h1] = 2;
	}
	int h2 = 73;
	for(k = wid2; k <= K1; k++){
		arr[k][h2] = 3;
		road[k][h2] = 2;
	}
	int h3 = 22;
	for(k = K1+wid3; k <= K2; k++){
		arr[k][h3] = 3;
		road[k][h3] = 2;
	}
}
void Map::randomRoad(int poi,int poj,int ableDir1, int ableDir2){
	int dir;
	int toi = poi;
	int toj = poj;
	if(rand()%2){
		dir = ableDir1;
	}
	else{
		dir = ableDir2;
	}
	while((arr[toi][toj] != 1)&&(toi >=0)&&(toi < size1)&&(toj >= 0)&&(toj < size2)){
		if(arr[toi][toj] == 0){
			arr[toi][toj] = 3;
			road[toi][toj] = 2;
			poi = toi;
			poj = toj;
		}
		if(rand()%2){
			dir = ableDir1;
		}
		else{
			dir = ableDir2;
		}
			if(dir == up){
				toi = poi -1;
				toj = poj;
			}
			else if(dir == down){
				toi = poi + 1;
				toj = poj;
			}
			else if(dir == Leftt){
				toi = poi;
				toj = poj - 1;
			}
			else if(dir == Rightt){
				toi = poi;
				toj = poj + 1;
			}
			else if(dir == LefttUp){
				toi = poi - 1;
				toj = poj - 1;
			}
			else if(dir == LefttDown){
				toi = poi + 1;
				toj = poj - 1;
			}
			else if(dir == RighttUp){
				toi = poi - 1;
				toj = poj + 1;
			}
			else if(dir == RighttDown){
				toi = poi + 1;
				toj = poj + 1;
			}
	}
	if(arr[toi][toj] == 1){
	 arr[toi][toj] = 3;
	 road[toi][toj] = 2;
	}
}

void Map::printMap(){
	int a,b;
	for(int i = 0; i < size1; i++){
		for(int j = 0; j < size2; j++){
			if(view[i][j] == 0){
				cout<<" ";
				continue;
			}
			a = arr[i][j];
			b = IorE[i][j];
			if(a == Yen){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
				cout<<"Y";
			}
			else if((b == 1)&&(a == 2)){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
				cout<<"I";
			}
			else if((b == 2)&&(a == 2)){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
				cout<<"E";
			}
			else{
				switch(a){
					case 0:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
						cout<<" ";
					break;
					case 1:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
						cout<<"X";
					break;
					case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
						cout<<".";
					break;
					case 3:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
						cout<<"#";
					break;
					case 4:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED| FOREGROUND_BLUE);
						cout<<"M";
					break;
					case 7:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);
						cout<<"@";
					break;
				}
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY);
		cout<<endl;
	}
}

void Map::addview(int i,int j){
	for(int k = i - seeRange; k <= i + seeRange; k++){
		for(int r = j - seeRange; r <= j + seeRange; r++){
			if((k >= 0)&&(k < size1)&&(j >= 0)&&(j < size2)){
				if(view[k][r] == 0)
					view[k][r] = 1;
			}
		}
	}
}
int Map::playerMove(int poi,int poj,int dir){
	int toi,toj;
	if(dir == here){
		arr[poi][poj] = 7;//Player
		return true;
	}
	else if(dir == up){
		toi = poi - 1;
		toj = poj;
	}
	else if(dir == down){
		toi = poi +1;
		toj = poj;
	}
	else if(dir == Rightt){
		toi = poi;
		toj = poj + 1;
	}
	else if(dir == Leftt){
		toi = poi;
		toj = poj - 1;
	}
	else if(dir == LefttUp){
		toi = poi - 1;
		toj = poj - 1;
	}
	else if(dir == LefttDown){
		toi = poi + 1;
		toj = poj - 1;
	}
	else if(dir == RighttUp){
		toi = poi - 1;
		toj = poj + 1;
	}
	else if(dir == RighttDown){
		toi = poi + 1;
		toj = poj + 1;
	}
	if((arr[toi][toj] == 2)||(arr[toi][toj] == 3)||(arr[toi][toj] == Yen)){
			arr[toi][toj] = 7;
			if(road[poi][poj] == 1)
				arr[poi][poj] = 2;
			else if(road[poi][poj] == 2)
				arr[poi][poj] = 3;
			return 1;
	}
	else if(arr[toi][toj] == 4)
		return ATTACK;
	else{
		return 0;
	}
}

bool Map::IsInsideRoom(int poi, int poj){
	if((poi > 0)&&(poi < wid1)&&(poj > 0)&&(poj < len1))
		return true;
	else if((poi > K1)&&(poi < wid3)&&(poj > 0)&&(poj < len3))
		return true;
	else if((poi > K2)&&(poi < wid5)&&(poj > 0)&&(poj <len5))
		return true;
	else if((poi > 0)&&(poi < wid2)&&(poj > L1)&&(poj < L1+len2))
		return true;
	else if((poi > K1)&&(poi < K1+wid4)&&(poj >L1)&&(poj<L1+len4))
		return true;
	else if((poi > K2)&&(poi < K2+wid6)&&(poj > L1)&&(poj < L1+len6))
		return true;
	else
		return false;
}

int Map::MonsterMove(const int Mpoi,const int Mpoj,int Ppoi, int Ppoj){
	int dir = 0;
	int Mindistance = 1000000;
	int distance,todir;
	int m,n;
	int toi,toj;
	int temp = 0;
	for(m = Mpoi -1; m <= Mpoi + 1; m++){
		for(n = Mpoj -1; n <= Mpoj+1;n++){
			if((arr[m][n] == 2)||(arr[m][n] == 3)||(arr[m][n] == 7)){
				distance = (Ppoi - m)*(Ppoi - m)+(Ppoj - n)*(Ppoj - n);
				if(distance < Mindistance){
					Mindistance = distance;
					todir = dir;
					toi = m;
					toj = n;
				}
			}
			dir++;
		}
	}
	if((arr[toi][toj] == 2)||(arr[toi][toj] == 3)){
		arr[toi][toj] = 4;
		if(road[Mpoi][Mpoj] == 2){
			arr[Mpoi][Mpoj] = 3;
		}
		else if(road[Mpoi][Mpoj] == 1){
			arr[Mpoi][Mpoj] = 2;
		}
		return todir;
	}
	else if(arr[toi][toj] == 7){
		return ATTACK;
	}
	else{
		cout<<"sleep"<<endl;
	}
}//计算距离玩家最近的点，移动并且返回移动方向,不移动(wall item equipment void)则返回-1

bool Map::MonsterDie(int Mpoi,int Mpoj,int hp){
	if(hp <= 0){
		if(road[Mpoi][Mpoj] == 1){
			arr[Mpoi][Mpoj] = 2;
		}
		else if(road[Mpoi][Mpoj] == 2){
			arr[Mpoi][Mpoj] = 3;
		}
		return true;
	}
	else
		return false;
}

void Map::printRoad(){
	for(int i = 0; i < size1; i++){
		for(int j = 0; j < size2; j++){
			std::cout<<road[i][j];
		}
		std::cout<<endl;
	}
}
void Map::printMapforDebug(){
	for(int i = 0;i < size1; i++){
		for(int j = 0; j < size2 ; j++){
			std::cout <<arr[i][j];
		}
		std::cout<<endl;
	}
}

bool Map::ItemAdd(item *i){
	int poi = i->getPoi();
	int poj = i->getPoj();
	if((IorE[poi][poj] == 0)&&(arr[poi][poj] == 2)){
		IorE[poi][poj] = 1;
		return true;
	}
	else {
		//cout<<"Not in room"<<endl;
		return false;
	}
}
bool Map::PickItem(int poi,int poj,item *i){
	 if((IorE[poi][poj] == 1)){
		 if((i->getPoi()==poi)&&(i->getPoj() == poj)){
			 IorE[poi][poj] = 0;
			 return true;
		 }
		 return false;
	 }
	 else{
		 //cout<<"pick item failed"<<endl;
		 return false;
	 }
}
bool Map::EquipAdd(Equip *e){
	int poi = e->getPoi();
	int poj = e->getPoj();
	if((IorE[poi][poj] == 0)&&(arr[poi][poj] == 2)){
		IorE[poi][poj] = 2;
		return true;
	}
	else{
		//cout<<"No in room"<<endl;
		return false;
	}
}
bool Map::PickEquip(int poi,int poj, Equip *e){
	if((IorE[poi][poj] == 2)){
		if((e->getPoi() == poi)&&(e->getPoj()==poj)){
			IorE[poi][poj] = 0;
			return true;
		}
		return false;
	}
	else {
		//cout<<"pick equipment faied"<<endl;
		return false;
	}
}

bool Map::getYen(int poi, int poj){
	if((poi == Ypoi)&&(poj == Ypoj)){
		return true;
	}
	return false;
}
