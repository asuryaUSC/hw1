#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

// push back function
void ULListStr::push_back(const std::string& val){
  if(tail_ == nullptr || tail_ -> last == ARRSIZE){
    Item* newItem = new Item;
    if(tail_ != nullptr){
      tail_->next = newItem;
      newItem->prev = tail_;
    }
    tail_ = newItem;
    if(head_ == nullptr){
      head_ = tail_;
    }
  }
  tail_->val[tail_->last++] = val;
  size_++;
}

// push front function
void ULListStr::push_front(const std::string& val){
  if(head_ == nullptr || head_->first == 0){
    Item* newItem = new Item;
    newItem->first = newItem->last = ARRSIZE;

    if(head_ != nullptr){
      head_->prev = newItem;
      newItem->next = head_;
    }
    head_ = newItem;
    if(tail_ == nullptr){
      tail_ = head_;
    }
  }
  head_->val[--head_->first] = val;
  size_++;
}

// pop back function
void ULListStr::pop_back(){
  if(tail_ == nullptr){
    throw std::invalid_argument("List is empty");
  }
  if(--tail_->last == 0){
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
    if(tail_ != nullptr){
      tail_->next = nullptr;
    } else{
      head_ = nullptr;
    }
  }
  size_--;

}

// pop front function
void ULListStr::pop_front(){
  if(head_ == nullptr){
    throw std::invalid_argument("List is empty");
  }

  if(++head_->first == ARRSIZE){
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
    if(head_ != nullptr){
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }
  }
  size_--;
}

// back function
std::string const & ULListStr::back() const{
  if(tail_ == nullptr){
    throw std::invalid_argument("List is empty");
  }
  return tail_->val[tail_->last - 1];
}

// front
std::string const & ULListStr::front() const{
  if(head_ == nullptr){
    throw std::invalid_argument("List is empty");
  }

  return head_->val[head_->first];
}

// getValAtLoc function
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if(loc >= size_ || head_ == nullptr){
    return nullptr;
  }
  Item* temp = head_;
  size_t idx = loc;

  while(temp != nullptr){
    if(idx < (temp->last - temp->first)){
      return &temp->val[temp->first + idx];
    }
    idx -= (temp->last - temp->first);
    temp = temp->next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
