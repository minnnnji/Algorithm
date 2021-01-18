citations = list(map(int,input().split()))

def solution(citations):
    
    cnt = len(citations)
    citations.sort()
    for i in range(cnt):
        if citations[i] >= cnt-i:
            return cnt-i
    
    return 0

print(solution(citations))
