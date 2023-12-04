lst = []

for x in range(100):
    if x % 3 or x % 5 == 0:
        continue
    lst.append(x)

print(lst)
