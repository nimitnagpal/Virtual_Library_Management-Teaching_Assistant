//
//  Reader.cpp
//
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Book.h"
#include "Copy.h"
#include "Reader.h"
//#include "Student.h"
//#include "Teacher.h"

Reader::Reader() {
    
}

Reader::Reader(string tempusername, string temppassword) {
    set_username(tempusername);
    set_password(temppassword);
    numbooksreserved=0;
    numcopiesborrowed=0;
    numpenalties=0;
}

Reader::Reader(char temptype, string tempusername, string temppassword, int tempnumcopies, list<Copy> tempcopiesborrowed, int tempnumbooks, list<Book> tempbooksreserved, int tempnumpenalties, int tempmaxcopies) {
    readertype=temptype;
    set_username(tempusername);
    set_password(temppassword);
    numcopiesborrowed=tempnumcopies;
    copiesborrowed=tempcopiesborrowed;
    numbooksreserved=tempnumbooks;
    booksreserved=tempbooksreserved;
    numpenalties=tempnumpenalties;
    max_copies= tempmaxcopies;
}

void Reader::setmax_copies(int tempmax_copies) {
    max_copies = tempmax_copies;
}

void Reader::setnumpenalties(int tempnumpenalties) {
    numpenalties=tempnumpenalties;
}

void Reader::addcopyborrowed(Copy tempborrowedcopy) {
    copiesborrowed.push_back(tempborrowedcopy);
}

void Reader::deletecopyborrowed(Copy copytodelete) {
    
    list<Copy>::iterator deleteiter = find(copiesborrowed.begin(), copiesborrowed.end(), copytodelete);
    
    deleteiter = copiesborrowed.erase(deleteiter);
    
    numcopiesborrowed = numcopiesborrowed-1;
    
}

void Reader::deletebookreserved(Book& booktodelete) {
    Book realdeletebook;
    realdeletebook.setISBN(booktodelete.getISBN());
    
    list<Book>::iterator finditer = find(booksreserved.begin(), booksreserved.end(), realdeletebook);
    
    bool found = (find(booksreserved.begin(), booksreserved.end(), realdeletebook) != booksreserved.end());
    
    if (found) {
        finditer = booksreserved.erase(finditer);
        numbooksreserved--;
    }
    //finditer = booksreserved.erase(finditer);
    else if (!found) {
        //
    }
    
    
    return;
}

void Reader::setlistcopiesborrowed(list<Copy> tempcopiesborrowed) {
    copiesborrowed=tempcopiesborrowed;
}

void Reader::setlistbooksreserved(list<Book> tempbooksreserved) {
    booksreserved=tempbooksreserved;
}

void Reader::setreadertype(char tempreadertype) {
    readertype=tempreadertype;
}

void Reader::setnumbooksreserved(int tempnumbooksreserved) {
    numbooksreserved=tempnumbooksreserved;
}

void Reader::setnumcopiesborrowed(int tempnumcopiesborrowed) {
    numcopiesborrowed=tempnumcopiesborrowed;
}

// input readers using overloaded operator
void Reader::operator>>(list<Reader>& mytempreaders) {
    ifstream input;
    string tempusername, temppassword, blankline;
    char tempreadertype;
    list<Copy> tempcopiesborrowed, mytempcopies;
    list<Copy>::iterator iter=tempcopiesborrowed.begin();
    list<Book> tempbooksreserved, mytempbooks;
    list<Book>::iterator itera=tempbooksreserved.begin();
    int tempnumpenalties, tempcopyID, tempnumcopies, tempnumbooks, tempbookISBN, tempmaxcopies;
    Book inputbook;
    Copy inputcopy;
    
    inputbook>>mytempbooks;
    inputcopy>>mytempcopies;
    
    
    
    input.open("readerfinal.dat");
    if(input.fail()) {
        cerr << "Error opening readerfinal.dat..." << endl;
    }
    
    while(input >> tempreadertype) {
        getline(input, blankline);
        getline(input, tempusername);
        getline(input, temppassword);
        input >> tempnumcopies;
        for(int i=0;i<tempnumcopies;i++) {
            input >> tempcopyID;
            //check copy ID, return copy to tempcopy
            Copy tempcopy=Copy::whichcopy(tempcopyID, mytempcopies);
            tempcopiesborrowed.insert(iter, tempcopy);
        }
        input >> tempnumbooks;
        for (int a=0;a<tempnumbooks;a++) {
            input >> tempbookISBN;
            Book tempbook=Book::whichbook(tempbookISBN, mytempbooks);
            tempbooksreserved.insert(itera, tempbook);
        }
        
        input >> tempnumpenalties;
        input >> tempmaxcopies;
        
        Reader tempreader(tempreadertype, tempusername, temppassword, tempnumcopies, tempcopiesborrowed, tempnumbooks
                          , tempbooksreserved, tempnumpenalties, tempmaxcopies);
        
        mytempreaders.push_back(tempreader);
        
        tempcopiesborrowed.clear();
        tempbooksreserved.clear();
        
    }
    input.close();
}

