#include<iostream>
#include<cstdlib>
#include<string>
#include "Map.hpp"
#include "player.hpp"
#include "monster.hpp"
#include "item.hpp"
#include "bag.hpp"
#include "equip.hpp"
using std::cout;
using std::endl;
using std::cin;
using std::string;
void playerdie(player p1){
	cout << string(50,'\n');
	cout << "Fare thee well " <<p1.getName()<< endl;
}
int main(){
  Map map1;
	string p;
	cout << "Please enter your name\n";
	cin >> p;
	player p1(p);
	Bag bag1;
	map1.playerMove(p1.getPoi(),p1.getPoj(),here);
	map1.printMap();//初始化
	char act = '.';
	int dir;
	int statusPlayerMove;
  int EquipNum = 0;
  Equip* headE = new Equip(p1.getPoi(),p1.getPoj());
  EquipNum++;
  Equip* tempE = headE;
  map1.EquipAdd(headE);
  while(act != '0'){
		if(act == 'h')
			dir = left;
		else if(act == 'j')
			dir = down;
		else if(act == 'k')
			dir = up;
		else if(act == 'l')
			dir = right;
		else if(act == '.')
			dir = here;
		else if(act == 'y')
			dir = LeftUp;
		else if(act == 'u'){
			dir = RightUp;
		}
		else if(act == 'b'){
			dir = LeftDown;
		}
		else if(act == 'n'){
			dir = RightDown;
		}
		else if(act == ','){
			dir = here;
			/*tempI = headI;
			while((tempI->getNext() != NULL)&&(tempI != NULL)){
				if(map1.PickItem(p1.getPoi(),p1.getPoj(),tempI) == 1){
					//加到背包里
					bag1 += *tempI;
					//tempI->BePicked();
					cout<<"you pick a item"<<tempI->getName()<<" and add it to the bag"<<endl;
					break;
				}
				tempI = tempI->getNext();
			}*/
			tempE = headE;
			while(tempE->getNext() != NULL){
				if(map1.PickEquip(p1.getPoi(),p1.getPoj(),tempE) == 1){
					bag1 += *tempE;
					cout <<"you pick an equpment: "<<tempE->getName()<< "and add it to"<<endl;
					break;
				}
				tempE = tempE->getNext();
			}
		}
    else{
			cout << "Invalid move"<< endl;
		}
    statusPlayerMove = map1.playerMove(p1.getPoi(),p1.getPoj(),dir);
    if(statusPlayerMove == 1){
      p1.move(dir);
    }
    int EquipRate = rand()%4+1;
		if((EquipRate < 6)&&(EquipNum <= 15)){
			EquipNum++;
			tempE = headE;
			while(tempE->getNext()!=NULL){
				tempE = tempE->getNext();
			}
			tempE->setNext(new Equip(p1.getPoi(),p1.getPoj()));
			tempE = tempE->getNext();
			map1.EquipAdd(tempE);
			cout<<"new eq created  :"<<tempE->getName()<<endl;
		}
    if(p1.getCurrentHp() <= 0){
			playerdie(p1);
			break;
		}
		map1.printMap();
    cout<<bag1.openBag();
    cout <<"Player Name: "<<p1.getName()<<" CurrentHp: "<<p1.getCurrentHp()<<"  MaxHp: "<<p1.getMaxHp()<<"  Power: "<<p1.getPower()<<endl;
    cout <<"player position:("<<p1.getPoi()<<","<<p1.getPoj()<<")"<<endl;
    cin >> act;
    cout << string(50,'\n');
  }
  tempE = headE;
	while(tempE->getNext()!= NULL){
		headE = tempE->getNext();
		delete tempE;
		tempE = headE;
	}
	delete tempE;
	tempE = NULL;
  return 0;
}
