#include<iostream>
#include "genthread.h"

using namespace N;
using namespace std;

int main()
{
    TBTree<char> tree;
    tree.insert('p');
    tree.insert('b');
    tree.insert('c');
    tree.insert('v');
    tree.insert('q');
    tree.InorderTraversal();
    cout<<endl;
    tree.PreorderTraversal();

    return 0;
}



