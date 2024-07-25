// Run in repl.it:
// g++ -pthread -std=c++17 -o call call.cpp; ./call < call_test1.in
// Run in zeus:
//g++ -pthread -o call call.cpp; ./call < call_test1.in

#include <iostream>
#include <string>
#include <cassert>

#include "dlist.h"

/*
 * Format of input line:
 *
 *  <timestamp> <Name> <status> <duration>
 *
 * Note: first four fields terminated by whitespace
 *       request terminated by newline.
 *
 * Format of input file:
 * 
 * A single line with the number of requests
 * zero or more input lines followed by EOF.
 */

enum Status {
  NONE = 0, SILVER = 1, GOLD = 2, PLATINUM = 3
};

struct reqNode {
  int         timestamp;
  std::string name;
  Status      status;
  int         duration;
};

/**** INSTRUCTOR NOTE: DO NOT MODIFY ABOVE THIS LINE ****/

/***************************************************
 * INSTRUCTOR NOTE: Implement the functions below. *
 **************************************************/

// EFFECTS: Reads and parses each request from the standard input stream
// std::cin. For each request, creates a reqNode struct and enqueues their
// pointers in the requests queue, which is a Dlist of pointers to reqNode
// structs. 
void ObtainRequests(Dlist<reqNode*> &requests) {
    //gets length of input file
    int lengthOfInputFile;
    std::cin >> lengthOfInputFile;

    //for each input line
    for (int i = 0; i < lengthOfInputFile; i++) {

        //grab all 4 input values
        int timestamp;
        std::string name;
        std::string statusStr;
        int duration;
        std::cin >> timestamp >> name >> statusStr >> duration;

        //convert status string to enum
        Status statusEnum;
        if (statusStr=="silver") {
            statusEnum = SILVER;
        } else if (statusStr=="gold") {
            statusEnum = GOLD;
        } else if (statusStr=="platinum") {
            statusEnum = PLATINUM;
        } else {
            statusEnum = NONE;
        }

        //store them into a reqNode pointer
        reqNode *n = new reqNode();
        n->timestamp = timestamp;
        n -> name = name;
        n -> status = statusEnum;
        n -> duration = duration;

        //store the reqNode pointer into the requests stack
        requests.InsertBack(n);

    }
}

// EFFECTS: Insert any callers with timestamps equal to the tick number
// (the clock param) into their appropriate queues. When a caller is
// inserted, you should print a message that exactly matches the following 
// example (with the correct name and status):
// 
// Call from Jeff a silver member
//
// You can get the appropriate status by calling status_names[status]. 
// Note: If two (or more) calls have the same timestamp, they should be
// printed in input file-order, not in priority-order.
void InsertRequests(Dlist<reqNode*> &requests, Dlist<reqNode*> queues[], int clock, std::string status_names[]) {
    //loop through requests until a timestamp greater than the current tick is found
    //as the timestamps are in order, this ensures we are only adding the timestamps that correspond to the current tick
    bool keepGoing = !requests.IsEmpty();
    while (keepGoing) {
        if (requests.IsEmpty()) {   //if its empty stop
            keepGoing = false;
        } else {    //check the first value
            reqNode *n = requests.RemoveFront();     //get the next node
            if (n->timestamp > clock) {          //if the timestamp is higher than the clock, put the node back in and stop
                requests.InsertFront(n);
                keepGoing = false;
            } else {    //not empty and correct timestamp, add it to the correct queue, and print message
                queues[n->status].InsertBack(n);
                std::cout << "Call from " << n->name << " a " << status_names[n->status] << " member" << std::endl;
            }
        }
    }
}

// EFFECTS: Simulate the actions of the agent at this tick. The agent must
// follow these rules:
// 1. If the agent is not busy, the agent checks each queue, in priority order
// from Platinum to None. If the agent finds a call, the agent answers the
// call, and you should print a message that exactly matches the following 
// example (with the correct name):
// 
// Answering call from Jeff
// 
// You will need to decrement time_agent_busy by 1. 
// 
// 2. If the agent was already busy at the beginning of this tick, the agent
// continues servicing the current client. You will need to decrement
// time_agent_busy by 1. 
// 
// 3. If the agent is not busy, and there are no current calls, the agent
// does nothing. 
//
// If all calls have been placed, answered, and completed, then return true
// to end the program. Otherwise, return false.
bool SimulateAgent(Dlist<reqNode*> &requests, Dlist<reqNode*> queues[], int &time_agent_busy) {
    if (time_agent_busy==0) {     //agent is not busy
        //check calls until a call is answered, or no call was found
        int currentQueue = 3;
        while (currentQueue>=0 && time_agent_busy==0) {
            if (!queues[currentQueue].IsEmpty()) {
                //call was found
                reqNode *answeredCall = queues[currentQueue].RemoveFront();
                time_agent_busy = answeredCall->duration;
                std::cout << "Answering call from " << answeredCall->name << std::endl;
            }
            currentQueue--;
        }
    }

    //completion flag, everything is done, this needs to happen before the decrement so it doesn't end early
    bool complete = requests.IsEmpty() && time_agent_busy == 0 && queues[0].IsEmpty() && queues[1].IsEmpty() && queues[2].IsEmpty() && queues[3].IsEmpty();

    if (time_agent_busy!=0) {     //agent is busy, decrement time and continue
        time_agent_busy--;
    }

    return complete;
}

/**** INSTRUCTOR NOTE: DO NOT MODIFY BELOW THIS LINE ****/

int main() {
  // The current time, starting at tick 0. 
  int clock = 0;

  // The remaining time that the agent is busy with the current
  // caller, or 0 if the agent is not busy. 
  int time_agent_busy = 0;

  // An array of four queues, one for each status: regular, silver,
  // gold, platinum. Each queue is a DList of pointers to reqNode
  // structs. 
  Dlist<reqNode*> queues[4]; 

  // A queue of requests matching the input. The queue is a DList of 
  // pointers to reqNode structs.
  Dlist<reqNode*> requests;

  // Flag for whether or not the program should terminate. 
  bool done = false;

  // Array of status name strings for each Status. 
  std::string status_names[4];
  status_names[NONE] = "regular";
  status_names[SILVER] = "silver";
  status_names[GOLD] = "gold";
  status_names[PLATINUM] = "platinum";

  // Run call center simulation.
  ObtainRequests(requests);
  while (!done) {
    std::cout << "Starting tick #" << clock << std::endl;
    InsertRequests(requests, queues, clock, status_names);
    done = SimulateAgent(requests, queues, time_agent_busy);
    clock++;
  }

  return 0;
}



