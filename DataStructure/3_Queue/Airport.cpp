#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>

using namespace std;

typedef int MyQueueType;

#define MAX 120

enum States
{
    Empty,
    Full,
    Success
};

enum Plane_Status
{
    Null,
    Arriving;
    Departing
};

class MyQueue
{
public:
    MyQueue();
    States Append(MyQueueType item);
    States Serve();
    States Retrieve(MyQueueType *item);
    bool IsEmpty();
    bool IsFull();
    int Size();
    States Clear();

private:
    MyQueueType Queue[MAX];
    int front, rear, count;
    };

class Random
{
public:
    Random(bool pseudo = true);

private:
    int reseed();
    int seed, multiplier, add;
}

class Planes
{
    public:
        Planes();
        Planes(string id, int arrive_time, Plane_Status status)

}

MyQueue::MyQueue()
{
    front = count = 0;
    rear = (MAX - 1) % MAX;
}
States MyQueue::Append(MyQueueType item)
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

States MyQueue::Retrieve(MyQueueType *item)
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

Random::Random(bool pseudo)
{
    if (pseudo)
    {
        seed = 1;
    }
    else
    {
        seed = time(NULL) % INT_MAX;
        multiplier = 2743;
        add = 5923;
    }
}

int Random::reseed()
{
    seed = (multiplier * seed + add) % 2147483647;
    return seed;
}

double Random::random_real()
{
    double max = INT_MAX + 1.0;
    double temp = reseed();
    if (temp < 0)
        temp += max;
    return temp / max;
}

int Random::Poisson(double mean)
{
    double limit = exp(-mean);
    double product = random_real();
    int count = 0;
    while (product > limit)
    {
        product *= random_real();
        count++;
    }
    return count;
}
