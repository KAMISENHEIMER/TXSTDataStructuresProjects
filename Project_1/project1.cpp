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
//   check if the list is empty
//     if it is, return the current location + the sum of the rest of the list
//     if it is not, return 0
//
// COMMENTS:
// By checking if the rest of the list is empty, and returning the current location in the base case,
// I reduce the number of function calls by 1
// EDIT: The above text is no longer true, I realize that in my ambition for efficiency,
// my hubris led me down a path in which the case where the given list was empty resulted in an error.
int Sum(RecursiveList list) {
    if (!ListIsEmpty(list)) {   //if the list is not empty, continue the recursion
        return ListFirst(list) + Sum(ListRest(list));   //add the current value to the sum of the rest of the list
    }
    return 0;     //If the list was empty, return 0
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
    if (!ListIsEmpty(list)) {   //if the list is not empty, continue the recursion
        return ListFirst(list) * Product(ListRest(list));   //multiply the current value by the product of the rest of the list
    }
    return 1;     //If list was empty, return 1
}


/** QUESTION 2: TAIL RECURSIVE SUM **/

// EFFECTS: adds the next element in the list to the sum so far
// Your implementation of TailRecursiveSumHelper MUST be tail recursive.
//
// PSEUDOCODE:
// algorithm TailRecursiveSumHelper
//   check if the list is empty,
//     if it is, the current sum
//     if it is not, continue into the recursion with the rest of the list, and the current sum + the current location
// COMMENTS:
// This is a Tail Recursive function as the final piece of the function is the recursive piece,
// which means there are no additional steps after the recursive step.
int TailRecursiveSumHelper(RecursiveList list, int sum_so_far) {
    if (ListIsEmpty(list)) {
        return sum_so_far;
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
// EDIT: due to previously mentioned hubris, I had to fix this function as well, making it more similar to the FilterEven function.
RecursiveList FilterOdd(RecursiveList list) {
    if (!ListIsEmpty(list)) {   //if the list is not empty, continue the recursion
        if (ListFirst(list)%2==1) {           //if the current value is odd
            return MakeList(ListFirst(list), FilterOdd(ListRest(list)));    //make a list of the current value and all odd numbers in the rest of the list
        } else {                              //if the current value is not odd
            return FilterOdd(ListRest(list));      //skip the current value return the rest of the odd numbers
        }
    }
    return list;
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
    if (!ListIsEmpty(list) && !ListIsEmpty(ListRest(list))) {     //if the current list is not empty continue
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
//     if it is empty, return the second list
//
//
// COMMENTS:
// This function ended up becoming the backbone for many other functions in this project.
RecursiveList Append(RecursiveList first_list, RecursiveList second_list) {
    if (!ListIsEmpty(first_list)) {   //continue if the rest of the first list is not empty
        return MakeList(ListFirst(first_list), Append(ListRest(first_list), second_list));  //venture further into the first list, while keeping track of the current value.
    }
    return second_list;     //return the second list
}


/** QUESTION 6: CHOP **/

// REQUIRES: list has at least n elements
// EFFECTS: returns the list equal to list without its last n elements
//
// PSEUDOCODE:
// algorithm ChopHelper
//   check if n is greater than 0, and the list is not empty
//     if so, continue into the recursion with the rest of the list, and n decreased by 1
//     if not, return the current list
//
// algorithm Chop
//     reverse the given list,
//     pass it to the recursive function, ChopHelper
//     reverse the chopped list, putting it at the correct order to return
//
// COMMENTS:
// I feel like there should be a way to do this problem without a helper function and reversing the list,
// but even after thinking long and hard about it, I could not come up with one.
RecursiveList ChopHelper(RecursiveList list, unsigned int n) {

    if (n>0 && !ListIsEmpty(list)) {        //if the list is not empty, and n is greater than 1
        return ChopHelper(ListRest(list), --n);     //continue into the recursion with the rest of the list and lower n by 1
    }
    return list;    //return only part of the list after the end continue has been met.

}

RecursiveList Chop(RecursiveList list, unsigned int n) {
    RecursiveList returnList = Reverse(list);   //reverse the given list
    returnList = ChopHelper(returnList, n);     //chop off the first n values
    returnList = Reverse(returnList);       //reverse the list again, so it is in the correct order
    return returnList;


}

/** QUESTION 7: ROTATE **/

// EFFECTS: returns a list equal to the original list with the
//          first element moved to the end of the list n times.
// For example, Rotate(( 1 2 3 4 5 ), 2) yields ( 3 4 5 1 2 )
//
// PSEUDOCODE:
// algorithm Rotate
//   check if n is greater than 0, and the list is not empty
//     if so, continue into the recursion with the first value appended to the end of the list, and decrease n by 1.
//     if not, return the current list
//
// COMMENTS:
// not too much to say about this one, but I think the append function looks a little clunky,
// if this were a bigger project I would likely make other smaller functions to make this look cleaner.
RecursiveList Rotate(RecursiveList list, unsigned int n) {
    if (n>0 && !ListIsEmpty(list)) {        //if the list is not empty, and n is greater than 1
        return Rotate(Append(ListRest(list), MakeList(ListFirst(list),MakeList())),--n);    //move the first value to the end, subtract 1 from n, and continue into the recursion
    }
    return list;    //return what the current list contains after the end of the end condition is met
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
//   check if n is greater than 0, and the list is not empty
//     if so, return the first value, and continue into the recursion with the rest of the list, and decrease n by 1.
//     if not, the second list, followed by the rest of the first list
//
// COMMENTS:
// The append function ended up being much more useful than I originally expected.
RecursiveList InsertList(RecursiveList first_list, RecursiveList second_list, unsigned int n) {
    if (n>0 && !ListIsEmpty(first_list)) {          //if the list is not empty, and n is greater than 1
        return MakeList(ListFirst(first_list), InsertList(ListRest(first_list), second_list, --n));     //keep the first value, and venture further into the recursion
    }
    return Append(second_list,first_list);      //once the target destination is reached, stick the second array in, and then follow it with the rest of the first array.
}