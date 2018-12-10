# -*- coding:utf-8
res=0
data=[int(i) for i in  input().split()]
windowsize=int(input())
for i in range(len(data)-windowsize+1):
    res+=max(data[i:i+windowsize])
   
print(res)