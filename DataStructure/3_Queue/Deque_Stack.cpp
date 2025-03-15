#include <iostream>

using namespace std;

typedef char MyStackType;

enum Type
{
    Underflow,
    Overflow,
    Success
};

#define MAX_SIZE 1000

class MyStack
{
public:
    MyStack();
    Type push(MyStackType item);
    MyStackType pop();
    MyStackType top() const;
    bool empty() const;
    bool full() const;
    int size() const;
    void clear();

private:
    MyStackType arr[MAX_SIZE];
    int count = 0;
};

MyStack::MyStack()
{
    count = 0;
}
Type MyStack::push(MyStackType item)
{
    if (count == MAX_SIZE)
    {
        return Overflow;
    }
    arr[count++] = item;
    return Success;
}
MyStackType MyStack::pop()
{
    if (count == 0)
    {
        return Underflow;
    }
    return arr[--count];
}
MyStackType MyStack::top() const
{
    if (count == 0)
    {
        return Underflow;
    }
    return arr[count - 1];
}
bool MyStack::empty() const
{
    return count == 0;
}
bool MyStack::full() const
{
    return count == MAX_SIZE;
}
int MyStack::size() const
{
    return count;
}
void MyStack::clear()
{
    count = 0;
}

int main()
{
    int n;
    MyStack S;
    cin >> n;
    char item;
    while (cin >> item)
    {
        S.push(item);
    }
    for (int i = 0; (i < n) && (!S.empty()); i++)
    {
        cout << S.pop() << " ";
    }
    cout << endl;
    return 0;
}