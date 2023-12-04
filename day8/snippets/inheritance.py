import abc # abstract base class

class Foo():
    def print_hi(self):
        print('hi')
    def print_bye(self):
        print('bye')

class Bar(Foo):
    def print_hi(self):
        print('hello there')

foo = Foo()
foo.print_hi()
foo.print_bye()
bar = Bar()
bar.print_hi()
bar.print_bye()
