#include <iostream>
#include <vector>
#include <string>

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
    MyQueue() : front(0), rear(-1), count(0) {}

    States Append(MyType item)
    {
        if (count == MAX)
            return Full;
        rear = (rear + 1) % MAX;
        Queue[rear] = item;
        count++;
        return Success;
    }

    States Serve()
    {
        if (count == 0)
            return Empty;
        front = (front + 1) % MAX;
        count--;
        return Success;
    }

    States Retrieve(MyType *item)
    {
        if (count == 0)
            return Empty;
        *item = Queue[front];
        return Success;
    }

    bool IsEmpty() { return count == 0; }

    bool IsFull() { return count == MAX; }

    int Size() { return count; }

    States Clear()
    {
        front = 0;
        rear = -1;
        count = 0;
        return Success;
    }

private:
    MyType Queue[MAX];
    int front, rear, count;
};

void Enqueue(MyQueue *teamQueues, MyQueue &mainQueue, int teamid, int peopleid)
{
    teamid--;
    teamQueues[teamid].Append(peopleid);

    if (mainQueue.IsEmpty() || mainQueue.Size() == 0)
    {
        mainQueue.Append(teamid);
    }
    else
    {
        MyType frontTeam;
        mainQueue.Retrieve(&frontTeam);
        if (frontTeam != teamid)
        {
            mainQueue.Append(teamid);
        }
    }
}

void Dequeue(MyQueue *teamQueues, MyQueue &mainQueue)
{
    if (!mainQueue.IsEmpty())
    {
        MyType frontTeam;
        mainQueue.Retrieve(&frontTeam);
        MyType person;
        if (teamQueues[frontTeam].Retrieve(&person) == Success)
        {
            cout << person << endl;
            teamQueues[frontTeam].Serve();
            if (teamQueues[frontTeam].IsEmpty())
            {
                mainQueue.Serve();
            }
        }
    }
}

void Countseni(int teamCount)
{
    MyQueue teamQueues[teamCount];
    MyQueue mainQueue;

    string Mode;
    while (true)
    {
        cin >> Mode;
        if (Mode == "ENQUEUE")
        {
            int teamid, peopleid;
            cin >> teamid >> peopleid;
            Enqueue(teamQueues, mainQueue, teamid, peopleid);
        }
        else if (Mode == "DEQUEUE")
        {
            Dequeue(teamQueues, mainQueue);
        }
        else if (Mode == "STOP")
        {
            break;
        }
    }
}

int main()
{
    int scenariocount = 1;
    int team;
    while (cin >> team)
    {
        if (team == 0)
            break;
        cout << "Scenario #" << scenariocount++ << endl;
        Countseni(team);
        cout << endl;
    }
    return 0;
}