
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
    //
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        auto * tmp=new ListNode(0);
        auto rem=tmp;
        tmp->next=head;
        while(tmp->next)
            tmp=reverse(tmp,k);
        return rem->next;
       
    }
private:
    //翻转start之后的k个节点(bu包含start)，并且返回k个之后的新的start
    //start 是头节点
    ListNode * reverse(ListNode *start,int k){
        ListNode *first = start, *second=first->next, *third;
 
        while (k--)
        {
            //遇到问题，修复链表
            if(!second){
                ListNode *before=nullptr,*now=first;
                while(now!=start){
                    auto rem=now->next;
                    now->next=before;
                    before=now;
                    now=rem;
                    
                }
                return first;
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
    auto a = new ListNode(1);
    auto b = new ListNode(2);
    auto c = new ListNode(3);
    auto d = new ListNode(4);
    auto e = new ListNode(5);
    auto f = new ListNode(6);
    auto g = new ListNode(7);
    auto h = new ListNode(8);
    

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next=f;
    f->next=g;
    g->next=h;    
    Solution cc;
    auto res = cc.reverseKGroup(a, 3);
    while (res)
    {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}




