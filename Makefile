all:
	g++ src/list.cpp red-black.cpp -o main
clean:
	rm -f main