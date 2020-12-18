//
// Created by raspberry on 2020-12-18.
//

#include "MaxHeap.h"


template<typename T>
void MaxHeap<T>::insertItem(T value) {
    if ( size+1 >= vect.size())
    {
        vect.push_back(0);
    }
    vect[++ size]= value;
    shiftUp(size);
    return;

}


template<typename T>
void MaxHeap<T>::shiftDown(int i) {
    if (i > size) return;
    int swapId = i;// compare parent to two children    rather than just looking to the parent of the child
    if (l(i) <= size && vect[i] < vect[l(i)])
    {
        swapId=l(i);
    }// left child is greater than its parent so we need to swap
    // The case that the left child is larger than the parent but before swapping the right child
    // also could be greater the both so we need to swap the right with the prant not the left that's why we keep the id

    if ( r(i)<= size && vect[swapId]<vect[r(i)])
    {
        swapId= r(i);
    }
    if (swapId !=i){ //recurrsion
        swap(vect[i],vect[swapId]);
        shiftDown(swapId);
    }
    return;

}

template<typename T>
void MaxHeap<T>::shiftUp(int i) {
    if ( i > size) return;  // index that does not exist
    if ( i==1) return;
    if ( vect[i]> vect[p(i)])
    {
        swap(vect[p(i)],vect[i]);
    }

    shiftUp(p(i)); // recurrsion to get the parent of the parent and shift things up


}

template<typename T>
T MaxHeap<T>::extractMax() {
    int maxNum= vect[1];
    swap(vect[1], vect[size--]); // swap the elements and then decrement the size
    shiftDown(1);
    return maxNum;
}
