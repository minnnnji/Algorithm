s = "Zbcdefg"
a = []
for i in s:
    a.append(i)
a = sorted(a ,reverse=True)
d = ''
for i in a:
    d += i
print(s,d)