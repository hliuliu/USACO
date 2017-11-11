
"""
ID: heng_li1
LANG: PYTHON2
TASK: prefix
"""
fin = open ('prefix.in', 'r')
fout = open ('prefix.out', 'w')

prims = []
s= ''

flag =0
for line in fin:
	if line[0]=='.':
		flag =1
		continue
	if not flag:
		prims.extend(line.split())
	else:
		s += line.strip()

haspref = [False]*(len(s)+1)


haspref[0] = True

prims.sort(key=lambda x: (len(x),x))


table = [[False]*len(prims) for _ in xrange(len(haspref))]

for i, p in enumerate(prims):
	ind = s.find(p)
	while ind>=0:
		table[ind+len(p)][i] = True
		ind = s.find(p,ind+1)



longest =0
for i in xrange(1, len(haspref)):
	for j,p in enumerate(prims):
		if len(p)>i:
			break
		if table[i][j]:
			haspref[i] = haspref[i] or haspref[i-len(p)]
			if haspref[i]:
				break
	if haspref[i]:
		longest = i

print >>fout, longest

fout.close()
