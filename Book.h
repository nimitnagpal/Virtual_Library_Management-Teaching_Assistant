//
//  Book.hpp
//

#ifndef Book_h
#define Book_h

#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <vector>
#include "User.h"
using namespace std;

class Book {

    public:
        // constructors
        Book();
        Book(int ISBN, string temptitle, string tempauthor, string tempcategory);
        
        // print book or list of books
        void printbook();
        static void printbooks(list<Book>& mybooks);
        void printreservers();

        // mutators and accessors
        void settitle(string);
        void setauthor(string);
        void setcategory(string);
        void setISBN(int);
        int getISBN();
        int getnumreservers();
        deque<string> getlistofreservers();
        string getauthor();
        string gettitle();
        string getcategory();
        void addreserver(string);
        void addbookreserver(string);
        void setnumreservers(int);
        void setlistofreservers(deque<string>);
        void deletereserver(string);

        // operator overloading
        bool operator== (const Book);
        void operator>> (list<Book>&);
        void operator<< (list<Book>&);
        bool operator>( const Book& rhs) const;

        // adjust queue
        void updatequeue(int& currentdate, int& reservationdate);
        void deletefirstinline();
    
        // find book from list
        static  Book whichbook(int, list<Book>);
    
    private:
        int ISBN;
        string title;
        string author;
        string category;
        int numreservers;
        // used a deque instead of a normal queue because need to remove elements from middle
        deque<string> listofreservers;
};

#endif /* Book_h */
