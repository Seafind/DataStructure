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
    if (n == 0)
        return NULL;

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

void deleteLinkedList(Node<int> **head, int n) 
{
    Node<int> *prev = NULL; 
    Node<int> *cur = *head;

    while (cur)
    {
        if (cur->entry == n)
        {
            Node<int> *temp = cur;
            if (prev)
            {
                prev->next = cur->next; 
            }
            else
            {
                *head = cur->next; 
            }
            cur = cur->next;
            delete temp;
        }
        else
        {
            prev = cur; 
            cur = cur->next;
        }
    }
}

void printLinkedList(Node<int> *head)
{
    Node<int> *cur = head;
    while (cur)
    {
        cout << cur->entry << " ";
        cur = cur->next;
    }
    cout << endl;
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
    Node<int> *head = createLinkedList(n);
    int x;
    cin >> x;
    deleteLinkedList(&head, x);
    printLinkedList(head);
    freeLinkedList(head);
    return 0;
}