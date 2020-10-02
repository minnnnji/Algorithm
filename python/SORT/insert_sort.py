# ver.book

data = list(map(int, input().split()))
def insert_sort(data):
    for i in range(1,len(data)):
        for j in range(i,0,-1):
            if data[j]<data[j-1]:
                data[j],data[j-1] = data[j-1],data[j]
            else:
                break

insert_sort(data)
print(data)

# ver .minnnnji
'''
data = list(map(int, input().split()))

def insert_sort(data):

    for i in range(1,len(data)):
        tmp = i
        while data[tmp] < data[tmp-1] and tmp > 0:
            data[tmp],data[tmp-1] =  data[tmp-1],data[tmp]
            tmp -= 1

insert_sort(data)
print(data)

'''