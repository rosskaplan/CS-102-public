def anything(*args, **kwargs):
    for arg in args:
        print(arg)
    for key, value in kwargs.items():
        print(key, ':', value)

anything(1, 'hello', 5.3, boo='!', whatever=[])
