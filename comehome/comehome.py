
"""
ID: heng_li1
LANG: PYTHON2
TASK: comehome
"""
fin = open ('comehome.in', 'r')
fout = open ('comehome.out', 'w')

V = set()

G = {}

n = int(fin.readline())

for _ in xrange(n):
	u,v,cost =  fin.readline().split()
	cost = int(cost)
	for w in [u,v]:
		if w not in V:
			V.add(w)
			G[w] = {}
	if v not in G[u] or cost<G[u][v]:
		G[u][v] =cost
		G[v][u] = cost

# dijkstras

d = {v: 10**10 for v in V} 
d['Z'] =0;

mk = {v:False for v in V}

for _ in V:
	# print mk
	mx = float('inf')
	nxt = None
	for v in V:
		if not mk[v] and d[v]<mx:
			nxt = v
			mx = d[v]

	mk[nxt] = True
	for v in G[nxt]:
		d[v] = min(d[v], d[nxt]+G[nxt][v])

mv,md = None,float('inf')

for v,dv in d.iteritems():
	if ord('A')<=ord(v)<ord('Z'):
		if dv<md:
			mv,md = v,dv

# print d
print >>fout, mv,md




fout.close()
