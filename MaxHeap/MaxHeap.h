//
// Created by raspberry on 2020-12-18.
//


#include <iostream>
#include <vector>

using namespace std;
using std::vector;
template<typename T>

class MaxHeap
{
private:
    int size;
    vector<T> vect={-1};
    /// Functions the position of the parent
    int p(int i) {return i>>1;}; // i/2
    int l( int i ) {return i<<1;}; // i*2
    int r(int i) {return (i<<1)+1;}; // i *2 +1

public:
    bool isEmpty() const { return size== 0;};
    T getMax() const { return vect[1];};
    void insertItem(T value);
    void shiftUp(int i);  // index of the item that we're inserting
    T extractMax();  // to popping up an item from the vector // replace with the smallest element and then eliminate
    void shiftDown(int i);
};






