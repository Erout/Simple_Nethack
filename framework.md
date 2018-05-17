# MidTerm Project：Simple_Nethack框架
## 主要实现功能
- 打印目前游戏情况
- 移动
- 攻击
- 怪物生成
- 怪物攻击
- 拾取装备
- 打开背包
- 查看人物属性
- 视野系统

## 主要模块
- 人物
- 怪物
- 地图
- 道具
- 装备

## 代码实现思路
### 类
- 玩家(player)
```
Class player{
private:
    int currentHP;
    int Power;
    //int Derexity;
    int currentDefence;//may de|increase by equipment,potion
    int least Defence;//changed only by potion
    char name[15];
    int pox;
    int poy;
    int MaxHp；
public:
    player();
    ~player();
    bool addHp(int ad);//full hp return false
    bool subHp(int de);//Hp==0,die
    bool addDefence(int i);//drink potion or dress up equipment
    bool subDefence(int i);//drink potion or take down equipment
    bool subPower(int i);
    bool addPower(int i);
    int getPower();
    int getCurrentHp();
    int getMaxHp();
    int getDefence();
    int getPox();
    int getPoy();
};
```
- 地图(Map)
```
Class Map{
private:
    int arr[500][500];
    int view[500][500];//0:not seeing
    int Ypox;//if==-1,not here
    int Ypoy;//the position of Yendor 项链
public:
    Map();
    ~Map();
    void printMap();
    void addview(int pox,int poy);//根据人物位置，增加视野范围
    void playerMove(int pox,int poy);
    void MosterMove(int pox,int poy);//if pox==-1,then disappear
    void EquipAdd(int pox,int poy);
    void ItemAdd(int pox,int poy);
    void PickItem(int pox,int poy);
    void PickEquip(int pox,int poy);
    void ThrowItem(int pox,int poy);
    void ThrowEquip(int pox,int poy);
}
```
- 怪物(Monster)
```
Class Monster{
private:
    int Id;
    char* name;
    int Hp；
    int Power;
    int pox;
    int poy;
public:
    Monster();//随机
    ~Monster();
    void Move();//访问玩家的位置，并改变自己的位置
    int getPower();
    int getHp();
    int getStatus();
    int getPox();
    int getPoy();
}
```
- 道具(items)
```
Class items{
private:
    char* name;
    int id;
    char* use;
public:
    items();//随机生成
    ~items();
    char* getUse();
    char* getName();
    int getId();
}
```
- 背包(Bag)
```
Class Bag{
private:
    int usedRoom;
    const int room;
    int item[50][3];
    //int money;
public:
    void openBag();//打开背包，打印背包内容
    void addItem(int id);
    void useItem(int id);
}
```
- 装备(Eqiupment)
```
Class Equipment{
private:
    int id;
    int distance;
    int harm;
    int defence;
    char* name;
    char* use;
public:
    Equipment();// 随机生成
    ~Equipment();
    int getId();
    char* getUse();
    char* getName();
}
```

### 各模块具体实现
#### 地图
- 用数组表示，一个数组储存各个位置的出现的东西，另一个数组储存视野范围，以及存储路的属性(房间中的路or房间外的路,有道具or无道具，有怪物or无怪物)

**arr[i][j]**

|Number|Meaning|sign|
|------|-------|----|
|0|void||
|1|wall|X|
|2|road|.|
|3|road|#|
|4|monster|M|
|5|equipment|E|
|6|inventory|I|
|7|player|@|

**view[i][j]**

|Number|Meaning|
|------|-------|
|0|void|
|1|inside|
|2|outside|
- 随机生成地图规则：(并不)房间数(4),大小随机()长宽,连接的道路随机(误) room1 left ->room2 right,room2 down ->room3 up, room3 right ->room4 left;
- 每走一步可能进行的改动：人物or怪物or道具or装备->路，反之同理
- 视野范围：以人物为中心，前后左右各2格，已走过的路持续显示

#### 人物
- 在地图上显示位置：getposition,再map.move；
- 人物移动：遇到怪物的时候要把怪物打死才能移动，遇到item equipment等优先显示人物，(p指令才pickup)
- 打怪物：根据现有的力量，打怪(条件，使用近身武器的时候，要距离怪物很近，以人物为中心一个单位能打到，使用远程武器可以打以人物为中心四个单位的怪物)
- 站在道具上面的时候显示道具的名称，这时候才可以捡起来

#### 怪物
- 在地图上显示位置，getposition，再monstermove
- 攻击玩家（计算周围八个点和玩家的曼哈顿距离）并移动,若与玩家相距一个单位，可开始攻击玩家（不同怪物每步攻击玩家概率和伤害都不同）

#### 道具
- 随机出现

#### 背包
- 有一定容量，
- pick的时候往背包里放东西
- throw的时候丢东西

#### 装备
- 增加玩家hp power defence 等等属性
- 武器：远程以及近程

