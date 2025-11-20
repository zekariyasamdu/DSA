#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queues
{
private:
    int front;
    int rear;
    int currentSize;
    int capacity;
    vector<T> arr;

public:
    Queues(int s) : arr(s)
    {
        front = 0;
        rear = 0;
        currentSize = 0;
        capacity = s;
    }
    void enqueue(T s)
    {
        if (isFull())
        {
            cout << "The queue is Full";
            return;
        }
        arr[rear] = s;
        rear++;
        currentSize++;
    }
    void dequeue(T s)
    {
        if (isEmpty())
        {
            cout << "The queue is empty";
            return;
        }
        currentSize--;
        front++;
    }
    bool isEmpty()
    {
        if (rear == front)
            return true;
        return false;
    }
    bool isFull()
    {
        if (rear == capacity)
            return true;
        return false;
    }
    T frontElement()
    {
        if(isEmpty()) return 0;
        return arr[front];
    }
    int size()
    {  
        return currentSize;
    }
};

int main()
{
    Queues<int> c(10);
    return 0;
}