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
    test = s[0] * m[0] + t[0] * x[0] 
    return s


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
    