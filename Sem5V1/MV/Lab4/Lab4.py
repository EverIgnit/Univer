import math


def derivative(x):
    return 3 / (x + 3) + math.log(x + 3)


def fun(x):
    return x / ((x + 3) * (x + 3))


def middle_rectangle(f, a, b, n):
    h = (b - a) / n
    s = 0
    x = a + h / 2
    for i in range(n):
        s = s + f(x)
        x = x + h
    s = s * h
    return s


def left_rectangle(f, a, b, n):
    h = (b - a) / n
    s = 0
    x = a
    for i in range(n):
        s = s + f(x)
        x = x + h
    s = s * h
    return s


def right_rectangle(f, a, b, n):
    """Интеграл f(x) от a до b
    методом правых прямоугольн.
    при n разбиениях"""
    h = (b - a) / n
    s = 0
    x = a + h
    for i in range(n):
        s = s + f(x)
        x = x + h
    s = s * h
    return s


def trapeze(f, a, b, n):
    """Интеграл f(x) от a до b
    методом трапеций
    при n разбиениях"""
    h = (b - a) / n
    s = (f(a) + f(b)) / 2
    x = a + h
    for i in range(n - 1):
        s = s + f(x)
        x = x + h
    s = s * h
    return s


def simpson(f, a, b, n):
    """Интеграл f(x) от a до b
    методом Симпсона (парабол)
    при n разбиениях"""
    if n % 2 != 0:
        return
    h = (b - a) / n
    m = n // 2
    s = f(a) + f(b)
    x = a + h
    for i in range(m - 1):
        s = s + 4 * f(x) + 2 * f(x + h)
        x = x + 2 * h
    s = s + 4 * f(b - h)
    s = s * h / 3
    return s


def inaccuracies(a, b):
    return abs((a - b) / a)


def meth_stat(method, own_divs:bool):
    global a, b
    i = 2
    res = method(fun, a, b, i)
    if not own_divs:
        while inaccuracies(derivative(b) - derivative(a), res) > 0.001:
            i += 2
            res = method(fun, a, b, i)
    else:
        i = 4
        res = method(fun, a, b, i)
    print('кол-во разбиений:', i)
    print(res)
    print('погр:', inaccuracies(derivative(b) - derivative(a), res))


a, b = 0, 2
print('метод трап. выбором разбиений:')
meth_stat(trapeze, True)
print('метод трап. подсчётом разбиений:')
meth_stat(trapeze, False)
print('метод сред. прям. выбором разбиений:')
meth_stat(middle_rectangle, True)
print('метод сред. прям. подсчётом разбиений:')
meth_stat(middle_rectangle, False)
print('метод прав. прям. выбором разбиений:')
meth_stat(right_rectangle, True)
print('метод прав. прям. подсчётом разбиений:')
meth_stat(right_rectangle, False)
print('метод лев. прям. выбором разбиений:')
meth_stat(left_rectangle, True)
print('метод лев. прям. подсчётом разбиений:')
meth_stat(left_rectangle, False)
print('метод Симпсона выбором разбиений:')
meth_stat(simpson, True)
print('метод Симпсона подсчётом разбиений:')
meth_stat(simpson, False)
