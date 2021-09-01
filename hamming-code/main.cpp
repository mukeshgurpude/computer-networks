#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

unsigned int find_r(unsigned int m) {
  unsigned int r = 0;
  while (pow(2, r) < m + r + 1) {
    r++;
  }
  return r;
}

bool r_value(int n, int *data, int r) {
  int step = pow(2, r);
  int bit = 0;
  for (int i = 0; i <= n; i++) {
    if ((i/step)%2 == 1) {
      bit = bit ^ data[i];
    }
  }
  cout << "r = " << r << " bit = " << bit << endl;
  return bit;
}

int main() {
  int m; // Bit length
  int r; // Number of redundant bits
  int n; // Number of data bits
  cout << "Enter the bit length of the message: ";
  m = 7;
  // cin >> m;
  r = find_r(m);
  n = pow(2, r);

  // vector<int> data_bits;
  int data_bits[n];

  cout<<"Enter data bits: ";
  int count = 0;
  for(int i = 0; i < n; i++) {
    if(i == pow(2, count)) {
      // data_bits.push_back(0);
      data_bits[i] = 0;
      count++;
    }else if(i < (m+count)){
      int bit;
      cin >> bit;
      // data_bits.push_back(bit);
      data_bits[i] = bit;
    }
    else {
      // data_bits.push_back(0);
      data_bits[i] = 0;
    }
  }
  // Print data bits
  cout << "Data bits: ";
  for(int i = n - 1; i >= 0; i--) {
    cout << data_bits[i];
  }
  cout<<endl;
  for (int i = 0; i < r; i++){
    cout << "r = " << i << " pos = " << (n - pow(2, i)) << " bit = " << r_value(n, data_bits, i) << endl;
    data_bits[(int)(n - pow(2, i))] = r_value(n, data_bits, i);
  }

  cout << "Encoded Data: ";
  for(int i = n - 1; i >= 0; i--) {
    cout << data_bits[i];
  }
  
  return 0;
}
