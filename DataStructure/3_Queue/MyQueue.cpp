#include <iostream>

using namespace std;

typedef int MyType;

#define MAX 120

enum States
{
    Empty,
    Full,
    Success
};

class MyQueue
{
public:
    MyQueue();
    States Append(MyType item);
    States Serve();
    States Retrieve(MyType *item);
    bool IsEmpty();
    bool IsFull();
    int Size();
    States Clear();
private:
    MyType Queue[MAX];
    int front, rear, count;
};

MyQueue::MyQueue()
{
    front = count = 0;
    rear = (MAX - 1) % MAX;
}
States MyQueue::Append(MyType item)
{
    if (count == MAX){
        return Full;
    }
    rear = (rear + 1) % MAX;
    Queue[rear] = item;
    count++;
    return Success;
}

States MyQueue::Serve()
{
    if (count == 0){
        return Empty;
    }
    front = (front + 1) % MAX;
    count--;
    return Success;
}

States MyQueue::Retrieve(MyType *item)
{
    if (count == 0){
        return Empty;
    }
    *item = Queue[front];
    return Success;
}

bool MyQueue::IsEmpty()
{
    return count == 0;
}

bool MyQueue::IsFull()
{
    return count == MAX;
}

int MyQueue::Size()
{
    return count;
}

States MyQueue::Clear()
{
    front = count = 0;
    rear = (MAX - 1) % MAX;
    return Success;
}

int main (){
    MyQueue CirQueue;
    while (true){
        int item;
        cin >> item;
        if (item == -1){
            break;
        }
        CirQueue.Append(item);
    }
    while (!CirQueue.IsEmpty()){
        int item;
        CirQueue.Retrieve(&item);
        CirQueue.Serve();
        cout << item << " ";
    }
    cout << endl;
    return 0;
}