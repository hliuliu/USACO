
/*
ID: heng_li1
TASK: lamps
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <functional>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;


string reversed(string s) {
	string rev = s;
	for (int i=0;i<s.length();i++) {
		rev[s.length()-i-1] = s[i];
	}
	return rev;
}

// template<int N>
bool bitset_cmp( bitset<100> x,  bitset<100> y)
{
    for (int i = 0; i < 100; i++) {
        if (x[i] ^ y[i]) return y[i];
    }
    return false;
}

bool (*cfptr) (bitset<100>, bitset<100>) = bitset_cmp;

bitset<100> press(int button, bitset<100> prev) {
	bitset<100> ret (prev);
	switch(button) {
		case 1:
			ret.flip();
			break;
		case 2:
			for (int i=0;i<100;i+=2) {
				ret.flip(i);
			}
			break;
		case 3:
			for (int i=1;i<100;i+=2) {
				ret.flip(i);
			}
			break;
		default:
			for (int i=0;i<100;i+=3) {
				ret.flip(i);
			}
	}
	return ret;
}

void bfs (bitset<100> start, bitset<100> end, bitset<100> known,vector<bitset<100> > &results, int c) {
	set<bitset<100>, bool(*)(bitset<100>,bitset<100>) > q(cfptr), nq(cfptr);
	q.insert(start);
	for (;c>0;c--) {
		for (bitset<100> bt:q) {
			for (int i =1;i<5;i++) {
				nq.insert(press(i,bt));
			}
		}
		q.clear();
		q= nq;
		nq.clear();
	}
	// results = q;
	for (bitset<100> res: q) {
		// cerr << res << endl;
		// cerr << end << endl;
		// cerr << known << endl;
		bitset<100> check = (end ^ res) & known;
		if (check.none()) {
			results.push_back(res);
		}
	}

}

int main() {
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");
    int n,c,x;

    fin >> n >> c;

    const int nconst = 100;

    bitset<nconst> start,end, known;

    start.flip();

    fin >> x;
    while (--x>=0) {
    	end[x] = 1;
    	known[x] = 1;
    	fin >> x;
    }

    fin >> x;
    while (--x>=0) {
    	known[x] = 1;
    	fin >> x;
    }

    // cerr << start << endl;
    // cerr << end << endl;
    // cerr << known << endl;

    

    vector<bitset<100> > results;
    bfs(start,end,known,results,c);

    sort(results.begin(),results.end(),bitset_cmp);

    for (bitset<100> res:results) {
    	// cerr << res << endl;
    	fout << reversed(res.to_string().substr(100-n)) << endl;
    }

    if (results.empty()) {
    	fout << "IMPOSSIBLE" << endl;
    }



    fout.close();
    return 0;
}
