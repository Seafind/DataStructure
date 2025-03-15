#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef char MyType;

#define MAX 1000

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
    if (count == MAX)
    {
        return Full;
    }
    rear = (rear + 1) % MAX;
    Queue[rear] = item;
    count++;
    return Success;
}

States MyQueue::Serve()
{
    if (count == 0)
    {
        return Empty;
    }
    front = (front + 1) % MAX;
    count--;
    return Success;
}

States MyQueue::Retrieve(MyType *item)
{
    if (count == 0)
    {
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

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        MyQueue q;
        char mode;
        string s;
        getline(cin, s);
        int len = s.length();
        for (int j = 0; j < len; j++)
        {
            q.Append(s[j]);
        }
        int left = 0, right = 0;
        bool HaveColon = false;
        string leftstr, rightstr;
        while (!q.IsEmpty())
        {
            char c;
            q.Retrieve(&c);
            if (c == ':')
            {
                HaveColon = true;
            }
            else if (!HaveColon)
            {
                left++;
                leftstr += c;
            }
            else
            {
                right++;
                rightstr += c;
            }
            q.Serve();
        }
        if (left == right)
        {
            if (leftstr == rightstr)
            {
                mode = 'S';
            }
            else
            {
                mode = 'D';
            }
        }
        else if ((left > right) && HaveColon)
        {
            mode = 'L';
        }
        else if ((left < right) && HaveColon)
        {
            mode = 'R';
        }
        else
        {
            mode = 'N';
        }
        cout << mode << endl;
    }
    return 0;
}