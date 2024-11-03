#include <iostream>
#include "BinarySearchTree.h"  // 假设 BinarySearchTree 类定义在这个头文件中

void testBinarySearchTree() {
    BinarySearchTree<int> bst;

    // 测试插入功能
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);
    bst.insert(1);
    bst.insert(20);
    // 测试打印树结构
    std::cout << "Initial Tree:" << std::endl;
    bst.printTree();

    // 测试查找最小和最大元素
    std::cout << "Minimum element: " << bst.findMin() << std::endl;
    std::cout << "Maximum element: " << bst.findMax() << std::endl;

    // 测试 contains 功能
    std::cout << "Contains 7? " << (bst.contains(7) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 20? " << (bst.contains(20) ? "Yes" : "No") << std::endl;

    // 测试删除功能
    bst.remove(7);
    std::cout << "Tree after removing 7:" << std::endl;
    bst.printTree(); 

    bst.remove(15);
    std::cout << "Tree after removing 15:" << std::endl;
    bst.printTree(); 

    bst.remove(10);
    std::cout << "Tree after removing 10:" << std::endl;
    bst.printTree();

    bst.remove(3);
    std::cout <<"Tree after removing 3:" << std::endl;
    bst.printTree();

    bst.remove(2);
    std::cout <<"Tree after removing 2:" << std::endl;
    bst.printTree();
    // 测试清空树
    bst.makeEmpty();
    std::cout << "Tree after making empty:" << std::endl;
    bst.printTree();

    bst.remove(1);
    std::cout <<"Tree after removing null root:" << std::endl;
    bst.printTree();
    // 测试是否为空
    std::cout << "Is tree empty? " << (bst.isEmpty() ? "Yes" : "No") << std::endl;

}

int main() {
    testBinarySearchTree();
    return 0;
}