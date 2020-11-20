#ifndef STACK
#define STACK

#include<iostream>
namespace N
{
    template<class T>
    class Node {
        public:
            T data;
            Node *next;

            Node( )
            {
                next = NULL;
            }
            Node ( const T& val, Node* link = NULL)
            {
                data = val;
                next = link;
            }
    };

    template<class T>
    class SLLStack {
        private:
            Node<T> *top;
            int curr_size;

        public:

            SLLStack( )
            {
                top = NULL;
                curr_size = 0;
            }

            int isEmpty( ){return curr_size == 0;}

            void push(const T &val);
            T pop();

            int size( )const{return curr_size;}
            T Top()const{return top->data;}

            void display();
            void clear();
    };

    template<class T>
    void SLLStack<T>::push(const T& val)
    {
        top = new Node<T>(val, top);
        curr_size++;
    }


    template<class T>
    T SLLStack<T>::pop( )
    {
        if(isEmpty())
        {
            std::cout << "Underflow" << std::endl;
            return -999999;
        }

        T data = top->data;
        Node<T> *tmp = top;
        top = top->next;
        delete tmp;
        curr_size--;
        return data;
    }



    template<class T>
    void SLLStack<T>::display()
    {
        if(!top)
        {
            std::cout << "Stack is Empty" << std::endl;
            return;
        }
        Node<T> *tmp = top;
        for (; tmp;tmp= tmp->next)
        {
            std::cout << tmp->data <<" ";
        }
        std::cout << std::endl;
    }

    template<class T>
    void SLLStack<T>::clear()
    {
        while(top)
        {
            this->pop();
        }
    }

}


#endif 
