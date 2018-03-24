w = open("out.out", "w")

f = [0] * 60
C = [[0] * 60 for i in range(60)]

for i in range(0,51):
	C[i][0] = 1
	for j in range(1,i+1):
		C[i][j] = C[i-1][j] + C[i-1][j-1]
for i in range(1,51):
	f[i] = 2**(i*(i-1)//2)
	for j in range(1,i):
		f[i] -= C[i-1][j-1] * (2**((i-j)*(i-j-1)/2)) * f[j]
	w.write("\"%d\",\n" %f[i] )
    