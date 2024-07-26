#ifndef __DLIST_H__
#define __DLIST_H__

#include <iostream>

/**********************************************************
 * INSTRUCTOR NOTE: Do not modify the class declarations! *
 * The class Dlist is a class template.                   *
 *********************************************************/
class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:
  // Maintenance methods

  Dlist();                                // constructor
  Dlist(const Dlist &l);                  // copy constructor
  Dlist &operator=(const Dlist &l);       // assignment
  ~Dlist();                               // destructor

  // Operational methods

  // EFFECTS: returns true if list is empty, false otherwise
  bool IsEmpty() const;

  // MODIFIES: this
  // EFFECTS: inserts o at the front of the list
  void InsertFront(const T &o);

  // MODIFIES: this
  // EFFECTS: inserts o at the back of the list
  void InsertBack(const T &o);

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveFront();

  // MODIFIES: this
  // EFFECTS: removes and returns last object from non-empty list
  //          throws an instance of emptyList if empty
  T RemoveBack();

 private:
  // A private type

  struct node {
    node   *next;
    node   *prev;
    T      o;
  };

  // Private member variables 

  node   *first; // The pointer to the first node (NULL if none)
  node   *last;  // The pointer to the last node (NULL if none)

  // Private utility methods

  // EFFECTS: called by constructors to establish empty list invariant
  void MakeEmpty();

  // EFFECTS: called by copy constructor/operator= to copy nodes
  //          from a source instance l to this instance
  void CopyAll(const Dlist &l);
    
  // EFFECTS: called by destructor and operator= to remove and destroy
  //          all list nodes
  void RemoveAll();
};

// Constructor
template <typename T>
Dlist<T>::Dlist() {
  MakeEmpty();
}

// Copy constructor
template <typename T>
Dlist<T>::Dlist(const Dlist &l) {
  MakeEmpty();
  CopyAll(l);
}

// Assignment operator
template <typename T>
Dlist<T>& Dlist<T>::operator=(const Dlist<T> &l) {
  if (this != &l) {
    RemoveAll();
    CopyAll(l);
  }
  return *this;
}

// Destructor 
template <typename T>
Dlist<T>::~Dlist() {
  RemoveAll();
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/**********************************************************
 * INSTRUCTOR NOTE: Implement the member functions below. *
 * These member functions are all function templates.     * 
 *********************************************************/

// EFFECTS: returns true if list is empty, false otherwise
template <typename T>
bool Dlist<T>::IsEmpty() const {
  return (first == nullptr || last == nullptr);
}

// MODIFIES: this
// EFFECTS: inserts o at the front of the list
template <typename T>
void Dlist<T>::InsertFront(const T& o) {

    //initialize new node
    node *n = new node();
    n -> o = o;
    n -> next = first;
    n -> prev = nullptr;

    //empty case
    if (IsEmpty()) {
        last = n;
    } else {    //non-empty case
        first -> prev = n;
    }
    first = n;

}

// MODIFIES: this
// EFFECTS: inserts o at the back of the list
template <typename T>
void Dlist<T>::InsertBack(const T& o) {

    //initialize new node
    node *n = new node();
    n -> o = o;
    n -> next = nullptr;
    n -> prev = last;

    //empty case
    if (IsEmpty()) {
        first = n;
    } else {    //non-empty case
        last -> next = n;
    }
    last = n;

}

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty
template <typename T>
T Dlist<T>::RemoveFront() {

    // empty case
    if (IsEmpty()) {
        throw emptyList();
    } else {

        T data = first->o;      //store the data
        node *temp = first;     //store the pointer

        //1 element case
        if (first->next == nullptr) {
            last = nullptr;
            first = nullptr;
        } else {    //rest of cases
            first = first->next;     //move the first pointer to the next one
            first->prev = nullptr;  //update the new first node's prev pointer
        }
        delete temp;            //delete the node
        return data;            //return the data that was in the node
    }
}

// MODIFIES: this
// EFFECTS: removes and returns last object from non-empty list
//          throws an instance of emptyList if empty
template <typename T>
T Dlist<T>::RemoveBack()
{
    // empty case
    if (IsEmpty()) {
        throw emptyList();
    } else {
        T data = last->o;      //store the data
        node *temp = last;     //store the pointer
        //1 element case
        if (last->prev == nullptr) {
            last = nullptr;
            first = nullptr;
        } else {    //rest of cases
            last = last->prev;     //move the last pointer to the prev one
            last->next = nullptr;  //update the new last node's next pointer
        }
        delete temp;            //delete the node
        return data;            //return the data that was in the node
    }
}

// EFFECTS: called by constructors to establish empty list invariant
template <typename T>
void Dlist<T>::MakeEmpty() {
    first = nullptr;
    last = nullptr;
}

// EFFECTS: called by copy constructor/operator= to copy nodes
//          from a source instance l to this instance
template <typename T>
void Dlist<T>::CopyAll(const Dlist &l) {

    node *location = l.first;
    node *prev_n = nullptr;
    while (location != nullptr) {

        //instantiate the new node
        node *n = new node();
        n->o = location->o;
        n->next = nullptr;      //will be set later
        n->prev = prev_n;

        //handle head and next ptrs
        if (first==nullptr) {   //1st node case
            first = n;
        } else {        //not 1st node case
            prev_n->next = n;    //tell the prev node to connect to the current one
        }

        //move the current node back
        prev_n = n;

        //move the location forward
        location = location->next;
    }
    //set the last node
    last = prev_n;
}

// EFFECTS: called by destructor and operator= to remove and destroy
//          all list nodes
template <typename T>
void Dlist<T>::RemoveAll() {
  while (first != nullptr) {
      node *temp = first->next;     //store the next pointer
      delete first;
      first = temp;
  }
  last = nullptr;
}

/**** INSTRUCTOR NOTE: DO NOT DELETE #endif FROM END OF FILE. ****/
#endif /* __DLIST_H__ */
