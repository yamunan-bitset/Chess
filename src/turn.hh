#ifndef __TURN__HH__
#define __TURN__HH__

class Turn
{
public:
  const char* turn = turn_number % 2 == 1 ? "white" : "black";
  int turn_number;
  friend bool operator == (Turn&, char*);
  friend bool operator != (Turn&, char*);
  friend bool operator == (Turn&, int);
  friend bool operator != (Turn&, int);
};

#endif
