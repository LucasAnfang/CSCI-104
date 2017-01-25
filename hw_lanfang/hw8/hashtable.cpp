#include "hashtable.h"
#include <cctype>
#include <algorithm>
#include <iostream>
 
using namespace std;
HashTable::HashTable(int num_buckets) : num_buckets(num_buckets)
{
  numberElements = 0;
  buckets = new list<hashNode*>* [num_buckets];
  for(int i = 0 ; i < num_buckets; i++)
  {
    buckets[i] = new list<hashNode*>();
  }
}
/* Constructor that builds a hash table with 31 indices. */
HashTable::~HashTable()
{
  for(int i = 0; i < num_buckets; i++ )
  {
    list<hashNode*> *bucket = buckets[i];
    for(list<hashNode*>::iterator it = bucket->begin(); it!= bucket->end(); ++it)
    {
      delete (*it);
    }
    delete buckets[i];
  }
  delete[] buckets;
}

void HashTable::add (std::pair<std::string, int> new_item)
{
  if(((double)(numberElements+1))/num_buckets>1)// need to resize
  {
    //resize
    resize();
  }

  long long hash_code = Hash(new_item.first);
  int bucket_index =  hash_code % num_buckets;
  bool found = false; 
  list<hashNode*> *bucket = buckets[bucket_index];
  for(list<hashNode*>::iterator it = bucket->begin(); it!= bucket->end(); ++it)
  {
    if((*it)->hash_code == hash_code)
    {
      if((*it)->new_value.first == new_item.first)
      {
        found = true;
        break;
      }
    }
  }
  if(found)
  {
    throw "Key already exists";
  }
  else 
  {
    hashNode* newNode = new hashNode(new_item, hash_code);
    bucket->push_front(newNode);  
    numberElements++;
  }
}


         /* adds new_item to the hashtable.  
            Conflicts should be resolved via chaining.
            You may use the STL list to accomplish this. 
            Throws an exception if the key is already 
            in the hashtable.*/
const int& HashTable::find(std::string key) const
{
  long long hash_code = Hash(key);
  int bucket_index =  hash_code % num_buckets;
  bool found = false; 
  int *result;
  list<hashNode*> *bucket = buckets[bucket_index];
  if(bucket->size()==0)
  {
    throw "Key not found";
    //return 0;
  }
  for(list<hashNode*>::iterator it = bucket->begin(); it!= bucket->end(); ++it)
  {
    if((*it)->hash_code == hash_code)
    {
      if((*it)->new_value.first == key)
      {
        found = true;
        result = &((*it)->new_value.second);
        break;
      }
    }
  }
  if(!found)
  {
    throw "Key not found";
  }
  else 
  {
    return *result;  
  }
}

         /* returns the value with the associated key. 
            Throws an exception if the key is not in the
            hashtable. */
void HashTable::remove (std::string key)
{
  long long hash_code = Hash(key);
  int bucket_index =  hash_code % num_buckets;
  bool found = false; 
  //int *result;
  list<hashNode*> *bucket = buckets[bucket_index];
  if(bucket->size()==0)
  {
    throw "Key not found";
    //return 0;
  }
  for(list<hashNode*>::iterator it = bucket->begin(); it!= bucket->end(); ++it)
  {
    if((*it)->hash_code == hash_code)
    {
      if((*it)->new_value.first == key)
      {
        found = true;
        delete (*it);
        bucket->erase(it);
        break;
      }
    }
  }
  if(!found)
  {
    throw "Key not found";
  }
  else 
  {
    return;  
  }
}

         /* removes the element with the associated key. 
            Throws an exception if the key is not in the
            hashtable. */
void HashTable::update (std::pair<std::string, int> new_value)
{
  long long hash_code = Hash(new_value.first);
  int bucket_index =  hash_code % num_buckets;
  bool found = false; 
  //int *result;
  list<hashNode*> *bucket = buckets[bucket_index];
  if(bucket->size()==0)
  {
    throw "Key not found";
    //return 0;
  }
  for(list<hashNode*>::iterator it = bucket->begin(); it!= bucket->end(); ++it)
  {
    if((*it)->hash_code == hash_code)
    {
      if((*it)->new_value.first == new_value.first)
      {
        found = true;
        delete (*it);
        bucket->erase(it);
        bucket->push_front(new hashNode(new_value, hash_code));
        //result = &((*it)->new_value.second);
        break;
      }
    }
  }
  if(!found)
  {
    throw "Key not found";
  }
  else 
  {
    return;  
  }
}


         /* finds the item with the associated key,
            and updates its value accordingly. 
            Throws an exception if the key is not in the
            hashtable. */
long long HashTable::Hash(std::string key) const
{
  std::transform(key.begin(),key.end(), key.begin(), ::tolower);
  const char * lower_char = key.c_str();
  long long hash_code = 0;
  for(unsigned int i = 0 ; i < key.length() ; i++)
  {
    hash_code = 29*hash_code+lower_char[i];
  }
  return hash_code;
}

void HashTable::resize()
{
  //cout << "hi i am resizing" << endl;
    list<hashNode*> **new_buckets;
    int new_num_buckets = 2*num_buckets +1;
    new_buckets = new list<hashNode*>* [new_num_buckets];
    for(int i = 0 ; i < new_num_buckets; i++)
    {
      new_buckets[i] = new list<hashNode*>();
    }

    for(int i = 0; i < num_buckets; i++ )
    {
      list<hashNode*> *bucket = buckets[i];
      for(list<hashNode*>::iterator it = bucket->begin(); it!= bucket->end(); ++it)
      {

        hashNode* currentNode = (*it);
        long long current_hash_code = currentNode->hash_code;
        int new_bucket_index = current_hash_code%new_num_buckets;
        new_buckets[new_bucket_index]->push_front(currentNode);

      }
      delete buckets[i];
    }
    num_buckets = new_num_buckets;
    buckets = new_buckets;
    //cout << "Wow I finished the resize!" << endl;

}
