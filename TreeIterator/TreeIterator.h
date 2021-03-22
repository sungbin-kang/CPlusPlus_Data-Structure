
/*
The first element of a subtree is always the leftmost one. The next element after an element is the first element of its right subtree. If the element does not have a right child, the next element is the element's first right ancestor. If the element has neither a right child nor a right ancestor, it is the rightmost element and it's last in iteration.

*/
#include <iostream>

using namespace std;

class TreeIterator
{
    struct Node
    {
        Node *next;
        Node *left;
        Node *right;
        Node *parent;
    };

private:
    Node *next;

public:
    TreeIterator(Node *root)
    {
        next = root;
        if (next == nullptr)
            return;

        while (next->left != nullptr)
            next = next->left;
    }

    bool hasNext()
    {
        return next != nullptr;
    }

    Node next()
    {
        if (!hasNext())
            //throw new NoSuchElementException();
        Node *r = next;

        // If you can walk right, walk right, then fully left.
        // otherwise, walk up until you come from left.
        if (next->right != nullptr)
        {
            next = next->right;
            while (next->left != nullptr)
                next = next->left;
            return *r;
        }

        while (true)
        {
            if (next->parent == nullptr)
            {
                next = nullptr;
                return *r;
            }
            if (next->parent->left == next)
            {
                next = next->parent;
                return *r;
            }
            next = next->parent;
        }
    }
};