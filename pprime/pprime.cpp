
/*
ID: heng_li1
TASK: pprime
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> pals;

bool isprime(int val) {
	for(int i =2;i*i<=val;i++) {
		if (val%i==0) {
			return false;
		}
	}
	return true;
}

void genpp(int nd) {
	int nh = (nd+1)>>1;
	int start = pow(10,nh-1);
	for (int part = start; part<10*start;part++) {
		int x = part;
		if (nd&1) {
			x = x/10;
		}
		int y = part;
		while (x) {
			y = y*10+(x%10);
			x/=10;
		}
		pals.push_back(y);
	}
}


int main() {
    ofstream fout ("pprime.out");
    ifstream fin ("pprime.in");

    int a,b;

    fin >> a >> b;

    for (int i =1;i<=8;i++) {
    	genpp(i);
    }

    // copy(pals.begin(),pals.end(),ostream_iterator<int>(fout,"\n"));

    for (int p:pals) {
    	if (p<a) {
    		continue;
    	}
    	if (p>b) {
    		break;
    	}
    	if (isprime(p)) {
    		fout << p << endl;
    	}
    }

    fout.close();
    return 0;
}
