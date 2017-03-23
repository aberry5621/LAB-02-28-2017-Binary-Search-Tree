// header

#include <iostream>

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class T>
class BST {

public:
    BST();
    void insert(T new_item);
    //void delete(T deleteMe); //tricky!
    //Tree traversals
    void inOrder();
    void preOrder();
    //void postOrder();

private:
    struct Node {
        T data;
        Node *llink = nullptr;
        Node *rlink = nullptr;
    };
    Node *m_root = nullptr;
    //Helper functions
    void helperInOrder(Node *ptr);
    void helperPreOrder(Node *ptr);
};

template <class T>
BST<T>::BST() {
    m_root = nullptr;
}

template <class T>
void BST<T>::insert(T new_item) {
    //Create the new node for insert item
    Node *temp = new Node;
    temp->data = new_item;
    temp->llink = nullptr;
    temp->rlink = nullptr;
    //Insert into an empty tree
    if (m_root == nullptr) {
        m_root = temp;
        return;
    }
    // 1. 'trailPtr' trails right behind movPtr as it moves
    // down to find the spot for insertion
    // REASON: movPtr will become null at some point
    // but we need the last node it last traversed to,
    // in order to link up the new node.
    // 2. 'left' boolean variable allows us to determine
    // if we need to link the new node to the left of right
    // link of an existing node.
    Node *movPtr = m_root;
    Node *trailPtr = movPtr;
    bool left = true;
    while (movPtr != nullptr) {
        if (movPtr->data > new_item)
        {
            trailPtr = movPtr;
            movPtr = movPtr->llink;
            left = true;
        }
        else if (movPtr->data < new_item)
        {
            trailPtr = movPtr;
            movPtr = movPtr->rlink;
            left = false;
        }
        else if (movPtr->data == new_item)
            return;
    }
    // Choose left or right link to link up
    // the new node pointed to by 'temp'
    if (left)
        trailPtr->llink = temp;
    else
        trailPtr->rlink = temp;
    temp = nullptr;
}

//template <class T>
//void BST<T>::delete(T deleteMe)
//{
// std::cout << "This could be tricky, make sure we have discussed this first!n";
//}

template <class T>
void BST<T>::inOrder() {
    std::cout << "inOrder Called..\n";
    helperInOrder(m_root);
}

template <class T>
void BST<T>::helperInOrder(Node *ptr) {
    if (ptr != nullptr) {
        helperInOrder(ptr->llink);
        std::cout << ptr->data << ' ';
        helperInOrder(ptr->rlink);
    }
}

template <class T>
void BST<T>::preOrder() {
    std::cout << "\npreOrder Called..\n";
    helperPreOrder(m_root);
}

template <class T>
void BST<T>::helperPreOrder(Node *ptr) {
    // std::cout << "preOrder Called..\n";
    
    // process right sub tree
    if (ptr != nullptr) {
        // process (visit) root
        std::cout << ptr->data << ' ';
        // process left sub tree
        if (ptr->llink != nullptr) {
            helperPreOrder(ptr->llink);
            std::cout << ptr->data << ' ';
        }
        if (ptr->rlink != nullptr) {
            helperPreOrder(ptr->rlink);
            std::cout << ptr->data << ' ';
        }
    }
}


//template <class T>
//void postOrder()
//{
//
//}

#endif /* BINARYSEARCHTREE_H */





