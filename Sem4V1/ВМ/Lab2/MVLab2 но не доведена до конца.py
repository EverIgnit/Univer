import copy


def matrix_mul_internet(input_matrix1, input_matrix2):
    end_matrix = input_matrix1
    if len(input_matrix1) != len(input_matrix2):
        print("matrix can't be multiplied")
    else:
        size = len(input_matrix1)
        for i in range(0, size):
            for j in range(0, size):
                for k in range(0, size):
                    end_matrix[i][j] += input_matrix1[i][k] * input_matrix2[k][j]
    return end_matrix


def matrix_mul(a, b):
    res = [[0 for j in range(len(b[0]))] for i in range(len(a))]
    for i in range(len(a)):
        for j in range(len(b[0])):
           res[i] += a[i][j]*b[i]
    return res


def reverse_matrix(matrix):
    for i in range(0, 4):
        for j in range(i, 4):
            a = matrix[i][j]
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = a
    return matrix


def transform_matrix_into_up_triangle(matrix):
    for i in range(0, 4):
        j = i - 1
        while j >= 0:
            matrix[i][j] = 0
            j -= 1
    return matrix


def transform_matrix_into_low_triangle(matrix):
    for j in range(0, 4):
        i = j - 1
        while i >= 0:
            matrix[i][j] = 0
            i -= 1
    return matrix


def round_matrix(matrix):
    for i in range(0, 4):
        matrix[i] *= 100
        matrix[i] = round(matrix[i])
        matrix[i] = matrix[i] / 100


def main():
    matrix = [[3.3, -2.5, 19.2, -10.8],
              [5.5, -9.3, -14.2, 13.2],
              [7.1, -11.5, 5.3, -6.7],
              [14.2, 23.4, -8.8, 5.3]]
    vector = [4.3, 6.8, -1.8, 7.2]
    low_tr_matrix = transform_matrix_into_low_triangle(copy.deepcopy(matrix))
    print("low:", low_tr_matrix)
    up_tr_matrix = transform_matrix_into_up_triangle(copy.deepcopy(matrix))
    print("up:", up_tr_matrix)
    rev_low_tr_matrix = reverse_matrix(copy.deepcopy(low_tr_matrix))
    print("rev low:", rev_low_tr_matrix)
    rev_up_tr_matrix = reverse_matrix(copy.deepcopy(up_tr_matrix))
    print("rev up:", rev_up_tr_matrix)
    y_matrix = matrix_mul(
        copy.deepcopy(rev_low_tr_matrix),
        copy.deepcopy(vector))
    print("y:", y_matrix)
    round_matrix(y_matrix)
    print("Y:", y_matrix)
    res = matrix_mul(
        copy.deepcopy(y_matrix),
        copy.deepcopy(rev_up_tr_matrix))
    print("X (not round):", res)
    round_matrix(res)
    print("X:", res)


main()
