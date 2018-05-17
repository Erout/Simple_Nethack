#include<iostream>
#include<vector>
#include<sstream>
#include"bag.hpp"

using std::string;
using std::endl;
using std::stringstream;
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
    out << count<<" Name: "<<it->getName()<<"  Use: "<<it->getUse()<<endl;
    it++;
    count++;
  }
  auto eq = Eq.begin();
  int count2 = 1;
  out<<"Equipments: "<<endl;
  while(eq != Eq.end()){
    out<< count <<" Name: "<<eq->getName();
    if(eq->getWield() == 1){
      out<<"(Wielded)";
    }
    else{
      out <<"(Not Wielded)";
    }
    out<<"   Use: "<<eq->getUse()<<endl;
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
    out<<count<<" Name:"<<it->getName()<<"  Use:"<<it->getUse()<<endl;
    it++;
    count++;
  }
  return out.str();
}
string Bag::showEquips(){
  auto eq = Eq.begin();
  int count2 = 1;
  out<<"Equipments: "<<endl;
  while(eq != Eq.end()){
    out<< count <<" Name: "<<eq->getName();
    /*if(eq->getWield() == 1){
      out<<"(Wielded)";
    }
    else{
      out <<"(Not Wielded)";
    }*/
    out<<"   Use: "<<eq->getUse()<<endl;
    eq++;
    count++;
  }
  return out.str();
}
/*item* getItem(int num){
  auto it = It.begin();
  if(num > It.size())
  return NULL;
  for(int i = 1; i < num; i++){
    it++;
  }
  return it;
}*/
Equip* getEquip(int num){
  auto = Eq.begin();
  if(num > Eq.size())
  return NULL;
  for(int i = 1; i < num;i++){
    it++;
  }
  return it;
}
