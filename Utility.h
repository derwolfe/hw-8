#include "Hash_Table.h" 

enum Command
{
  PRINT,
  SEARCH,
  LOAD_FACTOR,

  INVALID
};

Command get_next_command(std::string cmd_str);
void process_phonebook_db(std::string filename, Hash_Table* hash_table);
void process_phonebook_cmd(std::string filename, Hash_Table* hash_table);
