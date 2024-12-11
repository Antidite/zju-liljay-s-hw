#include<iostream>
#include"HeapSort.h"
#include <chrono>
#include <algorithm>
#include <random>

bool is_sorted(std::vector<int> input)
{
    for(auto i = input.begin()+1;i != input.end();i++)
    {
        if(*i > *(i-1))
            return false;
    }
    return true;
}

void check_my(std::vector<int> &input)
{
    Heapsort<int> heapsort;
    auto start = std::chrono::high_resolution_clock::now();
    heapsort.sort(input);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout <<"myheapsort耗时："<<duration.count() << std::endl;
    if(is_sorted(input))
        return;
    std::cout << "wrong" << std::endl; 

}
void check_std(std::vector<int> &input)
{  
    Heapsort<int> heapsort;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort_heap(input.begin(),input.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "std::sort_heap耗时："<<duration.count() << std::endl;
}
void check(std::vector<int> &input)
{   
    std::vector<int> input_copy = input;
    check_my(input_copy);
    check_std(input);
}


int main()
{   
    std::random_device rd;  
    std::mt19937 gen(rd());  
    std::uniform_int_distribution<> dis1(0, 100000000);
    std::uniform_int_distribution<> dis2(0, 1000);//抽屉原理保证重复性
    std::vector<int> sequence (1111111);
    for(auto i = 0;i < sequence.size(); i++)
    {
        sequence[i] = 2*i +1 ;
    }
    check(sequence);
    std::vector<int> reserve(1111111);
    for(auto i = 0;i < reserve.size(); i++)
    {
        reserve[i] = i*(-3) +1 ;
    }
    check(reserve);
    std::vector<int> random(1111111);
    for (int& val : random) {
        val = dis1(gen); 
    }
    check(random);
    std::vector<int> repetitive(1111111);
    for (int& val : repetitive){
        val = dis2(gen);
    }
    check(repetitive);


    std::uniform_int_distribution<> dis(0, 8);
    int i = dis(gen);
    std::cout << i;
}