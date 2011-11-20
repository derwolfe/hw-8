#include "Linked_List.h"

using namespace std;

Linked_List::Linked_List()
{
  head = NULL;
  size = 0;
}

Linked_List::~Linked_List()
{
  Node* delete_node;

  while (size != 0) {
    delete_node = head;
    head = head->next;
    
    delete delete_node;
    size--;
  }
}

/*PRINT*/
void Linked_List::print(ostream& os)
{
  Node* cur = head;

  while (cur != NULL) {
    os << *cur->entry;
    cur = cur->next;
  }
}

bool Linked_List::is_empty()
{
  return size == 0;
}

int Linked_List::get_size()
{
  return size;
}

void Linked_List::sorted_insert(PB_entry* in_entry)
{
    /*
     * IMPLEMENT ME
     */
}

PB_entry* Linked_List::retrieve(string key)
{
    /*
     * IMPLEMENT ME
     */
}
