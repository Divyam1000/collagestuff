# -*- coding: utf-8 -*-
"""
Created on Thu Aug 31 10:41:00 2023

@author: Asus-PC
"""
from statistics import mean
from scipy import stats
estimate = [12,12,34,56,2,56,23,98,23,357,2,76,12,84,4,314,876,1,87,61,85,1,62,26,73,356,1,457]
estimate.sort()
m = stats.trim_mean(estimate, 0.2)
print(m)
#estimate.sort()
#v = int(0.2 * len(estimate))
#estimate = estimate[tv:]
#estimate = estimate[:len(estimate)-tv]
#for i in range(len(estimate)):
 #   print(estimate[i])
 
#print(mean(estimate))