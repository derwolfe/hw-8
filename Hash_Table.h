#ifndef HASH_TABLE_H
#define HASH_TABLE_H 

#include <string>
#include <stdint.h> 
#include "Bucket.h"

#define HASH_FUNC_CONST 10

class Hash_Table
{
  private:
    Bucket* buckets;
    int table_size;
    int elements;

  public:
    Hash_Table(int size = 10); // default value
    ~Hash_Table();
    
    void insert(std::string first, std::string last, std::string number);
    void search(std::string key, std::ostream& os);
    double get_load_factor();
    friend std::ostream& operator<<(std::ostream &os, Hash_Table &hash_table);

  private:
    uint32_t SuperFastHash(const char * data, int len); 
};

#endif
