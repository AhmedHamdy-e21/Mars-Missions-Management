//
// Created by raspberry on 2020-11-30.
//
#pragma once
template<typename T>
class NodeBST
{
private:
    T key; // mission
    int priority;
    NodeBST * left;
    NodeBST * right;
    NodeBST * parent;

public:
    NodeBST()
    {
        left=right=parent= nullptr;
    }

    void setKey(T key)
    {
        this->key=key;
    }

    T getKey()
    {
        return this->key;
    }


    NodeBST*& getRight()
    {
        return this->right;
    }

    NodeBST*& getLeft()
    {
        return this->left;
    }

    NodeBST*& getParent()
    {
        return this->parent;
    }


    void setLeft(NodeBST<T>* left)
    {
        this->left=left;
    }


    void setRight(NodeBST<T>* right)
    {
        this->right=right;
    }

    void setParent(NodeBST<T>* parent)
    {
        this->parent=parent;
    }

};
