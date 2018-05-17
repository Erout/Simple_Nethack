#include<iostream>
#include<sstream>
#include<string>
#include"player.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;
#define up 1
#define down 7
#define left 3
#define right 5
#define here 4
#define LeftUp 0
#define LeftDown 6
#define RightUp 2
#define RightDown 8
#define initHp 10
#define initPower 2
#define initDef 2
player::player(string s){
  name = s;
  currentHp = initHp;
  MaxHp = initHp;
  power = initPower;
  currentDefence = initDef;
  leastDef = initDef;
  poi = 1;
  poj = 1;
}
bool player::addHp(int ad){
  if(currentHp == MaxHp){
    cout<<"Hp full. No need to recover.\n";
    return false;
  }
  else if((currentHp + ad) >= MaxHp){
    currentHp = MaxHp;
    return true;
  }
  else{
    currentHp += ad;
    return true;
  }
}
bool player::subHp(int de){
  currentHp -= de;
  return true;
}
bool player::addDefence(int i,int way){
  if(way == 0){
    leastDef += i;
    currentDefence += i;
  }
  else if(way == 1){
    currentDefence += i;
  }
  return true;
}
bool player::subDefence(int i, int way){
  if(way == 0){
    if(leastDef == 0)
      return false;
    else{
      leastDef -= i;
      currentDefence -= i;
      if(leastDef < 0)
        leastDef = 0;
      return true;
    }
  }
  else if(way == 1){
    currentDefence -= i;
    return true;
  }
}
bool player::subPower(int i){
  if(power == 0)
    return false;
  else{
    power -= i;
    if(power < 0)
      power = 0;
    return true;
  }
}
bool player::addPower(int i){
  power += i;
  return true;
}
void player::move(int dir){
  if(dir == here)
    return;
  else if(dir == up){
    poi -= 1;
  }
  else if(dir == down){
    poi += 1;
  }
  else if(dir == right){
    poj += 1;
  }
  else if(dir == left){
    poj -= 1;
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
int player::getPower(){
  return this->power;
}
int player::getCurrentHp(){
  return this->currentHp;
}
int player::getMaxHp(){
  return this->MaxHp;
}
int player::getDefence(){
  return this->currentDefence;
}
int player::getPoi(){
  return this->poi;
}
int player::getPoj(){
  return this->poj;
}
string player::getName(){
  return this->name;
}
