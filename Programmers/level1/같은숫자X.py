
def solution(arr):
    ind = 0 # list에서 현재 위치를 알려줄 index

    l = [arr[0]] # 첫 번째 미리 넣어 놓기

    for a in arr: # 리스트 다 돌기
        if l[ind] == a: # 같은 숫자일 때 까지 
            pass
        else: # l의 현재 위치와 다른 숫자일 때 
            l.append(a) # 현재 수 넣어주고 
            ind +=1 # 그 위치로 바꾸기
    return l 