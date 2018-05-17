#ifndef PLAYER_HPP
#define PLAYER_HPP
#include<iostream>
using std::string;
class player{
private:
    string name;
    int currentHp;
    int MaxHp;
    int power;
    int currentDefence;//may de|increase by equipment,potion
    int leastDef;//changed only by potion
    int poi;
    int poj;
public:
    player(string s = "Bugger");
    ~player(){};
    bool addHp(int ad);//full hp return false
    bool subHp(int de);//Hp==0,die
    bool addDefence(int i,int way);//drink potion or dress up equipment
    //0 for potion, 1 for equipment
    bool subDefence(int i, int way);//drink potion or take down equipmentf
    bool subPower(int i);
    bool addPower(int i);
    void move(int dir);
    int getPower();
    int getCurrentHp();
    int getMaxHp();
    int getDefence();
    int getPoi();
    int getPoj();
    string getName();
};
#endif
