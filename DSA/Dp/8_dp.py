# Grid unique paths

def countWaysUtil(m, n, dp):
    for i in range(m):
        for j in range(n):
            if i == 0 and j == 0:
                dp[i][j] = 1
                continue
            up = 0 
            left = 0
            if i > 0:
                up = dp[i-1][j] 
            if j > 0:
                left = dp[i][j-1]
            
            dp[i][j] = up + left
    return dp[m-1][n-1]

def countWays(m, n):
    dp =[[-1 for j in range(n)] for i in range(m)]
    return countWaysUtil(m, n, dp)

def main():
    m = 3
    n = 2
    print(countWays(m, n))

if __name__ == "__main__":
    main()