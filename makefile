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
