
"""
ID: heng_li1
LANG: PYTHON2
TASK: castle
"""
fin = open ('castle.in', 'r')
fout = open ('castle.out', 'w')

m,n = map(int, fin.readline().split())

castle  = [map(int, fin.readline().split()) for _ in xrange(n)]

trav = [[0 for _ in row] for row in castle]

numrooms = 1

roomsize ={}

def fill(i,j):
	global trav, roomsize
	q = [(i,j)]
	trav[i][j] = numrooms
	dirs = {(1,0, -1),(2,-1,0), (4,0,1), (8,1,0)}
	sz =1
	while q:
		i,j = q.pop(0)
		for d, dx,dy in dirs:
			if not castle[i][j]&d:
				if not trav[i+dx][j+dy]:
					sz+=1
					q.append((i+dx,j+dy))
					trav[i+dx][j+dy] = numrooms
	roomsize[numrooms] = sz


for i in xrange(n):
	for j in xrange(m):
		if not trav[i][j]:
			fill(i,j)
			numrooms += 1

# for row in trav:
# 	print row

# print roomsize


maxwall = None

for j in xrange(m):
	for i in xrange(n-1,-1,-1):
		# check north wall
		if i>0 and castle[i][j]&2:
			if trav[i][j]!=trav[i-1][j] and (maxwall is None or maxwall[-1]< roomsize[trav[i][j]]+roomsize[trav[i-1][j]]):
				maxwall = (i,j,'N',roomsize[trav[i][j]]+roomsize[trav[i-1][j]])
		# check east wall
		if j<m-1 and castle[i][j]&4:
			if trav[i][j]!=trav[i][j+1] and (maxwall is None or maxwall[-1]< roomsize[trav[i][j]]+roomsize[trav[i][j+1]]):
				maxwall = (i,j,'E',roomsize[trav[i][j]]+roomsize[trav[i][j+1]])

# print maxwall

print >>fout, numrooms-1
print >>fout, max(roomsize.values())
print >>fout, maxwall[-1]
print >> fout, maxwall[0]+1, maxwall[1]+1, maxwall[2]

fout.close()
