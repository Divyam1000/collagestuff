# -*- coding: utf-8 -*-
"""
Created on Sun Sep 24 17:01:13 2023

@author: Asus-PC
"""

name=input("Enter File:")
try:
    handle= open(name,)

    counts=dict()
    for line in handle:
        words=line.split()
        for word in words:
            counts[word]=counts.get(word,0)+1
except:
    print("file doesn't exist")
    quit() 


largest_count=None
largest_word=None
for word,count in counts.items():
    if largest_count==None or count>largest_count:
        largest_word=word
        largest_count=count
print(largest_word,largest_count)