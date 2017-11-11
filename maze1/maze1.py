
"""
ID: heng_li1
LANG: PYTHON2
TASK: maze1
"""
fin = open ('maze1.in', 'r')
fout = open ('maze1.out', 'w')

w,h = map(int, fin.readline().split())

moves = [(0,1,1),(-1,0,2),(0,-1,8),(1,0,4)]

grid = [fin.readline().replace('\n','') for _ in xrange(2*h+1)]


maze = [[0]*w for _ in xrange(h)]

for i in xrange(h):
	for j in xrange(w):
		for dx,dy,b in moves:
			if grid[2*i+1+dx][2*j+1+dy]!=' ':
				maze[i][j]|=b

# print maze

exits = []

for i in xrange(h):
	if not maze[i][0]&8 :
		exits.append((i,0,8))
	if not maze[i][-1]&1 :
		exits.append((i,w-1,1))

for j in xrange(w):
	if not maze[0][j]&2:
		exits.append((0,j,2))
	if not maze[-1][j]&4:
		exits.append((h-1,j,4))

# print exits

optpaths = [[[0]*w for _ in xrange(h)] for _ in exits]

for (ex,ey,ed), mpath in zip(exits,optpaths):
	seen = [[0]*w for _ in xrange(h)]
	q = [(ex,ey,1)]
	seen[ex][ey] = 1
	mpath[ex][ey] = 1
	while q:
		x,y,dst = q.pop(0)
		for dx,dy,b in moves:
			if maze[x][y]&b:
				continue
			nx,ny = x+dx,y+dy
			if 0<=nx<h and 0<=ny<w and not seen[nx][ny]:
				mpath[nx][ny] = dst+1
				q.append((nx,ny,dst+1))
				seen[nx][ny] = 1
	# print mpath

print >>fout, max([min( [mpath[i][j] for mpath in optpaths] ) for i in xrange(h) for j in xrange(w)])

fout.close()
