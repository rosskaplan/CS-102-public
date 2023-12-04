def divide(**kwargs):
    return kwargs['top'] / kwargs['bottom']

result = divide(top=1, bottom=5)
print(result)
