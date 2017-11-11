
/*
ID: heng_li1
TASK: nocows
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MOD 9901

using namespace std;

int getSum(vector<vector<int> > &table, vector<vector<int> > &upper, int i, int j) {
	int s =0;
	for (int t = 1;t<i-1;t++) {
		int term =0;
		term = upper[i-1-t][j-1];
		term *= table[t][j-1];
		term %= MOD;
		s+= term;
		s%=MOD;
		term =0;
		term+= upper[t][j-1];
		term *= table[i-1-t][j-1];
		term %= MOD;
		s+= term;
		s%=MOD;

		term = table[t][j-1] * table[i-1-t][j-1];
		term %= MOD;
		s+= MOD-term;
		s%=MOD;
	}
	return s;
}

int main() {
    ofstream fout ("nocows.out");
    ifstream fin ("nocows.in");

    int n, k;
    fin  >> n >> k;

    vector<vector<int> > table (n+1, vector<int>(k+1,0));
    vector<vector<int> > upper (n+1, vector<int>(k+1,0));
    table[0][0] =1;

    for (int i =1;i<=n;i++) {
    	for(int j =1; j<=k;j++) {
    		table[i][j] = i==1? (j==1? 1 : 0) : (j==1? 0: getSum(table,upper,i,j));
    		upper[i][j] = (table[i][j] + upper[i][j-1])%MOD;
    	}
    }

    fout << table[n][k] << endl;



    fout.close();
    return 0;
}
