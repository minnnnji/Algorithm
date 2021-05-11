def perfectSubstring(s, k):
    # Write your code here
    s = list(map(int,s))
    uni = list(set(s))
    cnt = [0]* (max(uni)+1)

    flag = 0
    a = 0
    result = 0
    while(1):
        if a > (len(s) - k):
            break
        for i in range(a,len(s)):             
            cnt[s[i]] += 1
            if ((i-a) % k) == k-1:
                for j in cnt:
                    if j != k and j != 0:
                        flag = 1
                        break
                    if j > k :
                        break
                
                if flag == 0:
                    result+=1
                else:
                    flag=0
        a+=1
        cnt = [0]*(max(uni)+1)
    return result

s = '1020122'
k = 2
print(perfectSubstring(s,k))