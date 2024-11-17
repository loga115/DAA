#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 21:30:54 2022

@author: janaki
"""

n=50000
fp = open(f"D:\College\sem5\lps2\descending_{n}.txt","w")
fp.write(str(n)+" ")  
for i in range(n,1,-1):
    fp.write(str(i)+" ")  
fp.write(str(1))
fp.close()
