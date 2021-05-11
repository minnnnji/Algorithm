
def numPaths(warehouse):
    # Write your code here
    visited = [[-1] * (m) for _ in range(n)]

    
    if warehouse[0][0] == 0:
        visited[0][0] = 0
    else:
        visited[0][0] = 1

    print(warehouse)
    # print(visited)
    for i in range(1,n):
        print(warehouse[i][0])
        if warehouse[i][0] == 0:
            visited[i][0] = 0
        else:
            visited[i][0] = visited[i-1][0]
        
    for i in range(1,m):
        if warehouse[0][i] == 0:
            visited[0][i] = 0
        else:
            visited[0][i] = visited[0][i-1]
    
    for x in range(1, n):
        for y in range(1,m):
            if warehouse[x][y] == 0:
                visited[x][y] = 0
            else:
                visited[x][y] = visited[x-1][y ] + visited[x][y-1]
    
    print(visited)
        
    

n = 3
m = 4
warehouse = [[1,1,1,1],[1,1,1,1],[1,1,1,1]]
# warehouse = [[1,1],[0,1]]
numPaths(warehouse)