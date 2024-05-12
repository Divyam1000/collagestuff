# -*- coding: utf-8 -*-
"""
Created on Thu Sep 28 23:21:23 2023

@author: Asus-PC
"""

n = int(input())

def print_indexes(n):
    n_str = str(n)
    nums = {}
    for idx, digit in enumerate(n_str):
        if digit not in nums:
            idx_list = [idx]
            nums[digit] = idx_list
        elif digit in nums:
            tmp = nums.get(digit)
            tmp.append(idx)
            nums[digit] = tmp
    for key, val in nums.items():
        print(key,*val)
print_indexes(n)
