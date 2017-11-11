
"""
ID: heng_li1
LANG: PYTHON2
TASK: fact4
"""
fin = open ('fact4.in', 'r')
fout = open ('fact4.out', 'w')

n = int(fin.readline())

fact =1

for i in xrange(1,n+1):
	fact*=i
	while fact%10==0:
		fact //=10

print >>fout, fact%10

fout.close()
