# Minimum insertions to make string palindrome
def lcs(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[0 for j in range(m+1)] for i in range(n+1)]

    for ind1 in range(1, n+1):
        for ind2 in range(1, m+1):
            if s1[ind1-1] == s2[ind2-1]:
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1]
            else:
                dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1])
    return dp[n][m]


def solve(s):
    t = s
    #  reverse a string
    s = s[::-1]
    return lcs(s, t)


def minimumInsertion(s):
    n = len(s)
    k = solve(s)
    return n - k


def main():
    s = "abcaa"
    print(minimumInsertion(s))


if __name__ == "__main__":
    main()
