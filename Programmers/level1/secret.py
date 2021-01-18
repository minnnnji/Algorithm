n = int(input())

arr1 = list(map(int,input().split()))
arr2 = list(map(int,input().split()))

arr3 = []
arr4 = []
result = []
for i in arr1:
    arr3.append(format(i,'b').zfill(n))

for i in arr2:
    arr4.append(format(i,'b').zfill(n))

for i in range(n):
    row = ''
    for j in range(n):
        if arr3[i][j] == '0' and arr4[i][j] == '0':
            row += ' '
        else:
            row +='#'
    result.append(row)

print(result)

# for x in
