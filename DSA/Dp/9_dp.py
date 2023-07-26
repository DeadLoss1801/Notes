# grid unique paths 2

def solveUtil(n, m, arr, dp):
    for i  in range(n):
        for j in range(m):
            if i > 0 and  j > 0 and arr[i][j] == -1:
                dp[i][j] = 0
                continue
            if i == 0 and j ==0 :
                dp[i][j] =1
                continue
            up = 0 
            left = 0
            if i > 0 :
                up = dp[i-1][j] 
            if j > 0:
                left = dp[i][j-1]
            dp[i][j] = up  + left
    return dp[n-1][m-1]


def solve(n, m , arr):
    dp = [[-1 for j in range(m )] for i in range(n)]
    return solveUtil(n, m , arr, dp)

def main():
    maze = [[0, 0, 0], 
            [0, -1, 0], 
            [0, 0,0]]
    n = len(maze)
    m = len(maze[0])
    print(solve(n, m , maze))

if __name__ == "__main__":
    main()
