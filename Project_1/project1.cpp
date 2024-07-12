/*
 * project1.cpp
 * 
 * The implementation file where you will implement your code for Project 1.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file. You may add helper functions for 
 * any function other than Sum in Question 1. 
 */

#include "recursive_list.h"
#include "project1.h"

/** QUESTION 1: SUM AND PRODUCT **/

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// Your implementation of Sum should NOT be tail recursive and should NOT
// use a helper function. 
//
// PSEUDOCODE:
// algorithm Sum
//   check if the rest of the list is empty
//     if it is, return the current location + the sum of the rest of the list
//     if it is not, just return the current location
//
// COMMENTS:
// By checking if the rest of the list is empty, and returning the current location in the base case,
// I reduce the number of function calls by 1
int Sum(RecursiveList list) {
    if (!ListIsEmpty(ListRest(list))) {   //if the rest of the list is not empty, continue the recursion
        return ListFirst(list) + Sum(ListRest(list));   //add the current value to the sum of the rest of the list
    }
    return ListFirst(list);     //If the rest of the list was empty, return just this index
}

// EFFECTS: returns the product of each element in list, or one if the list is
//          empty
//
// PSEUDOCODE:
// algorithm Product
//   check if the rest of the list is empty
//     if it is, return the current location * the sum of the rest of the list
//     if it is not, just return the current location
//
// COMMENTS:
// Almost entirely the same as the sum function, but a * instead of a +
int Product(RecursiveList list) {
    if (!ListIsEmpty(ListRest(list))) {   //if the rest of the list is not empty, continue the recursion
        return ListFirst(list) * Product(ListRest(list));   //multiply the current value by the product of the rest of the list
    }
    return ListFirst(list);     //If the rest of the list was empty, return just this index
}


/** QUESTION 2: TAIL RECURSIVE SUM **/

// EFFECTS: adds the next element in the list to the sum so far
// Your implementation of TailRecursiveSumHelper MUST be tail recursive.
//
// PSEUDOCODE:
// algorithm TailRecursiveSumHelper
//   check if the rest of the list is empty,
//     if it is, return the current location + the current sum
//     if it is not, continue into the recursion with the rest of the list, and the current sum + the current location
// COMMENTS:
// This is a Tail Recursive function as the final piece of the function is the recursive piece,
// which means there are no additional steps after the recursive step.
int TailRecursiveSumHelper(RecursiveList list, int sum_so_far) {
    if (ListIsEmpty(ListRest(list))) {
        return ListFirst(list) + sum_so_far;
    }
    return TailRecursiveSumHelper(ListRest(list), ListFirst(list)+sum_so_far);

}

// EFFECTS: returns the sum of each element in list, or zero if the list is
//          empty
// THIS FUNCTION IS PROVIDED AS PART OF THE STARTER CODE.
// DO NOT MODIFY THIS FUNCTION.
// 
// PSEUDOCODE:
// algorithm TailRecursiveSum
//   return TailRecursiveSumHelper(list, 0)
int TailRecursiveSum(RecursiveList list) {
  return TailRecursiveSumHelper(list, 0);
}


/** QUESTION 3: FILTER ODD AND FILTER EVEN **/

// EFFECTS: returns a new list containing only the elements of the original list
//          which are odd in value, in the order in which they appeared in list
// For example, FilterOdd(( 4 1 3 0 )) would return the list ( 1 3 )
//
// PSEUDOCODE:
// algorithm FilterOdd
//   check if the list is empty
//     if it is not empty, check if the current value is odd
//       if it is odd, continue the recursion with the current value and the rest of the odd values
//       if it is not odd, continue the recursion with just the rest of the odd values
//     if the rest is empty, check if the last value is odd
//       if it is odd, return the current value
//       if it is not odd, return an empty list
// COMMENTS:
// Checking whether the rest of the list is empty (as opposed to the current value) is causing this code to look a little bloated,
// but I still think it is more efficient, as it reduces the number of function calls by 1
RecursiveList FilterOdd(RecursiveList list) {
    if (!ListIsEmpty(ListRest(list))) {   //if the rest of the list is not empty, continue the recursion
        if (ListFirst(list)%2==1) {           //if the current value is odd
            return MakeList(ListFirst(list), FilterOdd(ListRest(list)));    //make a list of the current value and all odd numbers in the rest of the list
        } else {                              //if the current value is not odd
            return FilterOdd(ListRest(list));      //skip the current value return the rest of the odd numbers
        }
    }
    if (ListFirst(list)%2==1) {           //if the rest of the list is empty, check if the last value is odd
        return list;    //return the final value (as a list so that it works with the rest of the function's processes)
    } else {                              //if the final value is not odd
        return MakeList();      //return an empty list
    }
}

