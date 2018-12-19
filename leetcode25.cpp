
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
   
        ListNode* first=head,*second=first->next,*third;
        while(--k){
            third=second->next;
            second->next=first;
            first=second;
            second=third;
        }

        head->next=third;
        return first;
    }
};