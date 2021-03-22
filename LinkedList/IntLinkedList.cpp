#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Traverses contents of linked list starting from the given node
void traverse(Node *head)
{
    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
}

// find the node by matching data number
Node *findNum(Node *head, int num)
{
    Node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
        if (curr->data == num)
        {
            return curr;
        }
    }
    return nullptr;
}

// Pre: index < size of the list
Node *nodeAt(Node *head, int index)
{
    Node *curr = head;
    int counter = 0;
    while (curr->next != nullptr)
    {
        curr = curr->next;
        counter++;

        if (counter == index)
        {
            return curr;
        }
    }
    return nullptr;
}

void deleteNode(Node *head, int num)
{
    Node *curr = head;
    // First traverse to the node before the node to be deleted.
    while (curr->next->next != nullptr || curr->data != num)
    {
        curr = curr->next;
    }
    Node *temp = curr->next->next;
    delete curr->next;
    curr->next = temp;
}

void insert(Node *head, Node *newNode, int index)
{
    Node *curr = head;

    if (index == 0)
    {
        newNode->next = head->next;
        head->next = newNode;
    }
    else
    {
        int counter = 0;
        // Find the node of where the new node to be added on the next place.
        while (curr->next != nullptr)
        {
            curr = curr->next;
            if (counter == index)
            {
                newNode->next = curr->next;
                curr->next = newNode;
            }
        }
    }
}

int main()
{
    // Creating head of the linked list
    Node *head = new Node;
    head->next = nullptr;

    Node *curr = head;

    // Treaverses the whole list
    traverse(head);

    // Insertion
    Node *newNode = new Node;
    insert(head, newNode, 0);

    // Inserting at the beginning of a list
}