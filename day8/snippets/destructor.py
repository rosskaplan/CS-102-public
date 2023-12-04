class Foo():

    def __init__(self, x):
        self.x = x

    def print_x(self):
        print(self.x)

    def __del__(self):
        print('I am being destroyed')

foo = Foo(5)
foo.print_x()
print('getting rid of foo')
foo = 1
print('got rid of foo')
