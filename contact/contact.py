
"""
ID: heng_li1
LANG: PYTHON2
TASK: contact
"""

from collections import defaultdict as dd

fin = open ('contact.in', 'r')
fout = open ('contact.out', 'w')

a,b,n = map(int, fin.readline().split())

pat = ''

line= fin.readline().strip()
while line:
	pat += line
	line = fin.readline().strip()


counts = dd(int)

for i in xrange(len(pat)):
	for j in xrange(a,b+1):
		if i+j>len(pat):
			break
		counts[pat[i:i+j]]+=1

# print counts

grouped = dd(list)

for p, c in counts.iteritems():
	grouped[c].append(p)

# print grouped

for seq in grouped.values():
	seq.sort(key = lambda x: (len(x),x))

# print grouped

for c in sorted(grouped,reverse= True)[:n]:
	print >>fout, c
	for i,j in enumerate(grouped[c],1):
		if not i%6 or i== len(grouped[c]):
			print >>fout, j
		else:
			print >>fout, j,

fout.close()
