#include "stackint.h"
#include "alistint.h"
StackInt::StackInt()
{

}

StackInt::~StackInt()
{

}

bool StackInt::empty() const
{
   return list_.size() == 0;
}

void StackInt::push(const int& val)
{
   list_.insert(list_.size(), val);
}

int const &  StackInt::top() const
{
   return list_.get(list_.size()-1);
}

void StackInt::pop()
{
   list_.remove(list_.size()-1);
}



