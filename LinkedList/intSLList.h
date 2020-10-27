#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class Node {
public:
    int data;
    Node *next;

    Node ( ){
        next = 0;
    }

    Node (int value, Node *link = 0)
    {
        data = value;
        next = link;
    }
};

class SLList {
    private:
        Node *head, *tail;
    public:
    SLList ( ){
        head = 0;
        tail = 0;
    }
    ~SLList();

    int isEmpty( ){
        return head == 0;
    }

    void push_front(int);
    void push_back(int);
    void insert(int, int);
    int  pop_front();
    int pop();
    void deleteNode(int);
    bool isInList(int) const;
};

#endif 