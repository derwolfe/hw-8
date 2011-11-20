#include <iomanip>
#include "PB_entry.h"

using namespace std;

PB_entry::PB_entry(string first, string last, string number)
{
  first_name = first;
  last_name = last;
  phone_number = number;
  key = phone_number;
}

string PB_entry::get_key()
{
  return key;
}

/*PRINT*/
ostream& operator<<(ostream &os, PB_entry &in_entry)
{
  os << setw(name_width) << left << in_entry.first_name << " ";
  os << setw(name_width) << left << in_entry.last_name << " ";
  os << setw(number_width) << left << in_entry.format_number() << endl;

  return os;
}

string PB_entry::format_number()
{
  string area_code = phone_number.substr(0,3);
  string first_three = phone_number.substr(3,3);
  string last_four = phone_number.substr(6,4);

  return area_code + "-" + first_three + "-" + last_four;
}


