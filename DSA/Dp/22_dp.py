# Coin change 2
def solve(arr, T):
    n = len(arr)
    dp = [([0] * (T+1))for _ in range(n)]

    for i in range(T+1):
        if i % arr[0] == 0:
            dp[0][i] = 1
        else:
            dp[0][i] = 0

    for ind in range(1, n):
        for target in range(T+1):
            notTake = dp[ind-1][target]
            take = 0
            if arr[ind] <= target:
                take = dp[ind][target - arr[ind]]
            dp[ind][target] = take + notTake

    ans = dp[n-1][T]
    if ans >= int(1e9):
        return -1
    return ans


def main():
    arr = [1, 2, 3]
    T = 4
    print(solve(arr, T))


if __name__ == "__main__":
    main()
