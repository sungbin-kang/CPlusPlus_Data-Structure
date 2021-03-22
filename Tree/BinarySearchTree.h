#pragma once
#include "BinarySearchTreeInterface.h"

template <typename T>
class BinarySearchTree : public BinarySearchTreeInterface<typename T>
{
    friend BinarySearchTreeTest;

    struct Node
    {
        T item;
        Node *left;
        Node *right;
    };

private:
    Node *root;

public:

    /**
     * Constructor
     */
    BinarySearchTree();

    /**
     * Destructor
     */
    ~BinarySearchTree();

    /** 
     * Tests whether this binary tree is empty.
     * @return True if the binary tree is empty, or false if not. 
     */
    bool isEmpty() const;

    /** 
     * Gets the height of this binary tree. 
     * @return The height of the binary tree. 
     */
    int getHeight() const;

    /** 
     * Gets the number of nodes in this binary tree. 
     * @return The number of nodes in the binary tree. 
     */
    int getNumberOfNodes() const;

    /** 
     * Gets the data that is in the root of this binary tree.
     * @pre The binary tree is not empty.
     * @post The root’s data has been returned, and the binary tree is unchanged
     * @return The data in the root of the binary tree. 
     */
    T getRootData() const;

    /** Replaces the data item in the root of this binary tree with the given 
     * data, if the tree is not empty. However, if the tree is empty, inserts 
     * a new root node containing the given data into the tree. 
     * @pre None.
     * @post The data in the root of the binary tree is as given.
     * @param newData The data for the root. 
     */
    void setRootData(const T &newData);

    /** 
     * Adds a new node containing the given data to this binary tree. 
     * @param newData The data for the new node.
     * @post The binary tree contains a new node.
     * @return True if the addition is successful, or false not. 
     */
    bool add(const T &newData);

    /** 
     * Removes the node containing the given data item from this binary tree. 
     * @param data The data value to remove from the binary tree.
     * @return True if the removal is successful, or false not. 
     */
    bool remove(const T &data);

    /** 
     * Removes all nodes from this binary tree. 
     */
    void clear();

    /** 
     * Gets a specific entry in this binary tree.
     * @post The desired entry has been returned, and the binary tree is 
     * unchanged. If no such entry was found, an exception is thrown. 
     * @param anEntry The entry to locate.
     * @return The entry in the binary tree that matches the given entry. 
     * @throw NotFoundException if the given entry is not in the tree. 
     */
    T getEntry(const T &anEntry) const throw(NotFoundException);

    /** 
     * Tests whether a given entry occurs in this binary tree.
     * @post The binary search tree is unchanged.
     * @param anEntry The entry to find.
     * @return True if the entry occurs in the tree, or false if not. 
     */
    bool contains(const T &anEntry) const;

    void print() const;

    void print(const T &node) const;

    /** 
     * Traverses this binary tree in preorder (inorder, postorder) and calls 
     * the function visit once for each node.
     * @param visit A client-defined function that performs an operation on 
     * or with the data in each visited node. 
     */
    void preorderTraverse(void visit(T &)) const;
    void inorderTraverse(void visit(T &)) const;
    void postorderTraverse(void visit(T &)) const;
};

#include "BinarySearchTree.cpp"