# VER . minnnnji
n,m = map(int,input().split())

result = 0
l = []
for i in range(n):

    data = list(map(int,input().split()))

    l.append(min(data))

print(max(l))
    
# < VER 1 >
'''
n,m = map(int,input().split())

result = 0

for i in range(n):

    data = list(map(int,input().split()))

    min_data = min(data)

    result = max(min_data,result)

print(result)
'''

# < VER 2 >
'''
n,m = map(int,input().split())

result = 0

for i in range(n) :

    data = list(map(int,input().split()))
    min_data = 10001
    
    for a in data:
        min_data = min(min_data,a)
    
    result = max(result,min_data)

print(result)
'''