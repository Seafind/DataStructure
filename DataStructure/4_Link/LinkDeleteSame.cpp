#include <iostream>
#include <unordered_set>

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
    if (n == 0)
        return NULL;

    unordered_set<int> entries;
    Node<int> *head = new Node<int>;
    Node<int> *cur = head;

    cin >> head->entry;
    entries.insert(head->entry);

    for (int i = 1; i < n; i++)
    {
        int num;
        cin >> num;
        if (entries.find(num) == entries.end())
        {
            entries.insert(num);
            cur->next = new Node<int>;
            cur->next->entry = num;
            cur->next->prev = cur;
            cur = cur->next;
        }
    }
    cur->next = NULL;
    return head;
}

void printLinkedList(Node<int> *head)
{
    Node<int> *cur = head;
    while (cur != NULL)
    {
        cout << cur->entry << " ";
        cur = cur->next;
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
    printLinkedList(head);
    freeLinkedList(head);

    return 0;
}
