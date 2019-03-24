import re

def search(pattern,text):
    begin=0

    res=0
    while(True):
  
        res=text.find(pattern,begin)
    
        if(res==-1):
            break
        yield res
        begin=res+1
    

N=int(input())


for i in range(N):
    text,pattern=input().split(',')
    lis=list(search(pattern,text))
    for i in range(len(lis)-1):
        print(lis[i],end=" ")
    print(lis[-1])

  