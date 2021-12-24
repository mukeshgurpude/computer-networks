#include <iostream>
using namespace std;
string xor1(string a, string b) {
  string result = "";
  for (int i = 1; i < b.length(); i++) {
    if (a[i] == b[i]) result += "0";
    else result += "1";
  }
  return result;
}
string mod2div(string divident, string divisor) {
  int pick = divisor.length();

  string tmp = divident.substr(0, pick);
  int n = divident.length();
  while (pick < n)
  {
    if (tmp[0] == '1')
      tmp = xor1(divisor, tmp) + divident[pick];
    else 
      tmp = xor1(string(pick, '0'), tmp) + divident[pick];
    pick += 1;
  }

  if (tmp[0] == '1')
    tmp = xor1(divisor, tmp);
  else
    tmp = xor1(string(pick, '0'), tmp);
  return tmp;
}

void encodeData(string data, string key) {
  int l_key = key.length();
  // Appends n-1 zeroes at end of data
  string appended_data = (data + string(l_key - 1, '0'));
  string remainder = mod2div(appended_data, key);
  // Append remainder in the original data
  string codeword = data + remainder;
  cout << "Remainder : " << remainder << "\n";
  cout << "Encoded Data (Data + Remainder) :" << codeword << "\n";
}

int main() {
  string data; // "100100";
  string key;  // "1101";
  cout << " Enter 4 bits of beat stream (divident) :";
  cin >> data;
  cout << "Enter value of G(x) (Divisor) : ";
  cin >> key;
  encodeData(data, key);
}
