#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

// random seed will be generated based on ms since start of program running
system_clock::time_point program_start = system_clock::now();

shared_ptr<vector<int>> unsort(shared_ptr<vector<int>> sorted){ // O(n) runtime using a reverse insertion sort, might get lengthy with high array lengths
  high_resolution_clock::time_point run_time = high_resolution_clock::now();
  duration<double, std::milli> timespan = (run_time - program_start);
  //cout << "Seed: " << 1000*(timespan.count());
  srand(1000*(timespan.count()));

  int len = sorted->size();
  for(int i = 0; i < len; i++){
    int randindex = i + (rand()%(len - i));
    int temp = sorted->at(i);
    (*sorted)[i]=sorted->at(randindex);
    (*sorted)[randindex] = temp;
  }
  return sorted;
}

shared_ptr<vector<int>> createUnsortedArray(int length){
  shared_ptr<vector<int>> sorted = make_shared<vector<int>>(length);
  for(int i = 0; i < length; i++){
    (*sorted)[i] = i;
  }
  sorted = unsort(sorted);
  return sorted;
}

string printArr(shared_ptr<vector<int>> arr){
  string output = "[";
  int i;
  for(i = 0; i < arr->size()-1; i++){
    output += to_string(arr->at(i)) + ", ";
  }
  output += to_string(arr->at(i))+"]\n\n";
  return output;
}

int main() {
  cout << "How many arrays do you want generated?\n";
  int runs;
  cin >> runs;
  cout << "Length of arrays?\n";
  int len;
  cin >> len;
  for(int i(0); i<runs; i++){
    cout << printArr(createUnsortedArray(len));
  }
}