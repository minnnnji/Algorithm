n,m = map(int,input().split())

l = list(map(int,input().split()))

if m in l:
    print(l.index(m))
else :
    if l[n-1] < m:
        print(n)
    elif l[0] > m:
        print(0)
    else:
        for i in range(len(l)):
            if l[i] < m and l[i+1] > m :
                print(i)
                break
        