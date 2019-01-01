
#include <iostream>
#include<string.h>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        auto ab=haystack.c_str;
   
        return strstr(haystack.c_str,needle.c_str)-haystack.c_str;

    }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
