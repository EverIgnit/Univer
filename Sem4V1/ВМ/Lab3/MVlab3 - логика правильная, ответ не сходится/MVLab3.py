import MVLab3_logic


def main():
    a = [[0.34, 0.71, 0.63],
         [0.71, -0.65, -0.18],
         [1.17, -2.35, 0.75]]
    b = [2.08, 0.17, 1.28]
    n = len(a)

    for diag in range(0, n - 1):
        max_ind = MVLab3_logic.find_max_in_col(a, n, diag)  # ищем главный элемент
        MVLab3_logic.swap_lines(a, n, max_ind, diag)  # меняем верхнюю строку с главной
        for line in range(diag + 1, n):
            mul_el = a[line][diag] / a[diag][diag]     # запоминаем мн-ли для преобразования строк
            a[line][diag] = 0     # заполняем нулями под главных элементом
            for col in range(diag + 1, n):   # преобразуем элементы вне гл. стлб.
                a[line][col] -= a[diag][col] * mul_el
            b[line] -= b[diag] * mul_el    # преобразуем матрицу свободных членов

    print(a)
    print(b)


main()
