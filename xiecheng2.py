#!/bin/python
# -*- coding: utf8 -*-
import sys
import os
import re

#请完成下面这个函数，实现题目要求的功能
#当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
#******************************开始写代码******************************
def upper_bound(nums, target):
    if(len(nums)==0):
        return 0
    low, high = 0, len(nums)-1
    pos = len(nums)
    while low<high:
        mid=int((low+high)/2)
        if nums[mid]<=target:
            low = mid+1
        else:#>
            high = mid
            pos = high
    if nums[low]>target:
        pos = low
    return pos


def  calcMinStaff():
    n=int(input())
    nums=[]
    for _ in range(n):
        nums.append([int(i) for i in input().split(',') ])
    nums.sort(key= lambda x:x[0])

    res=[]
    for x,y in nums:
     
    
        pos=upper_bound(res,x)-1
        
        if pos!=-1:
            res.pop(pos)
        
        ins=upper_bound(res,y)
        res.insert(ins,y)
 
       
    return len(res)

#******************************结束写代码******************************


  
res = calcMinStaff()

print(str(res) + "\n")


