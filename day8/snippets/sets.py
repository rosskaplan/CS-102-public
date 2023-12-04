a = set(range(100)) # create a set of numbers 1-100
print(a)
print(50 in a)
print(200 in a)
a.remove(50)
a.add(200)
print(50 in a)
print(200 in a)
x = set(range(75)) # Create a set of numbers from 0 to 74
y = set(range(50, 100)) # Create a set of numbers from 50 to 100
print(x.intersection(y)) # Get the numbers that are in boths sets
print(x.union(y)) # Get the numbers that are in either set
