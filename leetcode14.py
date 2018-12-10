import numpy as np
class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        res=""
        count=0
    
        while True:
            try:
                ls=np.unique( [i[count] for i in strs]) 
                if(len(ls)==1):
                    res+=ls[0]
                else:
                    break
                count+=1
            except:
                break
        return res



