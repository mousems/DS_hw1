hw1: hw1.o
	g++ hw1.o -o hw1
	./hw1
hw1.o: hw1.cpp
	g++ hw1.cpp -c
clean:
	rm -rf hw1.o 
