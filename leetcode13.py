
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000
class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        res=0
        old=0
        dic={"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        for i in s:
            
            now=dic[i]
            if(old>now):
                res-=2*old
            res+=now
            old=now

        return res