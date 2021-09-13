/*
Compile with:
  g++ -std=c++11 -pthread -o main main.cpp

Run with:
  ./main
*/

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
bool aknowledged = true, end_data = false;
bool sender_ready = false, receiver_ready = false;
int i = 0;

void sender() {
  cout << "Sender ready" << endl;
  sender_ready = true;
  while (true) {
    // Wait for receiver to be ready
    if(!receiver_ready) {
      this_thread::sleep_for(chrono::seconds(1));
      continue;
    }
    if (aknowledged) {
      if(i!=0) cout << "\nAknowledged from receiver\n";
      
      if (i == data.size()) {
        // Data end
        break;
      }
      cout << "Sending " << data[i] << endl;
      aknowledged = false;
    }
    this_thread::sleep_for(chrono::seconds(1));
  }
  end_data = true;
}

void receiver() {
  cout << "Receiver ready" << endl;
  receiver_ready = true;
  while (!end_data){
    // Wait for sender to be ready
    if (!sender_ready) {
      this_thread::sleep_for(chrono::seconds(1));
      continue;
    }
    if (!aknowledged) {
      cout << "Received: " << data[i] << endl;
      aknowledged = true;
      i++;
    }
    this_thread::sleep_for(chrono::seconds(1));
  }
}

int main() {
  cout << "--- Implementation of Simplest Noiseless protocol with Multithreading ---" << endl;
  thread t1(sender);
  thread t2(receiver);

  t2.join();
  t1.join();

  cout << "All packets received and acknowledged" << endl;
  return 0;
}
