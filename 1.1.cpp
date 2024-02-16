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
    void embed_after(Node *node_before, int value)
    {
        Node *item = new Node(value);
        Node *node_after = node_before->next;
        ++length;
        link(node_before, item);
        link(item, node_after);
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
    void insert_front(int value)
    {
        Node *item = new Node(value);
        if (!head)
        {
            head = tail = item;
        }
        else
        {
            link(item, head);
            head = item;
        }
    }
    void insert_sroted(int value)
    {
        if (!length || value <= head->data)
        {
            insert_front(value);
        }
        else if (value >= tail->data)
        {
            insert_end(value);
        }
        else
        {
            for (Node *item = head; item; item = item->next)
            {
                if (value <= item->data)
                {
                    embed_after(item->prev, value);
                    break;
                }
            }
        }
    }
    void delete_front()
    {
        if (!head)
            return;
        Node *cur = head->next;
        delete (head);
        head = cur;
        if (head)
        {
            head->prev = nullptr;
        }
        else if (!length)
        {
            tail = nullptr;
        }
    }
    void delete_end()
    {
        if (!head)
            return;
        Node *cur = tail->prev;
        delete (tail);
        --length;
        tail = cur;
        if (tail)
        {
            tail->next = nullptr;
        }
        else if (!length)
        {
            tail = nullptr;
        }
    }
    Node *delete_and_link(Node *cur)
    {
        Node *ret = cur->prev;
        link(cur->prev, cur->next);
        delete (cur);
        return ret;
    }
    void delete_node_with_key(int value)
    {
        if (!length)
            return;
        Node *item = head;
        while (item != nullptr)
        {
            for (Node *cur = head; cur; cur = cur->next)
            {
                if (cur->data == value)
                {
                    cur = delete_and_link(cur);
                    if (!cur->next)
                        tail = cur;
                }
            }
            item = item->next;
        }
    }
};
