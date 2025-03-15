#include <iostream>

using namespace std;

typedef int MyType;

enum Type
{
    Underflow,
    Overflow,
    Success
};

#define MAX_SIZE 120

class MyStack {
    public:
        MyStack();
        Type push(MyType item);
        MyType pop();
        MyType top() const;
        bool empty() const;
        bool full() const;
        int size() const;
        void clear();
    private:
        MyType arr[MAX_SIZE];
        int count = 0;
};

MyStack::MyStack(){
    count = 0;
}
Type MyStack::push(MyType item){
    if (count == MAX_SIZE)
    {
        return Overflow;
    }
    arr[count++] = item;
    return Success;
}
MyType MyStack::pop()
{
    if (count == 0)
    {
        return Underflow;
    }
    return arr[--count];
}
MyType MyStack::top() const
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
MyType MyStack::size() const
{
    return count;
}
void MyStack::clear()
{
    count = 0;
}

int main(){
    MyStack stack;
    MyType n;
    while (cin >> n && n != -1){
        stack.push(n);
    }
    while (!stack.empty()){
        cout << stack.pop() << " ";
    }
    cout << endl;
    return 0;
}