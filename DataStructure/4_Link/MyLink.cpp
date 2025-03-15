#include <iostream>

using namespace std;

template <typename T>

struct Node
{
    T entry;
    Node *next;
};

Node<int> *createLinkedList(int n)
{
    Node<int> *head = new Node<int>;
    Node<int> *cur = head;

    int num;
    cin >> num;
    head->entry = num;

    for (int i = 1; i < n; i++)
    {
        cin >> num;
        cur->next = new Node<int>;
        cur = cur->next;
        cur->entry = num;
    }
    cur->next = NULL;

    return head;
}

int sumLinkedList(Node<int> *head)
{
    int sum = 0;
    while (head)
    {
        sum += head->entry;
        head = head->next;
    }
    return sum;
}

void freeLinkedList(Node<int> *head)
{
    Node<int> *cur = head;
    while (cur)
    {
        Node<int> *temp = cur;
        cur = cur->next;
        delete temp;
    }
}

int main()
{
    int n;
    cin >> n;
    if (n == 0) {
        cout << "0" << endl;
        return 0;
    }
        Node<int> *head = createLinkedList(n);
        cout << sumLinkedList(head) << endl;
        freeLinkedList(head);
        return 0;
}