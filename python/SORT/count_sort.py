data = list(map(int,input().split()))

count = (max(data)+1) *[0]

for i in range(len(data)):
    count[data[i]]+=1
s = []
for i in range(len(count)):
    for j in range(count[i]):
        s.append(i)

print(s)
