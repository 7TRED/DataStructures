#include<iostream>
#include<cstring>
#include<ctype.h>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>

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

        T pop( ){
            if(isEmpty())
            {
            	throw "Stack is empty";
			}
        
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

        T Top()
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


string join(vector<char> v)
{
    string s;
    for(char i:v)
    {
        s.push_back(i);
    }

    return s;
}

/* 
	Function mathches delimeters () [] {} and comments /* 
	
*/

bool delimeterMatching(const char* s)
{
    int len = strlen(s);

    SLLStack<char> st;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '('|| s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else if(s[i] == ')'|| s[i] == ']' || s[i] == '}')
        {
            switch(st.pop())
            {
                case '(':
                    if(s[i] != ')')
                        return false;
                    break;
                
                case '[':
                    if(s[i] != ']')
                        return false;
                    break;

                case '{':
                    if(s[i] != '}')
                        return false;
                    break;

                default :
                    return false;
                    break;
            }
        }
        else if (s[i] == '/')
        {
            if(s[i+1] == '*')
            {
                i = i + 2;
                while(i+1 < len && !(s[i] == '*' && s[i+1] == '/'))
                    i++;
                
                if(i == len-1)
                    return false;
            }

        }

        else
            continue;
    }

    if(st.isEmpty())
        return true;

    return false;
}

char delMatch(const char& ch)
{
    char opp;
    switch(ch)
    {
        case ')':
            opp = '(';
            break;
        case '(':
            opp = ')';
            break;

        case '[':
            opp = ']';
            break;
        case ']':
            opp = '[';
            break;
        case '}':
            opp = '{';
            break;
        case '{':
            opp = '}';
            break;

    }
    return opp;
}

void popUntil(SLLStack<char>& st,vector<char>& result, const char& ch )
{

    char opp = delMatch(ch);

    while(st.Top()!= opp)
    {
        result.push_back(st.pop());
    }
    st.pop();
}

int precedence(const char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if ( ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}


char* reverseInfix(const char *s)
{
    
    int len = strlen(s);
    char *p = new char[len];
    char ch;
    for (int i = len-1; i >= 0;i--)
    {
        if(s[i] == '('|| s[i] == '[' || s[i] == '{')
            p[len - 1 - i] = delMatch(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            p[len - 1 - i] = delMatch(s[i]);
        else
            p[len - 1 - i] = s[i];
    }
    p[len] = '\0';

    return p;
}


string infixToPostfix (const char* s)
{
    vector<char> result;
    SLLStack<char> st;
    if(delimeterMatching(s))
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if(s[i] == '('|| s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if(s[i] == ')'|| s[i] == ']' || s[i] == '}')
            {
                popUntil(st, result, s[i]);
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                if(st.isEmpty())
                    st.push(s[i]);
                else
                {
                    while(!(st.isEmpty()) && precedence(s[i]) < precedence(st.Top()))
                    {
                        result.push_back(st.pop());
                    }
                    st.push(s[i]);
                }
            }
            else
                result.push_back(s[i]);
        }

        while(!st.isEmpty())
        {
            result.push_back(st.pop());
        }
    }
    else{
        result.push_back('#');
    }

    return join(result);
}

string infixToPrefix(const char* s)
{
    
    char* p = reverseInfix(s);
    string v = infixToPostfix(p);
    int low = 0;
    int high = v.size() - 1;
    while(low<=high)
    {
        swap(v[low], v[high]);
        low++;
        high--;
    }
    return v;
}

void pushPopPrefix(SLLStack<string>& operand, SLLStack<char>& op)
{
    char o = op.pop();
    string op1 = operand.pop();
    string op2 = operand.pop();
    string tmp = "";
    tmp.push_back(o);
    tmp += op2 + op1;
    operand.push(tmp);
}

string infixToPrefix2(char const* s)
{
    SLLStack<string> operand;
    SLLStack<char> op;
    int len = strlen(s);
    if(delimeterMatching(s))
    {
        for (int i = 0; i < len; i++)
        {
            if(s[i] == '('|| s[i] == '[' || s[i] == '{')        // a+((b+c)+(d+e)*f)/g
                op.push(s[i]);
            else if(s[i] == ')'||s[i] == ']'||s[i] == '}')
            {
                char opp = delMatch(s[i]);
                while(!(op.isEmpty()) && !(op.isEmpty()) && op.Top() != opp)
                {
                    pushPopPrefix(operand, op);
                }
                op.pop();
            }

            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                if(op.isEmpty())
                    op.push(s[i]);
                else
                {
                    while(!(op.isEmpty()) && !(operand.isEmpty()) && precedence(s[i]) < precedence(op.Top()))
                    {
                        pushPopPrefix(operand, op);
                    }
                    op.push(s[i]);
                }
            }
            else{
                string tmp;
                tmp.push_back(s[i]);
                operand.push(tmp);
            }
        }

        while(!op.isEmpty() && !operand.isEmpty())
        {
            pushPopPrefix(operand, op);
        }
        return operand.Top();
    }
    else
        return "Invalid Infix expression";
}


void calculate(SLLStack<string>& result, const char& ch, bool flag = false)
{
    long long op1, op2;
    if(flag)
    {
        op1 = stoi(result.pop());
        op2 = stoi(result.pop());
    }
    else
    {
        op2 = stoi(result.pop());
        op1 = stoi(result.pop());
    }


    switch(ch)
    {
        case '+':
            result.push(to_string(op1 + op2));
            break;
        case '-':
            result.push(to_string(op1 - op2));
            break;
        
        case '*':
            result.push(to_string(op1 * op2));
            break;
        case '/':
            result.push(to_string(op1 / op2));
            break;
        case '^':
            result.push(to_string(pow(op1, op2)));
            break;
    }
}


auto postfixEval(string s)
{
    SLLStack<string> result;
    int len = s.length();

    for (int i = 0; i < len; i++)
    {
        if(s[i] == '+' ||s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' )
        {
            calculate(result, s[i]);
        }
        else {
            string tmp;
            tmp.push_back(s[i]);
            result.push(tmp);
        }
    }

    return result.Top();
}


auto prefixEval(string s)
{
     SLLStack<string> result;
    int len = s.length();

    for (int i = len-1; i >= 0; i--)
    {
        if(s[i] == '+' ||s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^' )
        {
            calculate(result, s[i], true);
        }
        else {
            string tmp;
            tmp.push_back(s[i]);
            result.push(tmp);
        }
    }

    return result.Top();
}




int main() 
{
    
	char s[100];
	cout<<"Enter expression: ";
	cin.getline(s,100);
	string postfix = infixToPostfix(s);
	string prefix = infixToPrefix(s);
	cout<<"Postfix: "<<postfix<<endl;
	cout<<"Prefix: "<<prefix<<endl;
	string postfixeval = postfixEval("12+");
	cout<<postfixeval<<endl;
	
	return 0;
	
}
