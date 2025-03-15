#include <iostream>
#include <string>

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

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        MyStack stack;
        string s;
        bool result = true;
        cin >> s;
        for (int j = 0; j < (int)s.length(); j++){
            if (s[j] == 'I'){
                stack.push(1);
            }
            else if (s[j] == 'O' && stack.pop() == Underflow){
                result = false;
                continue;
            }
        }
        if (result){
            cout << "true" << endl;
        }
        else{
            cout << "false" << endl;
        }
    }
    return 0;
}