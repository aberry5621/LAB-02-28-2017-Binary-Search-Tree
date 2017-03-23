//
//  main.cpp
//  LAB 02 28 2017 Binary Search Tree
//
//  Created by ax on 3/23/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "binarySearchTree.h"
#include <iostream>
using namespace std;

int main() {
    
    cout << "BINARY SEARCH THREE\n";
    
    int dataArr[] = {8,3,6,2,9,4,7,5,1,0};
    
    BST<int> myTree1;
    
    for (int i = 0; i < 10; i++) {
        myTree1.insert(dataArr[i]);
    }
    
    cout << "TEST 1: Number Tree...\n";
    
    myTree1.inOrder();
    
    myTree1.preOrder();
    
    BST<char> myTree2;
    
    for (int i = 0; i < 10; i++) {
        myTree2.insert(static_cast<char> ('A' + i));
    }
    
    cout << endl;
    
    cout << "TEST 2: Character Tree...\n";
    
    myTree2.inOrder();
    
    cout << endl;
    
    return 0;

}
