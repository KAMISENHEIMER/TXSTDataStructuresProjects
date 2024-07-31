/*
 * autocomplete.cpp
 * 
 * The file where you will implement your autocomplete code for Project 4.
 *
 * INSTRUCTOR NOTE: Do not change any of the existing function signatures in
 * this file, or the testcases will fail. 
 */

#include "autocomplete.h"

/** QUESTION 1: FINDNODE **/

// EFFECTS: Traverses the Tree based on the charactes in the prefix and 
//          returns the TreeNode that we end at. If we cannot find a valid node,
//          we return an empty TreeNode. The index variable keeps track of what 
//          character we're at in prefix.
// 
// PSEUDOCODE:
// algorithm FindNode
//   Input: A TreeNode to start from, A string representing the prefix to search through, an integer representing where to start from
//   Output: A TreeNode representing the final letter in the prefix
//   Your pseudocode goes here.
//
//  take off the first 'index' amount of values from the prefix
//  handle the empty prefix case, just return the given node
//  make sure the node and prefix is valid, and then loop through all the children of the node
//    find the child that has the same value of the first letter of the prefix
//      if its the last letter in prefix, return that node
//      if there are still more letters, venture further into the tree
//  finally, if none of the other cases are met, return an empty node to indicate nothing was found
//
// COMMENTS:
// The instructions did not clearly define a use of the index variable, and I cannot think of a reason for it existing in an autocompleting word context,
// so this program does not use it that much, only chopping off the first letters if an index is provided so that it satisfies certain test cases.
TreeNode<char> FindNode(TreeNode<char> node, std::string prefix, int index) {
    TreeNode<char> returnNode;  //start the returnNode at an empty node, if it is not passed correct values or cannot find the last node, return this.
    if (index>0) {      //chop off the first 'index' values from the prefix, I don't know why you'd want to do this, but some of the test cases require it.
        returnNode = FindNode(node, prefix.substr(index), 0);
    } else if (prefix.length() == 0) {  //in the case that an empty prefix is passed in, return the given node, as any following letter will work
        return node;
    } else {
        if (!node.IsEmpty() && prefix.length() > 0) {     //catch for all things that should not happen
            //stop when prefix length 0, or if the node is not contained in the tree
            for (TreeNode<char> child : node.GetChildren()) {   //loop through all children of the current node until you find the first value
                if (child.GetValue() == prefix.front()) {   //if the current child's value is the current prefix front, venture into it
                    if (prefix.length() > 1) {  //more than 1 letter in the prefix, venture further into the tree and into the prefix
                        returnNode = FindNode(child, prefix.substr(1), index);
                    } else {    //final value in prefix, return the child
                        returnNode = child;
                    }
                }
            }
        }
    }
    return returnNode;
}

/** QUESTION 2: COLLECTWORDS **/

// EFFECTS: Collects all the words starting from a given TreeNode. For each word, 
//          prepends the word with the prefix and adds it to the results vector.
// 
// PSEUDOCODE:
// algorithm CollectWords
//   Input: A TreeNode to venture out from, a string to represent the prefix, a list of strings representing all the built words.
//   Output: None (the results string array is modified instead)
//   Your pseudocode goes here.
//
//   loop through all of the children of the given node
//     if the value of this node is $, return the current prefix
//     else, recursively travel into all of that notes children, while adding the current letter to the prefix
//
// COMMENTS:
// Add comments here that might help us to understand your thought process,
// especially if you're unable to finish the pseudocode or code. This can help
// us award points in the code logic category.  
void CollectWords(TreeNode<char> node, std::string prefix, std::vector <std::string> &results) {
    for (TreeNode<char> child : node.GetChildren()) {   //loop through all the children, this needs to be first so it skips the first given node
        if (child.GetValue() == '$') {    //if the value is '$', it means we reached the end of a word, add it to results
            results.push_back(prefix);
        } else { //not at the end of the word, add the current letter to the prefix, then continue into the children of the node
            CollectWords(child, prefix + child.GetValue(), results);
        }
    }
}


/** QUESTION 3: GETCANDIDATES **/

// EFFECTS: Returns the list of all possible words that can be made starting with
//          the letters in prefix, based on traversing the tree with the given root.
//
// PSEUDOCODE:
// algorithm GetCandidates
//   Input: A TreeNode representing the root node of the tree, A string representing the beginning of the word to complete
//   Output: A list of strings representing all the possible words starting with the prefix
//   Your pseudocode goes here.
//
//   run FindNode to get the last node in the prefix
//   run CollectWords to get all words from that node, and attach the prefix to them
//   return all the words
//
// COMMENTS:
// This is fairly straightforward, so long as the other 2 functions work, this one should as well, as it is really just calling both of them.
std::vector <std::string> GetCandidates(TreeNode<char> root, std::string prefix) {
    TreeNode<char> finalLetter = FindNode(root, prefix, 0);     //get the node of the final letter in prefix
    std::vector <std::string> results;
    CollectWords(finalLetter, prefix, results);     //collect all the words can be made with that letter, append prefix to them, and store in 'results'
    return results;
}
