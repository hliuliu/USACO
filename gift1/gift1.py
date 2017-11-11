
"""
ID: heng_li1
LANG: PYTHON2
TASK: gift1
"""
fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')

np = int(fin.readline())

people = [fin.readline().strip() for _ in xrange(np)]

earnings = {p:0 for p in people}

for _ in xrange(np):
	giver = fin.readline().strip()
	amt,ng = map(int, fin.readline().split())
	if ng==0:
		earnings[giver]+=amt
	else:
		amtdiv,amt = divmod(amt,ng)
		for _ in xrange(ng):
			earnings[fin.readline().strip()] += amtdiv
		earnings[giver]-=ng*amtdiv

for p in people:
	print >>fout, p, earnings[p]


fout.close()
