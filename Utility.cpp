#include <fstream>
#include "Utility.h"

using namespace std;

void process_phonebook_db(string filename, Hash_Table* hash_table)
{
  string firstname, lastname, number;
  ifstream fin(filename.c_str());
  fin >> firstname >> lastname >> number;

  while (!fin.eof()) {
    /*
     * IMPLEMENT ME
     */
    fin >> firstname >> lastname >> number;
  }

  fin.close();
}

/*PRINT*/
void process_phonebook_cmd(string filename, Hash_Table* hash_table)
{
  ifstream fin(filename.c_str());
  string cmd_str, key;
  double load_factor;
  fin >> cmd_str;

  while (!fin.eof()) {
    Command cmd = get_next_command(cmd_str);

    switch (cmd) {
      case SEARCH:
        fin >> key;
        cout << "***************" << endl;
        cout << "*   SEARCH: " << key << endl;
        cout << "***************" << endl;

        /*
         * IMPLEMENT ME
         */
        break;
      case PRINT:
        cout << "***************" << endl;
        cout << "*    PRINT:   *" << endl;
        cout << "***************" << endl;

        /*
         * IMPLEMENT ME
         */
        break;
      case LOAD_FACTOR:
        cout << "***************" << endl;
        cout << "* LOAD FACTOR *" << endl;
        cout << "***************" << endl;

        /*
         * IMPLEMENT ME
         */
        cout << "Load factor: " << load_factor << endl;
        break;
      case INVALID:
        cout << "Error: command is invalid" << endl;
        break;
    }

    fin >> cmd_str;
  }

  fin.close();
}

Command get_next_command(string cmd_str)
{
  Command cmd;

  if (cmd_str.compare("search") == 0) {
    cmd = SEARCH;
  } else if (cmd_str.compare("print") == 0) {
    cmd = PRINT;
  } else if (cmd_str.compare("load_factor") == 0) {
    cmd = LOAD_FACTOR;
  } else {
    cmd = INVALID;
  }
  
  return cmd;
}
