#include<iostream>
#include<cstdlib>
#include<ctime>
#include "equip.hpp"
#define K1 10
#define K2 20
#define L1 50
using std::cout;
using std::string;
Equip::Equip(int pi, int pj){
  srand(time(0));
  int seed = rand()%200;
  srand(seed);
  id = rand()%7+1;
  switch(id){
    case 1:
    name = "long sword";
    use = "cool sword which can badly hur enemy";
    harm = 3;
    defence = 0;
    break;
    case 2:
    name = "arrow";
    use = "not so cool,but can still hurt enemy";
    harm = 2;
    defence = 0;
    break;
    case 3:
    name = "chest";
    use = "protect you ,reduce harm from monster";
    harm = 0;
    defence = 2;
    break;
    case 4:
    name = "dart";
    use = "Brilliant dart! Looks excellent! It must be very expensive!";
    harm = 1;
    defence = 0;
    break;
    case 5:
    name = "chi";
    use = "It seems that it came form ancient China";
    harm = 2;
    defence = 2;
    break;
    case 6:
    name = "camera";
    use = "Wow, a mordern equipment!";
    harm = 3;
    defence = 0;
    break;
    case 7:
    name = "Discrete Mathematics";
    use = "???";
    harm = 5;
    defence = 2;
    break;
  }
  int room = rand()%6+1;
  poi = pi;
  poj = pj;
  //wield = 0;
  next = NULL;
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
}

int Equip::getId(){
  return id;
}
string Equip::getUse(){
  return use;
}
string Equip::getName(){
  return name;
}
int Equip::getPoi(){
  return poi;
}
int Equip::getPoj(){
  return poj;
}
bool Equip::operator==(Equip &e){
  if(this->id == e.id){
    return true;
  }
  else{
    return false;
  }
}
Equip* Equip::getNext(){
  return next;
}
void Equip::setNext(Equip *e){
  next = e;
}
int Equip::getharm(){
  return harm;
}
int Equip::getDefence(){
  return defence;
}
