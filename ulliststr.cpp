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
void ULListStr::push_back(const std::string& val)
{
	if (tail_ == NULL){ // list is empty, making this become the only node
		Item* newItem = new Item();
		newItem->val[0] = val;
		newItem->first = 0;
		newItem->last = 1;
		head_ = newItem; // change this?
		tail_ = newItem;
	}
	else if (tail_->last < ARRSIZE) // there's still room at the end of the tail node's array
	{
		tail_->val[tail_->last] = val;
		tail_->last++;
	}
	else { // the tail node's array is therefore full, meaning we need to allocate a new node right after it
		Item* newItem = new Item();
		newItem->val[0] = val;
		newItem->first = 0;
		newItem->last = 1;
		newItem->prev = tail_;
		tail_->next = newItem;
		tail_ = newItem;
	}
	size_++;
}

void ULListStr::pop_back()
{
	if (tail_ == NULL){
		throw std::invalid_argument("The list is empty");
	}
	tail_->last--; // shrink the used range from the back

	if (tail_->first == tail_->last){ // no used slots left? remove it from the list entirely
		Item* deleteThis = tail_;
		tail_ = tail_->prev;

		if (tail_ == NULL){
			head_ = NULL;
		}
		else {
			tail_->next = NULL;
		}
		delete deleteThis;
	}
	size_--;
}

void ULListStr::push_front(const std::string& val)
{
	if (head_ == NULL){ 
		Item* newItem = new Item();
		newItem->val[0] = val;
		newItem->first = 0;
		newItem->last = 1;
		head_ = newItem; // change this?
		tail_ = newItem;
	}
	else if (head_->first > 0) // room is available before the current first used index
	{
		head_->first--;
		head_->val[head_->first] = val;
	}
	else { // no room before index 0, so create a new head node, placing the value in the last slot of this new array
		Item* newItem = new Item();
		newItem->first = ARRSIZE - 1;
		newItem->last = ARRSIZE;
		newItem->val[ARRSIZE - 1] = val;
		newItem->next = head_;
		head_->prev = newItem;
		head_ = newItem;
	}
	size_++;
}

void ULListStr::pop_front()
{
	if (head_ == NULL){
		throw std::invalid_argument("The list is empty");
	}
	head_->first++;

	if (head_->first == head_->last){
		Item* deleteThis = head_;
		head_ = head_->next;

		if (head_ == NULL){
			tail_ = NULL;
		}
		else {
			head_->prev = NULL;
		}
		delete deleteThis;
	}
	size_--;
}

std::string const & ULListStr::back() const // return the last used value in the tail node's array
{
	return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const // return the first used value in the head node's array
{
	return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const // O(n) OK
{
	if (loc >= size_){
		return NULL;
	}
Item* current = head_;
size_t countBefore = 0; // denotes how many values have been passed in the earlier nodes
while (current != NULL){
	size_t countInNode = current->last - current->first;
	if (loc < countBefore + countInNode){ // if loc is within this stated range, then we've found it
		size_t indexInNode = current->first + (loc - countBefore);
		return &current->val[indexInNode];
	}
	countBefore += countInNode;
	current = current->next;
}
return NULL; // otherwise
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
