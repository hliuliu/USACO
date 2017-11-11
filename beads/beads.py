
"""
ID: heng_li1
LANG: PYTHON2
TASK: beads
"""
fin = open ('beads.in', 'r')
fout = open ('beads.out', 'w')

n = int(fin.readline())

def findnum(beads):
	count = 0
	col = None
	for b in beads:
		if col is not None and b not in ['w',col]:
			return count
		count += 1
		if b != 'w':
			col = b


def process(beads):
	n = len(beads)
	ans = 0
	for _ in xrange(n):
		if beads[0]!=beads[-1]:
			count = findnum(beads)
			beads.reverse()
			count += findnum(beads)
			beads.reverse()
			ans = max(ans,count)
			if count>=n:
				return n
		beads.append(beads.pop(0))
	return ans


beads = fin.readline().strip()

if 'b' not in beads or 'r' not in beads:
	print >>fout, n
else:
	beads = list(beads)
	a1 = process(beads)
	# beads.reverse()
	# a2= process(beads)
	print >> fout, a1




fout.close()
