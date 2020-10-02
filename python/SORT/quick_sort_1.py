
data = list(map(int,input().split()))

def quick_sort(array):
    
    if len(array) <= 1:
        return array
    
    pivot = array[0]
    tail = array[1:]

    left_side = [x for x in tail if x <= pivot]
    right_side = [x for x in tail if x > pivot]

    return quick_sort(left_side) + [pivot] + quick_sort(right_side)

data = quick_sort(data)
print(data)

''' ver 1 // 7 5 9 0 3 1 6 2 4 8
data = list(map(int,input().split()))

def quick_sort(array,start,end):

    if start >= end:
        return
    
    pivot = start
    left = start+1
    right = end

    while left <= right:

        while left <= end and array[left] <= array[pivot]:
            left+=1
        while right > start and array[right] >= array[pivot]:
            right-=1
        
        if left > right :
            array[pivot],array[right] = array[right],array[pivot]
        else:
            array[right],array[left] = array[left],array[right]
        
    quick_sort(array,start,right-1)
    quick_sort(array,right+1,end)

quick_sort(data,0,len(data)-1)
print(data)
'''