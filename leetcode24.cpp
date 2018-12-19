// 24. Swap Nodes in Pairs
// Medium

// Given a linked list, swap every two adjacent nodes and return its head.

// Example:

// Given 1->2->3->4, you should return the list as 2->1->4->3.

// Note:

//     Your algorithm should use only constant extra space.
//     You may not modify the values in the list's nodes, only nodes itself may be changed.
#include <vector>
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto temp=new ListNode(0);
        temp->next=head;
        auto tmp=temp;
        while(tmp->next&&tmp->next->next){
            auto second=tmp->next;
            tmp->next=second->next;
            second->next=second->next->next;
            tmp->next->next=second;
            tmp=second;
        }
        return temp->next;
    }
};