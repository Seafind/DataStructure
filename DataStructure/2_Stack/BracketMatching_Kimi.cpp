#include <iostream>
#include <string>

using namespace std;

enum Type
{
    Underflow,
    Overflow,
    Success
};

#define MAX_SIZE 1600

class MyStack
{
public:
    MyStack() : count(0) {}

    Type push(char item)
    {
        if (count == MAX_SIZE)
            return Overflow;
        arr[count++] = item;
        return Success;
    }

    char pop()
    {
        if (count == 0)
            return Underflow;
        return arr[--count];
    }

    char top() const
    {
        if (count == 0)
            return Underflow;
        return arr[count - 1];
    }

    bool empty() const { return count == 0; }
    bool full() const { return count == MAX_SIZE; }
    int size() const { return count; }
    void clear() { count = 0; }

private:
    char arr[MAX_SIZE];
    int count;
};

void processNormalState(const string code, size_t i, string *result, int *state)
{
    char current = code[i];
    if (current == '"')
    {
        *state = 1;
        result->push_back(current);
    }
    else if (current == '/' && i + 1 < code.size())
    {
        if (code[i + 1] == '/')
        {
            *state = 2;
        }
        else if (code[i + 1] == '*')
        {
            *state = 3;
        }
        else
        {
            result->push_back(current);
        }
    }
    else
    {
        result->push_back(current);
    }
}

void processStringState(const string code, size_t i, string *result, int *state)
{
    result->push_back(code[i]);
    if (code[i] == '"' && (i == 0 || code[i - 1] != '\\'))
    {
        *state = 0;
    }
}

void processSingleCommentState(const string code, size_t i, int *state)
{
    if (code[i] == '\n')
    {
        *state = 0;
    }
}

void processMultiCommentState(const string code, size_t i, int *state)
{
    if (code[i] == '*' && i + 1 < code.size() && code[i + 1] == '/')
    {
        *state = 0;
    }
}

string Remove(const string &code)
{
    string result;
    int state = 0;

    for (size_t i = 0; i < code.size(); ++i)
    {
        switch (state)
        {
        case 0:
            processNormalState(code, i, &result, &state);
            break;
        case 1:
            processStringState(code, i, &result, &state);
            break;
        case 2:
            processSingleCommentState(code, i, &state);
            break;
        default:
            processMultiCommentState(code, i, &state);
            break;
        }
    }
    return result;
}

bool pushBracket(MyStack *bracket, char c)
{
    if (bracket->full())
        return false;
    bracket->push(c);
    return true;
}

bool popBracket(MyStack *bracket, char c)
{
    if (bracket->empty())
        return false;
    char top = bracket->pop();
    return (c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{');
}

bool isValidBracketSequence(const string code, int *count)
{
    MyStack bracket;

    for (char c : code)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            (*count)++;
            if (!pushBracket(&bracket, c))
                return false;
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            (*count)++;
            if (!popBracket(&bracket, c))
                return false;
        }
    }
    return bracket.empty();
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

    int counts = 0;
    bool result = isValidBracketSequence(code, &counts);

    cout << counts << " " << (result ? "yes" : "no") << endl;

    return 0;
}