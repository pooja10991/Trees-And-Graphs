#include <iostream>
using namespace std;  

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
	public:
		/***** Function Members *****/
		BST();
		bool empty() const;
		bool search(const int & item) const; 
		void insert(const int & item);

		/***** Node class *****/
		class BinNode 
		{
			public:
				int data;
				BinNode * left;
				BinNode * right;

				// BinNode constructors
				// Default -- data part is default int value; both links are null.
				BinNode()
					: left(0), right(0)
				{}

				// Explicit Value -- data part contains item; both links are null.
				BinNode(int item)
					: data(item), left(0), right(0)
				{}

		};// end of class BinNode declaration

		/***** Data Members *****/
		BinNode * myRoot;

		/***** Function Members *****/
		void display(BinNode * root, int level); 
		void preorder(BinNode * root);
		void postorder(BinNode * root);
		void inorder(BinNode * root);
		int nodeCount(BinNode * root);
		bool deleteNode(int number);
		int height(BinNode * root);
		int isBalanced(BinNode * root);
		void balancing();
		BinNode * casesForRotation(BinNode * root, int caseNo);
		BinNode* searchForParentNode(BinNode * root, int value);

}; // end of class declaration

#endif
