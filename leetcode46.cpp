#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum dir {mid,left,right};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         int len=nums.size();
  
//         vector<dir> flag(len,dir::left);
//         vector<int> map(len,0);
//         for(int i=0;i<len;i++)
//             map[i]=i;
//         flag[0]=dir::mid;
//         vector<vector<int>> res;
//         while(true){
//             res.push_back(nums);
  
//             auto it=map.rbegin();
//             int index;
//             for(;it!=map.rend();it++){
//                 int x=*it;
//                 if(flag[x]!=dir::mid)
//                     index=x;
//             }

//             if(it==flag.rend())
//                 break;

//             int m=nums[index];
     
//             if(*it==dir::left){
//                 swap(nums[index],nums[index-1]);
//                 swap(flag[index],flag[index-1]);
//                 swap(map[index],map[index-1]);
//             }
//             else{
//                 swap(nums[index],nums[index+1]);
//                 swap(flag[index],flag[index+1]);
//                 swap(map[index],map[index+1]);
//             }
           
//             if(flag.front()==dir::left)
//                 flag.front()=dir::mid;
//             if(flag.back()==dir::right)
//                 flag.back()=dir::mid;
//             for(auto tmp=index-1;tmp!=-1;tmp--)
//                 if(nums[tmp]>m&&flag[tmp]==dir::mid)
//                     flag[tmp]=dir::right;
//             for(auto tmp=index+1;tmp!=len;tmp++)
//                 if(nums[tmp]>m&&flag[tmp]==dir::mid)
//                     flag[tmp]=dir::left;
//             for_each(nums.begin(),nums.end(),[](int x){cout<<x<<" ";});
//             cout<<endl;
//             for_each(flag.begin(),flag.end(),[](int x){cout<<x<<" ";});
//             cout<<endl;
//         }


//         return res;
//     }
// };
int jc(int a){
    int res=1;
    while(a!=1)
        res*=a--;
    return res;

}


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        //reverse(nums.begin(),nums.end());
        for(int i=0;i<jc(nums.size());i++){

            for(int j=0;j<nums.size();j++){
                if(j+nums[j]!=nums.size())
                {
                reverse(nums.begin(),nums.begin()+j+1);
                vector<int> copy_(nums.begin(),nums.begin()+j+1);
                nums.erase(nums.begin(),nums.begin()+j+1);
         
                copy(copy_.begin(),copy_.end(),back_inserter(nums));
      
                break;
                }


            }
            auto a=nums;
            res.push_back(a); 




        }
        return res;


    }
};
int main(){
    vector<int> vc={1,2,3,4,5};
    Solution a;
    auto res=a.permute(vc);
    for(auto i:res){
        for(auto ii:i)
            cout<<ii<<" ";
        cout<<endl;
    }

    return 0;
}