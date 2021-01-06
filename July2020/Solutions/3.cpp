#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ofstream fout ("nfc.out");
  ifstream fin ("nfc.in");
  int n, f;
  fin >> n >> f;
  vector<int> vect;
  for (int i = 0; i < n; i++) {
    int a;
    fin >> a;
    vect.push_back(a);
  }
  int out1 = 1;
  int out2 = 1;
  int close = n + n;
  for(int i = 0; i < n; i++) {
    int v1 = vect[i];
    for(int q = 0; q < n; q++) {
      int v2 = vect[q];
      int tclose = q + i + 2;
      if (v2 + v1 == f && tclose < close) {
        out1 = min(q,i) + 1;
        out2 = max(q,i) + 1;
        close = tclose;
      }
    }
  }
  fout << out1 << " " << out2 << endl;
}
