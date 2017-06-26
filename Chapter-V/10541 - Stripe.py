fac=[1, 1]
for i in range(2, 210) :
	fac.append(fac[i-1]*i)
T=int(input())
while T>0 :
	T=T-1
	numbers=list(map(int, input().split()))
	N=numbers[0]
	K=numbers[1]
	blackSum=0
	for i in range(2, len(numbers)) :
		blackSum=blackSum+numbers[i]
	if N-blackSum<K-1 :
		print(0)
		continue
	x=N-blackSum+1
	ans=fac[x]
	ans=ans//fac[K]
	ans=ans//fac[x-K]
	print(int(ans))
