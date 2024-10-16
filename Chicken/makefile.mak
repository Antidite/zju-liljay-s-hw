all:
	g++ -Wall -std=c++17 Chicken.cpp -o Chicken  
  
clean:  
	rm -f Chicken 

.PHONY: all clean  