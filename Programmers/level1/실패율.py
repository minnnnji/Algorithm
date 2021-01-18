N = 4
stages = [4,4,4,4,4]
'''
# 아래의 경우는 안되는 경우가 너무 많음
def solution(N, stages):
    answer = []
    arrival = [0]*(N+2)
    data = []
    sum = 0
    if len(stages) != 0
    for i in range(len(stages)):
        arrival[stages[i]] += 1
    for i in range(1,len(arrival)):
        sum = 0
        for j in range (i,len(arrival)):
            sum += arrival[j]
        
        if sum != 0 :
            data.append((round(arrival[i]/sum,2),i))
        else:
            data.append((2,i))
    
    data = sorted(data,key = lambda x: x[0],reverse=True)
    for i in range(1,len(data)):
        answer.append(data[i][1])
    return answer

print(solution(N,stages))
'''
def solution(N, stages):
    result = {}
    num = len(stages)

    for stage in range(1, N+1):
        if num != 0:
            count = stages.count(stage)
            result[stage] = count / num
            num -= count
        else:
            result[stage] = 0

    return sorted(result, key=lambda x : result[x], reverse=True)