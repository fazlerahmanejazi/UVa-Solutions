fib=[1, 2, 3]
for x in range(3, 1001) :
	fib.append(fib[x-1]+fib[x-2])
try:
	while True :
		n=int(input())
		if n=="" :
			break
		print(fib[n])
except EOFError:
	pass
