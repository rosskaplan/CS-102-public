def count_to_n(n):
    for i in range(n):
        yield i

generator_10 = count_to_n(10)
generator_100 = count_to_n(100)
print(list(generator_10))
print(list(generator_100))
print(list(generator_10))
