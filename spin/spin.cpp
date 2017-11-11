
/*
ID: heng_li1
TASK: spin
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool wedges [5][360];
int speed[5];

int calculate() {
	int counts[360];
	for (int t=0;t<360;t++) {
		fill_n(counts,360,0);
		for (int i =0;i<5;i++) {
			int offset = t*speed[i];
			offset %=360;
			for (int j=0;j<360;j++) {
				if (!wedges[i][j]) {
					continue;
				}
				if(++counts[(j+offset)%360]>=5) {
					return t;
				}
			}
		}
	}
	return -1;
}

int main() {
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");

    for (int i =0;i<5;i++) {
    	fill_n(wedges[i],360,false);
    	int w,x,y;
    	fin >> speed[i] >> w;
    	speed[i] %=360;

    	for (int j =0;j<w;j++) {
    		fin >> x >> y;
    		for (int k =x;k<=x+y;k++) {
    			wedges[i][k%360] = true;
    		}
    	}

    }

    int ans = calculate();

    if (ans>=0) {
    	fout << ans << endl;
    }else {
    	fout << "none" << endl;
    }

    fout.close();
    return 0;
}
