

#include<queue>
#include<stack>


#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

// Overloading the pop() method to return a value
template<class T>
class Stack : public stack<T> {
    public:
    T pop() {
        T tmp = top();
        stack<T>::pop();
        return tmp;
    }
};

template<class T>
class Queue : public queue<T> {
    public:
        T dequeue() {
            T tmp = front();
            queue<T>::pop();
            return tmp;
        }

        void enqueue(const T& val)
        {
            push(val);
        }
};

// Node structure of the BST
template<class T>
class BSTNode {
    public:
        BSTNode *left, *right;
        T data;

        BSTNode() {
            left = right = 0;
        }

        BSTNode (const T& val, BSTNode<T> *l = 0, BSTNode<T> *r = 0) {
            data = val;
            left = l;
            right = r;
        }
};

// BST 
template<class T>
class BST {
    protected:
        BSTNode<T> *root;
    
    public:
        BST() {
            root = 0;
        }

        ~BST() {
            clear();
        }

        void clear() {
            clear(root);
            root = 0;
        }

        bool isEmpty() const {
            return root == 0;
        }

        void preorder() {
            preorder(root);
        }

        void inorder() {
            inorder(root);
        }

        void postorder(){
            postorder(root);
        }

        T* search(const T& val) const {
            return search(root, val);
        }

        void breadthFirst();
        void iterativePreorder();
        void iterativeInorder();
        void iterativePostorder();
        void MorrisInorder();
        void insert(const T &);
        void deleteByMerging(BSTNode<T> *&);
        void findAndDeleteByMerging(const T &);
        void deleteByCopying(BSTNode<T> *&);
        void balance(T *, int, int);

    protected:
        void clear(BSTNode<T> *);
        T* search(BSTNode<T> *, const T &) const;
        void preorder(BSTNode<T> *);
        void inorder(BSTNode<T> *);
        void postorder(BSTNode<T> *);
        vitual void visit(BSTNode<T>* p) {
            cout << p->data << ' ';
        }
};

#endif


