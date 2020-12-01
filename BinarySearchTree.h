#pragma once
#include "BinarySearchTree/NodeBST.h"

template<typename T>
class BinarySearchTree
{
private:
    NodeBST<T>* root;
    int hight;

public:
    BinarySearchTree()
    {
        this->root= nullptr;
    }

    void insert(T key)
    {

    }


//// Functino to change the priority of a node
//// This could include a change down or change up
/*
//    void changePriority(int i, int p)
//    {
//        int oldp = H[i];
//        H[i] = p;
//
//        if (p > oldp) {
//            shiftUp(i);
//        }
//        else {
//            shiftDown(i);
//        }
//    }
 */

//// Shiftup
/*
void shiftUp(int i)
{
    while (i > 0 && H[parent(i)] < H[i]) {

        // Swap parent and current node
        swap(H[parent(i)], H[i]);

        // Update i to parent of i
        i = parent(i);
    }
}
 */

//// shiftup
/*
  void shiftDown(int i)
{
    int maxIndex = i;

    // Left Child
    int l = leftChild(i);

    if (l <= size && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    // Right Child
    int r = rightChild(i);

    if (r <= size && H[r] > H[maxIndex]) {
        maxIndex = r;
    }

    // If i not same as maxIndex
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}
 */
    // Search function
    // Get the highest priority


    //// Function to extract the highest priority
    // Extract max
    /*
     int extractMax()
{
    int result = H[0];

    // Replace the value at the root
    // with the last leaf
    H[0] = H[size];
    size = size - 1;

    // Shift down the replaced element
    // to maintain the heap property
    shiftDown(0);
    return result;
}
     */
};

