def solution(dartResult):

    bonus = {'S' : 1, 'D' : 2, 'T' : 3}
    option = {'*' : 2, '#' : -1}

    a = [0,0,0]
    flag = -1

    for idx, dart in enumerate(dartResult) :
        if dart.isdigit() :
            flag += 1
            if dart == '0' :
                continue
            elif dartResult[idx+1].isdigit() :    # 10일 때 처리
                a[flag] = int(dart)*10
                flag -= 1
            else :
                a[flag] = int(dart)

        elif dart in 'SDT':                        # SDT    
            a[flag] **= bonus[ㅑㅜdart]

        else :
            if dart == "*" :                    # *인 경우
                a[flag-1] *= 2

            a[flag] *= option[dart]

    return sum(a)


# 75점 짜리 풀이 1시간

# import re
# p1 = re.compile('[^012345689]')
# p2 = re.compile('[012345689]')
# dart = input('please write : ')
# arr1 = p1.findall(dart)
# arr2 = list(map(int,p2.findall(dart)))

# for i in range(0,len(arr2)-1):
#     if arr2[i] == 1 and arr2[i+1] == 0:
#         arr2[i] *= 10
#         arr2.remove(arr2[i+1])

# total = []
# cnt = 0
# result = 0

# for i in range(0,len(arr1)):
    
#     if arr1[i] == 'S':
#         result = arr2[cnt]
#     if arr1[i] == 'D':
#         result = arr2[cnt]**2
#     if arr1[i] == 'T':
#         result = arr2[cnt]**3
#     if arr1[i] == '#':
#         total[cnt-1] *= (-1)

#     if result != 0:
#         total.append(result)
#         cnt+=1
#         result = 0

#     if arr1[i] =='*':
#         if cnt == 1:
#             total[cnt-1] *= 2
#         else:
#             total[cnt-1] *= 2
#             total[cnt-2] *= 2

# print(sum(total))


        


