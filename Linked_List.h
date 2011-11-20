#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "PB_entry.h"

class Linked_List
{
 private:
  struct Node
  {
    PB_entry *entry;
    Node     *next;
  };

  Node *head;
  int   size;
 public:
  Linked_List();
  ~Linked_List();

  void       sorted_insert(PB_entry* entry);
  PB_entry*  retrieve(std::string key);
  bool       is_empty();
  int        get_size();
  void       print(std::ostream& os);
};

#endif
