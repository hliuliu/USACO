
/*
ID: heng_li1
TASK: ariprog
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

typedef pair<int,int> PII;
set <PII> progression;

bool dfs(int n, vector<bool> &bisquare, int a, int b) {
	while (n) {
		if(a>=bisquare.size() || !bisquare[a]) {
			return false;
		}
		a+=b;
		n--;
	}
	return true;
}

int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");

    int n,m;
    fin >> n >> m;
    int upper = 2*m*m+1;
    vector<bool> bisquare (upper, false);
    set<int> S;

    for(int p =0;p<=m;p++) {
    	for (int q=p;q<=m;q++) {
    		int res = p*p+q*q;
    		bisquare[res] = true;
    		S.insert(res);
    	}
    }

    vector<int> diff(upper, 0);

    int last =0;
    for (int s: S) {
    	diff[last] = s-last;
    	last =s;
    }
    diff[last] =1;


    // bool found = false;
    for (int a: S) {
    	for(int b =diff[a] ; a+b*(n-1) <upper; b++) {
    		if (dfs(n, bisquare, a,b)) {
    			progression.insert(make_pair(b,a));
    			// fout << a << " " << b << endl;
    			// found = true;
    		}
    	}
    }



    for (PII p:progression) {
    	fout << p.second << " " << p.first << endl;
    }

    if (progression.empty()) {
    	fout << "NONE" << endl;
    }



    fout.close();
    return 0;
}
