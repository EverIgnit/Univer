def fact_rec(n):
    if n < 2:
        return 1
    return n * fact_rec(n - 1)
# 3(n - 1) + 1 - трудоёмкость алгоритма


def fact(n, res):
    for i in range(1, n):
        res *= n - i
    return res
# 6(n-1) + 1 - трудоёмкость алгоритма
# 2(n-1) - число арифместических операций


def main():
    n = int(input("Enter n > 0:\n>\t"))
    print("Fact res:", fact_rec(n), "and it's complexity is", 3*(n-1)+1)
    print("Res:", fact(n, n), "and it's complexity is", 6*(n-1)+1)


main()
