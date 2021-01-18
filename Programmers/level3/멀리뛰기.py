n = int(input())

def solution(n):
    if n < 3 :
        return n
    n1, n2 = 1,2

    for i in range(3,n+2):
        n1 , n2 = n2, n1 + n2
        print(n1,n2)
    
    return n1%1234567

print(solution(n))
'''
# 시간초과 
def Fibonacci(n):
    if n == 1:
        return 1
    elif n == 2 :
        return 2
    else:
        return Fibonacci(n-2)+Fibonacci(n-1)

print(Fibonacci(n))
'''