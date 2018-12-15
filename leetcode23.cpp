// 23. Merge k Sorted Lists
// Hard

// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

// /**
//  * Definition for singly-linked list.
//  *  

//此题采用败者树 来记录败者，时间复杂度可以达到log k *(N)  N是总节点数
//思路：归并排序
#include <vector>
#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

    //losertrees记录败者下标
    //winner记录胜者下标
    //number记录初始数组
    vector<int> losertree;
    vector<int> winner;
    vector<int> numbers;
    int getN(vector<ListNode*>& lists,int n){
        if(!lists[n])
            return INT32_MAX;
        int rem=lists[n]->val;
        lists[n]=lists[n]->next;
        numbers[n]=rem;
        return rem;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        ListNode *head=new ListNode(0);
        auto temp=head;
        losertree.assign(2*k-1,0);
        winner.assign(2*k-1,0);
        numbers.assign(k,0);
        for(int i=0;i<k;i++){
            getN(lists,i);
            losertree[k-1+i]=i;
            winner[k-i+1]=i;
        }
        for(int i=k-2;i>=0;i--){
            int left=winner[2*i+1];
            int right=winner[2*i+2];
            if(numbers[left]>numbers[right]){
                winner[i]=right;
                losertree[i]=left;
            }
            else{
                winner[i]=left;
                losertree[i]=right;
            }
        }
        //至此败者树已建立完毕，winner 作为临时变量不再使用
        //win表示胜者得下标
        int win=winner[0];
 
        while(numbers[win]!=INT32_MAX) {
            temp->next=new ListNode(numbers[win]);
            temp=temp->next;
            getN(lists,win);
     
            //从win往上遍历，tmp是win对应的值，win是下标
            for(int up=win;up!=0 ;up=(up-1)/2){
                //父节点记录了败者
                //tmp是新来的数，win是其下标
                if(numbers[losertree[up]]<numbers[win])
                                   
                    swap(win,losertree[up]);
            }





        }

        return head->next;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    ListNode *tmp=new ListNode(5);
    tmp->next=new ListNode(7);
    ListNode *tmp1=new ListNode(3);
    tmp1->next=new ListNode(6);
    vector<ListNode*> vc={tmp,tmp1};
    Solution a;
    cout<<1;
    auto b=a.mergeKLists(vc);
    cout<<3;
    while(b){

        cout<<b->val;
        b=b->next;
    }
    return 0;
}
