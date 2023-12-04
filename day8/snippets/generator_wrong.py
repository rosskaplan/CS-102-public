def count_to_3():
    yield 1
    yield 2
    yield 3

generator = count_to_3()
print(next(generator))
print(next(generator))
print(next(generator))
print(next(generator))
