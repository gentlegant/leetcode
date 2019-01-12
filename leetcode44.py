import re


import re
class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        return re.fullmatch(p,s)!=None


a=Solution()
res=a.isMatch("aa",".*")
print(res)