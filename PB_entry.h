#ifndef PB_ENTRY_H
#define PB_ENTRY_H

#include <iostream>
#include <string>

const int name_width = 10;
const int number_width = 12;

class PB_entry
{
  private:
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    std::string key;

  public:
    PB_entry(std::string first, std::string last, std::string number);
    std::string get_key();

    friend std::ostream& operator<<(std::ostream &os, PB_entry &in_entry);

  private:
    std::string format_number();
};

#endif
