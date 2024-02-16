#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next{};
    Node *prev{};
    Node(int data) : data(data){};
    void set(Node *next, Node *prev)
    {
        this->next = next;
        this->prev = prev;
    }
};
class DLL
{
private:
    Node *tail{};
    Node *head{};
    int length = 0;

public:
    void link(Node *first, Node *second)
    {
        if (first)
        {
            first->next = second;
        }
        else
        {
            second->prev = first;
        }
    }
    void insert_end(int value)
    {
        Node *item = new Node(value);
        if (!head)
        {
            head = tail = item;
        }
        else
        {
            link(tail, item);
            tail = item;
        }
    }
    bool is_palindrome()
    {
        if (length <= 1)
            return true;
        Node *n1 = head;
        Node *n2 = tail;
        int len = length / 2;
        while (len--)
        {
            if (n1->data != n2->data)
                return false;
            n2 = n2->prev;
            n1 = n1->next;
        }
        return true;
    }
};