### 设定值
#### 道具
|Id|Name|use|
|--|----|---|
|1|red potion|recover hp by 1|
|2|green potion|gain power by 1|
|3|black potion|decrease hp by 1|
|4|white potion|decrease power by 1|
|5|yellow potion|gain MaxHP by 1|

#### 装备
|Id|Name|use|distance|harm|defence|
|--|----|---|--------|----|-------|
|1|long sword|attack enemy in a short distance |1|3|0|
|2|arrow|bright arrow|4|2|0|
|3|chest|gain defence|0|0|4|
|4|dart|brilliant dart|4|1|0|
|5|chi|ancient chinese weapon|1|2|0|

#### 怪物
|Id|Name|power|Hp|
|--|----|-----|--|
|1|Bat|3|3|
|2|Bug|2|2|
|3|Rat|1|3|
|4|Gnome|4|5|

#### 地图
->j
                                 *len1+2+Lroad1 *len1+1+Lroad1+len2
0               *len1+1         *len1+1+Lroad1
XXXXXXXXXXXXXXXXX*len1+2         XXXXXXXXXXXXXXXX       0
X               X  *K1*   road1  X              X       max{wid1,wid2}
X   Room1        ################      Room2    X
X               X                X              X
X               X                XXXXXX XXXXXXXXX       *wid2+1
XXXXXXXXXXX XXXXX                  *K2*#                <-wid1+1 //*wid2+2
           #     <-wid1+2      road2   #         
           # road3                     #               
       *K3*#                           #
           #   <-wid1+1+Lroad3         #                *wid2+1+Lroad2
XXXXXXXXXXX XXXXXXXXXXwid1+2+Lroad3XXXX XXXXXX          *wid2+2+Lroad2
X                    X             X         X
X       Room4        X             X   Room3 X          
X                    X             X         X
XXXXXXXXXXXXXXXXXXXXXX             XXXXXXXXXXX          *wid2+1+Lroad2+wid3
0          *K3       *len4+1           *len1+2+Lroad1+K2
                                   *len1+2+Lroad1+K2-[0,len1+Lroad1-len4]
                                    *let K4 = len1 + Lroad1 - len4*
max{len1+Lroad1+len2,len4+len3}

地图大小100*100
房间长宽：20-40
路的长度：4-8
K1：2-15
K2：2-15
如何保证room3，4不重叠？->1，2长度设大一点，三四小一点
->room1 2长度：25-40
->room4长度：20-35

路的位置：road1（len1+2，K1）-（len1+2+Lroad1，K1）
         road2（len1+1+Lroad1+K2,wid2+1)-(len1+1+Lroad1+K2,wid2+1+Lroad2)
         road3(K3,wid1+1)-(K3,wid1+1+Lroad3)
room3 room2右移K2-4格
从（0，0）开始打印
随机生成：
- Room1:len1,wid1
- Lroad1
- Room2:len2,wid2
- Lroad2
- Room3:len3,wid3
- Lroad3
- Room4:len4,wid4
max{len1+Lroad1+len2}<500
max{wid1+Lroad3+len4,wid2+Lroad2+wid3}<500

随机生成六个房间，再生成路连接房间
房间宽度10-15
房间长度25-35
固定一些点,是每个房间的左上角点
生成房间之后，在每个房间的墙壁上取一个点，然后前后左右随机移动（若是房间内的路，则取另外的方向继续，若已开辟的路，则取另外方向继续，若碰到了其他墙壁，则停止，若超出数组范围，也停止。）使用while循环。

i     j->
|-----------------------------------------------------
|(0,0)       len1              (0,50)    50+len2
|room1   
|wid1                           wid2
|
|(20,0)      len3               (20,50)
|
|30+wid3                        30+wid4
|
|(40,0)      len5             (40,50)
|
|60+wid5                       60+wid6
|-----------------------------------------------------|
**arr[i][j]**

|Number|Meaning|sign|
|------|-------|----|
|0|void||
|1|wall|X|
|2|road|.|
|3|road|#|
|4|monster|M|
|5|equipment|E|
|6|inventory|I|
|7|player|@|

**view[i][j]**

|Number|Meaning|
|------|-------|
|0|void|
|1|inside|
|2|outside|
#### 攻击
自身血量减少公式 = Monster.getPower() - player.getDefence();
怪物血量减少公式 = player.getPower();

#### 死亡
player Hp == 0,游戏结束

### 文件
Map.hpp
Monster.hpp
Player.hpp
Equipment.hpp
Item.hpp
Bag.hpp
main.cpp
Map.cpp
Monster.cpp
Player.cpp
Equipment.cpp
Item.cpp
Bag.cpp

directon:
0 1 2
3 4 5
6 7 8
## 注意事项

##Diary
### 2018-05-08  
随机生成各数值之后将对应的符号赋值给数组也是有点难。。。考虑各点吧要。

### 2018-05-10
目前已经实现的功能：生成地图，人物移动
