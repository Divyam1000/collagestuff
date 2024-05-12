# -*- coding: utf-8 -*-
"""
Created on Thu Aug 31 10:35:24 2023

@author: Asus-PC
"""

import statistics
import matplotlib.pyplot as plt
#plt.plot([1,2,3,4],[1,4,9,16], 'r--')
#plt.ylabel("some values")

Estimates = [10,12,45,1,56,12,63,123,564,23,4576,456,5,36,46,364,754,364,524,467,25,467,254,46,143,6474,225,252,525,346,235,246,235,24,525,24,23,4265,425,4476,3434,36,435,4564,3,34,53,46,364,544,435,2354,54,425,56,25]
y = []

Estimates.sort()
tv = int(0.1 * (len(Estimates)))
Estimates = Estimates[tv:]
Estimates = Estimates[:len(Estimates)-tv]

for i in range(len(Estimates)):
    y.append(5)
    
plt.plot(Estimates,y,'r--')
plt.plot([statistics.mean(Estimates)],[5],'ro')
plt.plot([statistics.median(Estimates)],[5],'bs')
plt.plot([500],[5],'g^')