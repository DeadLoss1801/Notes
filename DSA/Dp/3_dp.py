# frog jump  with distance K
import sys
def solveUtil(ind, height, dp, k):
    if ind == 0:
        return 0
    if dp[ind] != -1:
        return dp[ind]
    
    mmSteps = sys.maxsize

    for j in range(1, k+1):
        if ind - j >=0 :
            jump = solveUtil(ind-j, height, dp, k) + abs(height[ind] - height[ind-j])
            mmSteps = min(jump, mmSteps)
    
    dp[ind] = mmSteps
    return mmSteps

def solve(n, height , k):
    dp =[-1 for i in  range(n)]
    print(solveUtil(n-1, height, dp, k))

def main() :
    height = [30, 10, 60, 10, 60, 50]
    n = len(height)
    k = 2
    solve(n, height, k)


if __name__ == "__main__":
    main()