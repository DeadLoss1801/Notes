# Subset sum equal to target

def solve(n, k, arr):
    dp = [[False for j in range(k+1)] for i in range(n)]
    for i in range(n):
        dp[i][0] = True

    if arr[0] <= k:
        dp[0][arr[0]] = True

    for ind in range(1, n):
        for target in range(1, k+1):
            notTaken = dp[ind-1][target]
            Taken = False
            if arr[ind] <= target:
                Taken = dp[ind-1][target - arr[ind]]
            dp[ind][target] = Taken or notTaken
    return dp[n-1][k]


def main():
    arr = [1, 2, 3, 4]
    k = 4
    n = len(arr)

    if solve(n, k, arr):
        print("Subset with given target found")
    else:
        print("Subset with given target not found")


if __name__ == "__main__":
    main()
