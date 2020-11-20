#include <iostream>
#include"binarySearchTree.h"

using namespace N;
using namespace std;

int main()
{
    printf("%s\n","############################## MENU #################################");
    printf("\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
			"1. Insert",
			"2. Delete",
			"3. Display Tree traversal (31. Inorder 32. Preorder 33. Postorder)",
			"4. Iterative Tree traversal (41. Inorder 42. Preorder, 43. Postorder)",
			"5. Display Depth",
			"6. Display Mirror",
			"7. Create Copy",
			"8. Display Parents with child Nodes",
			"9. Display Leaf Nodes",
			"10. Display Level-wise",
			"11. Search",
			"12. quit"
			);
	
	int choice{0};
	cout<<"Your Choice: ";
	cin>>choice;
	cout<<"For this example tree can contain integers"<<endl;
	BST<int> tree;
	BST<int> newTree;
	
	while(choice != 12)
	{
		int data{0};
		switch(choice)
		{
			case 1:
				cout<<"Enter data: ";
				cin>>data;
				tree.insert(data);
				break;
			
			case 2:
				cout<<"Enter data to be deleted: ";
				cin>>data;
				tree.Delete(data);
				break;
			
			case 31:
				cout<<"Inorder Traversal: ";
				tree.inorder();
				cout<<endl;
				break;
			
			case 32:
				cout<<"Preorder Traversal: ";
				tree.preorder();
				cout<<endl;
				break;
			
			case 33:
				cout<<"Postorder Traversal: ";
				tree.postorder();
				cout<<endl;
				break;
				
			case 41:
				cout<<"Iterative Inorder Traversal: ";
				tree.iterativeInorder();
				cout<<endl;
				break;
				
			case 42:
				cout<<"Iterative Preorder Traversal: ";
				tree.iterativePreorder();
				cout<<endl;
				break;
				
			case 43:
				cout<<"Iterative Postorder Traversal: ";
				tree.iterativePostorder();
				cout<<endl;
				break;
				
			case 5:
				cout<<"Depth of the tree: "<<tree.Depth()<<endl;
				break;
			
			case 6:
				cout<<"Inorder traversal of Mirror: ";
				tree.displayMirror();
				cout<<endl;
			
			case 7:
				cout<<"Copy Created!!\nHere is a level-wise traversal: ";
				newTree = tree;
				newTree.breadthFirst();
				cout<<endl;
				break;
			
			case 8:
				cout<<"Parents\n Left-Child  Right-Child\n";
				tree.parentsAndChild();
				cout<<endl;
				break;
			
			case 9:
				cout<<"Leaf Nodes: ";
				tree.displayLeafNodes();
				cout<<endl;
				break;
			
			case 10:
				cout<<"Level Order Traversal: ";
				tree.breadthFirst();
				cout<<endl;
				break;
				
			case 11:
				cout<<"Enter Element to be searched for: ";
				cin>>data;
				if(tree.search(data))
					cout<<"True"<<endl;
				else
					cout<<"False"<<endl;
				
				break;
				
			default:
				cout<<"Enter Correct choice!!"<<endl;
				break;		
		}
		
		cout<<"Choice: ";
		cin>>choice;
	}

    return 0;
}
