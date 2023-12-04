import abc # abstract base class

class Foo():
    def __init__(self, x):
        self.x = x

    def print_x(self):
        print('Printing x')
        print(self.x)

class Bar(Foo):
    def __init__(self, x, y):
        super().__init__(x)
        self.y = y

    def print_y(self):
        print('Printing y')
        print(self.y)

    def print_xy(self):
        print('Printing x and y')
        super().print_x()
        self.print_y()

foo = Foo(1)
foo.print_x()
bar = Bar(1, 2)
bar.print_x()
bar.print_y()
bar.print_xy()
