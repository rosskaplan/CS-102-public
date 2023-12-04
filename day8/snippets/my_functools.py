import functools

def add(a, b):
    return a + b

add_one = functools.partial(add, b=1)
print(add_one(4))


@functools.lru_cache(maxsize=128)
def fib_cached(n):
    if n in (0, 1):
        return 1
    else:
        return fib_cached(n-1) + fib_cached(n-2)

def fib(n):
    if n in (0, 1):
        return 1
    else:
        return fib(n-1) + fib(n-2)

print('running fib cached')
print(fib_cached(100))
print('running fib')
print(fib(34))
