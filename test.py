def quick_sort(left, right, arr, count):
    p = left
    q = right
    temp = arr[p]  # 基准值，一轮完这个值将处在正确的位置
    while p < q:
        while arr[q] >= temp and p < q:
            q -= 1
        if p < q:
            arr[p] = arr[q]
            count[0] += 1
            p += 1
            while arr[p] <= temp and p < q:
                p += 1
            if p < q :
                arr[q] = arr[p]
                count[0] += 1
                q -= 1

    arr[p] = temp

    if p-1 > left:
        quick_sort(left, p-1, arr, count)
    if q+1 < right:
        quick_sort(q+1, right, arr, count)

turn = int(input())
while turn > 0:
    length = int(input())
    tar = [int(i) for i in input().split()]
    ans = []
    ans.append(int(0))
    quick_sort(0, length-1, tar, ans)
    print(ans[0])
    turn -= 1
