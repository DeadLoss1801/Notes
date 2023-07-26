import sys

def solve(n, arr):
    dp =[[-1 for j in range(n+1)]for i  in range(n)]

    for i in range(n+1):
        dp[0][i] = i * arr[0]

    for ind in range(1, n):
        for length in range(1, n+1):
            notTaken   = 0 + dp[ind-1][length]
            taken = -sys.maxsize
            rodLength = ind+1
            if rodLength <= length:
                taken = arr[ind] + dp[ind][length - rodLength]
            
            dp[ind][length] = max(notTaken, taken)
    return dp[n-1][n]




def main():
    arr=[2, 5, 7, 8, 10]
    n=5
    print(solve(n, arr))


if __name__ == "__main__":
    main()
