s = "PoooyY"

cnt = [0,0]
for i in s:
    if i == 'p'or i =='P':
        cnt[0] +=1
    if i == 'y'or i =='Y':
        cnt[1] +=1

if cnt[0] == cnt[1]:
    print(True) 
else:
    print(False)