#  print lcs

def lcs(s1, s2):
    n = len(s1)
    m = len(s2)

    dp = [[-1 for j in range(m+1)] for i in range(n+1)]

    for i in range(n+1):
        dp[i][0] = 0
    for i in range(m+1):
        dp[0][i] = 0

    for ind1 in range(1, n+1):
        for ind2 in range(1, m+1):
            if s1[ind1-1] == s2[ind2-1]:
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1]
            else:
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1])

    len_ = dp[n][m]
    i = n
    j = m

    index = len_ - 1
    s = ""
    for k in range(1, 1+len_):
        s += "$"

    while i > 0 and j > 0:
        if s1[i-1] == s2[j-1]:
            s = s1[i-1] + s[:-1]
            i -= 1
            j -= 1
        elif dp[i-1][j] > dp[i][j-1]:
            i -= 1
        else:
            j -= 1
    print(s)


def main():
    s1 = "zxy"
    s2 = "yxz"
    lcs(s1, s2)


if __name__ == "__main__":
    main()
