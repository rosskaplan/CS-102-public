import abc # abstract base class

class Foo(abc.ABC):
    @abc.abstractmethod
    def print_me():
        pass

foo = Foo()
