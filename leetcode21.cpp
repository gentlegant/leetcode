#include<iostream>


using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(-1);
        auto tmp=head;
        while(l1 &&l2){
            if(l1->val<l2->val){
                tmp->next=new ListNode(l1->val);
                l1=l1->next;
                tmp=tmp->next;
            }
            else if(l1->val>l2->val){
                tmp->next=new ListNode(l2->val);
                l2=l2->next;
                tmp=tmp->next;
            }
            else{
                tmp->next=new ListNode(l1->val);
                l1=l1->next;
                tmp=tmp->next;
                tmp->next=new ListNode(l2->val);
                l2=l2->next;
                tmp=tmp->next;
            }
        }
        if(l1)
            tmp->next=l1; 
        if(l2)
            tmp->next=l2;
        return head->next;
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
