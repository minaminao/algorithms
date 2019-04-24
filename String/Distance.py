def levenshtein_distance(a, b):
    """
    Verified: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3517423#1
    """
    m = len(a)
    n = len(b)
    ld = [[m + n for j in range(n + 1)] for i in range(m + 1)]
    for i in range(m + 1):
        ld[i][0] = i
    for j in range(n + 1):
        ld[0][j] = j
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            ld[i][j] = min(ld[i-1][j]+1,
                           ld[i][j-1]+1,
                           ld[i-1][j-1]+(a[i-1] != b[j-1]))
    return ld[m][n]