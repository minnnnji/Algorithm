def solution(n):
    for i in range(2, n): # 2 ~ n-1까지 
        if n % i == 1: # 나머지가 1이면 
            return i # 그 수 return 
        
    return n