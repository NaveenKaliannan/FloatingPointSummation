
main:main.cpp
	g++ -std=c++11 -Wall main.cpp -o main

clean:
	rm -f main
	rm -f output/data/*
	rm -f output/graph/*
