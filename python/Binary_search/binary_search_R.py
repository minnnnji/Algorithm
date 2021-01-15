# 재귀 버젼
def binary_search_r(arr,start,end,key):

    if start > end:
        return None
    
    mid = (start+end)//2

    if arr[mid] == key:
        return mid
    elif arr[mid] > key:
        return binary_search_r(arr,start,mid-1,key)
    else:
        return binary_search_r(arr,mid+1,end,key)
    
n,target = map(int,input().split())

arr = list(map(int,input().split()))

arr = binary_search_r(arr,0,n-1,target)
if arr == None:
    print('No result')
else:
    print(arr+1)
