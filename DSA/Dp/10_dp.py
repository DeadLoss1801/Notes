def solve(n, m, arr):
    prev = [0]*m
    
    for i in range(n):
        for j in range(m):
            if i==0  and j == 0:
                prev[j] = arr[i][j] 
                continue
            up = int(1e9)
            left = int(1e9)
            if i > 0:
                up = prev[j]
            if j > 0:
                left = prev[j-1]

            prev[j] = arr[i][j] + min(up, left)
    return prev[m-1]


def main():
    arr = [[5, 9, 6], [11, 5, 2]]
    n = len(arr)
    m = len(arr[0])
    print(solve(n, m, arr))


if __name__ == "__main__":
    main()
