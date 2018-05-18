#ifndef ITEM_HPP
#define ITEM_HPP
#include<iostream>
using std::string;
class item{
private:
    int id;
    string name;
    string use;
    string result;
    int poi;
    int poj;
    int effHp;
    int effMhp;
    int effDef;
    int effPower;
    int onMap;
    item* next;
    static int number;
public:
    item(int pi,int pj);
    ~item(){};
    string getUse();
    string getName();
    string getResult();
    int getId();
    int getPoi();
    int getPoj();
    void BePicked();
    item* getNext();
    void setNext(item* i);
    bool operator==(item &i);
    int getEffectDef();
    int getEffectHp();
    int getEffectPower();
    int geteffectMhp();
};

#endif
