
/*
ID: heng_li1
TASK: butter
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef unsigned int UI;
typedef pair<int,int> PI;
typedef priority_queue<PI, vector<PI>, greater<PI> > PQ;

int G[800][800];
int cows[500];
int sp[500][800];
bool seen[800];

const int INF = 0xFFFFFF;

void compute_sp(int i, int p) {
	int *dist = sp[i];
	fill_n(dist, p, INF);
	int start = cows[i];
	dist[start] = 0;
	// fill_n(seen,p,false);
    PQ unseen;
    for (int j =0;j<p;j++) {
        unseen.push(make_pair(dist[j],j));
    }
	for (int _ =0 ;_<p; _++) {
		int mx = INF, nxt =-1;
        PI pr = unseen.top();
        unseen.pop();
        nxt = pr.second;
        // cout << nxt << endl;
		// for(int j:unseen) {
			// if (// !seen[j] && 
   //              dist[j]<mx
   //              ) {
			// 	mx = dist[j];
			// 	nxt = j;
			// }
		// }
		// seen[nxt] = true;
        // unseen.erase(nxt);
		for(int j =0;j<p;j++) {
			if (G[nxt][j]>0 && dist[j]>dist[nxt]+G[nxt][j]) {
				dist[j] = dist[nxt]+G[nxt][j];
                unseen.push(make_pair(dist[j], j));
			}
		}
	}
}

void printG(int p) {
	for (int i =0;i<p;i++) {
		cout << i << ": ";
		for (int j =0;j<p;j++) {
			if (G[i][j]>0) {
				cout << j << " -> " << G[i][j] << ", ";
			}
		}
		cout << endl;
	}
}

void printsps(int n,int p) {
	for (int i =0;i<n;i++) {
		cout << "cow " << i << " = " << cows[i] <<endl;
		int conn =0;
		for (int j =0;j<p;j++) {
			if (sp[i][j]<(INF)) {
				cout << j << " -> " << sp[i][j] << ", ";
				conn ++;
			}
		}
		cout << endl;
		cout << "Adjacency Count: " << conn << endl << endl;
	}
}

int main() {
    ofstream fout ("butter.out");
    ifstream fin ("butter.in");
    int n,p,c,x,y,d;

    fin >> n >> p >> c;

    for (int i=0;i<p;i++) {
    	fill_n(G[i],p,0);
    }

    for (int i=0;i<n;i++) {
    	fin >> cows[i];
    	cows[i] --;
    }

    //exit(0);

    for (int i=0;i<c;i++) {
    	fin >> x >> y >> d;
    	x--;y--;
    	G[x][y] = d;
    	G[y][x] = d;
    }

    //exit(0);

    // printG(p);

    for (int i=0;i<n;i++) {
    	compute_sp(i,p);
    }
    // printsps(n,p);

    UI opt = INF;

    for (int i =0;i<p;i++) {
    	UI sm = 0;
    	bool conn = true;
    	for (int j =0;j<n;j++) {
    		if (sp[j][i]<(INF)) {
    			sm+=sp[j][i];
    		}else {
    			conn= false;
    			break;
    		}
    	}
    	// cout << conn << endl;
    	if(conn) {
    		// cout << sm << endl;
    		opt = min(opt,sm);
    	}
    }

    fout << opt << endl;

    fout.close();
    return 0;
}
