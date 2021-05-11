# from itertools import permutations

# def maxInversions(arr):
#     ls = list(permutations(arr,3))

#     flag = 0
#     l = []
#     answer = len(ls)
#     for i in range(len(ls)):
#         for j in range(2):
#             if ls[i][j] < ls[i][j+1]:
#                 flag = 1
#                 break
#             else:
#                 flag = 0
#         if flag == 0 :
#             l.append(ls[i])
#     for i in l:

def maxInversions(arr):
    n = len(arr)
    invcount = 0 
    for i in range(1,n-1): 
      
        small = 0
        for j in range(i+1 ,n): 
            if (arr[i] > arr[j]): 
                small+=1

        great = 0; 
        for j in range(i-1,-1,-1): 
            if (arr[i] < arr[j]): 
                great+=1
  
        invcount += great * small

    print( invcount )
n = 5
arr = [5,3,4,2,1]
# arr = [15,10,1,7,8]
maxInversions(arr)