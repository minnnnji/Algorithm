
# < VER . minnnnji >
n,m,k = map(int,input().split())

data = list(map(int,input().split()))

data.sort()
first = data[n-1]
second = data[n-2]

largest = first * k + second

result = 0
count = m // (k+1)
result += count * largest
count = m % (k+1)
for i in range(count):
    result += first

print(result)

'''
< VER 1 >

n,m,k = map(int,input().split())

data = list(map(int,input().split()))

data.sort()
first = data[n-1]
second = data[n-2]

result = 0
while 1:
    for i in range(k):
        if m == 0: 
            break
        result += first
        m -= 1
    
    if m == 0:
        break
    result += second
    m -= 1

print(result)
'''

'''
< VER 2 >

n,m,k = map(int,input().split())

data = list(map(int,input().split()))

data.sort()
first = data[n-1]
second = data[n-2]

result = 0
count = int( m / ( k + 1 )) * k
count += m % (k + 1)

result += count * first
result += (m - count) * second

print(result)
'''