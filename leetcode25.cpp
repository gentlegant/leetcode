
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        auto * tmp=new ListNode(0);
        auto rem=tmp;
        tmp->next=head;
      
        while(tmp)
            tmp=reverse(tmp,k);
        return rem->next;
       
    }
    //翻转start之后的k个节点，并且返回k个之后的新的start
    //start 是头节点
    ListNode * reverse(ListNode *start,int k){
        ListNode *first = start, *second=first->next, *third;
 
        while (k--)
        {
            //遇到问题，修复链表
            if(!second){
                start->next=first;
                return nullptr;
            }
            third = second->next;
          

            second->next = first;
            first = second;
            second = third;
        }
        auto rem=start->next;
        start->next=first;
        rem->next=second;
        return rem;
    }
};

int main(int argc, char const *argv[])
{
    auto a = new ListNode(3);
    auto b = new ListNode(4);
    auto c = new ListNode(5);
    auto d = new ListNode(6);
    auto e = new ListNode(7);
    e->next=new ListNode(8);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Solution cc;
    auto res = cc.reverseKGroup(a, 4);
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}




