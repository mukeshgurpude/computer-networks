#include <cmath>

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
  return bit;
}
