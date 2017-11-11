
"""
ID: heng_li1
LANG: PYTHON2
TASK: msquare
"""
fin = open ('msquare.in', 'r')
fout = open ('msquare.out', 'w')

initial = '12345678'

final = ''.join(fin.readline().split())



used = {initial}

q = [(initial,'')]

def moveA(curr):
	curr = list(curr)
	curr.reverse()
	return ''.join(curr)

def moveB(curr):
	return curr[3]+curr[:3]+curr[5:8]+curr[4]

def moveC(curr):
	order = [0,6,1,3,4,2,5,7]
	return ''.join([curr[i] for i in order])

while q:
	curr,currseq = q.pop(0)
	if curr == final:
		print >> fout, len(currseq)
		print >> fout, currseq
		break
	for func, name in zip([moveA, moveB,moveC],'ABC'):
		nxt = func(curr)
		if nxt not in used:
			q.append((nxt,currseq+name))
			used.add(nxt)


fout.close()
