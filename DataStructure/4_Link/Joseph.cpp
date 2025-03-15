#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T entry;
    Node *next;
};

Node<int> *createCircle(int n)
{
    if (n == 0)
        return NULL;

    Node<int> *head = new Node<int>{1, NULL};
    Node<int> *cur = head;

    for (int i = 2; i <= n; i++)
    {
        cur->next = new Node<int>{i, NULL};
        cur = cur->next;
    }

    cur->next = head;
    return head;
}

int deleteCircle(Node<int> *&head, int step)
{
    if (head == NULL)
        return head->entry;

    Node<int> *cur = head;
    Node<int> *prev = cur;

    while (cur->next != cur)
    {
        for (int i = 0; i < step - 1; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        Node<int> *temp = cur->next;
        delete cur;
        cur = temp;
    }
    int ans = cur->entry;
    delete cur;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    Node<int> *head = createCircle(n);
    int m;
    cin >> m;
    if (m == 1)
        cout << n << endl;
    else
        cout << deleteCircle(head, m) << endl;
    return 0;
}
