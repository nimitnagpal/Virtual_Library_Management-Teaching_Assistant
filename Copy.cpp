//
//  Copy.cpp
//
#include <iostream>
#include "Copy.h"
#include "Book.h"
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

Copy::Copy() {
    readername="noone";
    ID=-1000;
    borrowdate=-9;
    expirationdate=-9;
    reservationdate=-9;
}

Copy::Copy(Book tempbook) {
    settitle(tempbook.gettitle());
    setauthor(tempbook.getauthor());
    setcategory(tempbook.getcategory());
    setISBN(tempbook.getISBN());
    setnumreservers(tempbook.getnumreservers());
    setlistofreservers(tempbook.getlistofreservers());
    readername="NoReader";
    borrowdate=-1;
    reservationdate=-1;
    expirationdate=-1;
}

// overloaded operator to input copies from file
void Copy::operator>>(list<Copy>& mycopies) {
    ifstream input;
    int tempbookISBN, tempborrowdate, tempreservedate, tempexpdate, tempID;
    string tempreadername;
    Book tempbook, inputbook;
    Copy tempcopy;
    
    list<Book> mybooks;
    
    inputbook>>mybooks;
    
    input.open("copyfinal.dat");
    if(input.fail()) {
        cerr << "Error opening 'copyfinal.dat'." << endl;
    }
    
    while(input >> tempbookISBN) {
        
        tempbook= whichbook(tempbookISBN, mybooks);
        
        Copy tempcopy(tempbook);
        
        input >> tempreadername >> tempborrowdate >> tempreservedate >> tempexpdate >> tempID;
        
        tempcopy.setreadername(tempreadername);
        tempcopy.setborrowdate(tempborrowdate);
        tempcopy.setreservationdate(tempreservedate);
        tempcopy.setexpirationdate(tempexpdate);
        tempcopy.setID(tempID);
        
        mycopies.push_back(tempcopy);
        
    }
}

void Copy::setborrowdate(int tempborrowdate) {
    borrowdate=tempborrowdate;
}

void Copy::setreadername(string tempreadername) {
    readername=tempreadername;
}

void Copy::setexpirationdate(int tempexpirationdate) {
    expirationdate=tempexpirationdate;
}

void Copy::setreservationdate(int tempreservationdate) {
    reservationdate=tempreservationdate;
}

void Copy::setID(int tempid) {
    ID=tempid;
}

void Copy::printCopy() {
    printbook();
    cout << "ID: " << setw(4) << setfill('0') << ID;
    cout << "\nReader name: " << readername << "\nBorrow Date: " << borrowdate << "\nReservation Date: " << reservationdate << "\nExpiration Date: " << expirationdate << endl;
}

void Copy::printcopies(list<Copy>& mycopies) {
    list<Copy>::iterator iterc;
    for(iterc=mycopies.begin(); iterc!=mycopies.end();iterc++) {
        Copy tempcopy=*iterc;
        tempcopy.printCopy();
        cout << endl;
    }
}

// overloaded operator to output copies to file
void Copy::operator<<(list<Copy>& mycopies) {
    ofstream output;
    list<Copy>::iterator iterc;
    
    output.open("copyfinal.dat");
    if(output.fail()) {
        cerr << "Error opening copyfinal.dat for output..." << endl;
    }
    
    for(iterc=mycopies.begin();iterc!=mycopies.end();iterc++) {
        Copy tempcopy=*iterc;
        output << tempcopy.getISBN() << "\n" << tempcopy.readername <<"\n" << tempcopy.borrowdate << "\n" << tempcopy.reservationdate << "\n" << tempcopy.expirationdate << "\n" << tempcopy.ID;
        output << endl << endl;
    }
    output.close();
}

// overloaded operator to find copy based on ID
bool Copy::operator==(const Copy& rhs) {
    //Copy tempcopyl;
    //tempcopyl=rhs;
    if(ID==rhs.ID) {
        return true;
    }
    else {
        return false;
    }
}

// find copy based on ID
Copy Copy::whichcopy(int tempID, list<Copy>& mytempcopies) {
    list<Copy>::iterator loopiter = mytempcopies.begin();
    Copy tempcopy, defaultcopy;
    int templistID;

    
    
    for(loopiter=mytempcopies.begin();loopiter!=mytempcopies.end();loopiter++) {
        tempcopy=*loopiter;
        
        templistID=tempcopy.getID();
        if(tempID==templistID) {
            return tempcopy;
        }
        
    }
    return defaultcopy;
}

int Copy::getID() {
    return ID;
}

string Copy::getreadername() {
    return readername;
}

int Copy::getexpirationdate() {
    return expirationdate;
}

int Copy::getreservationdate() {
    return reservationdate;
}

// updates copy info when it is returned
void Copy::copyreturned(int currentdate) {
    reservationdate = currentdate;
    readername = "NoReader";
    
}













