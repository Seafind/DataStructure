#include <iostream>
#include <cctype>

using namespace std;

enum Type
{
    Underflow,
    Overflow,
    Success
};

#define MAX_SIZE 120

class MyStack
{
public:
    MyStack();
    Type push(int item);
    int pop();
    int top() const;
    bool empty() const;
    bool full() const;
    int size() const;
    void clear();

private:
    int arr[MAX_SIZE];
    int count = 0;
};

MyStack::MyStack()
{
    count = 0;
}
Type MyStack::push(int item)
{
    if (count == MAX_SIZE)
    {
        return Overflow;
    }
    arr[count++] = item;
    return Success;
}
int MyStack::pop()
{
    if (count == 0)
    {
        return Underflow;
    }
    return arr[--count];
}
int MyStack::top() const
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
    char item;
    MyStack stack;
    while (scanf("%c", &item) == 1)
    {
        if (isdigit(item))
        {
            stack.push((int)(item - '0'));
        }
        else if (item =='\n'){
            break;
        }
        else
        {
            if (stack.size() < 2)
            {
                cout << "none" << endl;
                return 0;
            }
            int num1 = stack.pop();
            int num2 = stack.pop();
            switch (item)
            {
            case '+':
                stack.push(num2 + num1);
                break;
            case '-':
                stack.push(num2 - num1);
                break;
            case '*':
                stack.push(num2 * num1);
                break;
            case '/':
                if (num1 == 0)
                {
                    cout << "none" << endl;
                    return 0;
                }
                stack.push(num2 / num1);
                break;
            default:
                cout << "none" << endl;
                return 0;
            }
        }
    }
    if (stack.size() == 1)
    {
        cout << stack.pop() << endl;
    }
    else
    {
        cout << "none" << endl;
    }
    return 0;
}
