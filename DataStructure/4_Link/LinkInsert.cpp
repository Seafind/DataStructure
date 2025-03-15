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

void insertIntoLinkedList(Node<int> *&head, int x, int y)
{
    Node<int> *cur = head;
    Node<int> *prev = NULL;
    int count = 0; 

    while (cur)
    {
        count++;
        if (cur->entry == x)
        {
            Node<int> *newNode = new Node<int>;
            newNode->entry = y;
            newNode->next = cur->next; 
            cur->next = newNode;       

            cout << count << " ";
        }

        prev = cur;
        cur = cur->next;
    }
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
    int x, y;
    cin >> x >> y;
    insertIntoLinkedList(head, x, y);
    freeLinkedList(head);
    return 0;
}