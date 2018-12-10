
# I             1
# V             5
# X             10
# L             50
# C             100
# D             500
# M             1000

# I can be placed before V (5) and X (10) to make 4 and 9. 
# X can be placed before L (50) and C (100) to make 40 and 90. 
# C can be placed before D (500) and M (1000) to make 400 and 900.


#re.sub  神器！
import re

class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        def func(matched):
            dic={"V":"IX","L":"XC","D":"CM","I":"IV","X":"XL","C":"CD"}
            s=matched.group()
            return dic[s[0]]
        s=[]
        for k,v in  zip([1000,500,100,50,10,5,1],"MDCLXVI")  :
            s.extend(v*(num//k))
            num%=k
        pattern=r"V?I{4}|L?X{4}|D?C{4}"
        return re.sub(pattern,func,"".join(s))


        