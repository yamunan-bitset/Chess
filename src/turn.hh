#ifndef __TURN__HH__
#define __TURN__HH__

class Turn
{
public:
  char* turn;
  friend bool operator == (Turn&, char*);
  friend bool operator != (Turn&, char*);
};

#endif
