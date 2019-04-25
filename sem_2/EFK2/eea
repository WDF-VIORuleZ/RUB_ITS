#!/bin/python3

import argparse


def eea(mod, el): #Condition: gcd(m,x)=1
    m = [mod]
    x = [el]
    q = []
    s = [1]
    t = [0]

    ctr = 0
    while(x[ctr] != 0):
        q.insert(0,int(m[ctr]/x[ctr]))
        m.append(x[ctr])
        x.append(m[ctr]%x[ctr])
        ctr += 1
    q.insert(0,0)
    
    for i in range(len(q)-1):
        s.append(t[i])
        t.append(s[i]-(q[i+1]*t[i]))

    q = q[::-1]
    s = s[::-1]
    t = t[::-1]
    
    print(f"{'m':4}|{'x':4}|{'q':4}||{'s':4}|{'t':4}|") #limits us on 4 digit numbers
    print("--------------------------")
    for i in range(len(q)):
        print(f"{m[i]:<4}|{x[i]:<4}|{q[i]:<4}||{s[i]:<4}|{t[i]:<4}|")
    
    test = s[0] * m[0] + t[0] * x[0] 
    print(f"\nTest: {s[0]} * {m[0]} + {t[0]} * {x[0]} = {test}")
    
    print(f"\n{el}⁻¹ = {t[0]} mod {mod}")


def eea_latex(mod,el):
    m = [mod]
    x = [el]
    q = []
    s = [1]
    t = [0]

    ctr = 0
    while(x[ctr] != 0):
        q.insert(0,int(m[ctr]/x[ctr]))
        m.append(x[ctr])
        x.append(m[ctr]%x[ctr])
        ctr += 1
    q.insert(0,0)
    
    for i in range(len(q)-1):
        s.append(t[i])
        t.append(s[i]-(q[i+1]*t[i]))

    q = q[::-1]
    s = s[::-1]
    t = t[::-1]
    end = "\\"+"\\"
    print("\\begin{center}")
    print("\\begin{tabular}{ |c|c|c||c|c| }")
    print("\\hline")
    print("m & x & q & s & t " + end)
    print("\\hline")
    for i in range(len(q)):
        print(f"{m[i]}&{x[i]}&{q[i]}&{s[i]}&{t[i]} " + end)

    print("\\hline")
    print("\\end{tabular}")
    print("\\end{center}")
    



if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='Extended Euclidean algorithm')
    parser.add_argument('el', metavar='E', type=int, help='element to calculate the modular multiplicative inverse of')
    parser.add_argument('mod', metavar='M', type=int, help='modul of element')
    parser.add_argument("-l", "--latex", help="Print output in LaTeX", action='store_true')
    args = parser.parse_args()

    if(args.latex):
        eea_latex(args.mod,args.el)
    else:
        eea(args.mod,args.el)