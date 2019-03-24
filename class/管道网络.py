'''
管道网络

Description

Every house in the colony has at most one pipe going into it and at most one pipe going out of it. Tanks and taps are to be installed in a manner such that every house with one outgoing pipe but no incoming pipe gets a tank installed on its roof and every house with only an incoming pipe and no outgoing pipe gets a tap. Find the efficient way for the construction of the network of pipes.

Input

The first line contains an integer T denoting the number of test cases. For each test case, the first line contains two integer n & p denoting the number of houses and number of pipes respectively. Next, p lines contain 3 integer inputs a, b & d, d denoting the diameter of the pipe from the house a to house b.Constraints:1<=T<=50，1<=n<=20，1<=p<=50，1<=a, b<=20，1<=d<=100

Output

For each test case, the output is the number of pairs of tanks and taps installed i.e n followed by n lines that contain three integers: house number of tank, house number of tap and the minimum diameter of pipe between them.

Sample Input 1

1
9 6
7 4 98
5 9 72
4 6 10
2 8 22
9 7 17
3 1 66

Sample Output 1

3
2 8 22
3 1 66
5 6 10

'''


N=int(input())

def solve(n,nums):
    in_=[0]*(n+1)
    out_=in_.copy()
    m=max(nums,key=lambda x:x[2])[2]
    pipe=[m]*(n+1)
  
    for a,b,d in nums:
        in_[b]=a
        out_[a]=b
        pipe[a]=d
    print(in_.count(0)-1)
    for i in range(1,n+1):
        if in_[i]!=0:
            continue
        tmp=i
        mm=m
        while out_[tmp]!=0:
            mm=min(mm,pipe[tmp])
          
            tmp=out_[tmp] 
        print(i,tmp,mm)
 


for _ in range(N):
    n,p=[int(i) for i in input().split()]
    nums=[]
    for _ in range(p):
        nums.append([int(i) for i in input().split()])
   
   
    solve(n,nums)