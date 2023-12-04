def apply_function(f, lst):
    length = len(lst)
    for n in range(length):
        lst[n] = f(lst[n])

lst = [1, 2, 3]
print(lst)
apply_function(lambda x: x + 1, lst)
print(lst)
