n = int(input())
for i in range (1,n+1):
	a = int(input())
	fact = 1
	while a > 0 :
		fact = fact*a
		a = a-1
	print(fact)	
	