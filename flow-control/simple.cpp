#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

int main() {
  int n;
  vector<int> data;
  cout << "Enter number of bits: ";
  cin >> n;

  cout << "Enter " << n << " bits: ";
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    data.push_back(x);
  }

  int i = 0;
  vector <int> received_data;
  while(i < n) {
  
    // Sender side
    cout << "\nSending a frame of 1 bit to receiver" << endl;
    Sleep(1000);
  
    
    // Receiver
    cout << "Received a frame of 1 bit from sender" << endl;
    received_data.push_back(data[i]);
    Sleep(3000);
    i++;
  }
  cout << "\nReceived data: ";
  for (int i = 0; i < n; i++) {
    cout << received_data[i] << " ";
  }

  cout << "Enter key to exit";
  cin >> n;
  return 0;
}
