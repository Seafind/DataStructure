#include <iostream>

using namespace std;

enum ErrorState
{
    Overload,
    Underload,
    Success
};

template <typename T>
struct Node
{
    T entry;
    Node<T> *next;
};

template <typename T>
class LinkedStack
{
public:
    LinkedStack();
    ErrorState push(T entry);
    ErrorState pop();
    ErrorState top(T *item);
    bool isEmpty() const;
    int size() const;
    void clear();
    ~LinkedStack();

private:
    Node<T> *topNode;
    int count;
};

template <typename T>
LinkedStack<T>::LinkedStack()
{
    topNode = NULL;
    count = 0;
}

template <typename T>
ErrorState LinkedStack<T>::push(T entry)
{
    if (newNode == NULL)
    {
        return Overload;
    }
    Node<T> *newNode = new Node<T>{entry, topNode};
    topNode = newNode;
    count++;
    return Success;
}

template <typename T>
ErrorState LinkedStack<T>::pop()
{
    if (isEmpty())
    {
        return Underload;
    }
    Node<T> *temp = topNode;
    topNode = topNode->next;
    delete temp;
    count--;
    return Success;
}

template <typename T>
ErrorState LinkedStack<T>::top(T *item)
{
    if (isEmpty())
    {
        return Underload;
    }
    *item = topNode->entry;
    return Success;
}

template <typename T>
bool LinkedStack<T>::isEmpty() const
{
    return topNode == NULL;
}

template <typename T>
int LinkedStack<T>::size() const
{
    return count;
}

template <typename T>
void LinkedStack<T>::clear()
{
    while (!isEmpty())
    {
        pop();
    }
    count = 0;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    clear();
}

int main()
{
    LinkedStack<int> stack;
    while (true)
    {
        int item;
        cin >> item;
        if (item == -1)
        {
            break;
        }
        else
        {
            stack.push(item);
        }
    }
    while (!stack.isEmpty())
    {
        int item;
        stack.top(&item);
        cout << item << " ";
        stack.pop();
    }
    cout << endl;
    return 0;
}