#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
	: myRoot(0)
{}

bool BST::empty() const
{ return myRoot == 0; }


bool BST::search(const int & item) const
{
	BinNode * locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	return found;
}


void BST::insert(const int & item)
{
	BinNode * locptr = myRoot;   // search pointer
	BinNode * parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new BinNode(item);  
		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data )  // insert to left of parent
			parent->left = locptr;
		else                           // insert to right of parent
			parent->right = locptr;
	}
	else
		cout << "Item already in the tree\n";
}

//this function is only to display the tree for easy understanding.
void BST::display(BinNode * root, int level)
{
	if(root == NULL)
		return;
	BinNode * currentNode = root;
	display(currentNode->right, level+5);
	for(int i=0;i<level;i++)
	{
		cout << " ";
	}
	cout << currentNode->data << "\n";
	display(currentNode->left, level+5);
}

//Function implements Preorder.
void BST::preorder(BinNode * root)
{
	if(root == NULL)
		return;
	BinNode * currentNode = root;
	cout << currentNode->data << " ";
	preorder(currentNode->left);
	preorder(currentNode->right);
}

//Function implements Postorder.
void BST::postorder(BinNode * root)
{
	if(root == NULL)
		return;
	BinNode * currentNode = root;
	postorder(currentNode->left);
	postorder(currentNode->right);
	cout << currentNode->data << " ";
}

//Function implements Inorder.
void BST::inorder(BinNode * root)
{
	if(root == NULL)
		return;
	BinNode * currentNode = root;
	inorder(currentNode->left);
	cout << currentNode->data << " ";
	inorder(currentNode->right);
}

//Function implements Node Count.
int BST::nodeCount(BinNode * root)
{
	if(root == NULL)
		return 0;
	BinNode * currentNode = root;
	return 1+nodeCount(currentNode->left)+nodeCount(currentNode->right);
}

//Implementation for BST DELETE.
bool BST::deleteNode(int number)
{
	BinNode * locptr = myRoot;
	BinNode * currentNode;
	BinNode * toChangeNode;
	BinNode * parentNode;
	string direction;
	bool found = false;
	while (!found && locptr != 0)
	{
		if (number < locptr->data)	// descend left
		{
			parentNode = locptr;
			direction = "left";
			locptr = locptr->left;
		}
		else if (locptr->data < number)  // descend right
		{
			parentNode = locptr;
			direction = "right";
			locptr = locptr->right;
		}
		else
		{                           // item found
			found = true;

			//CASE 1 : when node to be deleted is root node and does not have any child.
			if(locptr == myRoot && locptr->right == 0 && locptr->left == 0)
				myRoot = 0;

			//CASE 2 : when the node to be deleted has 2 child.
			if(locptr->left != 0 && locptr->right != 0)
			{
				currentNode = locptr->left;
				toChangeNode = currentNode;
				while(currentNode != 0)
				{
					toChangeNode = currentNode;
					if(currentNode->right != 0)
					{
						if(currentNode->right->right == 0)
							parentNode = currentNode;
					}
					currentNode = currentNode->right;
				}
				locptr->data = toChangeNode->data;
				if(locptr->left == toChangeNode)
					locptr->left = toChangeNode->left;
				else
					parentNode->right = 0;
			}

			//CASE 3 : when node to be delete has one left child.
			else if(locptr->left != 0 && locptr->right == 0)
			{
				toChangeNode = locptr->left;
				locptr->data = toChangeNode->data;
				locptr->left = toChangeNode->left;
				locptr->right = toChangeNode->right;
			}

			//CASE 4 : When node to be deleted has one right child. 
			else if(locptr->left == 0 && locptr->right != 0)
			{
				toChangeNode = locptr->right;
				locptr->data = toChangeNode->data;
				locptr->right = toChangeNode->right;
				locptr->left = toChangeNode->left;
			}

			//CASE 5 : when node to be delete has no child.
			else if(locptr->left == 0 && locptr->right == 0)
			{
				if(direction.compare("left") == 0)
					parentNode->left = 0;
				else
					parentNode->right = 0;
			}
		}
	}
	return found;
}

//This function contains the implementation for searching the parent of the given value. Used for internal purpose.
BST::BinNode* BST::searchForParentNode(BinNode * root, int value)
{
	if(root->left == NULL && root->right == NULL)
		return NULL;

	if( (root->left != NULL && root->left->data == value)
			|| (root->right != NULL && root->right->data == value))
		return root;

	if(root->data > value)
		return searchForParentNode(root->left,value);

	if(root->data < value)
		return searchForParentNode(root->right,value);
}

//This function find the height of the tree. Used for internal purpose.
int BST::height(BinNode * root)
{
	int leftHeight = 0;
	int rightHeight = 0;
	if(root == NULL)
		return 0;
	else
	{
		leftHeight += height(root->left);
		rightHeight += height(root->right);
		return 1+(leftHeight>rightHeight?leftHeight:rightHeight);
	}
}

