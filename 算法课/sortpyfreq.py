
N=int(input())
while(N!=0):
    N-=1
    _=input()
    m=dict()
    line=input().split()
    for i in line:
        i=int(i)
        m[i]=m.get(i,0)+1
    tmp=sorted(m.items(), key=lambda x:x[1],reverse=True)
    for a,b in tmp:
        for _ in range(b):
            print(a,end=" ")