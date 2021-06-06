def main():
    a = [[0.34, 0.71, 0.63],
         [0.71, -0.65, -0.18],
         [1.17, -2.35, 0.75]]
    b = [2.08, 0.17, 1.28]
    n = len(a)
    for d in range(0, n-1):    # d for diagonal
        b[d] *= 1/a[d][d]
        for i in range(d+1, n):
            b[i] -= b[d]*a[i][d]
    for d in reversed(range(1, n)):
        b[d] *= 1/a[d][d]
        for i in reversed(range(0, d)):
            b[i] -= b[d] * a[i][d]
    print(b)


main()
