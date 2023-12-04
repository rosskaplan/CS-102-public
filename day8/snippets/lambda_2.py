import pprint
lst = [
    {'name': 'zachary', 'grade': 70},
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
print('Highest Grade')
pprint.pprint(max(lst, key=lambda record: record['grade']))
print('First Name (Alphabetically)')
pprint.pprint(min(lst, key=lambda record: record['name']))
