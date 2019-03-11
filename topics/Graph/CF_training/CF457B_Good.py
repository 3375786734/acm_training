n, m = [int(x) for x in input().split()]
a = input()
b = input()
if a[0] == '<' and b[0] == 'v' and a[-1] == '>' and b[-1] == '^':
	print('YES')
elif a[0] == '>' and b[-1] == 'v' and a[-1] == '<' and b[0] == '^':
	print('YES')
else:
	print('NO')
