CXX=g++   
CXXFLAGS=-Wall -std=c++17  
TARGET=Chicken  
  
all: $(TARGET)  
  
$(TARGET): Chicken.cpp  
	$(CXX) $(CXXFLAGS) Chicken.cpp -o $(TARGET)  
  
clean:  
	rm -f $(TARGET)  

.PHONY: all clean  