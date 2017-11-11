
"""
ID: heng_li1
LANG: PYTHON2
TASK: concom
"""
fin = open ('concom.in', 'r')
fout = open ('concom.out', 'w')

n= int(fin.readline())

G= {i:{} for i in xrange(1,101)}

def controls(i):
	owns = [0]*(101)
	q = [i]
	visited = {i}
	while q:
		i = q.pop(0)
		for j in G[i]:
			
			if j in visited:
				continue
			owns[j]+=G[i][j]
			if owns[j]>50:
				q.append(j)
				visited.add(j)
	return [i for i in xrange(1,101) if owns[i]>50]



for _ in xrange(n):
	i,j,p = map(int, fin.readline().split())
	G[i][j] = p

for i in xrange(1,101):
	for j in controls(i):
		print >>fout, i,j

fout.close()
