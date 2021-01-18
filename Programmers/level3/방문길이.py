dirs = input()

# 북 남 서 동 
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

D = {'U':0,'D':1,'L':2,'R':3}

def solution(dirs):
    answer = 0
    visited = []
    position = (0,0)

    for command in dirs:
        i = D[command]
        move = position[0] + dx[i], position[1] + dy[i]
        if abs(move[0]) > 5 or abs(move[1]) > 5 :
            continue
        
        if (position,move) not in visited:
            visited.append((position,move))
            visited.append((move,position))
            answer += 1
        position = move
    return answer    
print(solution(dirs))