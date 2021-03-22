#include <iostream>

using namespace std;

struct Node
{
    string data;
    Node *left;
    Node *right;
};

int inorderNodeCount(const Node *node)
{
    if (node == nullptr)
    {
        return 0;
    } 
    else
    {
        return inorderNodeCount(node->left) + 1 + inorderNodeCount(node->right);
    }
    
}

int preorderNodeCount(const Node *node)
{
    if (node == nullptr)
    {
        return 0;
    } 
    else
    {
        return 1 + preorderNodeCount(node->left) + preorderNodeCount(node->right);
    }
    
}

string inorderNodeRead(const Node *node)
{
    if (node == nullptr)
    {
        return "";
    }
    else
    {
        return node->data + " " + inorderNodeRead(node->left) + " " + inorderNodeRead(node->right);
    } 
}

string inorderNodeRead2(const Node *node)
{
    if (node == nullptr)
    {
        return "";
    }
    else if (node->left == nullptr && node->right == nullptr)
    {
        return node->data;
    }
    else if (node->right == nullptr)
    {
        return node->data + " " + inorderNodeRead2(node->left);
    } 
    else if (node->left == nullptr)
    {
        return node->data + " " + inorderNodeRead2(node->right);
    } 
    else
    {
        return node->data + " " + inorderNodeRead2(node->left) + " " + inorderNodeRead2(node->right);
    }
    
}

string inorderNodeRead3(const Node *node)
{
    if (node == nullptr)
    {
        return " ";
    }
    else
    {
        return node->data + inorderNodeRead3(node->left) + inorderNodeRead3(node->right);
    } 
}

int main()
{

    Node *n2 = new Node();
    n2->data = "2";

    Node *n1 = new Node();
    n1->data = "1";

    Node *n3 = new Node();
    n3->data = "3";

    Node *n4 = new Node();
    n4->data = "4";

    Node *n5 = new Node();
    n5->data = "5";

    Node *n6 = new Node();
    n6->data = "6";

    n2->left = n1;
    n2->right = n3;
    n1->right = n5;
    n3->left = n6;
    n3->right = n4;

    //     2
    //   /    \
    //  1      3
    //   \    / \
    //    5  6   4

    cout << "Inorder count: " << inorderNodeCount(n2) << endl;

    cout << "Preorder count: " << preorderNodeCount(n2) << endl;

    cout << "Inorder read without space condition 1:\t" << inorderNodeRead(n2) << endl;

    cout << "Inorder read with space condition 2:\t" << inorderNodeRead2(n2) << endl;

    cout << "Inorder read with space condition 3:\t" << inorderNodeRead3(n2) << endl;


    return 0;
}