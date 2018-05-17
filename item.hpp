#ifndef ITEM_HPP
#define ITEM_HPP
#include<iostream>
using std::string;
class item{
private:
    int id;
    string name;
    string use;
    int poi;
    int poj;
    int onMap;
    item* next;
    static int number;
public:
    item(int pi,int pj);
    ~item(){};
    string getUse();
    string getName();
    int getId();
    int getPoi();
    int getPoj();
    void BePicked();
    item* getNext();
    void setNext(item* i);
    bool operator==(item &i);
};

#endif
