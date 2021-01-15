data = list(map(int, input().split()))

def select_sort(data):
    
    for i in range(len(data)-1):
        tmp = i
        for j in range(i + 1,len(data)):
            if data[tmp] > data[j] : 
                tmp = j
        
        #if 문은 필요없음 
        #if tmp != i :
        data[i],data[tmp] =  data[tmp],data[i]
        
select_sort(data)
print(data)