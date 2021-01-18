array = list(map(int,input().split()))
commands = [[2,5,3],[4,4,1],[1,7,3]]

print(len(commands))
def solution(array,commands):
    result = []
    for l in commands:
        new = array[l[0]-1:l[1]]
        new.sort()
        result.append(new[l[2]-1])
    
    return result

print(solution(array,commands))

