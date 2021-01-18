
from itertools import permutations

numbers = input().split()
'''
def solution(numbers):
    answer = ""
    a = list(permutations(numbers,len(numbers)))
    l = []
    for i in range(len(a)):
        num = str()
        for j in range(len(numbers)):
            num += a[i][j]
        l.append(num)
    l = list(map(int,l))
    m = str(max(l))



solution(numbers)
'''
def solution(numbers):
    numbers = list(map(str,numbers))
    numbers.sort(key = lambda x : x*3,reverse = True)
    return str(int(''.join(numbers)))

print(solution(numbers))