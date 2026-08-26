#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (!head || !head->next || k == 0)
            return head;

        int n = 1;
        ListNode *tail = head;

        while (tail->next)
        {
            tail = tail->next;
            n++;
        }

        k = k % n;

        if (k == 0)
            return head;

        tail->next = head;

        int steps = n - k;

        while (steps--)
        {
            tail = tail->next;
        }

        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};

int main()
{
    // testing code goes here
}