
#ifndef THREADED_BINARY_TREE
#define THREADED_BINARY_TREE

/* 
    if LChild == 0  : then left points to in-order predeccesor
    if LChild == 1  : left points to child
    if RChild == 0  : then right points to in-order successor
    if RChild == 1  : right points to child
*/
namespace N
{
    template<class T>
    class TBTNode {
        public:
            TBTNode *left, *right;
            bool Lchild : true;
            bool Rchild : true;
            T data;

            TBTNode() {
                left = right = 0;
            }

            TBTNode(const T& val, TBTNode *l = 0, TBTNode *r = 0 )
            {
                data = val;
                left = l;
                right = r;
            }

    };

    template<class T>
    class TBTree {
        protected:
            TBTNode<T> *root, *head;

        public:
            TBTree(){
                root = 0;
            }
            void InorderTraversal();
            void PreorderTraversal();
            void insert(const T &data);
            

        protected:
            TBTNode<T> *inorderSuccessor(TBTNode<T> *p);
            TBTNode<T> *preorderSuccessor(TBTNode<T> *p);
            


    };


    template<class T>
    TBTNode<T>* N::TBTree<T>::inorderSuccessor(TBTNode<T> *p)
    {
        TBTNode<T> *pos = 0;
        if(p->Rchild == 0)
            return p->right;
        
        pos = p->right;
        while(pos->Lchild == 1)
            pos = pos->left;

        return pos;

    }

    template<class T>
    TBTNode<T>* N::TBTree<T>::preorderSuccessor(TBTNode<T> *p)
    {
        TBTNode<T> *pos;
        if(p->Lchild == 1)
            return p->left;
        
        pos = p;
        while(pos->right != NULL && pos->Rchild == 0)
            pos = pos->right;

        return pos->right;
        
    }

    template<class T>
    void TBTree<T>::InorderTraversal()
    {
        if(root == 0)
            std::cout << "Tree is empty!!" << '\n';
        TBTNode<T> *p = root;
        while(p->Lchild == true)
            p = p->left;
                
        while(p)
        {
            std::cout << p->data << " ";
            p = inorderSuccessor(p);
        }
    }


    template<class T>
    void TBTree<T>::PreorderTraversal()
    {
        if (root == NULL)
            std::cout << "Tree is Empty";

        TBTNode<T> *p = root;
        while(p){
            std::cout << p->data << " ";
            p = preorderSuccessor(p);
        }
    }


    template<class T>
    void TBTree<T>::insert(const T& data)
    {
        TBTNode<T>* p = root;
        TBTNode<T> *par = NULL;
        while(p)
        {
            if(data == (p->data))
            {
                std::cout << "Duplicate Key" << '\n';
                return;
            }

            par = p;

            if(data < p->data)
            {
                if(p->Lchild == true)
                    p = p->left;
                else
                    break;
            }

            else {
                if(p->Rchild == true)
                    p = p->right;
                else
                    break;
            }

        }

        
        if(par == NULL)
        {
            TBTNode<T> *tmp = new TBTNode<T>(data);
            root = tmp;
        }
        else if(data < par->data)
        {
            TBTNode<T> *tmp = new TBTNode<T>(data, par->left, par);
            par->Lchild = true;
            par->left = tmp;
        }
        else {
            TBTNode<T> *tmp = new TBTNode<T>(data, par, par->right);
            par->Rchild = true;
            par->right = tmp;
        }

    }
    
    
}



#endif
