/*
Name: Eric Wu
Professor: Tizana Ligorio
Description: Creating the LibraryRecord subclass for the project
Course: CSCI 235 Spring 2023
Due Date: 03/10/2023
*/

#ifndef LIBRARYRECORD_HPP_
#define LIBRARYRECORD_HPP_

#include "Book.hpp"
#include "ArrayBag.hpp"
#include <string>
#include <vector>

class LibraryRecord : public ArrayBag<Book>
{
    private:
    std::vector<Book> checked_out_;

    public:
    /** @param:   A reference to a Book object to be checked in
        @return:  returns true if a book was successfully added to items_, false otherwise
        @post:    adds book to items_.
    **/
    bool checkIn(const Book &book_checked_in);


    /** @param:   A reference to a Book object to be checked out   
        @return:  returns true if a book was successfully removed from items_, false otherwise
        @post:    removes the book from the LibraryRecord and if remove was successful, it adds the book to the vector of checked-out.
    **/
    bool checkOut(const Book &book_checked_out);


    /**
    @param:   A reference to a Book object
    @return:  The number of times (int) the referenced Book has been checked out
    */
    int getCheckOutHistory(const Book& book);


    /**
    @post: Outputs the names of the Books in the LibraryRecord and the number of times each Book has been cheked out

      For each Book in the LibraryRecord you will output:
            "[title_] is written by [author_]. Page Count: [page_count_]. [It is / It is not] available digitally.\n
            It has been checked out [_] times."
    **/
    void display() const;

    /**
    @post:    Prints the title of each Book in the LibraryRecord
    Example:
    "title1, title2, title3, title4!" Note the commas and exclamation mark.
    */
    void displayTitles() const;



    /**
    @return:    Returns true if the LibraryRecord was successfully duplicated, false otherwise (there is nothing to duplicate or duplicating would exceed DEFAULT_CAPACITY).
    @post:      Duplicates all the items in the LibraryRecord
    Example: we originally have [book1, book2] and after duplication we have [book1, book2, book1, book2]
    */
    bool duplicateStock() const;


    /**
    @param:   A reference to a book
    @return: True if at least one copy of the referenced book was removed from items_, false otherwise 
    @post: remove all occurrences of the referenced book
    */
    bool removeStock(const Book &book);


    /**
    @param:   A reference to another LibraryRecord
    @return:  Returns true if the 2 library records have the same contents, regardless of their order. For example, if the current holdings of the LibraryRecord are [book1, book2, book3]
    and those of the referenced LibraryRecord are [book3, book1, book2], it will return true
    */
    bool equivalentRecords(const LibraryRecord &record);



    /**
        @param:   A reference to another LibraryRecord object
        @post:    Combines the contents from both LibraryRecord objects, including duplicates.
        Example: [book1, book2, book3] += [book1, book4] will produce [book1, book2, book3, book1, book4]

        IMPORTANT: We are carrying over the number of times a book has been checked out. For example, if we have LibraryRecord1 += LibraryRecord2 and
        book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the += operation
        Hint: use getCheckOutHistory and the checkout history vector
    */
    void operator+=(const LibraryRecord &record);
    
    /** @param:   A reference to another LibraryRecord object
        @post:    Combines the contents from both LibraryRecord objects, EXCLUDING duplicates.
        Example: [book1, book2, book3] /= [book1, book4] will produce [book1, book2, book3, book4]

        IMPORTANT: We are carrying over the nunber of times a book has been checked out. For example, if we have LibraryRecord1 /= LibraryRecord2 and
        book4 is in LibraryRecord2 and has been checked out 2 times, then it should still be checked out 2 times in LibraryRecord1 after the /= operation
        Hint: use getCheckOutHistory and the checkout history vector
    */
    void operator/=(const LibraryRecord &record);
};

#endif