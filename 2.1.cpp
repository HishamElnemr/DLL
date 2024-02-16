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
        Node *delete_and_link(Node *cur)
    {
        Node *ret = cur->prev;
        link(cur->prev, cur->next);
        delete (cur);
        return ret;
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

    void delete_even()
    {
        if (length <= 1)
        {
            return;
        }
        else
        {
            for (Node *cur = head; cur; cur = cur->next)
            {
                delete_and_link(cur);
                cur = cur->next;
                if (!cur->next)
                {
                    tail = cur;
                }
            }
        }
    }
};
