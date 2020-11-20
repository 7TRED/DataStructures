#include <iostream>
#include<stack>

using namespace std;

stack<int> addition(stack<int>& s1, stack<int>& s2)
{
    int carry = 0;
    stack<int> result;
    while(!s1.empty() && !s2.empty() )
    {
        int a = s1.top();
        s1.pop();
        int b = s2.top();
        s2.pop();
        int sum;
        sum = a + b + carry;
        if(sum >= 10)
        {
            carry = sum / 10;
            sum = sum % 10;
            
        }

        result.push(sum);
    }

    if(!s1.empty())
    {
        while(!s1.empty())
        {
            int sum = s1.top() + carry;
            s1.pop();
            if(sum >= 10)
            {
                carry = sum / 10;
                sum = sum % 10;
               
            }

             result.push(sum);
        }
    }
    else if(!s2.empty())
    {
         while(!s2.empty())
        {
            int sum = s1.top() + carry;
            s2.pop();
            if(sum >= 10)
            {
                carry = sum / 10;
                sum = sum % 10;
               
            }

             result.push(sum);
        }
    }

    return result;
}


int main()
{
    stack<int> s1;
    stack<int> s2;

    for (int i = 0; i < 10; i++)
    {
        s1.push(rand() % 10);
        s2.push(rand() % 10);
    }

    stack<int> s = addition(s1, s2);
    while(!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}