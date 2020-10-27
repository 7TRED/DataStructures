#include<iostream>
#include "intSLList.h"

SLList :: ~ SLList( ){
    for (Node *p; !isEmpty(); )
    {
        p = head->next;
        delete head;
        head = p;
    }
}

void SLList:: push_front(int data) {
    head = new Node(data, head);
    if(tail == 0)
        tail = head;
}

void SLList::push_back(int data){
    if(tail != 0)
    {
        tail->next = new Node(data);
        tail = tail->next;
    }
    else
        head = tail = new Node(data);
}

void SLList::insert(int data, int index)
{
    Node *node = new Node(data);
    if(index == 0)
    {
        node->next = head;
        head = node;
    }
    int ind = 1;
    Node *tmp = head;
    for ( ; ind < index && tmp->next != tail;
         tmp = tmp->next )
        ;
    if(ind == index)
    {
        if (tmp->next == tail)
        {
            tmp->next = node;
            tail = node;
        }
        else{
        node->next = tmp->next;
        tmp->next = node;        
        }
    }else
        throw "Index of Out of bounds";
}

int SLList::pop_front( ){
    if(isEmpty())
        throw "List is empty";

    int data = head->data;
    Node *tmp = head;
    if(head == tail)
        head = tail = 0;
    else
        head = head->next;
    delete tmp;
    return data;
}


int SLList::pop ( ){
    if(isEmpty())
        throw "List is empty";

    int data = tail->data;
    if(head == tail){
        delete head;
        head = tail = 0;
    }
    else{
        Node *tmp;
        for (tmp = head; tmp->next != tail; tmp = tmp->next)
            ;
        delete tail;
        tail = tmp;
        tail->next = 0;
        
    }
    return data;
}

void SLList::deleteNode(int data){
    if(isEmpty())
        throw "List is Empty";
    if(head != 0)
    {
        if(head == tail && data == head->data){
            delete head;
            head = tail = 0;
        }
        else if (data == head->data){
            Node *tmp = head;
            head = head->next;
            delete tmp;
        }
        else {
            Node *pred, *tmp;
            for (pred = head, tmp = head->next;
                 tmp != 0 && !(tmp->data == data);
                 pred = pred->next, tmp = tmp->next)
                ;
            if(tmp != 0) {
                pred->next = tmp->next;
                if(tmp == tail)
                    tail = pred;
                delete tmp;
            }
        }

    }
}

bool SLList::isInList(int data)const {
    Node *tmp;
    for (tmp = head; tmp != 0 && !(tmp->data == data); tmp = tmp->next)
        ;
    return tmp != 0;
}
