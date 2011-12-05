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
   * IMPLEMENT ME: inserts the entry into the correct position relative to
   * the other elements
   * since the PB entry uses strings for all of its data, use str.compare to
   * check where the string belongs. I'll compare keys, since they should
   * always be unique, but last names might work just as well.
   * 
   * First, allocate the node, set its pointers.
   */
  Node* cur = new Node;   
  cur->entry = in_entry;
  cur->next = NULL;
  
//  /* Before searching, let's check if the list is empty. If so, set head,
//   * exit.*/
//  if (size == 0) {
//    head = cur;
//    return;
//  }
  /* Now that we know the list is NOT empty, we can insert the node. */
  Node* check = head;
  Node* prev  = NULL;
  
  
  while (check != NULL) {
    /* if items are equal, don't add, end the loop without making any changes
     */
    if (in_entry->get_key().compare(check->entry->get_key()) == 0) {
      return;
    } 
    /* Change this to last_name to test for name
     * if the new entry is LESS than or EQUAL to the current entry, insert it.*/
    if (in_entry->get_key().compare(check->entry->get_key()) < 0) { 
      break;
    } // otherwise, keep a trail.
    prev = check;
    check = check->next;
  }
  size++;
  if (prev == NULL) { // being inserted at the head
    cur->next = head;
    head = cur;
    return;
  } // else: this is not the head node
  prev->next = cur;
  cur->next = check;  
}

PB_entry* Linked_List::retrieve(string key)
{
    /*
     * IMPLEMENT ME
     *
     * Traverse the list, return a pointer to the entry!
     */
  Node* cur = head;

  if (size == 0) {
    return NULL; //or barf/throw exception
  } // else size > 0;
  while (cur)
   if (cur->entry->get_key().compare(key) == 0) {
     return cur->entry;
   } else {
     cur = cur->next;
   }
  /* if here then the entry was NOT found, so return NULL ptr or an exception */
  return NULL;
}

