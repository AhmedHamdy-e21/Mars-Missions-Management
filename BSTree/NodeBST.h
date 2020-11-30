#pragma once

class NodeBST
{
private:
	int data;
	NodeBST *left;
	NodeBST *right;
public:
	NodeBST(int val);
	void setdata(int d);
	int getdata();

	void setright(NodeBST* p);
	NodeBST*& getright();
	//returns a pointer by reference
	//Reason for that is explained in file BSTree.cpp as a note written
	//inside the body of function BSTree::rec_insertBST

	void setleft(NodeBST* p);
	NodeBST*& getleft();
};

