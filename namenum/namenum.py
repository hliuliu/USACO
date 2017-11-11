
"""
ID: heng_li1
LANG: PYTHON2
TASK: namenum
"""
fin = open ('namenum.in', 'r')
fout = open ('namenum.out', 'w')

def tonum(v):
	ans = 0
	for c in v:
		ans *=10
		ans += lton[c]
	return ans

n = int(fin.readline())

toname = {2:'ABC',3:'DEF',4:'GHI',5:'JKL',6:'MNO',7:'PRS',8:'TUV',9:'WXY'}

lton = {j:i for i in toname for j in toname[i]}

with open('dict.txt') as dh:
	valid = [line.strip() for line in dh]

valid_nums = {}
for v in valid:
	try:
		num = tonum(v)
	except KeyError:
		pass
	else:
		if num not in valid_nums:
			valid_nums[num] = []
		valid_nums[num].append(v)
# print valid_nums

if n in valid_nums:
	for name in valid_nums[n]:
		print >>fout, name
else:
	print >>fout, 'NONE'

fout.close()
