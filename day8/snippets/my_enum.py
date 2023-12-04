import enum

class Mode(enum.Enum):
    READ = 1
    WRITE = 2
    EXECUTE = 3

r = Mode.READ
w = Mode.WRITE
e = Mode.EXECUTE

print(r, w, e)
