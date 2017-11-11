
"""
ID: heng_li1
LANG: PYTHON2
TASK: preface
"""



fin = open ('preface.in', 'r')
fout = open ('preface.out', 'w')


def roman(i,freqs):
	for fst,snd,trd in ['IVX','XLC','CDM']:
		digit = i%10
		i-= digit
		i/=10
		if digit==9:
			for c in fst+trd:
				freqs[c]+=1
			digit =0
		if digit >=5:
			freqs[snd]+=1;
			digit -=5;
		if digit ==4:
			for c in fst+snd:
				freqs[c]+=1
			digit =0
		freqs[fst]+=digit
	freqs['M']+=i



n = int(fin.readline())
roman_str = 'IVXLCDM'
freqs={k:0 for k in roman_str}

for i in xrange(1,n+1):
	roman(i,freqs)

for last in reversed(roman_str):
	if freqs[last]:
		break

for ch in roman_str:
	print >>fout, ch, freqs[ch]
	if ch==last:
		break


fout.close()
