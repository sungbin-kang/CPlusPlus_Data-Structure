#include "Queue.h"

class QueueTest
{
public:
    void test()
    {
        Queue<int> testQ;

        Queue<int>::QueueNode *qn1 = new Queue<int>::QueueNode();
        qn1->item = 1;

        Queue<int>::QueueNode *qn2 = new Queue<int>::QueueNode();
        qn2->item = 2;

        Queue<int>::QueueNode *qn3 = new Queue<int>::QueueNode();
        qn3->item = 3;

        qn1->next = qn2;
        qn2->next = qn3;

        testQ.frontPtr = qn1;
        testQ.frontPtr = qn3;
    }

};

int main()
{
    QueueTest qt;

    qt.test(); 
    cout << "test." << endl;

    return 0;

}