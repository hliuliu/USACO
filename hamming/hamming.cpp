
/*
ID: heng_li1
TASK: hamming
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool G[1<<8][1<<8];

bool far(int p,int q, int d) {
	int x = p^q;
	while (d--) {
		if (!x) {
			return false;
		}
		x = x ^(x&(-x));
	}
	return true;
}

bool clique_search(int n,vector<int> &seq, int start, int end) {
	if (seq.size()==n) {
		return true;
	}
	for (int i =start; i<end;i++) {
		bool flag = true;
		for (int j:seq) {
			if (!G[i][j]) {
				flag= false;
				break;
			}
		}
		if (flag) {
			seq.push_back(i);
			if (clique_search(n,seq,i+1,end)) {
				return true;
			}
			seq.pop_back();
		}
	}
	return false;
}

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");

    int n,b,d;
    fin >> n >> b >> d;

    vector<int> seq;

    for (int i=0;i<(1<<b);i++) {
    	G[i][i] = false;
    	for (int j =0;j<i;j++) {
    		G[i][j] = G[j][i] = far(i,j, d);
    	}
    }

    clique_search(n,seq,0,1<<b);

    copy(seq.begin(),seq.end(),ostream_iterator<int>(cerr, " "));
    cerr << endl;

    for (int i=0;i<seq.size();i++) {
    	fout << seq[i] << ((i%10==9 || i==seq.size()-1)? "\n" : " ") ;
    }


    fout.close();
    return 0;
}
