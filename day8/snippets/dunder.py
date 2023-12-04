class Interval():
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def __repr__(self):
        return f'{self.start} -> {self.end}'

    def __str__(self):
        return f'{self.start} -> {self.end}'

    def __contains__(self, element):
        return bool(self.start < element < self.end)

    def __iter__(self):
        return iter(range(self.start, self.end + 1))

    def __mul__(self, other):
        return Interval(max(self.start, other.start), min(self.end, other.end))

    def __nonzero__(self):
        return bool(len(self))

    def __len__(self):
        return self.end - self.start

foo = Interval(5, 9)
bar = Interval(7, 11)
empty = Interval(7, 7)
print(foo)
print(6 in foo)
print(list(foo))
print(foo * bar)
print(len(empty))
print(bool(empty))
