progresses = [95, 90, 99, 99, 80, 99]
speeds = [1, 1, 1, 1, 1, 1]	

from math import ceil
# O(n) 풀이 
def solution(progresses, speeds):
    days = {}
    max_day = 0

    for p, s in zip(progresses, speeds):

        cnt = ceil((100 - p) / s)
    
        if max_day < cnt:
            max_day = cnt
            days[max_day] = [max_day]
        else :
            days[max_day].append(cnt)
    
    result = [len(v) for v in days.values()]
    return result

print(solution(progresses, speeds))
