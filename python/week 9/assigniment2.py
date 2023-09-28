# -*- coding: utf-8 -*-
"""
Created on Thu Sep 28 23:21:07 2023

@author: Asus-PC
"""

def mergeDic(d1, d2):
  dic = d1.copy()
  for key, val in d2.items():
    if key not in dic:
      dic[key] = val
  return dic
  	
key = list(map(int, input().split()))
val = list(map(int, input().split()))

d1 = {}
for i in range(len(key)):
    d1[key[i]] = val[i]
    
d2 = {}
key = list(map(int, input().split()))
val = list(map(int, input().split()))
for i in range(len(key)):
    d2[key[i]] = val[i]

print(mergeDic(d1, d2))