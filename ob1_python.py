# -*- coding: utf-8 -*-
"""
Created on Fri Jul  2 21:36:15 2021
"""
import random
import numpy as np
def random_list(x1,xn, dx = []):
    dr = dx
   
    i = x1
    while i < xn + 1:
        r1 = random.randint(x1, xn)
        if not (r1 in dr):
            dr += [r1]
            i += 1
        if len(dr) == xn:
            break
    return dr
def F1(data,dx,x):
    for i in range(len(data)):
        data[i][x] = dx[i]
    return data
def F2(data,x):
    dx = []
    for i in range(len(data)):
        dx.append(data[i][x])
    return dx
def F_p(data):
    for i in range(len(data)):
        for i2 in range(len(data[i])):
            print(data[i][i2], end=" ")
        print()
def F4():
    d = random_list(1, 9)
    d2 = [d[0:3],d[3:6],d[6:9]]

    return d2
def shuffle2(x,y):
    idx = np.random.permutation(y .shape[0])
    print(idx)
    x , y= x[idx] , y[idx]
    return x, y
def T1(x):
    xt = []
    t = 0
    while t < len(x):
        c = []
        for i in range(len(x)):
            c += [x[i][t]]
        xt += [c]
        t += 1
    return xt
def T2(x):
    xt = []
    t = len(x)-1
    while t >=0:
        c = []
        for i in range(len(x)):
            c += [x[i][t]]
        xt += [c]
        t -= 1
    return xt
def F5(a1):
    for i in range(len(a1)):
        for i2 in range(0,len(a1[i]),3):
            if i2 == 3 and i == 0:
                a1[i][i2:i2+3] = a1[i+2][:3]
            if i2 == 3 and i == 1:
                a1[i][i2:i2+3] = a1[i-1][:3]
            if i2 == 3 and i == 2:
                a1[i][i2:i2+3] = a1[i-1][:3]
            if i2 == 6 and i == 0:
                a1[i][i2:i2+3] = a1[i+1][:3]
            if i2 == 6 and i == 1:
                a1[i][i2:i2+3] = a1[i+1][:3]
            if i2 == 6 and i == 2:
                a1[i][i2:i2+3] = a1[i-2][:3]
    return a1
def F5_2(a1):
    for i in range(len(a1)):
        for i2 in range(0,len(a1[i]),3):
            if i2 == 3 and i == 0:  
                a1[i][i2:i2+3] = a1[i+2][:3]
            if i2 == 3 and i == 1:
                a1[i][i2:i2+3] = a1[i-1][:3]
            if i2 == 3 and i == 2:
                a1[i][i2:i2+3] = a1[i-1][:3]
    return a1

def Sydoky():
    
    a1 = F4()
    c1 = 1
    for i in range(len(a1)):
        if c1 == 1 and False:
            a2 = random_list(1, 9, a1[i])
            a1[i] = a2
            c1 = 0
        else:
            a1[i] = a1[i] + [0 for _ in range(6) ]   
    c1 = 6
    while c1 > 0:
        a1 += [[0 for _ in range(9)]]
        c1 -= 1
    a2 = F2(a1,0)
    a2 = random_list(1, 9,a2[:3])
    a1 = F1(a1,a2,0)
    a1 = F5(a1)
    a2 = T1(a1)
    a2 = F5(a2)
    a3 = T2(a2)
    a3 = F5(a3)
    a3_2 = T2(a3)
    a4 = F5_2(a3_2)
    for i in range(len(a4)):
        for i2 in range(0,len(a4[i]),3):
            if i == 3 and i2 == 3:
                a4[i][i2:i2+3] = a4[i+2][:3] 
            if i == 4 and i2 == 3:
                a4[i][i2:i2+3] = a4[i-1][:3]    
            if i == 5 and i2 == 3:
                a4[i][i2:i2+3] = a4[i-1][:3]
    F_p(a4)
    return a4
a = Sydoky()
if True:
    print("-" * 17 )    
    c = random.randint(10, 250)
    
    while c > 0:
         x = random.randint(0, 8)
         y = random.randint(0, 8)
         a[x][y] = "_"
         c -= 1
    F_p(a)




