#include <iostream>
#include "queuearray.h"

QueueArray::QueueArray()
{
    front = rear = -1;
}

QueueArray::~QueueArray()
{
}

bool QueueArray::isFull()
{
    return ((rear + 1) % MAXSIZE == front);
}

bool QueueArray::isEmpty()
{
    return (front == -1);
}

void QueueArray::enqueue(Photo *item)
{
    if(!isFull())
    {
        A[(rear+1) % MAXSIZE] = item;
        rear = (rear+1) % MAXSIZE;
        if(front == -1)
            front = 0;
        std::cout<<"Photo stored in queue.\n";
    }
    else
        std::cout<<"queue full...\n";
}

Photo *QueueArray::dequeue()
{
    Photo *item;
    item = NULL;
    if(!isEmpty())
    {
        bool flag = false;
        if(front == rear)
            flag = true;
        item = A[front];
        front = (front +1)% MAXSIZE;
        if(flag)
            front = rear = -1;
        std::cout<<"Photo dequeued from queuearray\n";
    }
    return item;
}

