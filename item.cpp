#include<iostream>
#include<cstdlib>
#include<ctime>
#include "item.hpp"
#define K1 10
#define K2 20
#define L1 50
using std::cout;
int item::number = 0;
item::item(int pi, int pj){
  srand(time(0));
  id = rand()%5+1;
  switch(id){
    case 1:
    name = "red potion";
    use = "recover hp by 1";
    effHp = 1;
    effDef = 0;
    effPower = 0;
    effMhp = 0;
    cout<<"create red";
    break;
    case 2:
    name = "green potion";
    use = "gain power by 1";
    effHp = 0;
    effDef = 0;
    effPower = 1;
    effMhp = 0;
    cout<<"create green";
    break;
    case 3:
    name = "black potion";
    use = "decrease hp by 1";
    effHp = -1;
    effDef = 0;
    effPower = 0;
    effMhp = 0;
    cout<<"create black";
    break;
    case 4:
    name = "white potion";
    use = "decrese power by 1";
    effHp = 0;
    effDef = 0;
    effPower = -1;
    effMhp = 0;
    cout <<"create white";
    break;
    case 5:
    name = "yellow potion";
    use = "gain MaxHP by 1";
    effHp = 0;
    effDef = 0;
    effPower = 0;
    effMhp = 1;
    cout<<"create yellow";
    break;
  }
  int room = rand()%6+1;
  poi = pi;
  poj = pj;
  while((poi == pi)&&(poj == pj)){
    switch (room) {
      case 1:
      poi = rand()%3 + 1;
      poj = rand()%23 + 1;
      break;
      case 2:
      poi = rand()%3 + 1;
      poj = L1 + rand()%23 + 1;
      break;
      case 3:
      poi = K1 + rand()%3 + 1;
      poj = rand()%23 + 1;
      break;
      case 4:
      poi = K1 + rand()%3 + 1;
      poj = L1 + rand()%23 + 1;
      break;
      case 5:
      poi = K2 + rand()%3 + 1;
      poj = rand()%23 + 1;
      break;
      case 6:
      poi = K2 + rand()%3 + 1;
      poj = L1 + rand()%23 + 1;
      break;
    }
  }
  onMap = 1;
  next = NULL;
  number += 1;
}
string item::getUse(){
  return use;
}
string item::getName(){
  return name;
}
int item::getId(){
  return id;
}
int item::getPoi(){
  return poi;
}
int item::getPoj(){
  return poj;
}
item* item::getNext(){
  return next;
}
void item::setNext(item* i){
  next = i;
}
bool item::operator==(item &i){
  if(i.id == this->id)
    return true;
  else
    return false;
}
int item::getEffectHp(){
  return effHp;
}
int item::getEffectDef(){
  return effDef;
}
int item::getEffectPower(){
  return effPower;
}
int item::geteffectMhp(){
  return effMhp;
}
