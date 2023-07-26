#  Maximum sum of non-adjacent element
def solveUtil(ind, arr, dp):
    if ind == 0:
        return arr[ind]
    if ind < 0:
        return 0
    if dp[ind] != -1:
        return dp[ind]

    pick = arr[ind] + solveUtil(ind-2, arr, dp)
    noPick = solveUtil(ind-1, arr, dp)
    dp[ind] = max(pick, noPick)
    return dp[ind]


def solve(n, arr):
    dp = [-1 for i in range(n)]
    return solveUtil(n-1, arr, dp)


def main():
    arr = [2, 1, 4, 9]
    n = len(arr)
    print(solve(n, arr))


if __name__ == "__main__":
    main()
