# Ninja and his friends 3-D dp

import sys


def solve(n, m, arr):
    dp = [[[0 for _ in range(m)] for _ in range(m)] for _ in range(n)]

    for j1 in range(m):
        for j2 in range(m):
            if j1 == j2:
                dp[n-1][j1][j2] = arr[n-1][j1]
            else:
                dp[n-1][j1][j2] = arr[n-1][j1] + arr[n-1][j2]

    for i in range(n-2, -1,  -1):
        for j1 in range(m):
            for j2 in range(m):
                maxi = -sys.maxsize

                for di in range(-1, 2):
                    for dj in range(-1, 2):
                        ans = 0
                        if j1 == j2:
                            ans = arr[i][j1]
                        else:
                            ans = arr[i][j1] + arr[i][j2]

                        if ((j1 + di < 0 or j1 + di >= m) or (j2+dj < 0 or j2+dj >= m)):
                            ans += int(-1e9)
                        else:
                            ans += dp[i+1][j1+di][j2+dj]

                        maxi = max(ans, maxi)

                dp[i][j1][j2] = maxi

    return dp[0][0][m-1]


def main():
    arr = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
    n = len(arr)
    m = len(arr[0])
    print(solve(n, m, arr))


if __name__ == "__main__":
    main()
