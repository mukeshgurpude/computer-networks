#include<iostream>

using namespace std;

bool get_parity_bit(unsigned int number) {
  int parity = 0;
  while (number > 0){
    parity = parity + number%2;
    number = number / 2;
  }
  return parity%2;
}

int main() {
  /* Assumed number in the decimal form
    e.g.
      number = 7
  */
  unsigned int number;
  bool expected_parity;
  cout<<"\tPlease enter the parity for this operation (even: 0, odd: 1):\t";
  cin>>expected_parity;

  cout<<"\tPlease enter the received data:\t";
  cin>>number;

  if( get_parity_bit(number) == expected_parity ) {
    cout<<"\t\tNo error in the received bits"<<endl;
  }else{
    cout<<"\t\tParity mismatch, please rerequest the data from sender"<<endl;
  }

  return 0;
}
