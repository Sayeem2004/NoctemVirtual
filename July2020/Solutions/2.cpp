#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  ofstream fout ("shadow.out");
  ifstream fin ("shadow.in");
  int n;
  fin >> n;
  vector<int> vect;
  for(int i = 0; i < n; i++) {
    int a;
    fin >> a;
    vect.push_back(a);
  }
  int m = 0;
  for(int i = 0; i < n - 4; i++) {
    int e1 = vect[i];
    int e2 = vect[i+1];
    int e3 = vect[i+2];
    int e4 = vect[i+3];
    int e5 = vect[i+4];
    if (e1 + e2 + e3 + e4 + e5 > m) {
      m = e1 + e2 + e3 + e4 + e5;
    }
  }
    fout << m << endl;
}
