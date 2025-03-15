// 队列: 在链表头serve, 尾append

#include <iostream>

using namespace std;

enum ErrorState
{
    Overload,
    Underload,
    Success
};

struct Node
{
    int entry;
    Node *next;
};

template <typename T>
class LinkedQueue
{
public:
    LinkedQueue();
    ErrorState append(T entry);
    ErrorState serve();
    ErrorState retrieve(T *entry);
    bool isEmpty();
    int size();
    void clear();
    ~LinkedQueue();

private:
    Node *head;
    Node *tail;
    int count;
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

template <typename T>
ErrorState LinkedQueue<T>::append(T entry)
{
    Node *newNode = new Node{entry, NULL};
    if (newNode == NULL)
    {
        return Overload;
    }
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        count++;
        return Success;
    }
    tail->next = newNode;
    tail = newNode;
    count++;
    return Success;
}

template <typename T>
ErrorState LinkedQueue<T>::serve()
{
    if (head == NULL)
    {
        return Underload;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    count--;
    return Success;
}

template <typename T>
ErrorState LinkedQueue<T>::retrieve(T *entry)
{
    if (head == NULL)
    {
        return Underload;
    }
    *entry = head->entry;
    return Success;
}

template <typename T>
bool LinkedQueue<T>::isEmpty()
{
    return (head == NULL);
}

template <typename T>
int LinkedQueue<T>::size()
{
    return count;
}

template <typename T>
void LinkedQueue<T>::clear()
{
    Node *temp = head;
    while (temp!= NULL)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    clear();
}

int main(){
    LinkedQueue<int> queue;
    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        queue.append(n);
    }
    while (!queue.isEmpty())
    {
        int n;
        queue.retrieve(&n);
        cout << n << " ";
        queue.serve();
    }
    return 0;
}
