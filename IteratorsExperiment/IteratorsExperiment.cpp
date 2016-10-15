// IteratorsExperiment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>
#include <iostream>


using namespace std;

class MyIterator
{
public:
  MyIterator()
  {
    cout << "MyIterator()" << '\n';
  }

  explicit MyIterator(const vector<string>::iterator& it) :
    _it(it)
  {
    //cout << "MyIterator(const vector<string>::iterator& it)" << '\n';
    cout << "Iterator is copied" << '\n';
  }

  MyIterator(const MyIterator& original) :
    _it(original._it)
  {
    //cout << "MyIterator(const MyIterator& original)" << '\n';
    cout << "Iterator is copied" << '\n';
  }

  MyIterator& operator++()
  {
    ++_it;
    return *this;
  }

  MyIterator operator++(int)
  {
    MyIterator _Tmp = *this;
    ++*this;
    return _Tmp;
  }

  bool operator==(const MyIterator& other) const
  {
    return (_it == other._it);
  }

  bool operator!=(const MyIterator& other) const
  {
    return (!(*this == other));
  }

  std::string& operator*() const
  {
    return *_it;
  }

private:
  vector<string>::iterator _it;
};

int main()
{
  vector<string> v;
  v.push_back("s0");
  v.push_back("s1");
  v.push_back("s2");

  vector<string>::iterator iiii;

  //   for (vector<string>::iterator it = v.begin(), end = v.end(); it != end; it++)
  //   {
  //     std::cout << *it << std::'\n';
  //   }

  cout << "\n\tThe default implementation" << '\n';
  for (MyIterator it(v.begin()); it != MyIterator(v.end()); it++)
  {
    cout << *it << '\n';
  }

  cout << '\n' << "\n\tWith prefix incrementation" << '\n';
  for (MyIterator it(v.begin()); it != MyIterator(v.end()); ++it)
  {
    cout << *it << '\n';
  }

  cout << '\n' << "\n\tWith prefix incrementation" << '\n';
  for (MyIterator it(v.begin()), end(v.end()); it != end; ++it)
  {
    cout << *it << '\n';
  }

  return 0;
}

