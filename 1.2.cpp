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
    void find_middle()
    {
        int count = 0;
        if (length % 2 == 0)
        {
            for (Node *cur = head; cur; cur = cur->next)
            {
                ++count;
                if (count == length / 2)
                {
                    cout << cur->data << " " << cur->next->data;
                }
            }
        }
        else
        {
            for (Node *cur = head; cur; cur = cur->next)
            {
                ++count;
                if (count == length / 2)
                {
                    cout << cur->next->data;
                }
            }
        }
    }
};
