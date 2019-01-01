# // 30. Substring with Concatenation of All Words
# // Hard

# // You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

# // Example 1:

# // Input:
# //   s = "barfoothefoobarman",
# //   words = ["foo","bar"]
# // Output: [0,9]
# // Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
# // The output order does not matter, returning [9,0] is fine too.

# // Example 2:

# // Input:
# //   s = "wordgoodgoodgoodbestword",
# //   words = ["word","good","best","word"]
# // Output: []
class Solution:
    def help(self,tmp,s,k,size,res):
        if len(s)==0:
            res.append(k)
            return 
        v=tmp.get(k,[])
        if v==[]:
            return 
        for i in v:
            if i not in s:
                continue 
            s.remove(i)
            self.help(tmp,s,k+size,size,res)
            s.add(i)
        

    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        res=[]
        tmp={}
        size=len(words[0])
        sizeofwords=len(words)
        for ind,i in enumerate(words):
            f=-1
            while True:
                f=s.find(i,f+1)
                if f==-1:
                    break
                t=tmp.get(f,[])
                t.append(ind)
                tmp[f]=t
        print(tmp)
        for k in sorted(tmp.keys()):
            s=set(range(sizeofwords))
        
            self.help(tmp,s,k,size,res)
        res=list(set(res))
        for ind,i in enumerate(res):
            res[ind]=i-sizeofwords*size
        return res


a=Solution()
b=a.findSubstring("wordgoodgoodgoodbestword",["word","good","best","good"])
print(b)