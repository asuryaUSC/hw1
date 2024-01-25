#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite
using namespace std;

int main(int argc, char* argv[])
{
  // test item 
  ULListStr dat;

  // Test push back on empty List
  dat.push_back("10");
  cout<< "After push_back(10): " << dat.get(0) << ", size: " << dat.size() << endl;

  // test push front on a non empty List
  dat.push_front("5");
  cout << "After push_front('5'): " << dat.get(0) << ", " << dat.get(1) << ", size: " << dat.size() << endl;

  // test pushing multiple items to back to make sure that there is proper node allocation
  dat.push_back("15");
  dat.push_back("20");
  cout << "After multiple push_back: ";
  for (size_t i = 0; i < dat.size(); i++) {
    cout << dat.get(i) << " ";
  }
  cout << ", size: " << dat.size() << endl;

  // test pop back function
  dat.pop_back();
  cout << "After pop_back: ";
  for (size_t i = 0; i < dat.size(); i++) {
    cout << dat.get(i) << " ";
  }
  cout << ", size: " << dat.size() << endl;

  // test pop front
  dat.pop_front();
  cout << "After pop_front: ";
  for (size_t i = 0; i < dat.size(); i++) {
    std::cout << dat.get(i) << " ";
  }
  cout << ", size: " << dat.size() << endl;

  // test back and front
  cout << "Front: " << dat.front() << ", Back: " << dat.back() << endl;

  // test emptying the List
  while (!dat.empty()) {
    dat.pop_front();
  }
  cout << "After emptying the list, size: " << dat.size() << endl;

  return 0;



}
