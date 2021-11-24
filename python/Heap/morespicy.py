scoville = [1, 2, 3, 9, 10, 12]
K = 7
import heapq

def solution(scoville, K):
    
    cnt = 0
    heapq.heapify(scoville)

    while scoville[0] < K:

        min, min2 = heapq.heappop(scoville), heapq.heappop(scoville)
        tmp = min + (min2 * 2)
        if len(scoville) == 1 and scoville[0] < K:
            return -1
        heapq.heappush(scoville, tmp)
        cnt += 1

    return cnt

print(solution(scoville, K))