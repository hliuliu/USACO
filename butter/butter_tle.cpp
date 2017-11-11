
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

using namespace std;

typedef unsigned int UI;

UI G[800][800];
UI cows[500];
bool seen[800];

const UI INF = 0xFFFFFF;



void printG(int p) {
	for (int i =0;i<p;i++) {
		cout << i << ": ";
		for (int j =0;j<p;j++) {
			if (G[i][j]>0 && G[i][j]<INF) {
				cout << j << " -> " << G[i][j] << ", ";
			}
		}
		cout << endl;
	}
}



int main() {
    ofstream fout ("butter.out");
    ifstream fin ("butter.in");
    int n,p,c,x,y,d;

    fin >> n >> p >> c;

    for (int i=0;i<p;i++) {
    	fill_n(G[i],p,INF);
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

    for (int i =0;i<p;i++) {
    	G[i][i] =0;
    }

    //exit(0);

    // printG(p);

    // FW alg
    for (int i=0;i<p;++i) {
    	for(int j =0;j<p;++j) {
    		for (int k =0;k<p;++k) {
    			if (G[j][k]<G[j][i]+G[i][k])
    				G[j][k] = G[j][i]+G[i][k];
    		}
    	}
    }

    // printG(p);


    UI opt = INF;

    for (int i =0;i<p;++i) {
    	bool conn = true;
    	UI sm =0;
    	for (int j =0;j<n;++j) {
    		if (G[i][cows[j]]<INF) {
    			sm += G[i][cows[j]];
    		}else {
    			conn = false;
   				break;
    		}
    	}
    	if (conn) {
    		opt = min(opt,sm);
    	}
    }

    fout << opt << endl;

    fout.close();
    return 0;
}
