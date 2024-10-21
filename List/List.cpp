#include "List.h"
#include <iostream>

int main()
{ // 测试默认构造函数     测试empty函数
    List<int> none;
    std::cout << none.empty() << std::endl;
    none.push_back(6);
    none.push_front(0);
    for (auto &x : none)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // 测试初始化和右值push_back与push_front
    List<int> l1{1, 2, 3, 4, 5};
    l1.push_back(7);
    l1.push_front(0);
    l1.push_front(2);
    for (auto &x : l1)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // 测试拷贝构造函数    // 测试移动构造函数    // 测试赋值构造函数和左值push_back front
    List<int> l1copy(l1);
    for (auto &x : l1copy)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    int a = 1;
    int b = 2;
    int c = 3;
    List<int> l2;
    l2 = l1;
    for (auto &x : l2)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    List<int> l1move(std::move(l1));
    for (auto &x : l1move)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (auto &x : l1copy)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (auto &x : l2)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // 测试iterator begin与end,前后置--与++运算符号以及*运算符,back front函数
    auto itb = l2.begin();
    auto ite = l2.end();
    std::cout << *itb << " " << *(--ite) << " " << *(ite--) << " "
                << *ite << " "
                <<*(++itb) <<" "<< *(itb++) << " " << *itb 
                << " " <<std::endl;
    itb = l2.begin();
    ite = l2.end();
    *itb = -1;
    *(--ite) = -2;
    std::cout << l2.front() << " " << l2.back() << std::endl;
    l2.push_front(a);
    l2.push_front(b);
    l2.push_back(c);
    for(auto it = l2.begin(); it!=l2.end();++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << l2.size();
    std::cout << std::endl;
    auto po = l2.end();
    std::cout << (po == l2.begin()) << " " <<(po != l2.begin())<< std::endl;
    //测试const_iterator的 begin end 前后置++ -- back * front 与== !=
    const List<char> lconst{'a','b','c','d'};
    for(auto it = lconst.begin(); it!=lconst.end();++it)
    {
        std::cout << *it << " ";
    }
    std::cout << lconst.front() << " " <<lconst.back() << std::endl; 
    auto conpo = lconst.end();
    std::cout << (conpo == lconst.begin()) << " " <<(conpo != lconst.begin())<< std::endl;
    //测试size函数
    std::cout << lconst.size();
    std::cout << std::endl;
    //测试clear函数
    std::cout << l1copy.empty() <<" ";
    l1copy.clear();
    std::cout << std::endl;
    // 测试pop_front与pop_back
    l2.pop_back();
    l2.pop_front();
    for(auto it = l2.begin(); it!=l2.end();++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    //测试iterator 左右值insert 与erase
    List<int> lin{1, 3, 4, 5, 7}; 
    int p = 6;
    auto i = lin.begin();
    ++i;
    auto s = lin.insert(i,2);
    auto j = lin.end();
    --j;
    auto t = lin.insert(j,p);
    std::cout << *s << " " << *t << " " << std::endl;
    for(auto it = lin.begin(); it!=lin.end();++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    auto k = lin.erase(s,t);
    for(auto it = lin.begin(); it!=lin.end();++it)
    {
        std::cout << *it << " ";
    }
    std::cout << *k <<std::endl;
    i = lin.erase(k);
    for(auto it = lin.begin(); it!=lin.end();++it)
    {
        std::cout << *it << " ";
    }
    std::cout << *i <<std::endl;
    //检查 iterator与const_iterator默认构造函数
    List<int>::iterator s0;
    List<int>::const_iterator con_s0;
    std::cout << s0.is_null() << " " <<
    con_s0.is_null() << " ";
    // std::cout << std::endl;
    // List<int> lst;

    // for (int i = 0; i < 10; ++i)
    //{
    //     lst.push_back(i);
    // }

    // lst.pop_back();

    // for (auto it : lst)
    // std::cout << it << std::endl;

    // for (auto it = lst.begin(); it != lst.end(); ++it)
    // {
    //     std::cout << *it << std::endl;
    // }

    //     List<int> lst = {1, 2, 3, 4, 5};
    //     for (auto &x : lst)
    //     {
    //         std::cout << x << "\t";
    //     }
    //     std::cout << std::endl;

    // //    List<int> lst2 = std::move(lst);
    //     List<int> lst2 = List<int> {5, 6};
    //     for (auto &x : lst2)
    //     {
    //         std::cout << x << "\t";
    //     }
    //     std::cout << std::endl;

    //     lst2 = std::move(lst);
    //     for (auto &x : lst2)
    //     {
    //         std::cout << x << "\t";
    //     }
    //     std::cout << std::endl;

    return 0;
}