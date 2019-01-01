# n 个区间
# 分区，给不同painter分配board
#arr 的sum 是 sum
def solve(arr, n,begin,end,sum):
    if n==1 or n==0:
        return sum
    sbegin=0
    send=0
    
    while send*(n-1)<(sum-send):    
        send+=arr[end]
        end-=1
    while sbegin*(n-1)<(sum-sbegin):    
        sbegin+=arr[begin]
        begin+=1


    sum-=sbegin+send
    tmp=solve(arr,n-2,begin,end,sum)
    return max(sbegin,send,tmp)


a=[10, 10 ,10 ,10  ]


n=2
begin=0
end=len(a)-1
sum=10

a=solve(a,n,begin,end,sum)
print(a)