classroom = {} # Create an empty dictionary (dict)
# Set values in the dict:
classroom['Cory'] = 80
classroom['Ross'] = 90
classroom['Gordon'] = 95
print(classroom)
# Get values in the dict:
print(classroom['Cory'])
print(list(classroom.items()))
print(list(classroom.keys()))
print(list(classroom.values()))
# Store a nested dict:
classroom = dict() # Create an empty dictionary (dict)
classroom['Cory'] = {'Grades': [75, 85, 95]}
classroom['Ross'] = {'Grades': [75, 85, 95, 100]}
classroom['Gordon'] = {'Grades': [95, 95]}
# Nested access
print(classroom)
print(classroom['Ross']['Grades'][-1]) # Get the last grade of Ross
