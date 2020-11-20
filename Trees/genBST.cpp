#include<iostream>
#include "genBST.h"

using namespace std;

template<class T>
T* BST<T>::search(BSTNode<T>* p, const T& data)const
{
    while(p)
    {
        if(data == p->data)
            return &p->data;
        else if(data > p->data)
            p = p->left;
        else
            p = p->right;
    }

    return 0;
}


template<class T>
void BST<T>::breadthFirst() {
    Queue<BSTNode<T> *> queue;
    BSTNode<T> *p = root;
    if(p)
    {
        queue.enqueue(p);
        while(!queue.empty()) {
            p = queue.dequeue();
            visit(p);
            if(p->left)
                queue.enqueue(p->left);
            if(p->right)
                queue.enqueue(p->right);
        }
    }
}


template<class T>
void BST<T>::inorder(BSTNode<T> *p){
    if(p) {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template<class T>
void BST<T>::preorder(BSTNode<T> *p) {
    if(p) {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template<class T>
void BST<T>::postorder(BSTNode<T> *p) {
    if(p) {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template<class T>
void BST<T>::iterativePreorder() {
    Stack<BSTNode<T> *> s;
    BSTNode<T> *p = root;
    if(p){
        s.push(p)
        while(!s.empty())
        {
            p = s.pop();
            visit(p);
            if(p->right)
                s.push(p->right);
            if(p->left)
                s.push(p->left);
            // left child is pushed after right child to be on
            // the top of the stack;
        }
    }
}

template<class T>
void BST<T>::iterativeInorder() {
    Stack<BSTNode<T> *> s;
    BSTNode<T> *p = root;
    while(1){
        for (; p; p = p->left)
            s.push(p);

        if(s.empty())
            break;
        p = s.pop();
        visit(p);
        p = p->right;
    }
}

template<class T>
void BST<T>::iterativePostorder() {
    Stack<BSTNode<T> *> s;
    BSTNode<T> *cur = root, *prev = root;
    while(cur)
    {
        for (; cur->left; cur = cur->left) // Not pushing the leaf nodes
            s.push(cur);
        while(cur->right == 0 || cur->right == q)
        {
            visit(cur);
            prev = cur;
            if(s.empty())
                return;
            cur = s.pop();
        }
        s.push(cur);
        cur = cur->right;
    }
}


template<class T>
void BST<T>::insert(const T& data){
    BSTNode<T> *p = root, *prev = 0;
    while(p)
    {
        prev = p;
        if(data == prev->data)
        {
            cout << "Duplicate value" << endl;
            return;
        }

        if(data < p->data)
            p = p->left;
        else
            p = p->right;
    }

    if(root == 0)
        root = new BSTNode<T>(data);
    else if(data < prev->data)
        prev->left = new BSTNode<T>(data);
    else
        prev->right = new BSTNode<T>(data);
}


template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node) {
    BSTNode<T> *tmp = node;
    if(node)
    {
        if(!node->right)
            node = node->left;
    
        else if (!node->left)
            node = node->right;

        else {
            tmp = node->left;
            while(tmp->right)
                tmp = tmp->right;

            tmp->right = node->right;

            tmp = node;
            node = node->left;
        }
    }

    delete tmp;

}

template<class T>
void BST<T>::findAndDeleteByMerging(const T& data) {
    BSTNode<T> *node = root, *prev = 0;
    while(node){
        if(node->data == data)
            break;
        prev = node;
        if(data < node->data)
            node = node->left;
        else
            node = node->right;
    }

    if(node != 0 && node->data == data)
    {
        if(node == root)
            deleteByMerging(root);
        else if(prev->left == node)
            deleteByMerging(prev->left);
        else
            deleteByMerging(prev->right);
    }

    else if (root != 0)
        cout << "element" << data << "is not in the tree\n";
    else
        cout << "the tree is empty\n";
}


