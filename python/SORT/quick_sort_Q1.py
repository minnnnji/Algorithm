#7 5 9 0 3 1 6 2 4 8
import random
n = int(input())

data = list(map(int,input().split()))

def pick_mid(array,start,end):
    l = [] 
    for i in range(3):
        a = random.randint(0,end - start)
        l.append((array[a],a))
        
    l = sorted(l,key=lambda x: x[0])
    return l[1][1]

# Pivot 기준을 바꿨으니까 조금 변형해야함
def quick_sort(array):

    if len(array) <= 1:
        return array
    
    pivot = pick_mid(array,0,len(array)-1)
    array[pivot],array[0] = array[0],array[pivot]
    
    pivot = array[0]
    tail = array[1:]

    left_side = [x for x in tail if x <= pivot]
    right_side = [x for x in tail if x > pivot]

    return quick_sort(left_side) + [pivot] + quick_sort(right_side)


print(quick_sort(data))