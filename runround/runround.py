
"""
ID: heng_li1
LANG: PYTHON2
TASK: runround
"""
fin = open ('runround.in', 'r')
fout = open ('runround.out', 'w')

n = int(fin.readline())

def digits(n):
	return map(int, str(n))

dn = digits(n)
if 0 in dn:
	ind = dn.index(0)
	while ind < len(dn):
		dn[ind] = 1
		ind +=1

n = int(''.join(map(str, dn)))

def incrment(n):
	q,r = divmod(n,10)
	if r<9:
		return n+1
	return incrment(q)*10+1



def runround(n):
	dn = digits(n)
	curr = 0
	seq = []
	seen = [False]*10
	while len(seq)<len(dn):
		seq.append(dn[curr])
		seen[dn[curr]] = True
		curr += dn[curr]
		curr %= len(dn)
		check = dn[curr]!=seq[0] if len(seq)==len(dn) else seen[dn[curr]]
		if check:
			return False
	return True



n=incrment(n)
while not runround(n):
	n=incrment(n)

print >>fout, n

fout.close()
