import pprint
lst = [
    {'name': 'cory', 'grade': 80},
    {'name': 'deborah', 'grade': 100},
    {'name': 'ross', 'grade': 90},
    {'name': 'gordon', 'grade': 85},
]
print('Unsorted')
pprint.pprint(lst)
lst.sort(key=lambda record: record['grade'])
print('Sorted by grade')
pprint.pprint(lst)
lst.sort(key=lambda record: record['name'])
print('Sorted by name')
pprint.pprint(lst)
