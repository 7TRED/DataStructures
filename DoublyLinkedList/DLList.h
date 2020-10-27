#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

template <class T>
class DLLNode {
    public:
    DLLNode() {
        next = prev = 0;
    }
    DLLNode(const T& el, DLLNode *n = 0, DLLNode *p = 0){
        data = el;
        next = n;
        prev = p;
    }
    T data;
    DLLNode *next, *prev;
};

template<class T>
class DoublyLinkedList {
protected:
    DLLNode<T> *head, *tail;

public:
    DoublyLinkedList( ){
        head = tail = 0;
    }
    void push_back(const T &data);  //inserts at the tail
    T pop(); //Deletes from the tail
    int isEmpty(){
        return head == 0;
    }
};

template<class T>
void DoublyLinkedList<T>::push_back(const T& data){
    if(tail !=  0)
    {
        tail = new DLLNode<T>(data, 0, tail);
        tail->prev->next = tail;
    }
    else
        head = tail = new DLLNode<T>(data);

}

template<class T>
T DoublyLinkedList<T>:: pop( )
{
    T data = tail->data;
    if(isEmpty())
        throw "List is already empty";
    if(head == tail){
        delete head;
        head = tail = 0;
    }
    else {
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return data;
}


#endif