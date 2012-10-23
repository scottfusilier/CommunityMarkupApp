#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#ifndef NULL
#define NULL (0L)
#endif

class Photo;

class QueueArray
{
    private:
        static const int MAXSIZE = 10;
        int front;
        int rear;
        Photo *A[MAXSIZE];
    public:
        QueueArray();
        ~QueueArray();
        bool isFull();
        bool isEmpty();
        void enqueue(Photo *);
        Photo *dequeue();
        int queueCount();
};
#endif //QUEUEARRAY_H
