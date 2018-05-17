#ifndef BAG_HPP
#define BAG_HPP
#include<iostream>
#include<vector>
#include "item.hpp"
#include "equip.hpp"
using std::vector;
using std::string;
class Bag{
private:
    vector<item> It;
    vector<Equip> Eq;
public:
    Bag(){};
    ~Bag(){};
    string openBag();//打开背包，打印背包内容
    friend class item;
    friend class Equip;
    Bag& operator+=(item &i);
    Bag& operator+=(Equip &e);
    Bag& operator-=(item &i);
    Bag& operator-=(Equip &e);
    string showItems();
    string showEquips();
    //item* getItem(int num);//NUll if doesnot exist
    Equip* getEquip(int num);
};
#endif
