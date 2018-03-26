//
//  Librarian.h
//

#ifndef Librarian_h
#define Librarian_h

#include <iostream>
#include <list>
#include "User.h"

class Librarian: public User {
    public:
    	// constructors
        Librarian(string, string);
        Librarian();

        // overloaded operators to input,output, and find librarian based on username
        void operator>>(list<Librarian>& mylibrarians);
        void operator<<(list<Librarian>& mylibrarians);
        bool operator==(const Librarian&);

        // print librarians
        void printlibrarian();
        static void printlibrarians(list<Librarian>& mylibrarians);
    

};

#endif /* Librarian_h */
