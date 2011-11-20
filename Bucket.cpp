#include "Bucket.h"

using namespace std;

Bucket::Bucket()
{
  /*
   * IMPLEMENT ME
   */
}

Bucket::~Bucket()
{
  /*
   * IMPLEMENT ME
   */
}

int Bucket::get_size()
{
  /*
   * IMPLEMENT ME
   */
}

void Bucket::insert(PB_entry* in_entry)
{
  /*
   * IMPLEMENT ME
   */
}

PB_entry* Bucket::search(std::string key)
{
  /*
   * IMPLEMENT ME
   */
}

/*PRINT*/
ostream& operator<<(ostream &os, Bucket &bucket)
{
  /*
   * IMPLEMENT ME
   */
  os << "is empty" << endl;

  return os;
}


