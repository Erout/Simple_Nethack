#ifndef EQUIP_HPP
#define EQUIP_HPP
#include<iostream>
using std::string;
class Equip{
private:
    int id;
    int harm;
    int defence;
    string name;
    string use;
    int poi;
    int poj;
    int wield;
    Equip *next;
public:
    Equip(int pi, int pj);// 随机生成
    ~Equip(){};
    int getId();
    string getUse();
    string getName();
    int getPoi();
    int getPoj();
    int getWield();
    void setWield(int w);
    Equip* getNext();
    void setNext(Equip *e);
    bool operator==(Equip &e);
    int getharm();
    int getDefence();
};
#endif
