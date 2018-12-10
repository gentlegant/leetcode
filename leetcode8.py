import re
class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        a=re.findall(r"^\s*[-+]?\d+",str)
        res=int(a[0]) if (len(a)!=0) else 0
        return min(max(res,-2**31),2**31-1)
