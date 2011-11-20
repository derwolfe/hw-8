#include <cstdlib>
#include <string>
#include "Utility.h"
#include "Hash_Table.h"

using namespace std;

int main(int argc, char* argv[])
{
  int    hash_table_size = 10; 
  string db_filename     = argv[1];
  string cmd_filename    = argv[2];

  if (argc > 3) {
    hash_table_size = atoi(argv[3]); 
  }

  Hash_Table* hash_table = new Hash_Table(hash_table_size);

  process_phonebook_db(db_filename, hash_table);
  process_phonebook_cmd(cmd_filename, hash_table);
  
  delete hash_table;

  exit(0);
}
