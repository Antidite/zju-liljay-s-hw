#include<iostream>
#include<vector>

template <typename T>
class Heapsort
{   public:
    void sort(std::vector<T> &input);
    private:
    void deleteMin(std::vector<T> &input);
    void heap_node(std::vector<T> &input,int current,int whole);
    void make_heap(std::vector<T> &input);
};

template <typename T>
void Heapsort<T>::make_heap(std::vector<T> &input)
{   
    if (input.size() <= 1)
        return;
    int n = input.size();
    for(int i = n/2-1;i >= 0; --i)
    {
        heap_node(input,i,n);
    }
}

template <typename T>
void Heapsort<T>::heap_node(std::vector<T> &input,int current,int whole)
{
    int min = current;
    int left_children = current*2+1;
    int right_children = current*2+2;
    if(left_children < whole && input[left_children] < input[min])
        min = left_children;
    if(right_children < whole && input[right_children] < input[min])
        min = right_children;
    if(current != min)
    {
        std::swap(input[current],input[min]);
        heap_node(input,min,whole);
    }
}

template <typename T>
void Heapsort<T>::sort(std::vector<T> &input)
{
    make_heap(input);
    deleteMin(input);
}

template <typename T>
void Heapsort<T>::deleteMin(std::vector<T> &input)
{   if (input.size() <= 1)
        return;
    int n = input.size();
    for(int i = n-1;i >= 1; i--)
    {
    std::swap(input[i],input[0]);
    heap_node(input,0,i);
    }
}
