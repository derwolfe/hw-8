#include <cstddef>
#include "Hash_Table.h"
#include "PB_entry.h"

using namespace std;

/*
 * IMPLEMENT ME
 *
 * Please implement the Hash Table methods in the same order in which
 * they are defined in Hash_Table.h, to simplify grading.
 *
 * Constructor
 * Destructor
 * insert
 * search
 * get_load_factor
 * operator<<
 */

/* constructor - allocates SIZE buckets, sets table size as an array, and elements */
Hash_Table::Hash_Table(size)
{
  buckets[size]; /* set the size of the array to hold buckets*/
  /* next, allocate memory for the buckets and shove them into the table */
  int i = 0;  
  while (i <= size - 1) {
    buckets[i] = new Bucket;
  }
  table_size = size;
  elements = 0;
} 

/* Destructor - deallocate all memory, zero/Null out private vars
 */
Hash_Table::~Hash_Table()
{ //also is buckets an array of ptrs? methinks yes.
  int i = 0;
  while (i <= size - 1) {
    delete buckets[i];
  }
  delete buckets;
  buckets = NULL;
  table_size = 0;
  elements = 0;
}

/* insert a new PB_entry */
void Hash_Table::insert(string first, string last, string number)
{
  /*
   * Hash the number to obtain the key value. Case the uint32_t to an int
   * to use it as an array value. 
   */
  int bucket_id = int(SuperFastHash(number, HASH_FUNC_CONST));
  buckets[bucket_id]->sorted_insert(first, last, number);
}
  

ostream& operator<<(ostream &os, Hash_Table &in_table)
{ 
    os << "Entry found!" << endl;
    os << "Entry not found" << endl;
    os << "Bucket: " << i << endl;
}
/*
 * Hash function and get16bits. Open source under LGPL 2.1
 *
 * http://www.azillionmonkeys.com/qed/hash.html
 *
 * Thanks to Paul Hsieh. 
 */
#undef get16bits
#if (defined(__GNUC__) && defined(__i386__)) || defined(__WATCOMC__) \
  || defined(_MSC_VER) || defined (__BORLANDC__) || defined (__TURBOC__)
#define get16bits(d) (*((const uint16_t *) (d)))
#endif

#if !defined (get16bits)
#define get16bits(d) ((((uint32_t)(((const uint8_t *)(d))[1])) << 8)\
                       +(uint32_t)(((const uint8_t *)(d))[0]) )
#endif

uint32_t Hash_Table::SuperFastHash(const char *data, int len) 
{
  uint32_t hash = len, tmp;
  int rem;

  if (len <= 0 || data == NULL) {
    return 0;
  }

  rem = len & 3;
  len >>= 2;

  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }

  /* Handle end cases */
  switch (rem) {
  case 3: 
    hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: 
    hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: 
    hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
    break;
  }

  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;

  return hash;
}

