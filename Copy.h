//
//  Copy.hpp
//  ESE224 Final
//

#ifndef Copy_h
#define Copy_h

#include <iostream>
#include <string>
#include "Book.h"
#include <vector>
using namespace std;


class Copy: public Book {
    public:
    
        // constructors
        Copy(Book);
        Copy();

        // accessors and mutators
        void setreadername(string);
        string getreadername();
        void setborrowdate(int);
        void setreservationdate(int);
        int getreservationdate();
        void setexpirationdate(int);
        int getexpirationdate();
        void setID(int);
        int getID();

        // print copies
        void printCopy();
        static void printcopies(list<Copy>& mycopies);

        // overloaded operator used to find copy in list
        bool operator== (const Copy&);

        // overloaded operators to input copy info from file
        void operator>> (list<Copy>& mycopies);

        // overloaded operator used to output copy info
        void operator<< (list<Copy>& mycopies);

        // used to determine which copy from the list of copies based on ID
        static Copy whichcopy(int tempID, list<Copy>& tempcopies);

        // update copy info when returned
        void copyreturned(int currentdate);
    
    private:
        string readername;
        int ID;
        int borrowdate;
        int reservationdate;
        int expirationdate;
};

#endif /* Copy_h */
