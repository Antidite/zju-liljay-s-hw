all:
	g++ test.cpp -o test -std=c++20 -O2

report:
	xelatex report.tex

clean:  
	rm -f test 

run: all
	./test

.PHONY: all clean  