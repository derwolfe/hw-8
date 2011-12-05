#include "Bucket.h"

using namespace std;

Bucket::Bucket()
{
  /*
   * IMPLEMENT ME
   * Construct a new linked list.
   */
  chain = new Linked_List;
}

Bucket::~Bucket()
{
  /*
   * IMPLEMENT ME
   *
   * deallocate the memory for the chain pointer, set it to NULL
   */
  delete chain;
  chain = NULL;
}

int Bucket::get_size()
{
  /*
   * IMPLEMENT ME
   *
   */
  if (chain == NULL) {
    return 0;
  } // else
  return chain->get_size();
}

void Bucket::insert(PB_entry* in_entry)
{
  /*
   * IMPLEMENT ME
   */
  if (in_entry == NULL) {
    return; //or throw exception
  }
  chain->sorted_insert(in_entry);
  return;
}

PB_entry* Bucket::search(std::string key)
{
  /*
   * IMPLEMENT ME
   *
   * use the LL key search - think of false cases where NULL should be
   * returned.
   */
  PB_entry* found;
  found = chain->retrieve(key);
  return found;
}

/*PRINT*/
ostream& operator<<(ostream &os, Bucket &bucket)
{
  /*
   * IMPLEMENT ME 
   * use the LL print method to print the contents of the bucket.
  */
  if (bucket.get_size() == 0) {
    os << "is empty" << endl;
  } else {
    bucket.chain->print(os);
  return os;
  }
}


