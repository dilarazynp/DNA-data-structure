all: compile run

compile :
	g++ -I ./include/ -o ./lib/GenNode.o -c ./src/GenNode.cpp
	g++ -I ./include/ -o ./lib/Kromozom.o -c ./src/Kromozom.cpp
	g++ -I ./include/ -o ./lib/KromozomListNode.o -c ./src/KromozomListNode.cpp
	g++ -I ./include/ -o ./lib/KromozomList.o -c ./src/KromozomList.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Kromozom.o ./lib/KromozomList.o ./lib/GenNode.o ./lib/KromozomListNode.o ./src/Test.cpp
run :
	./bin/Test