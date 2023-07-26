# Ninja training
def solve(n, arr):
    dp = [[0 for j in range(4)] for i in range(n)]

    dp[0][0] = max(arr[0][1], arr[0][2])
    dp[0][1] = max(arr[0][0], arr[0][2])
    dp[0][2] = max(arr[0][0], arr[0][1])
    dp[0][3] = max(arr[0][1], max(arr[0][0], arr[0][2]))

    for day in range(1, n):
        for last in range(4):
            dp[day][last] = 0
            for task in range(3):
                if task != last:
                    activity = arr[day][task] + dp[day-1][task]
                    dp[day][last] = max(dp[day][last], activity)

    return dp[n-1][3]


def main():
    points = [[10, 40, 70],
              [20, 50, 80],
              [30, 60, 90]]
    n = len(points)
    print(solve(n, points))


if __name__ == "__main__":
    main()