// EFFECTS: returns a new list containing only the elements of the original list
//          which are even in value, in the order in which they appeared in list
// For example, FilterEven(( 4 1 3 0 )) would return the list ( 4 0 )
//
// PSEUDOCODE:
// algorithm FilterEven
//   check if the current list is empty
//     if it is not, check if the current value is even,
//       if it is even, return a list of the current value and the rest of the even values
//       if it is not even, skip it and return the rest of the even values
//     if the list is empty, return it.
//
// COMMENTS:
// I experimented with the other way of running this function, and it definitely looks a lot cleaner than my FilterOdd,
// and because of this, it would probably be the one that I used, even though it will require 1 more call (a minuscule amount of time).
RecursiveList FilterEven(RecursiveList list) {
    if (!ListIsEmpty(list)) {   //if current list is not empty, continue the recursion
        if (ListFirst(list)%2==0) {           //if the current value is even
            return MakeList(ListFirst(list), FilterEven(ListRest(list)));    //make a list of the current value and all even numbers in the rest of the list
        } else {                              //if the current value is not even
            return FilterEven(ListRest(list));      //skip the current value return the rest of the even numbers
        }
    }
    return list;   //if the list is empty, simply return it
}


/** QUESTION 4: REVERSE **/

// EFFECTS: returns the reverse of list
// For example, the reverse of ( 3 2 1 ) is ( 1 2 3 )
//
// PSEUDOCODE:
// algorithm Reverse
//   check if the rest of the list is empty
//     if it is not, return the rest of the list + current value
//     if it is empty, return the current value
//
// COMMENTS:
// I reverted to checking the rest of the list in this one, because the problem is simple enough that
// the solution still looks clean.
RecursiveList Reverse(RecursiveList list) {
    if (!ListIsEmpty(ListRest(list))) {     //if the current list is not empty continue
        return Append(Reverse(ListRest(list)), MakeList(ListFirst(list), MakeList()));  //continue venturing into the list, while appending the current value to the end of the list
    }
    return list;       //if the current list is empty, return the current value (the last value in the list)
}


/** QUESTION 5: APPEND **/

// EFFECTS: returns the list (first_list second_list)
// For example, if first_list is ( 1 2 3 ) and second_list is ( 4 5 6 ), then
// returns ( 1 2 3 4 5 6 )
//
// PSEUDOCODE:
// algorithm Append
//   check if the current list not empty,
//     if it is not, venture deeper into the first list, while appending adding the first value to the front of our new list
//     if it is empty, return the final value in the first list, along with the second list
//
//
// COMMENTS:
// None
RecursiveList Append(RecursiveList first_list, RecursiveList second_list) {
    if (!ListIsEmpty(ListRest(first_list))) {   //continue if the rest of the first list is not empty
        return MakeList(ListFirst(first_list), Append(ListRest(first_list), second_list));  //venture further into the first list, while keeping track of the current value.
    }
    return MakeList(ListFirst(first_list),second_list);     //return the final value in the first list and the second list
}


/** QUESTION 6: CHOP **/

// REQUIRES: list has at least n elements
// EFFECTS: returns the list equal to list without its last n elements
//
// PSEUDOCODE:
// algorithm Chop
//   check if n is greater than 0, and if the rest of the list is not empty
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList Chop(RecursiveList list, unsigned int n) {
    if (!ListIsEmpty(ListRest(list))) {
        return MakeList(ListFirst(list), Chop(ListRest(list), n--));
    }


}


/** QUESTION 7: ROTATE **/

// EFFECTS: returns a list equal to the original list with the
//          first element moved to the end of the list n times.
// For example, Rotate(( 1 2 3 4 5 ), 2) yields ( 3 4 5 1 2 )
//
// PSEUDOCODE:
// algorithm Rotate
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList Rotate(RecursiveList list, unsigned int n) {
  // Implement this function.
  return list;
}


/** QUESTION 8: INSERT LIST **/

// REQUIRES: n <= the number of elements in first_list
// EFFECTS: returns a list comprising the first n elements of first_list,
//          followed by all elements of second_list, followed by any remaining
//          elements of "first_list"
// For example, InsertList (( 1 2 3 ), ( 4 5 6 ), 2) returns ( 1 2 4 5 6 3 )
//
// PSEUDOCODE:
// algorithm InsertList
//   Your pseudocode goes here. You do not need to define inputs, outputs, or
//   side effects, since the requires, modifies, and effects statements are
//   already provided above.
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.
RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list,
                         unsigned int n) {
  // Implement this function.
  return first_list;
}