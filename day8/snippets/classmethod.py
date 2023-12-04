class Foo():
    def __init__(self, one, two, three):
        self.one = one
        self.two = two
        self.three = three

    def print_all(self):
        print(self.one, self.two, self.three)

    @classmethod
    def make_foo_from_list(cls, lst):
        return cls(lst[0], lst[1], lst[2])

foo = Foo.make_foo_from_list(['a', 'b', 'c'])
foo.print_all()
