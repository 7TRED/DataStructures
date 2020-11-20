#include<iostream>
#include<string>

using namespace std;


template<class T>
class Node {
    public:
        T data;
        Node *next;
        Node( ){
            next = 0;
        }
        Node(const T& val, Node* link = 0 )
        {
            data = val;
            next = link;
        }
};

template<class T>
class SinglyLinkedList {
    private:
        Node<T> *head, *tail;
    
    public:
        SinglyLinkedList( ){
            head = 0;
            tail = 0;
        }

        bool isEmpty() { return head == 0; }
        int length();
        void push_front(const T& val);
        void push_back(const T& val);
        void insert(const T& val, int index);
        T pop_front();
        
        T pop();
        
        T del(int);
        
        void display( )
        {
            Node<T> *temp = head;
            for (; temp; temp=temp->next)
                cout << temp->data << " ";
            cout << endl;
        }
        
        int search(const T& data )
        {
        	Node<T>* temp = head;
        	int idx = 0;
        	for(;temp;temp=temp->next, idx++)
        	{
        		if(temp->data == data )
        			return idx;
			}
			
			return -1;
			
		}
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

template<class T>
int SinglyLinkedList<T>::length(){
    
    int count = 0;
    Node<T> *temp = head;
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
template<class T>
void SinglyLinkedList<T>::push_front(const T& val)
{
    head = new Node<T>(val, head);
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
template<class T>
void SinglyLinkedList<T>::push_back(const T& val)
{
    // O(1) implementation
    if (tail)
    {
        tail->next = new Node<T>(val);
        tail = tail->next;
    }
    else
        tail = head = new Node<T>(val);

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
template<class T>
void SinglyLinkedList<T>::insert(const T& val, int index)
{
    
    if (tail)
    {
        int idx = 1;
        Node<T> *temp = head;
        if(index == 0)
        {
            head = new Node<T>(val, head);
        }
        for (; idx < index && temp;
                idx++, temp = temp->next)
            ;
        if(!temp)
        {
            cout << "Out of bounds" << endl;
        }
        Node<T> *node = new Node<T>(val);
        node->next = temp->next;
        temp->next = node;
    }
    else
        head = tail = new Node<T>(val);
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

template<class T>
T SinglyLinkedList<T>::pop_front( ){
    if(isEmpty()) // if list is empty
    {
        throw "List is already empty";
    }

    T data = head->data;

    if(tail == head ) 
    {
        delete head;
        tail = head = 0;   
    }
    else{
        T data = head->data;
        Node<T> *temp = head;
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
template<class T>
T SinglyLinkedList<T>::pop( ){
    if(isEmpty())
        throw "List is already empty";
    T data = tail->data;
    if(head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else{
        Node<T> *temp = head;
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

template<class T>
T SinglyLinkedList<T>::del(int index)
{
    if(isEmpty())
        throw "List is empty";

    T data;
    int idx = 1;
    if(head == tail)
    {
        data = head->data;
        delete head;
        head = tail = 0;
    }
    else{
        Node<T> *cur = head;
        Node<T>* prev;
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




int main()
{
    SinglyLinkedList<string> list;
    string data;

    cout<<"#################### MENU #####################"<<endl;
    printf("%-10s\n%-10s\n%-10s\n%-10s\n%-10s\n%-10s\n%-10s\n%-10s\n%-10s\n",
							"1. Insert at start",
							"2. Insert at end",
							"3. Insert at position",
							"4. Delete at start",
							"5. Delete at end",
							"6. Delete at position",
							"7. Display a Record",
							"8. Search a Record",
							"9.  Quit"
							);
							
	int choice ;
	cout<<"Enter your choice: ";
	cin>>choice;
	
	
	
	while(choice != 9)
	{
		string ret;
		int idx;
		switch(choice)
		{
			case 1:
				cout<<"Enter data: ";
				cin>>data;
				list.push_front(data);
				break;
			
			case 2:
				cout<<"Enter data: ";
				cin>>data;
				list.push_back(data);
				break;
				
			case 3:
				cout<<"Enter data: ";
				cin>>data;
				cout<<"Enter position: ";
				cin>>idx;
				list.insert(data, idx);
				break;
				
			case 4:
				ret = list.pop_front();
				cout<<"Popped item: "<<ret<<endl;
				break;
				
			case 5:
				ret = list.pop();
				cout<<"Popped Item: "<<ret<<endl;
				break;
			
			case 6:
				cout<<"Enter position: ";
				cin>>idx;
				ret = list.del(idx);
				cout<<"Popped Item: "<<ret<<endl;
				break;
				
			case 7:
				list.display();
				break;
			
			case 8:
				cout<<"Element to be searched for: ";
				cin>>data;
				idx = list.search(data);
				if(idx != -1)
					cout<<"Element is at node: "<<idx<<endl;
				else
					cout<<"Element could not be found "<<endl;
				
				break;
					
			default:
				cout<<"Enter correct choice"<<endl;
				cin>>choice;
				continue;
		}
		
		cout<<"Enter choice: ";
		cin>>choice;
	}
	
	

    return 0;
}



