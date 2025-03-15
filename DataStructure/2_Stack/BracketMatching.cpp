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

string Remove (const string &code)
{
    string result;
    bool Comment = false;
    for (int i = 0; i < (int)code.size(); ++i)
    {
        if (Comment)
        {
            if (code[i] == '*' && i + 1 < (int)code.size() && code[i + 1] == '/')
            {
                Comment = false;
                i++; 
            }
        }
        else
        {
            if (code[i] == '/' && i + 1 < (int)code.size())
            {
                if (code[i + 1] == '/')
                {
                    break; 
                }
                else if (code[i + 1] == '*')
                {
                    Comment = true;
                    i++; 
                }
                else
                {
                    result += code[i];
                }
            }
            else
            {
                result += code[i];
            }
        }
    }
    return result;
}


int main()
{
    string code;
    string line;
    while (getline(cin, line))
    {
        code += line + "\n";
    }
    code = Remove(code);
    int n = (int)code.size();
    int counts = 0;
    MyStack bracket;
    bool result = true;
    for (int i = 0; i < n; ++i)
    {
        if (code[i] == '{'||code[i] == '['||code[i] == '(')
        {
            counts++;
            bracket.push(code[i]);
        }
        else if (code[i] == '}'||code[i] == ']'||code[i] == ')')
        {
            counts++;
            if (bracket.empty() || (bracket.top() == '{' && code[i] != '}') || (bracket.top() == '[' && code[i] != ']') || (bracket.top() == '(' && code[i] != ')'))
            {
                result = false;
            }
            else
            {
                bracket.pop();
            }
        }
    }
    if (!bracket.empty())
    {
        result = false;
    }
    cout << counts << " ";
    if (result)
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    return 0;
}