//This function will check if the tree satisfies the AVL properties. It will check the left and right balance of the tree. Use for internal purpose.
int BST::isBalanced(BinNode * root)
{
	int balancedNode = -1;
	if(root == NULL)
		return 0;

	if(root->right == 0 && root->left == 0)
		return 0;

	if(root->right != 0)
	{
		balancedNode = isBalanced(root->right);
		if(balancedNode!=0)
			return balancedNode;
	}		

	if(root->left != 0)
	{
		balancedNode = isBalanced(root->left);
		if(balancedNode!=0)
		        return balancedNode;
	}

	if(root->right != 0 && root->left != 0)
	{
		if(height(root->left)+1 == height(root->right) || height(root->left) == height(root->right)+1 || height(root->right) == height(root->left))
			balancedNode = 0;    // node is balanced
		else
		{
			if(height(root->left)>height(root->right)+1)
				balancedNode = 1;
			else if(height(root->right)>height(root->left)+1)
				balancedNode = 2;
		}
	}
	else if(root->right == 0 && root->left != 0)
	{
		if(height(root->left)==1)
			balancedNode = 0;
		else
			balancedNode = 1;
	}
	else if(root->left == 0 && root->right != 0)
	{
		if(height(root->right)==1)
			balancedNode = 0;
		else
			balancedNode = 2;
	}
	else if(root->right == 0 && root->left == 0)
		balancedNode = 0;
	return balancedNode;	
}

//This function does actual balancing of the AVL tree. 
//If after deletion or insertion the balance of the tree is broken and does not satisfy the AVL property then ROTATION needs to be carried out.
//This function is only applicable for AVL trees to satify the AVL properties.
void BST::balancing()
{
	int balanceNode = -1;
	BinNode * root = myRoot;
	BinNode * parentNode = NULL;
	BinNode * grandParentNode = NULL;

	while(balanceNode != 0 && root != 0)
	{
		//parentNode = root;
		if(root->left == 0 && root->right == 0)
			return;
		balanceNode = isBalanced(root);
		if(balanceNode != 0)
		{
			parentNode = root;
			if(balanceNode == isBalanced(root->right))
				root = root->right;
			else if(balanceNode == isBalanced(root->left))
				root = root->left;
			else
			{
				if(balanceNode == 1)
					root = root->left;
				else if(balanceNode == 2)
				        root = root->right;
			}				
		}

		//if(balanceNode == 1)
		//	root = root->left;
		//else if(balanceNode == 2)
		//	root = root->right;
	}

	if(parentNode == NULL)
		return;

	//CASE 2 : when right subtree is heavy with zig zag line.
	//There we do RIGHT ROTATION first then LEFT ROTATION.
	if(isBalanced(parentNode) == 2 && height(parentNode->right->left)>height(parentNode->right->right))
	{
		//cout << "case 2";
		root = casesForRotation(parentNode, 2);
	}

	//CASE 1 : when right subtree is heavy with straight line.
	//Therefore we do LEFT ROTATE.
	else if(isBalanced(parentNode) == 2) //&& balanced(parentNode->right) == 2)
	{
		//cout << "case 1";
		root = casesForRotation(parentNode, 1);
	}

	//CASE 4 : when left subtree is heavy with zig Zag line.
	//Therefore we do LEFT ROTATE first then RIGHT ROTATION.
	else if(isBalanced(parentNode) == 1 && height(parentNode->left->right)>height(parentNode->left->left))
	{
		cout << "case 4";
		root = casesForRotation(parentNode, 4);
	}

	//CASE 3 : when left subtree is heavy with straight line.
	//Therefore we do RIGHT ROTATE.
	else if(isBalanced(parentNode) == 1) // && balanced(parentNode->left) == 1)
	{
		//cout << "case 3";
		root = casesForRotation(parentNode, 3);
	}

	if(parentNode == myRoot)
		myRoot = root;
	else
	{
		grandParentNode = searchForParentNode(myRoot, parentNode->data);
		if(grandParentNode->right != 0 && grandParentNode->right->data == parentNode->data)
			grandParentNode->right = root;
		else if(grandParentNode->left != 0 && grandParentNode->left->data == parentNode->data)
			grandParentNode->left = root;
	}
}

//This function does actual rotation called from balancing function.
BST::BinNode * BST::casesForRotation(BinNode * root, int caseNo)
{
	BinNode * subNode;

	if(caseNo == 1)
	{
		subNode = root;
		root = root->right;
		subNode->right = root->left;
		root->left = subNode;	
		return root;
	}
	else if(caseNo == 2)
	{
		subNode = root->right;
		root->right = root->right->left;
		subNode->left = root->right->right;
		root->right->right = subNode;
		root = casesForRotation(root,1);
		return root;
	}
	else if(caseNo == 3)
	{
		subNode = root;
		root = root->left;
		subNode->left = root->right;
		root->right = subNode;
		return root;
	}
	else if(caseNo == 4)
	{
		subNode = root->left;
		root->left = root->left->right;
		subNode->right = root->left->left;
		root->left->left = subNode;
		root = casesForRotation(root,3);
		return root;
	}
	else
		cout << "Invalid case.";
}
