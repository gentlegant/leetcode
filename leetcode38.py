import collections

class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        old='1'
        new=old
        
        for _ in range(n-1):
        