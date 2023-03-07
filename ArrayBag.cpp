/*
Name: Eric Wu
Professor: Tizana Ligorio
Description: ArrayBag interface for term project
Course: CSCI 235 Spring 2023
Due Date: 03/10/2023
*/

#include "ArrayBag.hpp"


/** default constructor**/
template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): item_count_{0}
{
}  // end default constructor

/**
 @return item_count_ : the current size of the bag
 **/
template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return item_count_;
}  // end getCurrentSize

/**
 @return true if item_count_ == 0, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty

/**
 @return true if new_etry was successfully added to items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& new_entry)
{
	bool has_room = (item_count_ < DEFAULT_CAPACITY);
	if (has_room)
	{
		items_[item_count_] = new_entry;
		item_count_++;
      return true;
	}  // end if

	return false;
}  // end add

/**
 @return true if an_etry was successfully removed from items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& an_entry)
{
   int found_index = getIndexOf(an_entry);
	bool can_remove = !isEmpty() && (found_index > -1);
	if (can_remove)
	{
		item_count_--;
		items_[found_index] = items_[item_count_];
	}  // end if

	return can_remove;
}  // end remove

/**
 @post item_count_ == 0
 **/
template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	item_count_ = 0;
}  // end clear

/**
 @return the number of times an_entry is found in items_
 **/
template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& an_entry) const
{
   int frequency = 0;
   int cun_index = 0;       // Current array index
   while (cun_index < item_count_)
   {
      if (items_[cun_index] == an_entry)
      {
         frequency++;
      }  // end if

      cun_index++;          // Increment to next entry
   }  // end while

   return frequency;
}  // end getFrequencyOf

/**
 @return true if an_etry is found in items_, false otherwise
 **/
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& an_entry) const
{
	return getIndexOf(an_entry) > -1;
}  // end contains

// ********* PRIVATE METHODS **************//

/**
	@param target to be found in items_
 	@return either the index target in the array items_ or -1,
 	if the array does not containthe target.
 **/
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{  
	bool found = false;
  int result = -1;
  int search_index = 0;
   // If the bag is empty, item_count_ is zero, so loop is skipped
   while (!found && (search_index < item_count_))
   {

      if (items_[search_index] == target)
      {
         found = true;
         result = search_index;
      }
      else
      {
         search_index++;
      }  // end if
   }  // end while
   return result;
}  // end getIndexOf

template<class ItemType>
void ArrayBag<ItemType>::operator+=(const ArrayBag<ItemType> &arrayBag)//changes the += operator to add the values in a arraybag to another one.
{
   for(std::size_t i = 0; i < arrayBag.getCurrentSize(); i++)
   {
      if(item_count_ < 10){//while item count is lower than the maximum items allowed, loop through the range of the the arraybag to be added and add the new items.
         items_.add(arrayBag[i]);
         item_count_++;
      }
   }
}

template<class ItemType>
void ArrayBag<ItemType>::operator/=(const ArrayBag<ItemType> & arrayBag)//changes the /= operator to only add new arraybag values that are not duplicates.
{
   for(std::size_t i = 0; i < arrayBag.getCurrentSize(); i++)
   {
      if((items_.getIndexOf(arrayBag[i]) == -1) && (item_count_ < 10))//while the item count is lower than the maximum and the item in the arraybag isnt a duplicate, add it to the private member items_.
      {
         items_.add(arrayBag[i]);
         item_count_++;
      }
   }
}
