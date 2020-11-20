#include<iostream>
#include<bits/stdc++.h>




using namespace std;

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

        int isEmpty( )
        {
            return curr_size == 0;
        }

        void push(const T& val)
        {
            top = new Node<T>(val, top);
            curr_size++;
        }

        T& pop( ){
            if(isEmpty())
                throw "Underflow";

            T data = top->data;
            Node<T> *tmp = top;
            top = top->next;
            delete tmp;
            curr_size--;
            return data;
        }

        int size( )
        {
            return curr_size;
        }

        T& Top()
        {
            return top->data;
        }

        
        
        void display()
        {
            if(!top)
            {
                cout << "Stack is Empty" << endl;
                return;
            }
            Node<T> *tmp = top;
            for (; tmp;tmp= tmp->next)
            {
                cout << tmp->data <<" ";
            }
            cout << endl;
        }

        void clear()
        {
            while(top)
            {
                this->pop();
            }
        }

        void operator=(const SLLStack& c)
        {
            top = c.top;
            curr_size = c.curr_size;
        }
};


template<class T>
class AdvanceStack {
    SLLStack<T> mainStack;
    SLLStack<T> minStack;

    public:
        void push(const T& val)
        {
            mainStack.push(val);
            if(minStack.isEmpty())
            {
                minStack.push(val);
            }
            else
            {
                if(val <= minStack.Top())
                    minStack.push(val);
            }
        }

        T pop( )
        {
            T data = mainStack.pop();
            if(data == minStack.Top())
                minStack.pop();
            return data;
        }

        T getMin( )
        {
            return minStack.Top();
        }
};


int main() {
    AdvanceStack<int> st;
    for (int i = 0; i < 10; i++)
    {
        st.push(rand() % 100);
    }
    cout << st.getMin() << endl;
    return 0;
}