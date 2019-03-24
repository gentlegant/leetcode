'''
时间与收益

Description

Given a set of n jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Input

The first line of input contains an integer T denoting the number of test cases.Each test case consist of an integer N denoting the number of jobs and the next line consist of Job id, Deadline and the Profit associated to that Job.

Constraints:1<=T<=100，1<=N<=100，1<=Deadline<=100，1<=Profit<=500

Output

Output the number of jobs done and the maximum profit.

Sample Input 1

2
4
1 4 20 2 1 10 3 1 40 4 1 30
5
1 2 100 2 1 19 3 2 27 4 1 25 5 1 15

Sample Output 1

2 60
2 127

'''

N=int(input())

def solve(nums):

    nums.sort(key=lambda x:-x[2])
    n=max(nums,key=lambda x:x[1])[1]

    #N=len(nums)
    res=0
    time=[-1]*(n+1)

    for id,dead,val in nums:
        for k in range(dead,0,-1):
            if(time[k]==-1):
                time[k]=id
                res+=val
            
                break

    print(n+1-time.count(-1),end=' ')
    print(res)


for _ in range(N):
    input()
    nums=[int(i) for i in input().split()]
    n1=nums[::3]
    n2=nums[1::3]
    n3=nums[2::3]
    nums=list(zip(n1,n2,n3))
    solve(nums)