CXX=g++   
CXXFLAGS=-Wall -std=c++17  
TARGET=hello  
  
all: $(TARGET)  
  
$(TARGET): hello.cpp  
	$(CXX) $(CXXFLAGS) hello.cpp -o $(TARGET)  
  
clean:  
	rm -f $(TARGET)  

.PHONY: all clean  