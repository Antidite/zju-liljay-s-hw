all:
    g++ List.cpp -o List -std=c++20 -O2

report:
    xelatex report.tex

clean:  
    rm -f List 

.PHONY: all clean  