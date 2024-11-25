
with open('../res/commands', 'r') as file:
	lst = []
	for line in file:
		if line.startswith(';'):
			continue
		lst.append(line.removesuffix('\n'))
	print(lst)