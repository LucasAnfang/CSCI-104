#include "llistint.h"
#include <cstdlib>
#include <stdexcept>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const int& val)
{ 
   
   if(loc > size_)
   {
      return;
   }
   //create a new item
   Item* newItem = new Item();
   newItem->val = val; 
   newItem->next = NULL;
   newItem->prev = NULL;
   if(loc == size_) //Add this to the end of the list
   {
      if(tail_ == NULL) //List is empty
      {
         head_ = newItem;
         tail_ = newItem;
         size_ = 1;
      }
      else
      {
         tail_->next = newItem;
         newItem->prev = tail_;
         tail_ = newItem;
         size_++;
      }   
   }
   else if(loc == 0)//adding to the head
   {
      newItem->next = head_;
      head_->prev = newItem;
      head_ = newItem;
      size_++;
   }
   else//adding this somewhere else
   {  
      Item* currentItem = getNodeAt(loc);
      if(currentItem != NULL)
      {
         newItem->next = currentItem;
         newItem->prev = currentItem->prev;
         (currentItem->prev)->next = newItem;
         currentItem->prev = newItem;
         size_++;
      }   
   }
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
   //sanity check
   if(loc < 0 || loc >=size_)
   {
   return;
   }
   if(loc == 0)//remove the head
   {
      if(head_->next != NULL)
      {
         (head_->next)->prev = NULL;
         Item* currentItem = head_;       
         head_ = head_->next;
         delete currentItem;
         size_--;
      }
      else //head is the only element
      {
         delete head_;
         head_ = NULL;
         tail_ = NULL;
         size_ = 0;
      }    
   }
   else if(loc == size_-1) //remove the tail
   {
      (tail_->prev)->next = NULL;
      Item* currentItem = tail_;
      tail_ = tail_->prev;
      delete currentItem;
      size_--;
   }
   else //remove element in the middle of the list
   {
      Item* currentItem = getNodeAt(loc);
      if(currentItem != NULL)
      {
         (currentItem->next)->prev = currentItem->prev;
         (currentItem->prev)->next = currentItem->next;
         delete currentItem;
         size_--;        
      }      
   }   
}

LListInt::Item* LListInt::getNodeAt(int loc) const
{
   //Sanity Checks
   if(head_ == NULL)
   {
      return NULL;
   }
   if(loc < 0)
   {
      return NULL;
   }
   if(loc >= size_)
   {
      return NULL;
   }
   
   int scan = 0;
   Item* desiredItem = head_;
   while(scan < loc)
   {
      desiredItem = desiredItem->next;
      scan++;
   }
   return desiredItem;
}


void LListInt::set(int loc, const int& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  if(loc < 0 || loc >= size_){
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
