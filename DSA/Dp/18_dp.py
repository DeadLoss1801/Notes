# Subset sum equal to target (duplicate)

def solve(n, k, arr):
    dp = [[0]*(k+1)for i in range(n)]
    for i in range(n):
        dp[i][0] = 1

    if arr[0]  == 0 :
        dp[0][0] = 2
    else :
        dp[0][0] = 1   

    if arr[0]!=0 and arr[0] <= k:
        dp[0][arr[0]] = 1

    for ind in range(1, n):
        for target in range(0, k+1):
            notTaken = dp[ind-1][target]
            Taken = 0
            if arr[ind] <= target:
                Taken = dp[ind-1][target - arr[ind]]
            dp[ind][target] = Taken + notTaken
            # print(Taken  , notTaken)
        # print(dp[ind][k])
    
    return dp[n-1][k]


def main():
    arr = [0, 0, 1,2 ]
    k = 1
    n = len(arr)
    print(solve(n, sum(arr), arr))


if __name__ == "__main__":
    main()
