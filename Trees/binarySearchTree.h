
#include<queue>
#include<stack>


#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

namespace N
{    // Overloading the pop() method to return a value
    template<class T>
    class Stack : public std::stack<T> {
        public:
        T pop() {
            T tmp = std::stack<T>::top();
            std::stack<T>::pop();
            return tmp;
        }
    };

    template<class T>
    class Queue : public std::queue<T> {
        public:
            T dequeue() {
                T tmp = std::queue<T>::front();
                std::queue<T>::pop();
                return tmp;
            }

            void enqueue(const T& val)
            {
                std::queue<T>::push(val);
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

            auto Depth( )
            {
                return Depth(root);
            }

            void displayMirror()
            {
                rightinorder(root);
            }

            void displayLeafNodes(){
                displayLeafNodes(root);
            }

            T* search(const T& val) const {
                return search(root, val);
            }

            void parentsAndChild();

            void breadthFirst();
            void iterativePreorder();
            void iterativeInorder();
            void iterativePostorder();
            void insert(const T &);
            void deleteByMerging(BSTNode<T> *&);
            void Delete(const T &);

            void operator=(const BST<T>& p ){
                root = copy(p.root);
            }
            


        protected:
            T* search(BSTNode<T> *, const T &) const;
            void preorder(BSTNode<T> *);
            void inorder(BSTNode<T> *);
            void postorder(BSTNode<T> *);
            auto Depth(BSTNode<T> *)const;
            void rightinorder(BSTNode<T> *);
            BSTNode<T> *copy(BSTNode<T> *);
            void displayLeafNodes(BSTNode<T> *);
            void visit(BSTNode<T>* p) {
                std::cout << p->data << ' ';
            }
            void visitNull(){
            	std::cout<<"NULL"<<" ";
			}
    };


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
        if(!p)
            std::cout << "Tree is empty";
        else
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
            s.push(p);
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
            while(cur->right == 0 || cur->right == prev)
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
                std::cout << "Duplicate value" << std::endl;
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
    void BST<T>::Delete(const T& data) {
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
            std::cout << "element" << data << "is not in the tree\n";
        else
            std::cout << "the tree is empty\n";
    }

    template<class T>
    auto BST<T>::Depth(BSTNode<T> * p)const{
        if(!p)
            return 0;
        else
        {
            int ldepth = Depth(p->left);
            int rdepth = Depth(p->right);

            if(ldepth > rdepth)
                return (ldepth + 1);
            else
                return rdepth + 1;
        }
    }

    template<class T>
    void BST<T>::rightinorder(BSTNode<T> *p)
    {
        if(p)
        {
            rightinorder(p->right);
            visit(p);
            rightinorder(p->left);
        }
    }

    template<class T>
    BSTNode<T>* BST<T>::copy(BSTNode<T>* p)
    {
        if(!p)
            return p;
        BSTNode<T> *newNode = new BSTNode<T>(p->data);
        newNode->left = copy(p->left);
        newNode->right = copy(p->right);

        return newNode;
    }

    template<class T>
    void BST<T>::parentsAndChild()
    {
        Queue<BSTNode<T> *> q;
        BSTNode<T>* p = root;
        if(!p)
            std::cout << "Tree is empty";
        else
        {
            q.enqueue(p);
            while(!q.empty())
            {
                p = q.dequeue();
                visit(p);
                std::cout << '\n';
                p->left?visit(p->left):visitNull();
                p->right?visit(p->right):visitNull();
            	std::cout<<"\n\n";
                
                if(p->left)
                    q.enqueue(p->left);
                if(p->right)
                    q.enqueue(p->right);
                    
                
            }
        }
    }

    template<class T>
    void N::BST<T>::displayLeafNodes(BSTNode<T>*p)
    {
        if(p)
        {
            displayLeafNodes(p->left);
            displayLeafNodes(p->right);
            if(!p->left && !p->right)
                visit(p);
        }
        
    }
    
}






#endif


