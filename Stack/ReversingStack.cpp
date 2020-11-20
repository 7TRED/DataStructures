#include<iostream>
#include<stack>

using namespace std;

/* 
    Problem: To reverse a stack using a single stack and push and pops operation

    Appraoch is that first pop all the elements of the stack . Then push elements at the bottom of the stack
    Time Complexity O(n^2): Space Complexity O(n)
*/

void insertAtBottom(stack<int>& s, int data)
{
    int tmp;
    if(s.empty())
    {
        s.push(data);
        return;
    }
    tmp = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(tmp);
}

void reverseStack(stack<int>& s)
{
    if(s.empty())
        return;

    int data = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, data);
}

int main() {
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(1);
    s.push(9);
    s.push(10);
    s.push(11);

    reverseStack(s);
    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}