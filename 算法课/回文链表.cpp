// # 链表回文

// # Description

// # 判断一个单向链表是否为回文结构。自定义链表数据结构，要求时间复杂度为O(n)，额外空间复杂度为O(1)。

// # Input

// # 输入的每一行的值用空格隔开，第一个值为节点个数，后面为每一个节点值

// # Output

// # 是回文则输出true，不是则输出false，一行表示一个链表的结果。

// # Sample Input 1

// # 3 1 2 1
// # 4 1 2 2 1
// # 3 3 5 3
// # 6 a b c d c a

// # Sample Output 1

// # true
// # true
// # true
// # false

#include<iostream>
#include <sstream>
using namespace std;

class LinkList{
public:
    char val;
    LinkList *next;
    LinkList(char v){
        val=v;
        next=nullptr;
    }
};

LinkList* readinput(stringstream& s,int &n){
    LinkList *res=new LinkList(0);
    auto temp=res;
    s>>n;
    auto nn=n;
    while(nn--){
        char tmp;
        s>>tmp;
        temp->next=new LinkList(tmp);
        temp=temp->next;
    }
    return res;
}
bool solve(LinkList *node,int n){
    int half=n/2;
    LinkList* first=nullptr,*second=node->next,*third;
    while(half--){  
        third=second->next;
        second->next=first;
        first=second;
        second=third;
    }
    auto tmp1=first,tmp2=n%2==1?second->next:second;
    while(tmp1&&tmp2){
        if(tmp1->val!=tmp2->val)
            return false;
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s;
    
    while(getline(cin,s)){
        stringstream sss(s);
        int n;
        auto a=readinput(sss,n);
        cout<<(solve(a,n)?"true\n":"false\n");
    }
    
    return 0;
}
