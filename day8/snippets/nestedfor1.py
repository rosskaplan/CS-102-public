import pprint

a = []
for m in range(5):
    a.append([])
    for n in range(5):
        a[m].append((m, n))

pprint.pprint(a)
