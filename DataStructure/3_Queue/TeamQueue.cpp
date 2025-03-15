#include <iostream>
#include <vector>

using namespace std;

typedef int MyType;

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
    int team;
    while (cin >> team)
    {
        if (team == 0){
            break;
        }
        int count = 1;
        cout << "Scenario #" << count++ << ":" << endl;
        vector<MyQueue> teams(team);
        vector<int> teamids(team);
        string Mode;
        while (true)
        {
            cin >> Mode;
            if (Mode == "ENQUEUE")
            {
                int team, id;
                cin >> team >> id;
                teamids[team - 1] = id;
                teams[id - 1].Append(id);
            }
            else if (Mode == "DEQUEUE")
            {
                int id;
                for (int i = 0; i < team; i++)
                {
                    if (!teams[teamids[i] - 1].IsEmpty())
                    {
                        teams[teamids[i] - 1].Serve();
                        teams[teamids[i] - 1].Retrieve(&id);
                        cout << id << endl;
                    }
                }
            }
            else if (Mode == "STOP")
            {
                break;
            }
        }
        cout << endl;
    }
    return 0;
}