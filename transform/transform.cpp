
/*
ID: heng_li1
TASK: transform
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

int n;
bitset<100> before, after;

int mask(int row,int col) {
	return row*n+col;
}

bitset<100> rot90(bitset<100> before) {
	bitset<100> rot;
	for (int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			rot[mask(i,j)] = before[mask(n-1-j, i)];
		}
	}
	return rot;
}

bitset<100> fliph(bitset<100> before) {
	bitset<100> fl;
	for (int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			fl[mask(i,j)] = before[mask(i,n-1-j)];
		}
	}
	return fl;
}


int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    
    string line;
    fin >> n;
    getline(fin, line);
    int j =0;
    for (int i =0;i<n;i++) {
    	getline(fin, line);
    	// cout << line << endl;
    	for (int k=j;j<k+n;j++) {
    		before.set(j, line.at(j-k)=='@');
    	}
    }
    j=0;
    for (int i =0;i<n;i++) {
    	getline(fin, line);
    	for (int k=j;j<k+n;j++) {
    		after.set(j, line.at(j-k)=='@');
    	}
    }
    bitset<100> r1 = rot90(before);
    if (r1==after) {
    	fout << 1 << endl;
    } else {
    	bitset<100> r2 = rot90(r1);
    	if (r2==after) {
    		fout << 2 << endl;
    	}else {
    		bitset<100> r3 = rot90(r2);
    		if (r3==after) {
    			fout <<3 << endl;
    		}else {
    			bitset<100> r4 = fliph(before);
    			if (r4==after) {
    				fout << 4 << endl;
    			}else {
	    			bool done = false;
	    			for (int i =1;i<4;i++) {
	    				r4 = rot90(r4);
	    				if (r4==after) {
	    					done = true;
	    					fout << 5 << endl;
	    					break;
	    				}
	    			}
	    			if (!done) {
	    				fout << 6+(before!=after) << endl;
	    			}
	    		}
    		}
    	}
    }

    fout.close();

    return 0;
}
