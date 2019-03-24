def shell_sort(nums,*gap):
    for i in gap:
        for begin in range(i):
            tmp=sorted(nums[begin::i])
            nums[begin::i]=tmp


T=int(input())
for _ in range(T):
    nums=list(map(int,input().split()))
    gap=list(map(int,input().split()))
    shell_sort(nums,*gap)
    for i in nums[0:len(nums)-1]:
        print(i,end=" ")
    print(nums[-1])