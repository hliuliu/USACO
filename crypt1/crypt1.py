
"""
ID: heng_li1
LANG: PYTHON2
TASK: crypt1
"""
fin = open ('crypt1.in', 'r')
fout = open ('crypt1.out', 'w')

n = int(fin.readline())
digits = set(map(int, fin.readline().split()))


def verify(x, numd):
	factor = 10**numd
	if not factor//10<=x<factor:
		return False
	while x:
		x,r = divmod(x,10)
		if r not in digits:
			return False
	return True

def valid_pair(n1,n2):
	q,r = divmod(n2,10)
	p1,p2 = n1*r, n1*q
	return verify(p1,3) and verify(p2,3) and verify(n1*n2, 4)




def gennums(numd):
	if numd==0:
		yield 0
	else:
		for num in gennums(numd-1):
			for d in digits:
				yield 10*num+d

count = 0
for n1 in gennums(3):
	for n2 in gennums(2):
		if valid_pair(n1,n2):
			count +=1

print >> fout, count

fout.close()
