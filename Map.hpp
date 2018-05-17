#ifndef MAP_HPP
#define MAP_HPP
#include<iostream>
#include "monster.hpp"
#include "item.hpp"
#include "equip.hpp"
#define size1 30
#define size2 111
class Map{
private:
    int arr[size1][size2];
    int view[size1][size2];//0:not seeing
    int road[size1][size2];//0:void or wall 1:inside room 2:outside room
    int IorE[size1][size2];//0:void 1:item 2:equip 3;both
    int Ypoi;//if==-1,not here
    int Ypoj;//the position of Yendor 项链
    int len1;
    int len2;
    int len3;
    int len4;
    int len5;
    int len6;
    int wid1;
    int wid2;
    int wid3;
    int wid4;
    int wid5;
    int wid6;
public:
    Map();
    ~Map(){

    }
    void printMapforDebug();
    void printRoad();
    void printMap();
    void randomRoom();
    void setRoad();
    void constructRoad();
    void randomRoad(int poi, int poj,int unableDir1,int unableDir2);
    void addview(int i,int j);//根据人物位置，增加视野范围
    int playerMove(int poi,int poj,int dir);
    bool IsInsideRoom(int poi, int poj);
    int MonsterMove(const int Mpoi,const int Mpoj,int Ppoi,int Ppoj);//0-9for direction
    int MonsterMove2(const int Mpoi, const int mpoj, int Ppoi, int Ppoj);
    bool MonsterDie(int Mpoi,int Mpoj,int hp);
    bool EquipAdd(Equip* e);
    bool ItemAdd(item* i);
    bool PickItem(int poi, int poj,item* i);
    bool PickEquip(int poi,int poj,Equip* e);
    //void ThrowItem(int poi,int poj);
    /*void ThrowEquip(int poi,int poj);*/
    friend class item;
};
#endif
