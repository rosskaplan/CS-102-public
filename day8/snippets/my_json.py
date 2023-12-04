import json

lst = [
    {'name': 'cory', 'grade': 80},
    {'name': 'deborah', 'grade': 100},
    {'name': 'ross', 'grade': 90},
    {'name': 'gordon', 'grade': 85},
]

stringified = json.dumps(lst)

print(lst)
print(stringified)
print(lst[0])
print(stringified[0])

objectified = json.loads(stringified)

assert objectified == lst
