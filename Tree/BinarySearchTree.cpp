
// template<typename T>
// BinarySearchTree<T>::


template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

template<typename T>
bool BinarySearchTree<T>::isEmpty() const
{
    return false;
}

template<typename T>
int BinarySearchTree<T>::getHeight() const
{
    return -1;
}

template<typename T>
int BinarySearchTree<T>::getNumberOfNodes() const
{
    return -1;
}

template<typename T>
T BinarySearchTree<T>::getRootData() const
{
    return T;
}

template<typename T>
void BinarySearchTree<T>::setRootData(const T &newData)
{

}

template<typename T>
bool BinarySearchTree<T>::add(const T &newData) 
{
    return false;
}

template<typename T>
bool BinarySearchTree<T>::remove(const T &data)
{
    return false;
}

template<typename T>
void BinarySearchTree<T>::clear() 
{

}

template<typename T>
T BinarySearchTree<T>::getEntry(const T &anEntry) const //throw(NotFoundExecption)
{
    return T;
}

template<typename T>
bool BinarySearchTree<T>::contains(const T &anEntry) const
{
    return false;
}

// ==========================================================================

template<typename T>
void BinarySearchTree<T>::print() const
{
    inorderTraverse(print(root));
}

template<typename T>
void BinarySearchTree<T>::print(const T &node) const
{
    cout << node->item << endl;    
}


template<typename T>
void BinarySearchTree<T>::preorderTraverse(void visit(T &)) const
{
    preorderTraverse(visit(T->left));
    preorderTraverse(visit(T->right));
    visit(T);
}

template<typename T>
void BinarySearchTree<T>::inorderTraverse(void visit(T &)) const
{
    inorderTraverse(visit(T->left));
    visit(T);
    inorderTraverse(visit(T->right));
}

template<typename T>
void BinarySearchTree<T>::postorderTraverse(void visit(T &)) const
{

}