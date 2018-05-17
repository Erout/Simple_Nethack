#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include "monster.hpp"
#define K1 15
#define K2 35
#define L1 50
using namespace std;
Monster::Monster(int pi,int pj){
  srand(time(0));
  Id = rand()%4 + 1;
  if(Id == 1){
    name = "Bat";
    Hp = 3;
    Power = 3;
  }
  else if(Id == 2){
    name = "Bug";
    Hp = 2;
    Power = 2;
  }
  else if(Id == 3){
    name = "Rat";
    Hp = 3;
    Power = 1;
  }
  else if(Id == 4){
    name = "Gnome";
    Hp = 5;
    Power = 4;
  }
  int room = rand()%6+1;
  poi = pi;
  poj = pj;
  while((poi == pi)&&(poj == pj)){
    switch (room) {
      case 1:
      poi = rand()%4 + 1;
      poj = rand()%23 + 1;
      break;
      case 2:
      poi = rand()%4 + 1;
      poj = L1 + rand()%23 + 1;
      break;
      case 3:
      poi = K1 + rand()%4 + 1;
      poj = rand()%23 + 1;
      break;
      case 4:
      poi = K1 + rand()%4 + 1;
      poj = L1 + rand()%23 + 1;
      break;
      case 5:
      poi = K2 + rand()%4 + 1;
      poj = rand()%23 + 1;
      break;
      case 6:
      poi = K2 + rand()%4 + 1;
      poj = L1 + rand()%23 + 1;
      break;
    }
  }
}
void Monster::Move(int dir){
  if(dir == -1){
    return;
  }
  else if(dir == up){
    poi -= 1;
  }
  else if(dir == down){
    poi += 1;
  }
  else if(dir == left){
    poj -= 1;
  }
  else if(dir == right){
    poj += 1;
  }
  else if(dir == LeftUp){
    poi -= 1;
    poj -= 1;
  }
  else if(dir == LeftDown){
    poi += 1;
    poj -= 1;
  }
  else if(dir == RightUp){
    poi -= 1;
    poj += 1;
  }
  else if(dir == RightDown){
    poi += 1;
    poj += 1;
  }
}
int Monster::getPower(){
  return this->Power;
}
int Monster::getHp(){
  return this->Hp;
}
int Monster::getPoi(){
  return this->poi;
}
int Monster::getPoj(){
  return this->poj;
}
string Monster::MonsterInfo(){
  stringstream out;
  out << "Monster:" << name << "    "<<"Hp:"<<Hp <<"     "<<"Power"<<Power<<endl;
  return out.str();
}
bool Monster::subHp(int a){
  Hp -= a;
  return true;
}
string Monster::getName(){
  return name;
}
