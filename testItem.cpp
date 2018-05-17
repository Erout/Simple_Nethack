#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Map.hpp"
#include"player.hpp"
#include"item.hpp"
#include"bag.hpp"
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
  map1.printMap();
  char act = '.';
	int dir;
  int statusPlayerMove;
  int itemNum = 0;
	item* headI = new item(p1.getPoi(),p1.getPoj());
	itemNum++;
	item* tempI = headI;
	map1.ItemAdd(headI);
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
			tempI = headI;
			while((tempI->getNext() != NULL)&&(tempI != NULL)){
				if(map1.PickItem(p1.getPoi(),p1.getPoj(),tempI) == 1){
					//加到背包里
					bag1 += *tempI;
					//tempI->BePicked();
					cout<<"you pick a item"<<tempI->getName()<<" and add it to the bag"<<endl;
					break;
				}
				tempI = tempI->getNext();
			}
		}
		else{
			cout << "Invalid move"<< endl;
		}
		statusPlayerMove = map1.playerMove(p1.getPoi(),p1.getPoj(),dir);
		if(statusPlayerMove == 1){
			p1.move(dir);
		}
    //生成道具,最多十五个
    srand(time(0));
		int ItemRate = rand()%4+1;
		if((ItemRate < 6)&&(itemNum <= 15)){
			itemNum++;
			tempI = headI;
			while(tempI->getNext() != NULL){
				tempI = tempI->getNext();
			}
			//tempI->getNext() = new item(p1.getPoi(),p1.getPoj());
			tempI->setNext(new item(p1.getPoi(),p1.getPoj()));
			tempI = tempI->getNext();
			map1.ItemAdd(tempI);
			cout<<"new item created: "<<tempI->getPoi()<<","<<tempI->getPoj()<<endl;
		}
		//检查人物是否还生存

		if(p1.getCurrentHp() <= 0){
			playerdie(p1);
			break;
		}
		map1.printMap();
    cout<<bag1.openBag();
    cout <<"Player Name: "<<p1.getName()<<" CurrentHp: "<<p1.getCurrentHp()<<"  MaxHp: "<<p1.getMaxHp()<<"  Power: "<<p1.getPower()<<endl;
		cout <<"player position:("<<p1.getPoi()<<","<<p1.getPoj()<<")"<<endl;
		tempI = headI;
		cout<<"Item that has been created:";
		while(tempI->getNext() != NULL){
			cout<<tempI->getName();
			tempI = tempI->getNext();
		}
    cin >> act;
    cout << string(50,'\n');
  }
  tempI = headI;
  while(tempI->getNext()!=NULL){
    headI = tempI->getNext();
    delete tempI;
    tempI = headI;
  }
  delete tempI;
  tempI = NULL;
  return 0;
}
