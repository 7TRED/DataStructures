#ifndef CIRCULAR_LIST
#define CIRCULAR_LIST

template<class T>
class CLLNode {
    public:
        T data;
        CLLNode *next;

        CLLNode( ){
            next = 0;
        }
        CLLNode(const T& val, CLLNode *t = 0)
        {
            data = val;
            next = t;
        }
};

template<class T>
class CircularLinkedList {
    protected:
        CLLNode<T> *tail;

    public:
        CircularLinkedList( ){
           head =  tail = 0;
        }

        void push_back(const T &val);
        T pop();
};

template<class T>
void CircularLinkedList<T>::push_back(const T& val){
    if(tail != 0)
    {
        tail->next = new CLLNode<T>(val, tail->next);
        tail = tail->next;
    }
    else
    {
        tail = new CLLNode<T>(val);
        tail->next = tail;
    }
}

template <class T>
T CircularLinkedList<T>::pop( ){
    if(tail == 0)
        throw "List is Empty";

    if(tail->next = tail)
    {
        delete tail;
        tail = 0;
    }
    else{
        T data = tail->data;
        CLLNode<T> *tmp = tail;
        for (; tail->next != tmp; tail = tail-next)
            ;
        tail->next = tmp->next;
        delete tmp;
    }
    return data;
}

#endif 
