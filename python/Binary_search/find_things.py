import sys

def find_thing(arr,target):
    
    start = 0
    end = len(arr)-1
    result = 9999

    while(start<=end):
        mid = (start+end)//2

        if arr[mid]==target:
            result = mid
            break
        elif arr[mid]>target:
            end = mid-1
        else:
            start = mid+1
    
    if result== 9999:
        return 'No '
    else:
        return 'Yes '

n = int(input('N을 입력하세요 : ')) 
all_things = list(map(int,(sys.stdin.readline().rstrip().split())))

all_things.sort()

m = int(input('M을 입력하세요 : ')) 
things = list(map(int,(sys.stdin.readline().rstrip().split())))

result = ''
for i in range(m):
    result+= find_thing(all_things,things[i])

print(result)

