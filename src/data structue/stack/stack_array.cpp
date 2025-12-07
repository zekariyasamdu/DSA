#include <iostream>
using namespace std;

class Stack
{
private:
    int top = 0;
    int arr[10] = {};

public:
    bool isFull()
    {
        if (top == 10)
            return true;
        return false;
    };

    bool isEmpty()
    {
        if (top == 0)
            return true;
        return false;
    };

    void pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty"<<endl;
            return;
        }
        int num = arr[top -1];
        arr[top -1 ] = 0;
        top--;
        cout << "Number: " << num << ", is removed"<<endl;
    };

    void push(int num)
    {
        if (isFull())
        {
            cout << "The stack is full"<<endl;
            return;
        }
        arr[top] = num;
        top++;
        cout << "Number: " << num << ", has been added"<<endl;
    };

    int size()
    {
        return top;
    };

    void clear()
    {
        for (int i = 0; i = top; i++)
        {
            arr[i] = 0;
        }
        top = 0;
        cout << "Stack emptied!"<<endl;
    };

    void display()
    {
        for (int i = 9; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    };
};

int main()
{
    Stack s;
    s.push(7);
    s.push(1);
    s.push(8);
    s.push(2);
    s.push(8);
    s.push(9);
    s.pop();
    s.display();
}
