
/*
ID: heng_li1
TASK: numtri
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int tri [1000][1000], dp [1000][1000];

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");

    int r;
    fin >> r;


    for (int i =0;i<r;i++) {
    	for(int j =0;j<=i;j++) {
    		fin >> tri[i][j];
    	}
    }

    for (int j = 0;j<r;j++) {
    	dp[r-1][j] = tri[r-1][j];
    }

    for (int i =r-2;i>=0;i--) {
    	for (int j = 0;j<=i;j++) {
    		dp[i][j] = tri[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
    	}
    }

    fout << dp[0][0] << endl;

    fout.close();
    return 0;
}
