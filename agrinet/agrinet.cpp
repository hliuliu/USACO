
/*
ID: heng_li1
TASK: agrinet
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
typedef vector<int> VI;
typedef unordered_set<int> USI;

int G[100][100];

int inf = 1E9;

int primMST(int n) {
	VI cost(n, inf), treeedge(n, -1);
	USI F,Q;
	for (int i =0;i<n;i++) {
		Q.insert(i);
	}
	int wt = 0;
	while (!Q.empty()) {
		int v;
		for (int x: Q) {v=x;break;}
		for(int x: Q) {
			if (cost[x]<cost[v]) {
				v =x;
			}
		}
		Q.erase(v);
		F.insert(v);
		if (treeedge[v]>=0) {
			wt += G[v][treeedge[v]];
		}
		for (int w =0; w<n;w++ ) {
			if (w!=v && Q.find(w)!=Q.end()) {
				if (G[v][w]<cost[w]) {
					cost[w] = G[v][w];
					treeedge[w] = v;
				}
			}
		}
	}
	return wt;
}

int main() {
    ofstream fout ("agrinet.out");
    ifstream fin ("agrinet.in");

    int n;
    fin >> n;

    for (int i =0; i<n;i++) {
    	for (int j =0;j<n;j++) {
    		fin >> G[i][j];
    	}
    }

    fout << primMST(n) << endl;

    fout.close();
    return 0;
}
