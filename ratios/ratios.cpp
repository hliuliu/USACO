
/*
ID: heng_li1
TASK: ratios
LANG: C++11                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int A[3][3], mix[3], B[3][3], result[3];

int det2(vector<int> mat) {
	return mat[0]*mat[3]-mat[1]*mat[2];
}

void invert(int A[3][3],int B[3][3]) {
	for (int i=0;i<3;i++) {
		for(int j =0;j<3;j++) {
			vector<int> mat;
			for (int k=0;k<3;k++) {
				for(int l =0;l<3;l++) {
					if(k!=i && l!=j) {
						mat.push_back(A[k][l]);
					}
				}
			}
			B[j][i] = det2(mat)*((i+j)&1? -1 : 1);
		}
	}
}

void matmult(int A[3][3], int x[3], int b[3]) {
	for (int i=0;i<3;i++) {
		b[i] =0;
		for(int j=0;j<3;j++) {
			b[i] += A[i][j]*x[j];
		}
	}
}


int det3(int M[3][3]) {
	int ans =0;
	for (int i =0;i<3;i++) {
		int term = 1;
		for (int j =0;j<3;j++) {
			term*=M[j][(i+j)%3];
		}
		ans += term;
		term = 1;
		for (int j =0;j<3;j++) {
			term *= M[j][(i-j+3)%3];
		}
		ans -= term;
	}
	return ans;
}

int gcd(int a,int b) {
	while (b) {
		int r = a%b;
		a=b; b= r;
	}
	return a;
}

bool conclude(int d,int &ans) {
	int g = gcd(abs(d),abs(result[0]));
	g = gcd(g, abs(result[1]));
	g = gcd(g, abs(result[2]));
	ans = d/g;
	int sgn = d/abs(d);
	for (int i = 0;i<3;i++) {
		result[i] /=g*sgn;
		if (result[i]<0) {
			return false;
		}
	}
	ans *= sgn;
	return true;
}

void print_mat(int A[3][3]) {
	for (int i =0;i<3;i++) {
		for(int j =0;j<3;j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

void print_vec(int v[3]) {
	for (int i =0;i<3;i++) {
		cout << v[i] << " ";
	}
	cout<<endl;
}

int main() {
    ofstream fout ("ratios.out");
    ifstream fin ("ratios.in");
    for (int i =0;i<3;i++) {
    	fin >> mix[i];
    }

    for (int i =0;i<3;i++) {
    	for(int j =0;j<3;j++) {
    		fin >> A[j][i];
    	}
    }
    int d = det3(A);
    cout << d << endl;
    print_mat(A);
    invert(A,B);
    print_mat(B);
    // exit(0);
    matmult(B,mix,result);
    print_vec(mix);
    print_vec(result);

    int ans;
    if (!conclude(d,ans)) {
    	fout << "NONE" << endl;
    }else {
    	for (int i =0;i<3;i++) {
    		fout << result[i] << " ";
    	}
    	fout << ans << endl;
    }
    print_vec(result);

    fout.close();
    return 0;
}
