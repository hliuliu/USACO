
/*
ID: heng_li1
TASK: fence
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;
typedef unordered_multiset<int> USI;
typedef unordered_map<int,int> UMI;
typedef vector<USI> VU;
typedef vector<UMI> VM;
typedef multiset<int> SI;
typedef vector<SI> VS;



void findEC(int start, vector<int> &trav, VU &G) {
	SI tmp (G[start].begin(),G[start].end());
	for (int v:tmp) {
		auto it = G[start].find(v);
		if (it!=G[start].end()) {
			G[start].erase(it);
			it = G[v].find(start);
			G[v].erase(it);
			findEC(v,trav,G);
		}
	}
	trav.push_back(start);
}

int main() {
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");

    int n,a,b;

    fin >> n;

    VU G(500, USI() );

    USI vis;

    while (n--) {
    	fin >> a >> b;
    	a--;b--;
    	G[a].insert(b);
    	G[b].insert(a);
    	vis.insert(a);
    	vis.insert(b);
    }

    n= G.size();

    vector<int> trav;
    int start =0;

    SI ovis (vis.begin(),vis.end());
    for (int i : ovis) {
    	// find min vertex
    	start = i;
    	break;
    }

    for (int i : ovis) {
    	// find min odd vertex, if exists
    	if (G[i].size()&1) {
    		start=i;
    		break;
    	}
    }

    findEC(start,trav,G);

    reverse(trav.begin(),trav.end());

    for (int &t:trav) {t++;}

    copy(trav.begin(),trav.end(), ostream_iterator<int>(fout,"\n"));
    // fout << endl;

    fout.close();
    return 0;
}
