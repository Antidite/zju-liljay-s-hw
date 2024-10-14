CXX=g++   
CXXFLAGS=-Wall -std=c++17  
TARGET=SingleLinkedList  
  
all: $(TARGET)  
  
$(TARGET): SingleLinkedList.cpp  
	$(CXX) $(CXXFLAGS) SingleLinkedList.cpp -o $(TARGET)  
  
clean:  
	rm -f $(TARGET)  

.PHONY: all clean  