 
CXX=g++  
  
CXXFLAGS=-std=c++17 -Wall  
   
TARGET=Chicken 
  
all: $(TARGET)  
  
$(TARGET): Chicken.cpp  
    $(CXX) $(CXXFLAGS)  Chicken.cpp -o $(TARGET)  
   
clean:  
    rm -f $(TARGET)  
   
.PHONY: all clean  