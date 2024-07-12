/*
 * main.cpp
 * contain all the test cases for project 1
 */

#include <iostream>
#include "recursive_list.h"
#include "project1.h"

bool ListEqual(RecursiveList l1, RecursiveList l2) 
{
  // If either are empty, both must be empty for equality
  if (ListIsEmpty(l1) || ListIsEmpty(l2)) {
    return (ListIsEmpty(l1) && ListIsEmpty(l2));
  }

  if (ListFirst(l1) != ListFirst(l2)) {
    return false;
  } else {
    return ListEqual(ListRest(l1), ListRest(l2));
  }
}

int main() {
  int test_Count = 0;
  RecursiveList listA = MakeList();
  RecursiveList listB = MakeList();
  for (int i = 5; i > 0; i--) {
    listA = MakeList(i, listA);
    listB = MakeList(i + 10, listB);
  }

  std::cout << "Original: " << std::endl;
  PrintList(listA);
  std::cout << std::endl;
  PrintList(listB);
  std::cout << std::endl;

  std::cout << "QUESTION 1" << std::endl;
  std::cout << "Sum: " << std::endl;
  std::cout << Sum(listA) <<std::endl;
  std::cout << Sum(listB) <<std::endl;

  std::cout << "Product: " << std::endl;
  std::cout << Product(listA) <<std::endl;
  std::cout << Product(listB) <<std::endl;
  
  std::cout <<"Test 01 productTest" << std::endl;

  RecursiveList l = MakeList();
  int numelts = 5;
  int result = 1;
  int answer = 120;

  while (numelts) {
    l = MakeList(numelts, l);
    result *= numelts;
    numelts--;
  }

  int results = Product(l);

  if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q1 test 1 failed" << std::endl;  
  } 

  std::cout <<"Test 02 emptyProduct" << std::endl;
  l = MakeList();
  numelts = 5;
  answer = 1;

  results = Product(l);

    if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q1 test 2 failed" << std::endl;  
  } 
  
  std::cout <<"Test 03 productTest2" << std::endl;  
  l = MakeList();
  numelts = 5;
  result = 1;
  answer = -120;

  while (numelts) {
    l = MakeList(numelts * -1, l);
    result *= (-1 * numelts);
    numelts--;
  }
  results = Product(l);

  if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q1 test 3 failed" << std::endl;  
  } 

  std::cout <<"Test 04 sumTest" << std::endl;  
  l = MakeList();
  numelts = 5;
  result = 1;
  answer = 15;

  while (numelts) {
    l = MakeList(numelts, l);
    result += numelts;
    numelts--;
  }

  results = Sum(l);

  if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q1 test 4 failed" << std::endl;  
  } 

  std::cout <<"Test 05 sumOnEmpty" << std::endl;  
  l = MakeList();
  numelts = 5;
  result = 1;
  answer = 0;

  results = Sum(l);

   if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q1 test 5 failed" << std::endl;  
  } 

  std::cout <<"Test 06 sumTest" << std::endl;  
  l = MakeList();
  numelts = 5;
  result = 1;
  answer = -15;

  while (numelts) {
    l = MakeList(numelts * -1, l);
    result += (-1 * numelts);
    numelts--;
  }

  results = Sum(l);

  if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q1 test 6 failed" << std::endl;  
  } 

  std::cout << "No of successful tests for QUESTION 1 is "<<test_Count<<" out of 6" << std::endl;
  test_Count = 0;

  std::cout << "QUESTION 2" << std::endl;
  std::cout << "Sum (Tail Recursive): " << std::endl;
  std::cout << TailRecursiveSum(listA) << std::endl;
  std::cout << TailRecursiveSum(listB) << std::endl;

  std::cout <<"Test 01 tailSumFromAssignment" << std::endl;

  l = MakeList();
  numelts = 5;
  result = 1;
  answer = 15;

  while (numelts) {
    l = MakeList(numelts, l);
    result += numelts;
    numelts--;
  }

  results = TailRecursiveSum(l);

  if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q2 test 1 failed" << std::endl;  
  } 


  std::cout <<"Test 02 tailSumOnEmpty" << std::endl;

  l = MakeList();
  numelts = 5;
  result = 1;
  answer = 0;

  results = TailRecursiveSum(l);
  if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q2 test 2 failed" << std::endl;  
  } 


  std::cout <<"Test 03 tailSumFromAssignment" << std::endl;

  l = MakeList();
  numelts = 5;
  result = 1;
  answer = -15;

   while (numelts) {
    l = MakeList(numelts * -1, l);
    result += (-1 * numelts);
    numelts--;
  }

  results = TailRecursiveSum(l);

  if (results == answer) {
    test_Count++;
  } else {
    std::cout <<"Q2 test 3 failed" << std::endl;  
  } 


  std::cout << "NO. of successful tests for QUESTION 2 is "<<test_Count<<" out of 3" << std::endl;
  test_Count = 0;

  std::cout << "QUESTION 3" << std::endl;
  std::cout << "Filter Even: " << std::endl;
  PrintList(FilterEven(listA));
  std::cout << std::endl;
  PrintList(FilterEven(listB));
  std::cout << std::endl;

  std::cout << "Filter Odd: " << std::endl;
  PrintList(FilterOdd(listA));
  std::cout << std::endl;
  PrintList(FilterOdd(listB));
  std::cout << std::endl;

  std::cout <<"Test 01 filterEven" << std::endl;

  RecursiveList original = MakeList();
  RecursiveList filtered = MakeList();
  RecursiveList testlist;

  bool answer3 = true;
  int largest = 4;


  for (int i = largest; i > 0; i--) {
      original = MakeList(i, original);
      original = MakeList(i, original);
      original = MakeList(i, original);
      if (!(i % 2)) {
          filtered = MakeList(i, filtered);
          filtered = MakeList(i, filtered);
          filtered = MakeList(i, filtered);
      }
  }

  testlist = FilterEven(original);
  bool results3  = ListEqual(filtered, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q3 test 1 failed" << std::endl;  
  } 

  std::cout <<"Test 02 filterEvenEmpty" << std::endl;

  original = MakeList();
  filtered = MakeList();
  answer3 = true;

  testlist = FilterEven(original);
  results3  = ListEqual(filtered, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q3 test 2 failed" << std::endl;  
  } 

  std::cout <<"Test 03 filterOdd" << std::endl;
  original = MakeList();
  filtered = MakeList();
  answer3 = true;

  for (int i = largest; i > 0; i--) {
    original = MakeList(i, original);
    original = MakeList(i, original);
    original = MakeList(i, original);
    if (i % 2) {
      filtered = MakeList(i, filtered);
      filtered = MakeList(i, filtered);
      filtered = MakeList(i, filtered);
    }
  }
  testlist = FilterOdd(original);
  results3  = ListEqual(filtered, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q3 test 3 failed" << std::endl;  
  } 


  std::cout <<"Test 04 filterOddEmpty" << std::endl;
  original = MakeList();
  filtered = MakeList();
  answer3 = true;

  testlist = FilterOdd(original);
  results3  = ListEqual(filtered, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q3 test 4 failed" << std::endl;  
  } 


  std::cout << "NO. of successful tests for QUESTION 3 is "<<test_Count<<" out of 4" << std::endl;
  test_Count = 0;

  std::cout << "QUESTION 4" << std::endl;
  std::cout << "Reverse: " << std::endl;
  PrintList(Reverse(listA));
  std::cout << std::endl;
  PrintList(Reverse(listB));
  std::cout << std::endl;

  std::cout <<"Test 01 ReverseList" << std::endl;
  original = MakeList();
  RecursiveList reversed = MakeList();
  answer3 = true;

  for (int i = largest; i > 0; i--) {
    original = MakeList(i, original);
    reversed = MakeList(largest-i+1, reversed);
  }

  testlist = Reverse(original);
  results3  = ListEqual(reversed, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q4 test 1 failed" << std::endl;  
  } 


  std::cout <<"Test 02 reverseEmpty" << std::endl;
  original = MakeList();
  reversed = MakeList();
  answer3 = true;

  testlist = Reverse(original);
  results3  = ListEqual(reversed, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q4 test 2 failed" << std::endl;  
  } 


  std::cout << "NO. of successful tests for QUESTION 4 is "<<test_Count<<" out of 2" << std::endl;
  test_Count = 0;
  
  std::cout << "QUESTION 5" << std::endl;
  std::cout << "Append: " << std::endl;
  PrintList(Append(listA, listB));
  std::cout << std::endl;

  std::cout <<"Test 01 appendListToItself" << std::endl;
  original = MakeList();
  RecursiveList appended = MakeList();
  int status = 0;
  answer3 = true;
  largest = 4;

  for (int i = largest; i > 0; i--) {
    original = MakeList(i, original);
  }

  for (int i = 0; i < 2; i++) {
    for (int j = largest; j > 0; j--) {
      appended = MakeList(j, appended);
    }
  }

  testlist = Append(original, original);
  results3  = ListEqual(appended, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q5 test 1 failed" << std::endl;  
  } 


  std::cout <<"Test 02 appendEmptytoOriginal" << std::endl;
  original = MakeList();
  status = 0;
  answer3 = true;
  largest = 4;

  for (int i = largest; i > 0; i--) {
    original = MakeList(i, original);
  }

  testlist = Append(original, MakeList());
  results3  = ListEqual(original, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q5 test 2 failed" << std::endl;  
  } 


  std::cout <<"Test 03 appendOriginaltoEmpty" << std::endl;
  original = MakeList();
  status = 0;
  answer3 = true;

  for (int i = largest; i > 0; i--) {
    original = MakeList(i, original);
  }

  testlist = Append(MakeList(), original);
  results3  = ListEqual(original, testlist);

   if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q5 test 3 failed" << std::endl;  
  } 

  std::cout <<"Test 04 appendEmptytoEmpty" << std::endl;
  original = MakeList();
  status = 0;
  answer3 = true;

  for (int i = largest; i > 0; i--) {
    original = MakeList(i, original);
  }

  testlist = Append(MakeList(), MakeList());
  results3  = ListEqual(MakeList(), testlist);

   if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q5 test 4 failed" << std::endl;  
  } 

  std::cout << "NO. of successful tests for QUESTION 5 is "<<test_Count<<" out of 4" << std::endl;
  test_Count = 0;

  std::cout << "QUESTION 6" << std::endl;
  std::cout << "Chop: " << std::endl;
  PrintList(Chop(listA, 0));
  std::cout << std::endl;
  PrintList(Chop(listA, 1));
  std::cout << std::endl;
  PrintList(Chop(listA, 2));
  std::cout << std::endl;
  PrintList(Chop(listA, 3));
  std::cout << std::endl;

  std::cout <<"Test 01 fourChop" << std::endl;
  RecursiveList chopped = MakeList();
  original = MakeList();
  answer3 = true;
  largest = 7;
  int steps = 4;

  for (int i = largest-1; i >= 0; i--) {
    original = MakeList(i, original);
  }

  for (int i = largest-1-steps; i >= 0; i--) {
    chopped = MakeList(i, chopped);
  }

  testlist = Chop(original, steps);
  results3  = ListEqual(chopped, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q6 test 1 failed" << std::endl;  
  } 

  std::cout <<"Test 02 noChop" << std::endl;
  original = MakeList();
  answer3 = true;
  largest = 7;
  steps = 4;

  for (int i = largest-1; i >= 0; i--) {
    original = MakeList(i, original);
  }

  testlist = Chop(original, 0);
  results3  = ListEqual(testlist, original);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q6 test 2 failed" << std::endl;  
  } 

  std::cout <<"Test 03 emptyChopNone" << std::endl;
  original = MakeList();
  answer3 = true;
  largest = 7;
  steps = 4;

  for (int i = largest-1; i >= 0; i--) {
    original = MakeList(i, original);
  }

  testlist = Chop(MakeList(), 0);
  results3  = ListEqual(testlist, MakeList());

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q6 test 3 failed" << std::endl;  
  } 

  std::cout <<"Test 04 allChop" << std::endl;
  original = MakeList();
  answer3 = true;
  largest = 7;
  steps = 4;

  for (int i = largest-1; i >= 0; i--) {
    original = MakeList(i, original);
  }

  testlist = Chop(original, largest);
  results3  = ListEqual(testlist, MakeList());

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q6 test 4 failed" << std::endl;  
  } 


  std::cout << "NO. of successful tests for QUESTION 6 is "<<test_Count<<" out of 4" << std::endl;
  test_Count = 0;

  std::cout << "QUESTION 7" << std::endl;
  std::cout << "Rotate: " << std::endl;
  PrintList(Rotate(listA, 0));
  std::cout << std::endl;
  PrintList(Rotate(listA, 1));
  std::cout << std::endl;
  PrintList(Rotate(listA, 2));
  std::cout << std::endl;
  PrintList(Rotate(listA, 3));
  std::cout << std::endl;

  std::cout <<"Test 01 rotateList" << std::endl;
  original = MakeList();
  RecursiveList rotated = MakeList();
  answer3 = true;
  largest = 7;
  steps = 4;

  for (int i = largest-1; i >= 0; i--) {
    original = MakeList(i, original);
    rotated = MakeList((i+steps)%largest, rotated);
  }

  testlist = Rotate(original, steps);
  results3  = ListEqual(rotated, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q7 test 1 failed" << std::endl;  
  } 

  std::cout <<"Test 02 noRotate" << std::endl;
  original = MakeList();
  rotated = MakeList();
  answer3 = true;
  largest = 7;
  steps = 4 + largest;

  for (int i = largest-1; i >= 0; i--) {
    original = MakeList(i, original);
    rotated = MakeList((i+steps)%largest, rotated);
  }

  testlist = Rotate(original, 0);
  results3  = ListEqual(testlist, original);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q7 test 2 failed" << std::endl;  
  } 

  std::cout <<"Test 03 rotateMoreThanN" << std::endl;
  original = MakeList();
  rotated = MakeList();
  answer3 = true;
  largest = 7;
  steps = 4 + largest;

  for (int i = largest-1; i >= 0; i--) {
    original = MakeList(i, original);
    rotated = MakeList((i+steps)%largest, rotated);
  }

  testlist = Rotate(original, steps);
  results3  = ListEqual(testlist, rotated);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q7 test 3 failed" << std::endl;  
  } 

  std::cout << "NO. of successful tests for QUESTION 7 is "<<test_Count<<" out of 3" << std::endl;
  test_Count = 0;

  std::cout << "QUESTION 8" << std::endl;
  std::cout << "Insert List: " << std::endl;
  PrintList(InsertList(listA, listB, 0));
  std::cout << std::endl;
  PrintList(InsertList(listA, listB, 1));
  std::cout << std::endl;
  PrintList(InsertList(listA, listB, 2));
  std::cout << std::endl;
  PrintList(InsertList(listA, listB, 3));
  std::cout << std::endl;

  std::cout <<"Test 01 insertOneOneEnd" << std::endl;
  RecursiveList first = MakeList();
  RecursiveList second = MakeList();
  RecursiveList inserted = MakeList();
  answer3 = true;
  largest = 4;

  inserted = MakeList(largest, inserted);

  for (int i = largest; i > 0; i--) {
    first = MakeList(i, first);
    second = MakeList(i+largest, second);
    inserted = MakeList(i+largest, inserted);
  }

  for (int i = largest - 1; i > 0; i--) {
    inserted = MakeList(i, inserted);
  }


  testlist = InsertList(first, second, largest-1);
  results3  = ListEqual(inserted, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q8 test 1 failed" << std::endl;  
  } 


  std::cout <<"Test 02 beginningInsert" << std::endl;
  first = MakeList();
  second = MakeList();
  RecursiveList inserted_zero = MakeList();
  RecursiveList inserted_last = MakeList();
  status = 0;
  answer3 = true;
  largest = 10;

  inserted = MakeList(largest, inserted);

  for (int i = largest; i > 0; i--) {
    first = MakeList(i, first);
    second = MakeList(i+largest, second);
  }

  inserted_zero = first;
  inserted_last = second;
  for (int i = largest; i > 0; i--) {
    inserted_zero = MakeList(i+largest, inserted_zero);
    inserted_last = MakeList(i, inserted_last);
  }

  testlist = InsertList(first, second, 0);
  results3 = ListEqual(inserted_zero, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q8 test 2 failed" << std::endl;  
  } 

  std::cout <<"Test 03 endInsert" << std::endl;
  first = MakeList();
  second = MakeList();
  inserted_zero = MakeList();
  inserted_last = MakeList();
  answer3 = true;
  largest = 10;

  inserted = MakeList(largest, inserted);

  for (int i = largest; i > 0; i--) {
    first = MakeList(i, first);
    second = MakeList(i+largest, second);
  }

  inserted_zero = first;
  inserted_last = second;
  for (int i = largest; i > 0; i--) {
    inserted_zero = MakeList(i+largest, inserted_zero);
    inserted_last = MakeList(i, inserted_last);
  }

  testlist = InsertList(first, second, largest);
  results3 = ListEqual(inserted_last, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q8 test 3 failed" << std::endl;  
  } 

  std::cout <<"Test 04 insertingNothing" << std::endl;
  first = MakeList();
  second = MakeList();
  inserted_zero = MakeList();
  inserted_last = MakeList();
  answer3 = true;
  largest = 10;

  inserted = MakeList(largest, inserted);

  for (int i = largest; i > 0; i--) {
    first = MakeList(i, first);
    second = MakeList(i+largest, second);
  }

  inserted_zero = first;
  inserted_last = second;
  for (int i = largest; i > 0; i--) {
    inserted_zero = MakeList(i+largest, inserted_zero);
    inserted_last = MakeList(i, inserted_last);
  }

  testlist = InsertList(first, MakeList(), largest/2);
  results3 = ListEqual(first, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q8 test 4 failed" << std::endl;  
  } 

  std::cout <<"Test 05 insertingIntoNothing" << std::endl;
  first = MakeList();
  second = MakeList();
  inserted_zero = MakeList();
  inserted_last = MakeList();
  answer3 = true;
  largest = 10;

  inserted = MakeList(largest, inserted);

  for (int i = largest; i > 0; i--) {
    first = MakeList(i, first);
    second = MakeList(i+largest, second);
  }

  inserted_zero = first;
  inserted_last = second;
  for (int i = largest; i > 0; i--) {
    inserted_zero = MakeList(i+largest, inserted_zero);
    inserted_last = MakeList(i, inserted_last);
  }

  testlist = InsertList(MakeList(), first, 0);
  results3 = ListEqual(first, testlist);

  if (results3 == answer3) {
    test_Count++;
  } else {
    std::cout <<"Q8 test 5 failed" << std::endl;  
  } 

  std::cout << "NO. of successful tests for QUESTION 8 is "<<test_Count<<" out of 5" << std::endl;
  test_Count = 0;
}
