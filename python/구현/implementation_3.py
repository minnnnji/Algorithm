# VER . 1
'''
input_data = input()
row = int(input_data[1])
col = int(ord(input_data[0])) - int(ord('a')) + 1
# ord 는 문자의 아스키코드 값을 돌려주는 함수 

steps = [(-1,-2),(1,-2),(-2,-1),(2,-1),(-2,1),(2,1),(-1,2),(1,2)]

result = 0

for step in steps:
    next_row = row + step[0]
    next_col = col + step[1]

    if next_row >= 1 and next_row <= 8 and next_col >= 1 and next_col <= 8 :
        result+=1
    
print(result)
'''
# VER . minnnnji

l = ['a','b','c','d','e','f','g','h']

col, row = input()
row = int(row)
case = [(-1,-2),(1,-2),(-2,-1),(2,-1),(-2,1),(2,1),(-1,2),(1,2)]

for i in range(len(l)):
    if col == l[i]:
        col = i + 1
        break

count = 0
for i in range(8):
    result = tuple(sum(elem) for elem in zip(case[i],(col,row)))
    if result[0] > 8 or result[1] > 8 or result[0]< 1 or result[1] < 1:
        continue

    count+=1

print(count)

