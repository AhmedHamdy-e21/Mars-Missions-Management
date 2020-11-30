
#ifndef _NODE
#define _NODE
template <typename T>
class NodeBST
{
private:
	T item; // A data item
	NodeBST<T>* next; // Pointer to next node
public :
	NodeBST();
	NodeBST(const T & r_Item);
	NodeBST(const T & r_Item, NodeBST<T>* nextNodePtr);
	void setItem(const T & r_Item);
	void setNext(NodeBST<T>* nextNodePtr);
	T getItem() const ;
	NodeBST<T>* getNext() const ;
}; // end NodeBST
#endif

template < typename T>
NodeBST<T>::NodeBST()
{
	next = nullptr;
} 

template < typename T>
NodeBST<T>::NodeBST(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
} 

template < typename T>
NodeBST<T>::NodeBST(const T& r_Item, NodeBST<T>* nextNodePtr)
{
	item = r_Item;
	next = nextNodePtr;
}
template < typename T>
void NodeBST<T>::setItem(const T& r_Item)
{
	item = r_Item;
} 

template < typename T>
void NodeBST<T>::setNext(NodeBST<T>* nextNodePtr)
{
	next = nextNodePtr;
} 

template < typename T>
T NodeBST<T>::getItem() const
{
	return item;
} 

template < typename T>
NodeBST<T>* NodeBST<T>::getNext() const
{
	return next;
} 