void Reader::printReader() {
    Copy tempcopy;
    Book tempbook;
    string temptitle;
	int tempid;
    cout << "Type: " << readertype << "\n";
    print_user();
    cout << "Number of copies borrowed: " << numcopiesborrowed << "\nCopies Borrowed: ";
    for(iter=copiesborrowed.begin();iter!=copiesborrowed.end();iter++) {
        tempcopy=*iter;
        temptitle=tempcopy.gettitle();
		tempid = tempcopy.getID();
        cout << temptitle << "(ID: " << tempid << ")" << ",";
    }
    cout << endl;
    cout << "Number of books reserved: " << numbooksreserved << "\nBooks Reserved: ";
    for(itera=booksreserved.begin();itera!=booksreserved.end();itera++) {
        tempbook=*itera;
        temptitle=tempbook.gettitle();
        cout << temptitle << ",\t";
    }
    cout << endl;
    cout << "Number of penalties: " << numpenalties << endl;
}


void Reader::printcopiesborrowed() {
    for(iter=copiesborrowed.begin();iter!=copiesborrowed.end();iter++) {
        Copy tempcopy=*iter;
        string temptitle=tempcopy.gettitle();
        cout << temptitle << ",\t";
    }
    cout << endl;
}

void Reader::printbooksreserved() {
    for(itera=booksreserved.begin();itera!=booksreserved.end();itera++) {
        Book tempbook=*itera;
        string temptitle=tempbook.gettitle();
        cout << temptitle << "\t";
    }
    cout << endl;
}

// output readers to file using overloaded
void Reader::operator<<(list<Reader>& tempreaders) {
    ofstream output;
    list<Reader>::iterator iterr;
    list<Copy>::iterator iterc;
    Copy tempcopy;
    Book tempbook;
    output.open("readerfinal.dat");
    if(output.fail()) {
        cerr << "Error opening readerfinal.dat for output..." << endl;
    }
    
    for(iterr=tempreaders.begin();iterr!=tempreaders.end();iterr++) {
        Reader tempreader=*iterr;
        output << tempreader.readertype << "\n" << tempreader.get_username() << "\n";
        output << tempreader.get_password() << endl << tempreader.numcopiesborrowed << endl;
        
        
        
        for(iterc=tempreader.copiesborrowed.begin(); iterc!=tempreader.copiesborrowed.end(); iterc++) {
            tempcopy=*iterc;
            // check wich copy it is function
            output << setw(4) << setfill('0') << tempcopy.getID() << "\t";
        }
        
        
        
        output << endl;
        
        output << tempreader.numbooksreserved << endl;
        
        for(tempreader.itera=tempreader.booksreserved.begin(); tempreader.itera!=tempreader.booksreserved.end(); tempreader.itera++) {
            tempbook=*tempreader.itera;
            // check wich book it is function
            output << tempbook.getISBN() << "\t";
        }
        
        
        output << endl;
        
        output << tempreader.numpenalties << endl << tempreader.max_copies << endl << endl;
        
    }
    output.close();
}

char Reader::getreadertype() {
    return readertype;
}

int Reader::getnumcopiesborrowed() {
    return numcopiesborrowed;
}

int Reader::getnumbooksreserved() {
    return numbooksreserved;
}

int Reader::getnumpenalties() {
    return numpenalties;
}

int Reader::getmaxcopies() {
    return max_copies;
}

list<Book> Reader::getlistbooksreserved() {
    return booksreserved;
}

list<Copy> Reader::getlistcopiesborrowed() {
    return copiesborrowed;
}


// overloaded operator to find reader based on username
bool Reader::operator==(const Reader& rhs) {
    Reader tempreader;
    tempreader = rhs;
    
    if (get_username()== tempreader.get_username() ) {
        return true;
    }
    else {
        return false;
    }
}

// decrease reader maxcopies if they have 3 penalties then reset penalty count
void Reader::decreasemaxcopies() {
   
		if (numpenalties > 3) {

			if (max_copies < 2) {
				cout << "Your maximum copies allowed will not be reduced because it is at 1." << endl;
				cout << endl;
			}

			if (max_copies > 1) {
				max_copies = max_copies - 1;
				cout << "Your maximum copies allowed at once has been reduced to " << max_copies << endl;
				cout << endl;

			}

            numpenalties=0;

		}

}

void Reader::addbookreserved(Book tempbook) {
    booksreserved.push_back(tempbook);
    numbooksreserved=numbooksreserved+1;
}


