# VER 2

n, k = map(int,input().split())
result = 0

while 1:

    target = (n//k) * k
    result += (n - target)
    n = target

    if n < k :
        break

    result += 1
    n //= k

result += ( n - 1 )
print(result)

# VER 1
'''
n, k = map(int,input().split())

result = 0 
while n >= k :
    
    while n % k != 0:
        n -= 1
        result += 1

    n //= k 
    result += 1


while n > 1:
    n -= 1
    result +=1

print(result)
'''