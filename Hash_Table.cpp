#include <cstddef>
#include <math.h>
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
Hash_Table::Hash_Table(int size)
{
  Bucket* buck [size];
  buckets = buck;
  //buckets[size]; /* set the size of the array to hold buckets*/
  /* next, allocate memory for the buckets and shove them into the table
   * buckets* is an array of pointers to buckets.
   */
  int i = 0;  
  while (i <= size - 1) {
    buckets[i] = new Bucket; 
    i++;
  }
  table_size = size;
  elements = 0;
} 

/* Destructor - deallocate all memory, zero/Null out private vars
 */
Hash_Table::~Hash_Table()
{ 
  delete [] buckets; /* deallocate array, no need to loop through and delete elements */
  table_size = 0;
  elements = 0;
}

/* insert a new PB_entry */
void Hash_Table::insert(string first, string last, string number)
{
  /* instantiate a new PB object
   *
   * Hash the number to obtain the key value. 
   * superfasthash expects a char string, not a string. 
   * use c_str to change the string to a cstring
   */
  PB_entry* in_entry = new PB_entry(first, last, number);
  /* 
   * take hash modulo table size to get a usable bucket_id
   */
  int bucket_id = SuperFastHash(number.c_str(), 10) % table_size;
  /* 
   * Sanitize the hash/bucket id, by making it $SIZE number of digits long
   * make sure that all buckets in the table can be accessed (bucket 0);
   */
  buckets[bucket_id]->insert(in_entry);
  elements++;
  return;
}
  
void Hash_Table::search(string key, ostream& os)
{
  /* use the bucket's search function and return the node
   * this will call the LL retrieve function. If the item is not found, 
   * it will return a NULL ptr.
   *
   * if the item is found it will return a pointer to the PB_entry
   * The overloaded output operator for PB entry will spit the 
   * entry's contens out. 
   */
  int bucket_id = SuperFastHash(key.c_str(), 10) % table_size;
  PB_entry* result = buckets[bucket_id]->search(key); 
  if (result == NULL) {
    os << "Entry not found" << endl;
  } else if (result != NULL) {
    os << "Entry found!" << endl;
    os << "Bucket: " << bucket_id << endl;
    os << result << endl;
  }
}

double Hash_Table::get_load_factor()
{
  return (elements / table_size); /* ex. 40 elements, 10 buckets, load factor of 4. */
}

ostream& operator<<(ostream &os, Hash_Table &in_table)
{ 
  int inc = 0;
  while (inc < in_table.table_size) { 
    /* use the overloaded output operator from bucket */
    os << in_table.buckets[inc]; 
    inc++;
  }
  return os;
    
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

