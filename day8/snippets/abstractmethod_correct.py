import abc # abstract base class

class Foo(abc.ABC):
    @abc.abstractmethod
    def print_me(self):
        pass

class XBar(Foo):
    def __init__(self, x):
        self.x = x

    def print_me(self):
        print(self.x.lower())

class YBar(Foo):
    def __init__(self, y):
        self.y = y

    def print_me(self):
        print(self.y.upper())

xbar = XBar('xyz')
ybar = YBar('xyz')
xbar.print_me()
ybar.print_me()
