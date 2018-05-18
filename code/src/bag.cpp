#include<iostream>
#include<vector>
#include<sstream>
#include<iomanip>
#include"bag.hpp"

using std::string;
using std::endl;
using std::stringstream;
using std::setw;
using std::setiosflags;

Bag& Bag::operator+=(item &i){
  It.push_back(i);
  return *this;
}
Bag& Bag::operator-=(item &i){
  auto it = It.begin();
  while(!(*it == i)){
    it++;
  }
  It.erase(it);
  return *this;
}

Bag& Bag::operator+=(Equip &e){
  Eq.push_back(e);
  return *this;
}
Bag& Bag::operator-=(Equip &e){
  auto eq = Eq.begin();
  while(!(*eq == e)){
    eq++;
  }
  Eq.erase(eq);
  return *this;
}

string Bag::openBag(){
  auto it = It.begin();
  stringstream out;
  int count = 1;
  out << "Items: "<<endl;
  while(it != It.end()){
    out<<setiosflags(std::ios::left) <<count<<setw(4)<<" Id:"<<it->getId()<<setw(6)<<" Name:"<<setw(25)<<it->getName()<<setw(4)<<"Use:"<<setw(35)<<it->getUse()<<endl;
    it++;
    count++;
  }
  auto eq = Eq.begin();
  int count2 = 1;
  out<<"Equipments:"<<endl;
  while(eq != Eq.end()){
    out<<setiosflags(std::ios::left) << count <<setw(4)<<" Id:"<<eq->getId()<<setw(6)<<" Name:"<<setw(25)<<eq->getName();
    out<<setiosflags(std::ios::left)<<setw(4)<<"Use:"<<setw(35)<<eq->getUse()<<endl;
    eq++;
    count++;
  }
  return out.str();
}
string Bag::showItems(){
  auto it = It.begin();
  stringstream out;
  int count = 1;
  out << "Items:"<<endl;
  while(it != It.end()){
    out<<setiosflags(std::ios::left) <<count<<setw(4)<<" Id:"<<it->getId()<<setw(6)<<" Name:"<<setw(25)<<it->getName()<<setw(4)<<"Use:"<<setw(30)<<it->getUse()<<endl;
    it++;
    count++;
  }
  return out.str();
}
string Bag::showEquips(){
  auto eq = Eq.begin();
  int count = 1;
  stringstream out;
  out<<"Equipments: "<<endl;
  while(eq != Eq.end()){
    out<<setiosflags(std::ios::left) << count <<setw(4)<<" Id:"<<eq->getId()<<setw(6)<<" Name:"<<setw(25)<<eq->getName();
    out<<setiosflags(std::ios::left)<<setw(4)<<"Use:"<<setw(35)<<eq->getUse()<<endl;
    eq++;
    count++;
  }
  return out.str();
}

bool Bag::getEquip(int id){
  auto eq= Eq.begin();
  while(eq != Eq.end()){
    if(eq->getId() == id){
      return true;
    }
    eq++;
  }
  return false;
}
bool Bag::getItem(int id){
  auto it = It.begin();
  while(it != It.end()){
    if(it->getId() == id){
      return true;
    }
    it++;
  }
  return false;
}
