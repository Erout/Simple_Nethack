#include<iostream>
#include<cstdlib>
#include<string>
#include "Map.hpp"
#include "monster.hpp"
#include "player.hpp"
#define up 1
#define down 7
#define left 3
#define right 5
#define here 4
#define LeftUp 0
#define LeftDown 6
#define RightUp 2
#define RightDown 8
#define ATTACK 12580
using std::cout;
using std::endl;
using std::cin;
using std::string;
int main(){
  Map map1;
  Monster mon1(1,1);
  int status;
  int a, b;
  cout<<"enter two position"<<endl;
  cin >> b;
  cin >> a;
  while(a != -1){
    //cout<<"monster now position"<,endl;
    //status = map1.MonsterMove(mon1.getPoi(),mon1.getPoj(),a,b);
    status = map1.MonsterMove2(mon1.getPoi(),mon1.getPoj(),a,b);
    if((status > -1)&&(status < 9)){
      mon1.Move(status);
    }
    map1.printMap();
    //map1.printRoad();
    cout<<"enter two position"<<endl;
    cin >> b;
    cin >> a;
  }

  return 0;
}
