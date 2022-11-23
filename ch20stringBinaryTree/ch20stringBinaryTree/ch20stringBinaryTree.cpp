// ch20stringBinaryTree.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//Create a project for a binary tree that holds strings.
class StringBinaryTree
{
private:
	struct TreeNode
	{
		string value;
		TreeNode* left;
		TreeNode* right;
	};
	TreeNode* root;
	void insert(TreeNode*&, TreeNode*&);
	void destroySubTree(TreeNode*);
	void deleteNode(string, TreeNode*&);
	void makeDeletion(TreeNode*&);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;
public:
	StringBinaryTree()
	{
		root = NULL;
	}
	~StringBinaryTree()
	{
		destroySubTree(root);
	}
	void insertNode(string);
	bool searchNode(string);
	void remove(string);
	void displayInOrder() const
	{
		displayInOrder(root);
	}
	void displayPreOrder() const
	{
		displayPreOrder(root);
	}
	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
};

//Insert node
void StringBinaryTree::insertNode(string num)
{
	TreeNode* newNode = NULL;
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = NULL;
	insert(root, newNode);
}

//Insert node (private)
void StringBinaryTree::insert(TreeNode*& nodePtr, TreeNode*& newNode)
{
	if (nodePtr == NULL)
		nodePtr = newNode;
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);
	else
		insert(nodePtr->right, newNode);
}

//Search node
bool StringBinaryTree::searchNode(string num)
{
	TreeNode* nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

//Remove node
void StringBinaryTree::remove(string num)
{
	deleteNode(num, root);
}

//Delete node
void StringBinaryTree::deleteNode(string num, TreeNode*& nodePtr)
{
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

//Make deletion
void StringBinaryTree::makeDeletion(TreeNode*& nodePtr)
{
	TreeNode* tempNodePtr = NULL;
	if (nodePtr == NULL)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//Destroy subtree
void StringBinaryTree::destroySubTree(TreeNode* nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//Display in-order traversal
void StringBinaryTree::displayInOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << " ";
		displayInOrder(nodePtr->right);
	}
}

//Display pre-order traversal
void StringBinaryTree::displayPreOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << " ";
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//Display post-order traversal
void StringBinaryTree::displayPostOrder(TreeNode* nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << " ";
	}
}

int main()
{
    cout << "Ch 20 Binary Trees by Kevin Bell\n\n";
	cout << "Inserting the strings Bob Amy Doug Ann Brad Debbie\n\n";
	cout << "Here are the values in order in the tree:\n";
	StringBinaryTree tree;
	tree.insertNode("Bob"); //Insert the strings
	tree.insertNode("Amy");
	tree.insertNode("Doug");
	tree.insertNode("Ann");
	tree.insertNode("Brad");
	tree.insertNode("Debbie");
	tree.displayInOrder();
	cout << endl << endl;
	cout << "Here are the values using pre-order traversal:\n";
	tree.displayPreOrder();
	cout << endl << endl;
	cout << "Here are the values using post-order traversal:\n";
	tree.displayPostOrder();
	cout << endl << endl;
	cout << "Deleting name Bob\n";
	tree.remove("Bob");
	cout << "Now values in order are:\n";
	tree.displayInOrder();
	cout << endl << endl;
	cout << "Deleting name Doug\n";
	tree.remove("Doug");
	cout << "Now values in order are:\n";
	tree.displayInOrder();
	cout << endl;
	system("pause");
	return 0;
} //end main function
	