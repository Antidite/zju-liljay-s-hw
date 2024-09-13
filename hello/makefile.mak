 
CXX=g++  
  
CXXFLAGS=-std=c++17 -Wall  
   
TARGET=hello  
  
all: $(TARGET)  
  
$(TARGET): hello.cpp  
    $(CXX) $(CXXFLAGS) hello.cpp -o $(TARGET)  
   
clean:  
    rm -f $(TARGET)  
   
.PHONY: all clean  