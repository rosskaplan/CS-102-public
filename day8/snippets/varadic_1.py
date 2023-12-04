def sum_inputs(*args):
    total = 0
    for arg in args:
        total += arg

    return total

my_sum = sum_inputs(1, 2, 3)
print(my_sum)
