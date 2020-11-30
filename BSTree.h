#pragma once

#include "NodeBST.h"
template<typename T>
class BSTree
{
private:
	NodeBST<T>* root;

	// Utility Functions - Recursive Functions --------------------------

	// Given functions, WHY "static"?? See the Note below
	static void rec_insertBST(NodeBST<T> *& subRoot, T key, int priorty);
	static void rec_inorder_traverse(NodeBST<T>* subRoot);
	static void rec_preorder_traverse(NodeBST<T>* subRoot);
	static void rec_postorder_traverse(NodeBST<T>* subRoot);	
	static void rec_destroy_tree(NodeBST<T> *& subRoot);

	// [NOTE] 
	// The paramter passed to each utility function is named "subRoot" and it should be used as is inside the functions
	// It is a fatal logical mistake to use root (the data member) in place of subRoot inside these functions
	// To prevent developpers from making that mistake unintentionally, we made the functions "static"
	// Now, using "root" instead of the passed "subRoot" by mistake  => syntax error
	 
public:
	BSTree(void);
	~BSTree(void);

	// Public Functions --------------------------

	// Given functions
	void insertBST(T key,int priorty); // not const
	void inorder_traverse() const;
	void preorder_traverse() const;
	void postorder_traverse() const;	
	void destroy_tree(); // not const

	// [Note]: in the above public functions:
	// const functions are const because there is no chance to change 
	// the root (data member) either directly (root = something) 
	// or indirectly by passing it (by reference) to another function (utility fn here)
};

