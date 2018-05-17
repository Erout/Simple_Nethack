#ifndef MON_HPP
#define MON_HPP
#include<iostream>
#include "Map.hpp"
#define up 1
#define down 7
#define left 3
#define right 5
#define here 4
#define LeftUp 0
#define LeftDown 6
#define RightUp 2
#define RightDown 8
using std::string;
class Monster{
private:
    int Id;
    string name;
    int Hp;
    int Power;
    int poi;
    int poj;
public:
    Monster(int pi,int pj);//随机
    ~Monster(){};
    void Move(int dir);//change position ,-1 stay
    bool subHp(int a);//if die poi j = -1,disappear in map
    int getPower();
    int getHp();
    //int getStatus();
    int getPoi();
    int getPoj();
    string getName();
    string MonsterInfo();
};
#endif
