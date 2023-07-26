# Subset sum equal to target

def solve(n, k, arr):
    dp = [[0 for j in range(k+1)] for i in range(n)]
    for i in range(n):
        dp[i][0] = 1

    if arr[0] <= k:
        dp[0][arr[0]] = 1

    for ind in range(1, n):
        for target in range(1, k+1):
            notTaken = dp[ind-1][target]
            Taken = False
            if arr[ind] <= target:
                Taken = dp[ind-1][target - arr[ind]]
            dp[ind][target] = Taken + notTaken
    return dp[n-1][k]


def main():
    arr = [1, 2, 2, 3]
    k = 3
    n = len(arr)

    print(solve(n, k, arr))


if __name__ == "__main__":
    main()
