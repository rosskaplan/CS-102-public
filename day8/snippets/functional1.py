def transform(x: list, op):
    for n in range(len(x)):
        x[n] = op(x[n])

def add_one(x):
    return x + 1

x = [0, 1, 2]
print(x)
transform(x, add_one)
print(x)
