import sys

n,m = map(int,input().split())
arr = list(map(int,sys.stdin.readline().split()))

start = 0
end = max(arr)

result = 0
while(start<=end):
    total = 0
    mid = (start+end)//2

    for x in arr:
        if x > mid:
            total+= x-mid
    
    if total < m:
        end = mid-1
    else:
        result = mid
        start = mid+1

print(result)

# 내가 생각한 풀이 - 오류가 많음
# ex) 5 8
# 2 3 2 1 1

# def cutting(arr,target):
#     max_l = arr[1]+1
#     total = 0
#     for i in range(len(arr)):
#         max_l -=1
#         total+=i

#         if ((arr[i]-max_l)) > 0:
#             total += (arr[i]-max_l)
        
#         print(total,max_l,arr[i])
#         if total >= target:
#             return max_l

#     return max_l 



# n,m = map(int,input().split())
# arr = list(map(int,sys.stdin.readline().split()))

# arr.sort(reverse=True)
# result = cutting(arr,m)
# print(result)

# 4 6 
# 19 15 10 17