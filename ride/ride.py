"""
ID: heng_li1
TASK: ride
LANG: PYTHON2                 
"""

istream, ostream = open('ride.in', 'r'), open('ride.out','w')

comet,group = [istream.readline().strip() for _ in [1,2]]

def prodmod47(word):
	ans = 1
	for w in word:
		ans *= (ord(w)-ord('A')+1)
		ans %= 47
	return ans

c,g = map(prodmod47, [comet,group])

if c==g:
	print >>ostream, 'GO'
else:
	print >>ostream, 'STAY'


