#include "BSTree.h"

#include <iostream>
using namespace std;
template <typename T>
// Utility Functions - Recursive Functions --------------------------

// Given functions

NodeBST<T>* func1(NodeBST<T>* root) {
	if(root == NULL)
		return NULL;
	if(root->getleft() == NULL && root->getright() == NULL) {
		delete root;
		return NULL;
	}

	// Else recursively apply func1 to the left and right 
	// subtrees. 
	root->setleft(func1(root->getleft()));
	root->setright(func1(root->getright()));

	return root;
}

// Insert an integer key in a binary search tree.
// [Note]: subRoot is passed by ref because 
//         the new node may be inserted in the subRoot (if subRoot is empty nullptr)

template<typename T>
void BSTree<T>::rec_insertBST(NodeBST<T>*& subRoot, T key, int priorty)
{
	if (subRoot == nullptr)
		subRoot = new NodeBST<T>(key); // this line is why we pass subRoot by reference (subRoot = something)
	else if (subRoot->getdata() < key)
	{

		// ***   VERY IMPORTANT NOTE  *** //

		// rec_insertBST takes subRoot param (by reference)
		// Here we need to pass the right pointer that is returned from subRoot->getright() function
		//We have two case here:
		// 1- if Node::getright() is declared as  Node* Node::getright();			
		//		i.e. it returns "right" pointer (return by value)
		//		in this case, the returned pointer is called rvale (right-value)
		//		rvalue in C++ cannot be used at the left of assignment statement
		//		and cannot be passed by ref.
		//
		//2- if Node::getright() is declared as  Node*& Node::getright();
		//		i.e. it returns an alias to "right" pointer (return by ref)
		//		in this case, the returned pointer is called lvale (left-value)
		//		lvalue in C++ CAN be used at the left of assignment statement
		//		and CAN be passed by ref.

		// --> if getright() didn't return a reference, this line would give Syntax Error : because we cannot pass rvalue to by-reference parameter
		rec_insertBST(subRoot->getright(), key);


		//IF for any reason, getright in your code MUST return by value 
		// So the above call rec_insertBST(subRoot->getright(), key); would give an error because subRoot->getright() is rvalue
		// In this case you need to do the folowing:
		// 1- store right pointer it in temp, 
		// 2- pass the temp to the function, 
		// 3- set the right of subRoot with this temp (after calling the fn because it may be changed inside it - by ref)
		//Here is the code in this case to perform the same task
		/*
		Node * sub_right = subRoot->getright();
		rec_insertBST(sub_right, key);
		subRoot->setright(sub_right);
		*/

		// Remember: rvalue is some expression that is not stored in memory with a specific name
		// hence, you can't reach it by a name beyond the line that contains it 
		// like (x + 9): x is stored in memory, but (x + 9) returns a temp result that is not stored in memory with a name
		// same case for: subRoot->getright() --> if it returns an rvalue (or temp result without a name) of the "right"
	}
	else
	{
		// recursive call on left
		rec_insertBST(subRoot->getleft(), key);
	}
}

//* print the tree with inorder traversal.
template <typename T>
void BSTree<T>::rec_inorder_traverse(NodeBST<T>* subRoot)
{
	if (subRoot == nullptr) return;
	rec_inorder_traverse(subRoot->getleft());
	cout << subRoot->getdata() << " ";
	rec_inorder_traverse(subRoot->getright());
}

//* print the tree with preorder traversal.
template<typename T>
void BSTree<T>::rec_preorder_traverse(NodeBST<T>* subRoot)
{
	if (subRoot == nullptr) return;
	cout << subRoot->getdata() << "  ";
	rec_preorder_traverse(subRoot->getleft());
	rec_preorder_traverse(subRoot->getright());
}

//* print the tree with postorder traversal.
template <typename T>
void BSTree<T>::rec_postorder_traverse(NodeBST<T>* subRoot)
{
	if (subRoot == nullptr) return;
	rec_postorder_traverse(subRoot->getleft());
	rec_postorder_traverse(subRoot->getright());
	cout << subRoot->getdata() << "  ";
}

//* Deletes all the nodes in the tree.
// [Note]: subRoot is passed by ref because 
//         after deleting subRoot node we will make it point to nullptr (change subRoot)
template <typename T>
void BSTree<T>::rec_destroy_tree(NodeBST<T> *& subRoot)
{
	if (subRoot != nullptr)
	{
		// recursive call on left
		rec_destroy_tree(subRoot->getleft());

		// recursive call on right
		rec_destroy_tree(subRoot->getright());

		delete subRoot;
		subRoot = nullptr; // this line is why we pass subRoot by reference (subRoot = something)
	}
}

template <typename T>
BSTree<T>::BSTree()
{
	root = nullptr;
}

template <typename T>

BSTree<T>::~BSTree()
{
	destroy_tree();
}

// Public Functions ---------------------------------

// Given functions

template <typename T>

void BSTree<T>::insertBST(T key,int priorty) // not const
{
	// not const because rec_insertBST takes the root by reference, so may change it
	rec_insertBST(root, key,priorty);
}
template <typename T>
void BSTree<T>::inorder_traverse() const
{
	rec_inorder_traverse(root);
}
template <typename T>
void BSTree<T>::preorder_traverse() const
{
	rec_preorder_traverse(root);
}
template <typename T>
void BSTree<T>::postorder_traverse() const
{
	rec_postorder_traverse(root);
}
template <typename T>
void BSTree<T>::destroy_tree() // not const
{
	// not const because rec_destroy_tree takes the root by reference, so may change it
	rec_destroy_tree(root); 
}