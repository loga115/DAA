#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 21:24:46 2022

@author: janaki
"""
n=100
fp = open(f"ascending_{n}.txt","w")
fp.write(str(n)+" ")  
for i in range(1,n):
    fp.write(str(i)+" ")  
fp.write(str(n))
fp.close()
