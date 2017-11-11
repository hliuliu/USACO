
"""
ID: heng_li1
LANG: PYTHON2
TASK: wormhole
"""
fin = open ('wormhole.in', 'r')
fout = open ('wormhole.out', 'w')

n = int(fin.readline())

wormholes = [map(int,fin.readline().split()) for _ in xrange(n)]
for h in wormholes:
	h.reverse()
wormholes.sort()
for h in wormholes:
	h.reverse()

count =0


def trav(start, match):
	visited = set()
	while 1:
		if start in visited:
			return False
		visited.add(start)
		if start== n-1 or wormholes[start][1]!=wormholes[start+1][1]:
			return True
		start = match[start+1]


def safepairs(match):
	for i in xrange(n):
		if not trav(i,match):
			return False
	return True


def genpairs(unused,match):
	global count
	if not unused:
		if not safepairs(match):
			# print match
			count +=1
		return
	i = unused.pop()
	for j in set(unused):
		unused.discard(j)
		match[i] = j
		match[j] = i
		genpairs(unused,match)
		unused.add(j)
	unused.add(i)

match = [0]*n
unused = set(xrange(n))
genpairs(unused,match)

print >>fout, count

fout.close()
