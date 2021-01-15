# 비재귀 버젼

def binary_search(arr, key):

    start = 0
    end = len(arr)-1
    result = 9999
    while(start<=end):
        mid = (start+end)//2

        if arr[mid] == key:
            result = mid
            break
        elif arr[mid] > key:
            end = mid-1
        else:
            start = mid+1
    
    if result == 9999:
        return None
    else:
        return result+1

n, target = map(int,input().split())
arr = list(map(int,input().split()))

result = binary_search(arr,target)

if result == None:
    print('No result')
else:
    print(result)