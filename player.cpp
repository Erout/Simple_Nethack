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
#define Leftt 3
#define Rightt 5
#define here 4
#define LefttUp 0
#define LefttDown 6
#define RighttUp 2
#define RighttDown 8
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
bool player::changeHp(int c){
  if(c > 0){
    if(currentHp == MaxHp){
      cout<<"Hp full. No need to recover.\n";
      return false;
    }
    else if((currentHp + c) >= MaxHp){
      currentHp = MaxHp;
      return true;
    }
    else{
      currentHp += c;
      return true;
    }
  }
  else if(c < 0){
    currentHp += c;
    return true;
  }
}
/*bool player::addDefence(int i,int way){
  if(i <= 0)
  return false;
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
  if(i >= 0)
  return false;
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
}*/
bool player::changeDefence(int i,int way){
  if(i > 0){
    if(way == 0){
      leastDef += i;
      currentDefence += i;
    }
    else if(way == 1){
      currentDefence += i;
    }
    return true;
  }
  else if(i < 0){
    if(way == 0){
      if(leastDef == 0)
        return false;
      else{
        leastDef += i;
        currentDefence += i;
        if(leastDef < 0)
          leastDef = 0;
        return true;
      }
    }
    else if(way == 1){
      currentDefence += i;
      return true;
    }
  }
  else
  return false;
}
/*
bool player::subPower(int i){
  if(i >= 0)
  return false;
  if(power == 0)
    return false;
  else{
    power += i;
    if(power < 0)
      power = 0;
    return true;
  }
}
bool player::addPower(int i){
  if(i <= 0)
  return false;
  power += i;
  return true;
}*/
bool player::changePower(int i){
  if(i > 0){
    power += i;
    return true;
  }
  else if(i < 0){
    if(power == 0)
      return false;
    else{
      power += i;
      if(power < 0)
        power = 0;
      return true;
    }
  }
  else
    return false;
}
bool player::addMhp(int i){
  if(i <= 0)
  return false;
  MaxHp += 1;
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
  else if(dir == Rightt){
    poj += 1;
  }
  else if(dir == Leftt){
    poj -= 1;
  }
  else if(dir == LefttUp){
    poi -= 1;
    poj -= 1;
  }
  else if(dir == LefttDown){
    poi += 1;
    poj -= 1;
  }
  else if(dir == RighttUp){
    poi -= 1;
    poj += 1;
  }
  else if(dir == RighttDown){
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
