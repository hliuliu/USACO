
/*
ID: heng_li1
TASK: zerosum
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const string opstr = " +-";

int getsum(vector<char> ops,int n) {
	vector <int> toks;
	toks.push_back(1);
	for (int i =0;i<n-1;i++) {
		if (ops[i]==' ') {
			toks[toks.size()-1] *= 10;
			toks[toks.size()-1] += (toks[toks.size()-1]<0? -1:1)*(i+2);
		} else {
			toks.push_back((ops[i]=='-'? -1:1)*(i+2));
		}
	}
	int sm =0;
	for (int t:toks) {
		sm+= t;
	}
	return sm;
}

void process(vector<char> ops,int n, ofstream &fout) {
	int sm = getsum(ops,n);
	if (!sm) {
		for (int i=1;i<n;i++) {
			fout << i << ops[i-1];
		}
		fout << n << endl;
	}
}

void genops(vector<char> ops,int n, ofstream &fout) {
	if (ops.size()==n-1) {
		process(ops,n,fout);
		return;
	}

	for (char c: opstr) {
		ops.push_back(c);
		genops(ops,n,fout);
		ops.pop_back();
	}

}

int main() {
    ofstream fout ("zerosum.out");
    ifstream fin ("zerosum.in");

    int n;
    fin >> n;

    vector<char> ops;

    genops(ops,n,fout);

    fout.close();
    return 0;
}
