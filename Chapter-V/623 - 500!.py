from sys import stdin
fac=[1]
for x in range(1, 1001) :
	fac.append(fac[x-1]*x)
try:
	while True :
		n=int(input())
		if n=="" :
			break
		print(n, "!", "\n", fac[n], sep="")
except EOFError:
	pass
