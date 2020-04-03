#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    
        auto cpy=digits;
        auto i=cpy.rbegin();
        for(;i!=cpy.rend();i++){
            *i++;
            if(*i<10)
                break;
            
        }
        if(i==cpy.rend()){
            cpy.insert(cpy.begin(),1);

        }
        
        return cpy;

      
    }
};