def pythag(maxval):
    for a in range(1, maxval):
        for b in range(1, maxval):
            for c in range(1, maxval):
                if a**2 + b**2 == c**2:
                    return (a, b, c)

    return (None, None, None)

a, b, c = pythag(5)
if a is None:
    print('No solution')
else:
    print(a, b, c)
