#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class queues_circular
{
private:
    int front;
    int rear;
    int capcity;
    int currentSize;
    vector<T> arr;

public:
    queues_circular(int size) : arr(size)
    {
        front = 0;
        rear = 0;
        currentSize = 0;
        capcity = size;
    };

    void enqueue(T val)
    {
        if (is_full())
            return;
        arr[rear] = val;
        rear = (rear + 1) % capcity;
        currentSize++;
    }

    void dequeue()
    {
        if (is_empty())
            return;
        if (front == capcity - 1)
        {
            front = 0;
        }
        arr[front] = 0;
        front = (front + 1 ) % capcity;
        currentSize--;
    }

    bool is_full()
    {
        if (capcity == currentSize)
            return true;
        return false;
    }

    bool is_empty()
    {
        if (currentSize == 0)
            return true;
        return false;
    }

    int get_size()
    {
        return currentSize;
    }
};

int main()
{
    queues_circular<int> qc(10);
    return 0;
}