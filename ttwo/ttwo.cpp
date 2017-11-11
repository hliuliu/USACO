
/*
ID: heng_li1
TASK: ttwo
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PII> VPII;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef long long LL;

ostream& operator<< (ostream &stream, PII &p) {
	stream << p.first << "," << p.second;
	return stream;
}

LL mask(PII &farmer, PII &cow,PII &fd, PII &cd) {
	int a1 = farmer.first*3+fd.first+1;
	int a2 = farmer.second*3+fd.second+1;
	int a3 = cow.first*3+cd.first+1;
	int a4 = cow.second*3+cd.second+1;
	LL ans = a1*30+a2;
	ans = ans *30 + a3;
	ans = ans *30 + a4;
	return ans;
}

void rot90(PII &dir) {
	int x=dir.first,y=dir.second;
	dir.first = y;
	dir.second = -x;
}

bool inbound(int x, int y) {
	return x>=0 && y>=0 && x<10 && y<10;
}

void make_move(PII &pos, PII &dir, VVC &grid) {
	int x = pos.first+dir.first, y = pos.second+dir.second;
	if (!inbound(x,y) || grid[x][y]=='*') {
		rot90(dir);
	}else {
		pos.first = x;
		pos.second = y;
	}
}

int trav(PII &farmer,PII &cow,VVC &grid) {
	PII fd(-1,0), cd(-1,0); // north
	unordered_set<LL> seen;


	int count = 0;
	LL m = mask(farmer,cow,fd,cd);
	
	do {

		// cerr << farmer << " " << cow << " " << fd << " " << cd << endl;
		// cerr << count << endl;
		if (seen.find(m)!=seen.end()) {
			return 0;
		}
		seen.insert(m);



		make_move(farmer,fd,grid);
		make_move(cow,cd,grid);
		m = mask(farmer,cow,fd,cd);



		

		count++;

	}while(farmer!=cow);


	return count;
}

int main() {
    ofstream fout ("ttwo.out");
    ifstream fin ("ttwo.in");

    VVC grid (10, VC(10));

    int i=0,j=0;
    PII farmer,cow;

    for (VC &row: grid) {
    	j=0;
    	for (char &entry: row) {
    		fin >> entry;
    		// cerr << entry;
    		if (entry == 'F') {
    			farmer.first = i;
    			farmer.second = j;
    			entry = '.';
    		}else if (entry == 'C') {
    			cow.first = i;
    			cow.second = j;
    			entry = '.';
    		}
    		j++;
    	}
    	i++;
    }

    fout << trav(farmer,cow,grid) << endl;

    

    fout.close();
    return 0;
}
