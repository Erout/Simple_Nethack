# 期中项目 Simple Nethack 实验报告
## 代码运行方法
- 依赖的第三方库：<windows.h>,用于改变部分输出的颜色。
- 编译：

```
//Makefile
FLAGS := -std=c++11 -w
Objs := main.o bag.o equip.o item.o Map.o monster.o player.o

Nethack: $(Objs)
  g++ $(FLAGS) -o Nethack $(Objs)

main.o: main.cpp Map.hpp player.hpp monster.hpp item.hpp bag.hpp equip.hpp
  g++ $(FLAGS) -c main.cpp

bag.o: bag.cpp bag.hpp item.hpp equip.hpp
  g++ $(FLAGS) -c bag.cpp

equip.o: equip.cpp equip.hpp
  g++ $(FLAGS) -c equip.cpp

item.o: item.cpp item.hpp
  g++ $(FLAGS) -c item.cpp

Map.o: Map.cpp Map.hpp monster.hpp item.hpp equip.hpp
  g++ $(FLAGS) -c Map.cpp

monster.o: monster.cpp monster.hpp Map.hpp
  g++ $(FLAGS) -c monster.cpp

player.o: player.cpp player.hpp
  g++ $(FLAGS) -c player.cpp

clean:
  rm Nethack $(Objs)

```
- 运行：可直接运行生成的.exe文件

## 操作方法
- 符号代表：

|符号|意义|
|-|-|
|@|人物|
|M|怪物|
|# .|路|
|X|墙壁|
|E|装备|
|I|道具|

- 人物移动；yubnhjkl（八方向）

- 其他操作：

|key|function|
|-|-|
|a|使用道具|
|i|打开背包|
|w|装上装备|
|，|捡道具和装备|
## 设计思路
###  封装对象：
- 地图: Map
private部分：储存地图的信息，arr[][] 储存每个位置是墙壁，道路，怪物或者人物。road[][] 储存路的信息，房间内的路或者房间外的路，人物和怪物移动的时候需要将他们移动前的位置修改成对应的路。IorE储存道具或者装备信息，输出时先考虑有无道具，再考虑是否输出路。view[][] 储存视野信息，若不在视野范围内，则暂时先输出空格，表示看不到。Ypoi，Ypoj储存Yendor项链的位置，人物若在那个位置且捡起了项链，则胜利。len wid等储存各个房间的长宽大小信息。（设置路和随机房间大小时方便使用）
public部分：生成房间，路，修改道具装备人物怪物等在地图上的位置，以及输出地图

- 人物：player
private：储存人物的各属性值，
public：能获取各属性值，能对各属性值进行修改（使用装备或道具或被怪物攻击的时候），以及进行人物移动等操作

- 怪物：monster
private：储存怪物各属性
public：能获取各属性值以及对部分属性进行修改（被攻击时Hp减少）

- 道具：item
是一个链表
private：存储道具各属性（使用后对人物的hp defence power等的改变，以及名称和作用的说明等），还有记录下一个道具的指针
public：可以获取各属性，设置下一个指针等

- 装备：equipment
也是链表
private：储存各属性
public：获取各属性，设置下一个指针等

- 背包：bag
有两个friend class：item 和 equip
private：两个vector分别储存捡到的道具和装备
public：能加入道具，装备到背包里，能显示捡到的东西

### 运算符重载
- bag里面捡道具和装备，以及使用道具
```
Bag& operator+=(item &i);//把item i加到bag的vector it里面
Bag& operator+=(Equip &e);//和上面类似，加的是装备
Bag& operator-=(item &i);//把item i从背包的vector it中移除
Bag& operator-=(Equip &e); //和上面类似
```
- item里面有判断item的内容是否相等的运算符重载
- equip里面有判断equip的内容是否相等的运算符重载
（因为main函数里面item 和 equip 的链表储存了游戏过程中所有生成的道具，使用背包里的道具的时候访问bag的内容感觉比较麻烦，所以就从main的链表中找到bag中相应的道具，访问main的链表进行使用道具和装备的相应操作）

### 其他思路
- 地图的随机并不是特别随机。
- 全场最多一共只同时出现三个怪物，在main函数里new的monster，只有当其中一个死了，才能再生成新怪物。
- 道具和装备设定的最多生成十个。

## 拓展点
- 有视野范围的限制

## 改进空间
- 路可以再随机一些
- 怪物的生成可以不那么死板，或许可以考虑像道具装备那样弄一个链表。
- 对象的封装可以再考虑周全一些，比如人物的移动的时候需要在两个类里面都作修改，怪物移动也是，就感觉比较麻烦
- 更新屏幕或许可以考虑用windows console API。
