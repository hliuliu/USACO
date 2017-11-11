
"""
ID: heng_li1
LANG: PYTHON2
TASK: dualpal
"""
fin = open ('dualpal.in', 'r')
fout = open ('dualpal.out', 'w')

def tobase(s,b):
	rep = []
	while s:
		s,r = divmod(s,b)
		rep.insert(0,r)
	return rep

def ispal(seq):
	i = 0
	j = len(seq)-1
	while i<j:
		if seq[i]!=seq[j]:
			return False
		i+=1
		j-=1
	return True


n,s = map(int, fin.readline().split())

pals = [None]*2 + [tobase(s,b) for b in xrange(2,11)]

def incr(rep,b):
	if rep==[b-1]*(len(rep)):
		rep[:] = [0]*len(rep)
		rep.insert(0,1)
	else:
		index = -1
		while rep[index]==b-1:
			rep[index] = 0
			index-=1
		rep[index]+=1

while n:
	s+=1
	count = 0
	for b in xrange(2,11):
		incr(pals[b],b)
		if count<2 and ispal(pals[b]):
			count+=1
	if count>=2:
		print >> fout, s
		n-=1


fout.close()
