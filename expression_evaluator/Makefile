all:
	g++ main.cpp -o main -std=c++20 -O2

report:
	xelatex report.tex

clean:  
	rm -f main 

run: all
	./main

.PHONY: all clean  