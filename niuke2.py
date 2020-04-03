import collections

input()
a=input()

nums=[int(i) for i in a.split()]

cnt=collections.Counter(nums)



res=max(cnt.values() )
print(res)