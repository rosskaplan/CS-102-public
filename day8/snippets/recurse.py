def count(n):
    if n == 0:
        return 0
    else:
        return 1 + count(n-1)

print(count(5))
