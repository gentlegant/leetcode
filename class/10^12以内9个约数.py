import math

def generatesqrt(n):

    L1=list(range(1000001))
    for i in range(4,len(L1),2):
        L1[i]=0
    for i in  range(3,len(L1),2):
        if L1[i]==0:
            continue
        for j in range(2*i,len(L1),i):      
            L1[j]=0
    LL=[]
    for i in range(2,len(L1)):
        if L1[i]!=0:
            LL.append(L1[i]) 
    s=[]
 
    for i in range(len(LL)-1):
        for j in range(i+1,len(LL)):
            k=LL[i]*LL[j]
            if k>1000000:
                break
            s.append(k)
    for i in LL:
        k=int(math.pow(i,4))
        if k>100000:
            break
        s.append(k)      

    return sorted(s)

nums=[]
T=int(input())
for i in range(T):
    n=int(input())
    n=int(math.sqrt(n))
    nums.append(n)

m=max(nums)
s=generatesqrt(m)

for i in nums:
    count=0
    for j in s:
        if j<=i:
            count+=1
        else:
            break
    print(count) 

        
def mod(a, b, mode):
    sums = 1
    a = a % mode

    while b > 0:
       
        if b % 2 == 1:
            sums = (sums * a) % mode

        b = b // 2
        a = (a * a) % mode
    return sums


R = int(input())
for i in range(R):
    line = [int(k) for k in input().split()]
   
    print(mod(line[0], line[1], line[2]))