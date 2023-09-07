all: output main.o 

output: main.o Solution.o Input.o
	g++ main.o Solution.o Input.o -o a.exe

main.o: main.cpp
	g++ -c main.cpp

Solution.o: Solution.cpp
	g++ -c Solution.cpp

Input.o: Input.cpp
	g++ -c Input.cpp

clean:
	rm *.o 