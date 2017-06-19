fac=[1]
for x in range(1, 367) :
	fac.append(fac[x-1]*x)
while True :
	n=int(input())
	if n==0 :
		break
	cnt=[0]*10
	x=fac[n]
	while x!=0 :
		cnt[x%10]=cnt[x%10]+1
		x=x//10
	print(n, "!", " --", sep="")
	for i in range(0, 10) :
		print("    (%d)    %d"%(i, cnt[i]), end='')
		if i==4 :
			print("")
	print("")
