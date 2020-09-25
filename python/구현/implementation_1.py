# 상하좌우 길찾기 문제 
n = int(input())

datas = input().split()

x, y = 1,1


dy = [0 ,0, -1, 1]
dx = [-1, 1, 0, 0]
move_types = ['L','R','U','D']


for data in datas:

    for i in range(len(move_types)):
        if data == move_types[i]:
            nx = x + dx[i]
            ny = y + dy[i]

            break

    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue

    x, y = nx, ny

print(y,x)