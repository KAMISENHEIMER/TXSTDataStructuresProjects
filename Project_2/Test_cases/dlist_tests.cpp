// Run in repl.it:
// clang++-7 -pthread -std=c++17 -o dlist_tests ldist_tests.cpp; ./dlist_tests

#include <iostream>
#include <string>
#include "dlist.h"

using namespace std;

enum Job {STUDENT, FACULTY, STAFF};

struct Record {
  std::string name;
  std::string uniqname;
  Job job;
};

static int intval = 0;
static const int numints = 4;

int main() {
  cout<<"starting first test\n";

  int cnt = 0;
  //test 1
  Dlist<int> d;
  int x = d.IsEmpty();
  if(x != 1) cout<<"failed 1st test\n";
  else cnt++;

  //test 2
    cout<<"starting second test\n";


  string answer = "Caught front\nCaught back\n";
  string results = "";
  Dlist<int> d1;
  Dlist<int> d2;

  try {
    d1.RemoveFront();
  } catch (emptyList e) {
    results += "Caught front\n";
  }

  try {
    d2.RemoveBack();
  } catch (emptyList e) {
    results += "Caught back\n";
  }

  if(answer != results) cout<<"failed 2nd test\n";
  else cnt++;

  //test 3
    cout<<"starting third test\n";


    answer = "20134";
  results = "";
  Dlist<int> d4;
  int numints_5 =5;
  int ints[numints_5];
  int iv;
  int i;

  for (i=0; i<numints_5; i++) {
    ints[i] = i;
  }
  d4.InsertFront(ints[0]);
  d4.InsertFront(ints[1]);
  d4.InsertFront(ints[2]);
  iv = d4.RemoveFront();
  results.append(to_string(iv));
  iv = d4.RemoveBack();
  results.append(to_string(iv));
  iv = d4.RemoveBack();
  results.append(to_string(iv));

  d4.InsertFront(ints[3]);
  d4.InsertFront(ints[4]);

  iv = d4.RemoveBack();
  results.append(to_string(iv));
  iv = d4.RemoveBack();
  results.append(to_string(iv));
  if(answer != results) cout<<"failed 3rd test\n";
  else cnt++;

  //test4
    cout<<"starting fourth test\n";


  answer = "01230123";
  results = "";
  Dlist<int> *d14, *d24;
  int ints2[numints];
  int ip;
  i = 0;

  d14 = new Dlist<int>;

    cout<<"starting loop1\n";

    for (i=0; i<numints; i++) {
    ints2[i] = i;
    cout<<ints2[i];
    d14->InsertFront(ints2[i]);
  }


    //while (!d14->IsEmpty()) {
    //    ip = d14->RemoveBack();
    //    cout << ip;
    //}

  d24 = new Dlist<int>(*d14);



    cout<<"starting loop2\n";


    for (i = 0; i < numints; i++) {
        ip = d14->RemoveBack();
        cout << ip;
        results.append(to_string(ip));
    }


  delete d14;

    //cout<<"starting test while loop\n";
    //while (!d24->IsEmpty()) {
    //    ip = d24->RemoveBack();
    //    cout << ip;
    //}



    cout<<"starting loop3\n";
    for (i=0; i<numints; i++) {
    ip = d24->RemoveBack();
    results.append(to_string(ip));
  }


    delete d24;

  if(answer != results) cout<<"failed 4th test\n";
  else cnt++;



  //test5
    cout<<"starting fifth test\n";


    answer = "000111222333done";
  results = "";
  Dlist<int> d15, d25, d35;
  ip = 0;
  i = 0;

  for (i=0; i<numints; i++) {
    d15.InsertFront(i);
    d25.InsertFront(i);
  }

  d25 = d15;
  d35 = d15;
  d15 = d15;

  for (i=0; i<numints; i++) {
    ip = d15.RemoveBack();
    results.append(to_string(ip));

    ip = d25.RemoveBack();
    results.append(to_string(ip));

    ip = d35.RemoveBack();
    results.append(to_string(ip));

  }

  results.append("done");

  if(answer != results) cout<<"failed 5th test\n";
  else cnt++;



  //test6
    cout<<"starting six test\n";


    answer = 12;
  Dlist<int> *d16, *d26, *d36;
  ip = 0;
  i = 0;
  int sum = 0;

  d16 = new Dlist<int>;
  d26 = new Dlist<int>;
  d36 = new Dlist<int>;

  for (i=0; i<numints; i++) {
    d16->InsertFront(i);
    d26->InsertFront(i);
    d36->InsertFront(i);
  }

  delete d16;
  *d26 = *d36;

  for (i=0; i<numints; i++) {
    ip = d26->RemoveBack();
    sum += ip;
  }

  for (i=0; i<numints; i++) {
    ip = d36->RemoveBack();
    sum += ip;
  }

  delete d26;
  delete d36;

  results = sum;
  if(answer != results) cout<<"failed 6th test\n";
  else cnt++;



  cout<<cnt<<" out of 6 cases \n";

  return 0;
}