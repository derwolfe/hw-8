#include "Linked_List.h"
#include "PB_entry.h"

class Bucket
{
  private:
    Linked_List* chain;

  public:
    Bucket();
    ~Bucket();

    int get_size();
    void insert(PB_entry* in_entry);
    PB_entry* search(std::string key);
    friend std::ostream& operator<<(std::ostream &os, Bucket &bucket);
};
