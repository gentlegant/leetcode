// 链表区间逆序

// Description

// 将单个链表的每K个节点之间逆序，打印出新链表；最后不足K的节点数不需要逆序；要求时间复杂度为O(n)，额外空间复杂度为O(1)。

// Input

// 输入的每一行的值用空格隔开，第一个表示链表长度，中间为节点值，最后代表K。

// Output

// 输出的每一行为新的链表，节点值用空格隔开，末尾不要空格。

// Sample Input 1

// 8 1 2 3 4 5 6 7 8 3
// 8 a b c d e f g h 4

// Sample Output 1

// 3 2 1 6 5 4 7 8
// d c b a h g f e


#include <iostream>
#include<sstream>
using namespace std;

struct ListNode
{
    char val;
    ListNode *next;
    ListNode(char x) : val(x), next(NULL) {}
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
ListNode* readinput(stringstream &in, int &n){
    int t;
    in>>t;
    ListNode *tmp=new ListNode(0),*ret=tmp;
    
    while(t--){
        char tt;
        in>>tt;
        tmp->next=new ListNode(tt);
        tmp=tmp->next;
    }
    in>>n;
    return ret->next;
}
int main(int argc, char const *argv[])
{
    Solution sol;
    string s;
   
    while(true){
        getline(cin,s);
        if(s.empty())
            break;
        stringstream sss(s);
        int n;
        auto res=readinput(sss,n);
        if(res==NULL){
            break;
        }
        auto res1=sol.reverseKGroup(res,n);
     
        while(res1->next){
            cout<<res1->val<<" ";
            res1=res1->next;
        }
        cout<<res1->val;
        cout<<endl;
    }
    
    return 0;
}




