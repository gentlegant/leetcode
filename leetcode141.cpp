#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if(!head || !head->next)
            return false;
        auto fast=head->next;
        while (fast&&fast->next)
        {
            if(fast->next==head)
                return true;
            fast=fast->next->next;
            head=head->next;
        }
        return false;
        

    }
};