#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T entry;
    Node *next;
    Node *prev;
};

Node<int> *createLinkedList(int n)
{
    Node<int> *head = new Node<int>;
    int num;
    cin >> num;
    head->entry = num;
    head->next = NULL;
    head->prev = NULL;
    Node<int> *cur = head;

    for (int i = 1; i < n; i++)
    {
        Node<int> *newNode = new Node<int>;
        cin >> num;
        newNode->entry = num;
        newNode->next = NULL;
        newNode->prev = cur;
        cur->next = newNode;
        cur = newNode;
    }

    return head;
}

void reversePrint(Node<int> *head)
{
    if (head == NULL)
        return;

    Node<int> *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }

    while (cur != NULL)
    {
        cout << cur->entry << " ";
        cur = cur->prev;
    }
    cout << endl;
}

void freeLinkedList(Node<int> *head)
{
    Node<int> *cur = head;
    while (cur != NULL)
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

    Node<int> *head = createLinkedList(n);
    reversePrint(head);
    freeLinkedList(head);

    return 0;
}