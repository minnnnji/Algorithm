'''
모든 경우를 세서 푸는 문제로 '완전 탐색 유형'이라고 함 
전체 데이터의 수가 100만개 이하일 때 사용 가능 

이 경우는 24 * 60 * 60 = 86400개의 경우의 수 밖에 없기때문에 가능
'''
n = int(input())

count = 0
flag = 0
for i in range(24):
    if i > n:
        break
    for j in range (60):
        for k in range(60):
            num = i * 10000 + j * 100 + k
            if '3' in str(i)+str(j)+str(k):
                count += 1

print(count)