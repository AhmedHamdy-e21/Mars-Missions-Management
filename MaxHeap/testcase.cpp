
#include "MaxHeap.h"
#include "MaxHeap.cpp"
int main() {
    // test case
    MaxHeap<int>* PriorityQueue= new MaxHeap<int>();
    if( PriorityQueue->isEmpty())
    {
        cout<<" This is empty indeed";
    }
    else cout<<"there is a problem";

    PriorityQueue->insertItem(10);
    PriorityQueue->insertItem(120);
    PriorityQueue->insertItem(34);
    PriorityQueue->insertItem(41);
    PriorityQueue->insertItem(5);
    cout<<PriorityQueue->getMax()<<endl;
    PriorityQueue->extractMax();

    cout<<PriorityQueue->getMax()<<endl;
    PriorityQueue->extractMax();
    cout<<PriorityQueue->getMax()<<endl;


    return 0;
}
