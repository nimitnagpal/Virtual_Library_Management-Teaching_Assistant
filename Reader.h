//
//  Reader.hpp
//

#ifndef Reader_h
#define Reader_h

#include <iostream>
#include <string>
#include <list>
#include "User.h"
#include "Book.h"
#include "Copy.h"
#include <vector>

using namespace std;

class Reader: public User {
    
    public:
        // constructors
        Reader();
        Reader(string, string);
        Reader(char type, string, string, int , list<Copy> , int, list<Book>, int, int);

        // accessors and mutators
        void addcopyborrowed(Copy tempborrowcopy);
        void deletecopyborrowed(Copy tempdeletecopy);
        void addbookreserved(Book tempreservebook);
        void deletebookreserved(Book& tempdeletebook);
        void setmax_copies(int tempmax_copies);
        void setnumpenalties(int tempnumpenalties);
        void setlistcopiesborrowed(list<Copy>);
        void setlistbooksreserved(list<Book>);
        void setreadertype(char);
        void setnumbooksreserved(int);
        void setnumcopiesborrowed(int);
        char getreadertype();
        int getnumcopiesborrowed();
        int getnumbooksreserved();
        int getnumpenalties();
        int getmaxcopies();
        list<Copy> getlistcopiesborrowed();
        list<Book> getlistbooksreserved();
        
        // print reader info
        void printReader();
        void printcopiesborrowed();
        void printbooksreserved();
        
        // overloaded operators to input, output, and find reader based on username
        void operator>>(list<Reader>& myreaders);
        void operator<<(list<Reader>& myreaders);
        bool operator==(const Reader& rhs);

        // decrease max copies if penalty threshold reached
        void decreasemaxcopies();
    
    private:
        char readertype;
        int numbooksreserved;
        int numcopiesborrowed;
        int max_copies;
        list<Copy> copiesborrowed;
            list<Copy>::iterator iter=copiesborrowed.begin();
        list<Book> booksreserved;
            list<Book>::iterator itera=booksreserved.begin();
        int numpenalties;
};

#endif /* Reader_h */
