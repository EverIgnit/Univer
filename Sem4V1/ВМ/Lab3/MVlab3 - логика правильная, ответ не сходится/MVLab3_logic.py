def find_max_in_col(a, m, swap_lines_ind):
    max_el = a[0][0]
    max_ind = 0
    for i in range(swap_lines_ind, m):
        if a[i][0] > max_el:
            max_el = a[i][0]
            max_ind = i
    return max_ind


def swap_lines(a, n, max_ind, swap_lines_ind):
    if max_ind != 0:
        for j in range(swap_lines_ind, n):
            a[swap_lines_ind][j], a[max_ind][j] = a[max_ind][j], a[swap_lines_ind][j]
