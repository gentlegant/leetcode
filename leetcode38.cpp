
#include<iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string old="1",new_;
        for(int i=1;i<n;i++){
            //以下代码由old 得new_
        
            int begin=0;
            new_.clear();
      
            while(true){
                int tmp=begin;
                while(++tmp<old.size() && old[tmp]==old[begin]);
                new_.push_back(tmp-begin+'0');
                new_.push_back(old[begin]);
                if(tmp==old.size())
                    break;
                begin=tmp;

            }
    
            old=new_;
        }
        return old;
    }
};

int main(int argc, char const *argv[])
{

    Solution a;
    cout<<a.countAndSay(60);
    return 0;
}
