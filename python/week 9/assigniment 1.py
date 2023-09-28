# -*- coding: utf-8 -*-
"""
Created on Thu Sep 28 23:20:32 2023

@author: Asus-PC
"""

def subStr(s1, s2):
    return s2 in s1

if __name__ == "__main__":
    s1 = input()
    s2 = input()
    print(subStr(s1, s2))