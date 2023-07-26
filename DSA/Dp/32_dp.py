# Distinct subsequence2
prime = int(1e9+7)
def solveUtil(s1, s2, ind1, ind2, dp) :
    if ind2 < 0:
        return 1
    if ind1 < 0:
        return 0
    
    if dp[ind1][ind2] !=-1 :
        return dp[ind1][ind2]
    
    if s1[ind1] == s2[ind2]:
        take = solveUtil(s1, s2, ind1-1, ind2-1, dp) 
        notTake = solveUtil(s1, s2, ind1-1, ind2, dp)

        dp[ind1][ind2] = (take + notTake)% prime
        return dp[ind1][ind2]
    else :
        notTake = solveUtil(s1, s2, ind1-1, ind2, dp)

        dp[ind1][ind2] = notTake
        return dp[ind1][ind2]


def  solve(s1, s2):
    n = len(s1)
    m = len(s2)

    dp =[[-1 for j in range(m)] for i in range(n)]
    return solveUtil(s1, s2, n-1, m-1, dp)


def main():
    s1 = "babgbag"
    s2 ="bag"

    print(solve(s1, s2))


if __name__ == "__main__":
    main()
