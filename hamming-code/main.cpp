#include <iostream>
#include <cmath>
#include "functions.h"

using namespace std;

int main() {
  int m, r, n;

  cout << "Enter message length: "; // 4
  cin >> m;

  // Use find_r function from functions.h to find r
  r = find_r(m);
  n = pow(2, r);

  int data_bits_reversed[n];
  int data_bits[n];

  cout<<"Enter the data: "; // 1 0 0 1
  int count = r-1;
  for (int i = n - 1; i >= 0; i--) {
    if(i == pow(2, count)) {
      data_bits_reversed[i] = 0;
      count--;
    } else if( i <= (m + count)) {
      int bit;
      cin >> bit;
      data_bits_reversed[i] = bit;
    } else {
      data_bits_reversed[i] = 0;
    }
  }

  for(int i = 0; i < r; i++) {
    data_bits_reversed[(int) pow(2, i)] = r_value(n, data_bits_reversed, i);
  }

  for (int i = 0; i < n; i++){
    data_bits[i] = data_bits_reversed[n - i - 1];
  }
  // Print the data
  cout <<endl << "Encoded Data: ";
  
  count = 0;
  for (int i = 0; i < n; i++) {
    cout << data_bits[i];
    if(data_bits[i] == 1) count++;
  }
  if(count%2 == 0) cout << endl << " (Even) Parity" << endl;
  else cout << " (Odd) Parity" << endl;
  return 0;
}
