/*----- treetester.cpp -----------------------------------------------------
  Program for testing BST.
  ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "BST.h"

int main()
{
	int i = 10, j = 10, k = 10;
	while(i != 0)
	{
		BST intBST;
		BST intAVL;
		int number;
		cout << "Select the option to move forward.";
		cout << "\n1. To construct BST tree.";
		cout << "\n2. To construct AVL tree.";
		cout << "\n0. To EXIT.";
		cout << "\nEnter your option : ";
		cin >> i;

		//Calling all the BST related functions inside this if.
		if(i == 1)
		{
			cout << "Constructing empty BST\n";
			while(k != 0)
			{
				cout << "\nBST " << (intBST.empty() ? "is" : "is not") << " empty\n";

				cout << "\n1. Insert into BST.";
				cout << "\n2. Delete from BST.";
				cout << "\n3. Preorder.";
				cout << "\n4. Postorder.";
				cout << "\n5. Inorder.";
				cout << "\n6. Node Count.";
				cout << "\n7. Display.";
				cout << "\n8. Search.";
				cout << "\n0. To EXIT.";
				cout << "\n\nEnter the appropraite option : ";
				cin >> k;

				if(k==0)
					break;
				else if(k == 1)
				{	
					cout << "\nNow insert a bunch of integers into the BST."
						"\nTry items not in the BST and some that are in it:\n";

					for (;;)
					{
						cout << "Item to insert (-999 to stop): ";
						cin >> number;
						if (number == -999) break;
						intBST.insert(number);
						cout << "\nBST Tree : \n";
						intBST.display(intBST.myRoot,1);
						cout << "\nInorder : ";
						intBST.inorder(intBST.myRoot);
						cout << "\n";
					}
				}
				else if(k == 2)
				{
					for (;;)
					{

						cout << "\nEnter the node to delete (-999 to stop) : ";
						cin >> number;
						if (number == -999) break;
						cout << (intBST.deleteNode(number) ? "Found" : "Not found") << endl;
						cout << "\nBST Tree : \n";
						intBST.display(intBST.myRoot,1);
						cout << "\nInorder is : ";
						intBST.inorder(intBST.myRoot);
						cout << "\n";
					}
				}
				else if(k == 3)
				{
					cout << "\nPreorder is : ";
					intBST.preorder(intBST.myRoot);
				}
				else if(k == 4)
				{
					cout << "\nPostorder is : ";
					intBST.postorder(intBST.myRoot);
				}
				else if(k == 5)
				{
					cout << "\nInorder is : ";
					intBST.inorder(intBST.myRoot);
				}
				else if(k == 6)
					cout << "\nTotal Node Count is : " << intBST.nodeCount(intBST.myRoot);
				else if(k == 7)
				{
					cout << "\nTree is : \n";
					intBST.display(intBST.myRoot,1);
				}
				else if(k == 8)
				{
					cout << "\nTry both items in the BST and some not in it:\n";
					for (;;)
					{
						cout << "Item to find (-999 to stop): ";
						cin >> number;
						if (number == -999) break;
						cout << (intBST.search(number) ? "Found" : "Not found") << endl;
					}

				}
				else 
					cout << "\nYou have entered invalid choice.";
			}
		}

		//calling all the AVL related functions here.
		else if(i == 2)
		{
			cout << "Constructing empty AVL\n";
			while(j != 0)
			{
				cout << "\nAVL " << (intAVL.empty() ? "is" : "is not") << " empty\n";

				cout << "\n1. Insert into AVL.";
				cout << "\n2. Delete from AVL.";
				cout << "\n3. Preorder.";
				cout << "\n4. Postorder.";
				cout << "\n5. Inorder.";
				cout << "\n6. Node Count.";
				cout << "\n7. Display.";
				cout << "\n8. Search.";
				cout << "\n0. To EXIT.";
				cout << "\n\nEnter the appropraite option : ";
				cin >> j;

				if(j == 0)
					break;
				else if(j == 1)
				{
					for (;;)
					{
						cout << "Item to insert (-999 to stop): ";
						cin >> number;
						if (number == -999) break;
						intAVL.insert(number);
						cout << "\nBefore balacing : \n";
						intAVL.display(intAVL.myRoot, 1);
						intAVL.balancing();
						cout << "\nAfter balancing : \n";
						intAVL.display(intAVL.myRoot, 1);
						cout << "\nInorder is : ";
						intAVL.inorder(intAVL.myRoot);
						cout << "\n";
					}

				}
				else if(j == 2)
				{
					for (;;)
					{
						cout << "\nEnter the node to delete (-999 to stop) : ";
						cin >> number;
						if (number == -999) break;
						cout << (intAVL.deleteNode(number) ? "Found" : "Not found") << endl;
						cout << "\nBefore balancing : \n";
						intAVL.display(intAVL.myRoot,1);
						intAVL.balancing();
						cout << "\nAfter balancing : \n";
						intAVL.display(intAVL.myRoot,1);
						cout << "\nInorder is : ";
						intAVL.inorder(intAVL.myRoot);
						cout << "\n";
					}

				}
				else if(j == 3)
				{
					cout << "\nPreorder is : ";
					intAVL.preorder(intAVL.myRoot);
				}
				else if(j == 4)
				{
					cout << "\nPostorder is : ";
					intAVL.postorder(intAVL.myRoot);
				}
				else if(j == 5)
				{
					cout << "\nInorder is : ";
					intAVL.inorder(intAVL.myRoot);
				}
				else if(j == 6)
					cout << "\nTotal Node Count is : " << intAVL.nodeCount(intAVL.myRoot);
				else if(j == 7)
				{
					cout << "\nAVL Tree is : \n";
					intAVL.display(intAVL.myRoot,1);
				}
				else if(j == 8)
				{
					cout << "\nTry both items in AVL and some not in it:\n";
					for (;;)
					{
						cout << "Item to find (-999 to stop): ";
						cin >> number;
						if (number == -999) break;
						cout << (intAVL.search(number) ? "Found" : "Not found") << endl;
					}

				}
				else
					cout << "You have entered invalid choice.";
			}
		}
		else if(i == 0)
			break;
		else
			cout << "Please select correct choice.";
	}
}
