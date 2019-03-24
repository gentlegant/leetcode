'''
1
6 
900  940 950  1100 1500 1800
910 1200 1120 1130 1900 2000
'''
from ordered_set import OrderedSet

N=int(input())

def solve(nums):
 
    nums.sort(key=lambda x:x[1])

    N=[]
    for arr,depart in nums:
        flag=True
        for i in range(len(N)):
            if arr>N[i]:
                N[i]=depart
                flag=False
                break
        if flag:
            N.append(depart)
 
    return len(N)

for _ in range(N):
    input()
    arr=[int(i) for i in input().split()]
    depart=[int(i) for i in input().split()]
    nums=list(zip(arr,depart))
    print(solve(nums))