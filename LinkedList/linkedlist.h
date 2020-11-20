#ifndef  INT_LINKED_LIST
#define  INT_LINKED_LIST



#include<iostream>

using namespace std;



class Node {
    public:
        int data;
        Node *next;
        Node( ){
            next = 0;
        }
        Node(int val, Node* link = 0 )
        {
            data = val;
            next = link;
        }
};


class SinglyLinkedList {
    private:
        Node *head, *tail;
    
    public:
        SinglyLinkedList( ){
            head = 0;
            tail = 0;
        }

        bool isEmpty() { return head == 0; }
        int length();
        void push_front(int val);
        void push_back(int val);
        void insert(int val, int index);
        int pop_front();
        int pop();
        int del(int);
    


        Node* begin(){ return head; }
        Node* begin() const { return head; }
        Node* end() { return tail; }
        Node *end() const { return tail; }
};

/* 
Basic operations on a list
    1) Traversing the list.
    2) Inserting an item in the list.
    3) Deleting an item from the list.
*/
//##########################################################
// Traversing the List
/*
    while traversing the list we do the following
        @ follow the pointers
        @ Display the data of the nodes
        @ stop when the next pointers points to NULL
*/

int SinglyLinkedList::length(){
    
    int count = 0;
    Node *temp = head;
    for (;temp->next; temp = temp->next,count++)
        ;
    return count;

    // Time Complexity O(n), for scanning the complete list
    // Space Complexity O(1), for a temporary variable.
}
//###########################################################
/* 
    Insertion:
        @ insertion at head of the list.
        @ insertion at the tail.
        @ insertion at any random location.
*/

/* 
    Insertion at the head
        @ Update the next pointer of the new Node
          to point to the current head
        @ update the head to point to the new Node.
*/
void SinglyLinkedList::push_front(int val)
{
    head = new Node(val, head);
    /* 
    the code above basically does this
        Node* node = new Node<T>(val);
        node->next = head;
        head = node;
    */ 
    if(tail == 0)
        tail = head;
}


/* 
    Insertion at the tail:
        @ Either you can use a tail pointer to keep track
          of the end of the list. To make this operation
          O(1).
        
        @ You can traverse the whole list and then insert 
          the node.

        - new nodes next points to NULL
        - Last node's next points to new Node.
*/

void SinglyLinkedList::push_back(int val)
{
    // O(1) implementation
    if (tail)
    {
        tail->next = new Node(val);
        tail = tail->next;
    }
    else
        tail = head = new Node(val);

    /* O(n) implementation
        Node* node = new Node<T>(val);
        Node* temp = head;
        while(temp)
        {
            temp = temp->next;
        }
        temp->next = node;
        node->next = nullptr;
    */
}

/* 
    Inserting at any random location
        @ First check whether the list is empty or not
        @ If not, then traverse to the position and insert
          the node.
          "Assumption that provided index is correct"
*/

void SinglyLinkedList::insert(int val, int index)
{
    
    if (tail)
    {
        int idx = 1;
        Node *temp = head;
        if(index == 0)
        {
            head = new Node(val, head);
        }
        for (; idx < index && temp;
                idx++, temp = temp->next)
            ;
        if(!temp)
        {
            cout << "Out of bounds" << endl;
        }
        Node *node = new Node(val);
        node->next = temp->next;
        temp->next = node;
    }
    else
        head = tail = new Node(val);
}

//################################################################
/* 
    Deletion from the Linked List
        @ Delete from head
        @ Delete from tail
        @ Delete from any position
*/

/* 
    @ First check list is empty or not
    @ If not, then create a temporary node and 
      point to head. make the head point to next node 
      Then delete temp node.
      
*/


int SinglyLinkedList::pop_front( ){
    if(isEmpty()) // if list is empty
    {
        throw "List is already empty";
    }

    int data = head->data;

    if(tail == head ) 
    {
        delete head;
        tail = head = 0;   
    }
    else{
        int data = head->data;
        Node *temp = head;
        head = head->next;
        delete temp;  
    }

    return data;
}

/*
    Deletion from the end of the list
        @ Even though we are using a tail pointer 
          the deletion operation still takes O(n) time
          as we have to reach second last node.And SLL 
          doesn't have back reference.
*/

int SinglyLinkedList::pop( ){
    if(isEmpty())
        throw "List is already empty";
    int data = tail->data;
    if(head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else{
        Node *temp = head;
        for (; temp->next->next;temp = temp->next)
            ;
        temp->next = 0;
        delete tail;
        tail = temp;
        delete temp;
    }
    return data;
}


/* 
    Deleting at random location
        @ traverse to that node and also keep track
          of the previous node.

        # Assumption: Index is correct.
*/


int SinglyLinkedList::del(int index)
{
    if(isEmpty())
        throw "List is empty";

    int data;
    int idx = 1;
    if(head == tail)
    {
        data = head->data;
        delete head;
        head = tail = 0;
    }
    else{
        Node *cur = head;
        Node* prev;
        for (; idx < index && cur;
                prev = cur,cur = cur->next ,idx++)
            ;
        if(!cur)
        {
            cout << "Out of bounds" << endl;
        }
        else
        {
            data = cur->data;
            prev->next = cur->next;
            cur->next = 0;
            delete cur;
        }

        
    }

    return data;
}


void display(SinglyLinkedList& list)
{
    Node* temp = list.begin();
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

}



#endif


