//
//  functions.cpp
//  
//  This file contains all the Reader and Librarian Functions. They are called from the main function.
//  This makes sure the main program is more readable and the project is modular instead of a single long file.  
//
#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <algorithm>
#include <functional>
#include <fstream>
#include "User.h"
#include "Reader.h"
#include "Book.h"
#include "Copy.h"
#include "Student.h"
#include "Teacher.h"
#include "Librarian.h"
#include "functions.h"
using namespace std;

static int tempid(40);

// output lists to files using overloaded operators
void outputlists(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, list<Librarian>& mylibrarians) {
    Book outputbook;
    Copy outputcopy;
    Reader outputreader;
    Librarian outputlibrarian;
    
    outputbook<<mybooks;

    outputcopy<<mycopies;
    
    outputreader<<myreaders;
    
    outputlibrarian<<mylibrarians;
}


// check user type when signing in to program
int checkusertype() {
    string usertype;
    cout << "Welcome to the Library System. Please select your user type to login: \n" << endl;
    cout << "-----------------------------------------------------------------------\n" << endl;
    cout << "Librarian: Enter 1\n" << endl;
    cout << "Reader:    Enter 2\n" << endl;
    cout << "-----------------------------------------------------------------------\n" << endl;
    cin >> usertype;
    while(usertype!="1" && usertype!="2") {
        cout << "Invalid entry. Please try again.\n" << endl;
        cin >> usertype;
        cout << endl;
    }
    
    int intusertype = stoi(usertype);
    
    return intusertype;
    
}

// login the librians
void loginlibrarian(list<Librarian>& mylibrarians, string& usernametoreturn) {
    list<Librarian>::iterator iterl;
    string tempusername, temppassword;
    

    cout <<"-----------------------------------------------------------------------\n" << endl;
    cout << "Please enter username: ";
    
    //cin >> tempusername;
    getline(cin, tempusername);
    while (tempusername=="") {
        getline(cin,tempusername);
    }
    
    for (iterl=mylibrarians.begin(); iterl!=mylibrarians.end(); iterl++) {
        Librarian templibrarian = *iterl;
        if(tempusername==templibrarian.get_username()) {
            
			cout << "Please enter the password for the account: ";
            
            getline(cin, temppassword);
            while (temppassword=="") {
                getline(cin,temppassword);
            }

            while (temppassword!=templibrarian.get_password()) {
            cout << "\nIncorrect password entered, please try again: " << endl;
                
                
                //cin >> temppassword;
                getline(cin, temppassword);
                while (temppassword=="") {
                    getline(cin,temppassword);
                }
            
            }
            if(temppassword==templibrarian.get_password()) {
                usernametoreturn = tempusername;
                return;
            }
        }
        
    }
    
    cout << "\nA librarian does not exist with that username.\n" << endl;
    cout << "Please try again.\n";
    loginlibrarian(mylibrarians, usernametoreturn);
    
}

// menu of options available to librarian
int optionselectlibrarian() {
	string optionselect;
	cout << "-----------------------------------------------------------------------\n" << endl;
	cout << "Please select from the options below...\n" << endl;
	cout << "1 -- Search Books" << endl;
	cout << "2 -- Add    Books" << endl;
	cout << "3 -- Delete Copy" << endl;
	cout << "4 -- Search Users" << endl;
	cout << "5 -- Add New User" << endl;
	cout << "6 -- Delete User" << endl;
	cout << "7 -- My Information" << endl;
	cout << "8 -- Change Password" << endl;
	cout << "0 -- Log Out\n" << endl;
	cout << "-----------------------------------------------------------------------\n" << endl;
	cin >> optionselect;



	while (optionselect != "1" && optionselect != "2" && optionselect != "3" && optionselect != "4" && optionselect != "5" && optionselect != "6" && optionselect != "7" && optionselect != "8" && optionselect!="0") {
		cout << "Incorrect option entered. Please try again.\n" << endl;
		cin >> optionselect;
	}

	int returnoption = stoi(optionselect);

	return returnoption;

}


// menu of options available for reader
int optionselectreader() {
    string optionselect;
    
    cout << "-----------------------------------------------------------------------\n" << endl;
    cout << "Please select from the options below...\n" << endl;
    cout << "1 -- Search Books" << endl;
    cout << "2 -- Borrow Books" << endl;
    cout << "3 -- Return Books" << endl;
    cout << "4 -- Reserve Books" << endl;
    cout << "5 -- Cancel Reservations" << endl;
    cout << "6 -- My Information" << endl;
    cout << "7 -- Change Password" << endl;
    cout << "0 -- Log Out\n" << endl;
    cout << "-----------------------------------------------------------------------\n" << endl;
    
	
	cin >> optionselect;



    while (optionselect!="1" && optionselect!="2" && optionselect!="3" && optionselect!="4" && optionselect!="5" && optionselect!="6" && optionselect!="7" && optionselect!="0") {
        cout << "Incorrect option entered. Please try again.\n" << endl;
		cin >> optionselect;
    }

	int returnoption = stoi(optionselect);

    return returnoption;
}

// login reader to program
void loginreader(list<Reader>& myreaders, char& readertype, string& tempusernametoreturn) {
    list<Reader>::iterator iterr;
    string tempusername, temppassword;
    
    
    cout <<"-----------------------------------------------------------------------\n" << endl;
    cout << "Please enter username: ";
    
    
    //cin >> tempusername;
    getline(cin, tempusername);
    while (tempusername=="") {
        getline(cin,tempusername);
    }
    
    
    for (iterr=myreaders.begin(); iterr!=myreaders.end(); iterr++) {
        Reader tempreader = *iterr;
        if(tempusername==tempreader.get_username()) {
            cout << "Please enter the password for the account: ";
            
            //cin >> temppassword;
            getline(cin, temppassword);
            while (temppassword=="") {
                getline(cin,temppassword);
            }
            
            while (temppassword!=tempreader.get_password()) {
                cout << "\nIncorrect password entered, please try again: ";
                
                //cin >> temppassword;
                getline(cin, temppassword);
                while (temppassword=="") {
                    getline(cin,temppassword);
                }
            
            }
            if(temppassword==tempreader.get_password()) {
                readertype = tempreader.getreadertype();
                tempusernametoreturn = tempusername;
                return;
            }
        }
        
    }
    
    cout << "\nA Reader does not exist with that username.\n" << endl;
    cout << "Please try again.\n";
    loginreader(myreaders, readertype, tempusernametoreturn);
    
    
}

// first checks if reader is eligible to check out a book, if yes, continues to second function (borrowbookstudent2)
void borrowbookstudent(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate) {
    
    // check for overdue copies
    // boolean variable. if true, tell them they cant borrow and return to option select
    bool overdue = overduecopies(mycopies, username, currentdate);
    if (overdue) {
        cout << "Cannot borrow books as you have overdue copies." << endl;
        return;
    }
    
    //cout << "Congrats you may be able to borrow a book" << endl;
    
    // check for maxcopies
    
    bool readermaxcopies = maxcopiesreached(myreaders, username);
    if (readermaxcopies) {
        cout << "Cannot borrow books as you checked out your max number of copies." << endl;
        return;
    }
    
    //cout << "Congrats you may be able to borrow a book today" << endl;
    
    
    // check if the copy is being borrowed by someone else
    list<Copy>::iterator iterc;
    Copy tempcopy;
    Copy anothercopy;
    
    cout << "\nPlease enter the ID of the copy you would like to borrow: ";
    int borrowid;
    
    cin >> borrowid;
    cout << "\n" << endl;
    
    bool realID = false;
    
    while (!realID) {
        
        for (iterc=mycopies.begin(); iterc!=mycopies.end(); iterc++) {
            
            tempcopy = *iterc;
            realID = false;
            
            if (borrowid==tempcopy.getID()) {
                realID=true;
                break;
            }
            
        }
        
        if(realID) {
            break;
        }
        
        if (!realID) {
            cout << "Not a valid ID. Please try entering again." << endl;
            cin >> tempid;
        }
        
    }
    
    // Now we know it is a real copy and have its ID in a clone of it (tempcopy)
    
    if (tempcopy.getreadername()=="NoReader") {
        // you can borrow the book right here based on ID and return to main function
        borrowbookstudent2(mybooks, mycopies, myreaders, username, currentdate, borrowid);
        
        return;
    }
    
    cout << "That copy is currently checked out." << endl;
    
    bool isanothercopy = false;
    
    for(iterc=mycopies.begin(); iterc!=mycopies.end();iterc++) {
        
        isanothercopy = false;
        
        if(tempcopy.getISBN()==(*iterc).getISBN() && borrowid!=(*iterc).getID() && (*iterc).getreadername()=="NoReader") {
            isanothercopy = true;
            anothercopy.setID((*iterc).getID());
            break;
        }
    }
    
    int anotherid = anothercopy.getID();
    
    if (isanothercopy) {
        
        cout << "There is another copy available of that book." << endl;
		cout << "It's ID is " << anothercopy.getID() << ". Checking if it is available..." << endl;
        borrowbookstudent2(mybooks, mycopies, myreaders, username, currentdate, anotherid);
        // borrow the copy based on the id of anothercopy
    
        return;
    }

    
    cout << "Sorry but there are no copies of " << tempcopy.gettitle() << " available. If you make a reservation you can check it out once it is available." << endl;
    
    return;


}

// checks to see if there is a copy available. if available, reader has to be first in line or the queue
// has to be empty in order for the checkout to proceed to part 3
void borrowbookstudent2(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate, int& borrowid) {
    
    // we know that the id of the copy says no reader, but check if being reserved by anyone and if their reservation time has exceeded 10 days
    Copy copytoborrow = Copy::whichcopy(borrowid, mycopies);
    
    Book booktocheckreserve = Book::whichbook(copytoborrow.getISBN(), mybooks);
    
    // have copy of book to checkout, check its reserver list
    
    list<Book>::iterator findbook = find(mybooks.begin(), mybooks.end(), booktocheckreserve);
    
    deque<string> copyofqueueofreservers;
    
    copyofqueueofreservers = (*findbook).getlistofreservers();
    
    
    
    
    
    // if queue is empty, check out copy
    if (copyofqueueofreservers.empty()) {
        // implement funciton to check out book completely based on borrowid
        
        
        
        borrowbookstudent3(mybooks, mycopies, myreaders, username, currentdate, borrowid);
        
        return;
    }
    
    // if queue has elements, check if username is first element
    if (!copyofqueueofreservers.empty()) {
        

        
        
        int reservationdate;
        
        reservationdate = copytoborrow.getreservationdate();
        
        (*findbook).updatequeue(currentdate, reservationdate);
        list<Copy>::iterator updateiter;
        for (updateiter=mycopies.begin(); updateiter!=mycopies.end(); updateiter++) {
            if ((*updateiter).getISBN()==copytoborrow.getISBN() && (*updateiter).getreadername() == "NoReader") {
                (*updateiter).setreservationdate(reservationdate);
            }
        }
        
        
        if ((*findbook).getlistofreservers().empty()) {
            // implement function to check out book completely based on borrow id
            
            borrowbookstudent3(mybooks, mycopies, myreaders, username, currentdate, borrowid);
            
            return;
        }
        
        
        
        //cout << "Will print updated reservers" << endl;
        //(*findbook).printreservers();
        
        
        
        string firstinline;
        firstinline = (*findbook).getlistofreservers().front();
        if (firstinline == username) {
            
            cout << "You are first in line to check out this book." << endl;
            
            (*findbook).deletefirstinline();
            // implement function to check out book completely based on borrowid
            
            borrowbookstudent3(mybooks, mycopies, myreaders, username, currentdate, borrowid);
            
            return;
        }
        
        
        cout << "You cannot check out this book as there are people who have reserved it." << endl;
        cout << "The reserver list includes: " << endl;
        (*findbook).printreservers();
        
        cout << "\nPlease reserve the book in order to guarantee your spot.\n"
        << endl;
        return;
    }

    
    cout << "I got dumped out here" << endl;
    
}

// checks out the book for the student, and updates the reader info, book reservation list, and copy info
void borrowbookstudent3(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate, int& borrowid) {

  
    Copy copyforiterator;
    copyforiterator.setID(borrowid);

    list<Copy>::iterator findcopy = find(mycopies.begin(), mycopies.end(), copyforiterator);
    
    (*findcopy).setreadername(username);
    (*findcopy).setborrowdate(currentdate);
    (*findcopy).setexpirationdate(currentdate+20);
    
    
    // first update copy information
    Copy tempcopytoaddtoreader = *findcopy;
    
    
    
    Reader readertofind;
    readertofind.set_username(username);
    
    list<Reader>::iterator findreader = find(myreaders.begin(), myreaders.end(), readertofind);
    
    
    cout << endl;
    
    
    //(*findreader).printReader();
    
    
    (*findreader).addcopyborrowed(tempcopytoaddtoreader);
    
    int numbercurrentlyborrowed = (*findreader).getnumcopiesborrowed();
    
    (*findreader).setnumcopiesborrowed(numbercurrentlyborrowed + 1);

   
    cout << "\n\nCongratulations, you have checked out " << (*findcopy).gettitle() << endl;
    cout << "Be sure to return it by " << (*findcopy).getexpirationdate() << " to avoid penalties.\n" << endl;

	Book booktodeleteisbn;

	int isbntodelte = (*findcopy).getISBN();

	booktodeleteisbn.setISBN(isbntodelte);

	list<Book> booksresrevedbyreader = (*findreader).getlistbooksreserved();

	list<Book>::iterator deletefromreserveiter = find(booksresrevedbyreader.begin(), booksresrevedbyreader.end(), booktodeleteisbn);

	bool found = (find(booksresrevedbyreader.begin(), booksresrevedbyreader.end(), booktodeleteisbn) != booksresrevedbyreader.end());

	if (found) {
		(*findreader).deletebookreserved(booktodeleteisbn);
	}

    
        return;
    
}


// same as a above but for teacher types
void borrowbookteacher(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate) {
    
    // check for overdue copies
    // boolean variable. if true, tell them they cant borrow and return to option select
    bool overdue = overduecopies(mycopies, username, currentdate);
    if (overdue) {
        cout << "Cannot borrow books as you have overdue copies." << endl;
        return;
    }
    
    //cout << "Congrats you may be able to borrow a book" << endl;
    
    // check for maxcopies
    
    bool readermaxcopies = maxcopiesreached(myreaders, username);
    if (readermaxcopies) {
        cout << "Cannot borrow books as you checked out your max number of copies." << endl;
        return;
    }
    
    //cout << "Congrats you may be able to borrow a book today" << endl;
    
    
    // check if the copy is being borrowed by someone else
    list<Copy>::iterator iterc;
    Copy tempcopy;
    Copy anothercopy;
    
    cout << "\nPlease enter the ID of the copy you would like to borrow: ";
    int borrowid;
    
    cin >> borrowid;
    cout << "\n" << endl;
    
    bool realID = false;
    
    while (!realID) {
        
        for (iterc=mycopies.begin(); iterc!=mycopies.end(); iterc++) {
            
            tempcopy = *iterc;
            realID = false;
            
            if (borrowid==tempcopy.getID()) {
                realID=true;
                break;
            }
            
        }
        
        if(realID) {
            break;
        }
        
        if (!realID) {
            cout << "Not a valid ID. Please try entering again." << endl;
            cin >> tempid;
        }
        
    }
    
    // Now we know it is a real copy and have its ID in a clone of it (tempcopy)
    
    if (tempcopy.getreadername()=="NoReader") {
        // you can borrow the book right here based on ID and return to main function
        borrowbookteacher2(mybooks, mycopies, myreaders, username, currentdate, borrowid);
        
        return;
    }
    
    cout << "That copy is currently checked out." << endl;
    
    bool isanothercopy = false;
    
    for(iterc=mycopies.begin(); iterc!=mycopies.end();iterc++) {
        
        isanothercopy = false;
        
        if(tempcopy.getISBN()==(*iterc).getISBN() && borrowid!=(*iterc).getID() && (*iterc).getreadername()=="NoReader") {
            isanothercopy = true;
            anothercopy.setID((*iterc).getID());
            break;
        }
    }
    
    int anotherid = anothercopy.getID();
    
    if (isanothercopy) {
        
        cout << "There is another copy available of that book." << endl;
        
        borrowbookteacher2(mybooks, mycopies, myreaders, username, currentdate, anotherid);
        // borrow the copy based on the id of anothercopy
        
        return;
    }
    
    
    cout << "Sorry but there are no copies of " << tempcopy.gettitle() << " available. If you make a reservation you can check it out once it is available." << endl;
    
    return;
    
    
}

void borrowbookteacher2(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate, int& borrowid) {
    
    // we know that the id of the copy says no reader, but check if being reserved by anyone and if their reservation time has exceeded 10 days
    Copy copytoborrow = Copy::whichcopy(borrowid, mycopies);
    
    Book booktocheckreserve = Book::whichbook(copytoborrow.getISBN(), mybooks);
    
    // have copy of book to checkout, check its reserver list
    
    list<Book>::iterator findbook = find(mybooks.begin(), mybooks.end(), booktocheckreserve);
    
    deque<string> copyofqueueofreservers;
    
    copyofqueueofreservers = (*findbook).getlistofreservers();
    
    // if queue is empty, check out copy
    if (copyofqueueofreservers.empty()) {
        // implement funciton to check out book completely based on borrowid
        
        borrowbookteacher3(mybooks, mycopies, myreaders, username, currentdate, borrowid);
        
        return;
    }
    
    // if queue has elements, check if username is first element
    if (!copyofqueueofreservers.empty()) {
        
        int reservationdate;
        
        reservationdate = copytoborrow.getreservationdate();
        
        (*findbook).updatequeue(currentdate, reservationdate);
        list<Copy>::iterator updateiter;
        for (updateiter=mycopies.begin(); updateiter!=mycopies.end(); updateiter++) {
            if ((*updateiter).getISBN()==copytoborrow.getISBN() && (*updateiter).getreadername() == "NoReader") {
                (*updateiter).setreservationdate(reservationdate);
            }
        }
        
        
        
        
        
        if ((*findbook).getlistofreservers().empty()) {
            // implement function to check out book completely based on borrow id
            
            borrowbookteacher3(mybooks, mycopies, myreaders, username, currentdate, borrowid);
            
            return;
        }
        
        
        
        //cout << "Will print updated reservers" << endl;
        //(*findbook).printreservers();
        
        
        
        string firstinline;
        firstinline = (*findbook).getlistofreservers().front();
        if (firstinline == username) {
            
            cout << "You are first in line to check out this book." << endl;
            
            (*findbook).deletefirstinline();
            // implement function to check out book completely based on borrowid
            
            borrowbookteacher3(mybooks, mycopies, myreaders, username, currentdate, borrowid);
            
            return;
        }
        
        
        cout << "You cannot check out this book as there are people who have reserved it." << endl;
        cout << "The reserver list includes: " << endl;
        (*findbook).printreservers();
        
        cout << "\nPlease reserve the book in order to guarantee your spot.\n"
        << endl;
        return;
    }
    
    
    cout << "I got dumped out here" << endl;

    
    
}

void borrowbookteacher3(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate, int& borrowid) {
    
    
    Copy copyforiterator;
    copyforiterator.setID(borrowid);
    
    list<Copy>::iterator findcopy = find(mycopies.begin(), mycopies.end(), copyforiterator);
    
    (*findcopy).setreadername(username);
    (*findcopy).setborrowdate(currentdate);
    (*findcopy).setexpirationdate(currentdate+30);
    
    
    // first update copy information
    Copy tempcopytoaddtoreader = *findcopy;
    
    
    
    Reader readertofind;
    readertofind.set_username(username);
    
    list<Reader>::iterator findreader = find(myreaders.begin(), myreaders.end(), readertofind);
    
    
    cout << endl;
    
    
    //(*findreader).printReader();
    
    
    (*findreader).addcopyborrowed(tempcopytoaddtoreader);
    
    int numbercurrentlyborrowed = (*findreader).getnumcopiesborrowed();
    
    (*findreader).setnumcopiesborrowed(numbercurrentlyborrowed + 1);
    
    cout << "\n\nCongratulations, you have checked out " << (*findcopy).gettitle() << endl;
    cout << "Be sure to return it by " << (*findcopy).getexpirationdate() << " to avoid penalties.\n" << endl;
    
	Book booktodeleteisbn;

	int isbntodelte = (*findcopy).getISBN();

	booktodeleteisbn.setISBN(isbntodelte);

	list<Book> booksresrevedbyreader = (*findreader).getlistbooksreserved();

	list<Book>::iterator deletefromreserveiter = find(booksresrevedbyreader.begin(), booksresrevedbyreader.end(), booktodeleteisbn);

	bool found = (find(booksresrevedbyreader.begin(), booksresrevedbyreader.end(), booktodeleteisbn) != booksresrevedbyreader.end());

	if (found) {
		(*findreader).deletebookreserved(booktodeleteisbn);
	}
    
    return;
}


// checks if reader has overdue copies
bool overduecopies(list<Copy>& mycopies, string& username, int& currentdate) {
    list<Copy>::iterator iterc;

for (iterc = mycopies.begin(); iterc != mycopies.end(); iterc++) {
	Copy tempcopy = *iterc;

	if (tempcopy.getreadername() == username && tempcopy.getexpirationdate() < currentdate) {
		return true;
	}

}

return false;

}


// checks if reader has checked out their maximum number of copies
bool maxcopiesreached(list<Reader>& myreaders, string& username) {
	list<Reader>::iterator iterr;

	for (iterr = myreaders.begin(); iterr != myreaders.end(); iterr++) {
		Reader tempreader = *iterr;
		if (tempreader.getnumcopiesborrowed() >= tempreader.getmaxcopies() && tempreader.get_username() == username) {
			return true;
		}
	}

	return false;
}

// checks if string is only digits. used when searching books
bool isdigitsonly(string& searchstring) {
	return searchstring.find_first_not_of("0123456789") == string::npos;
}

// find books based from list of books
list<Book> searchbooks(string& searchstring, list<Book>& mybooks) {
	list<Book> foundbooks;
	list<Book>::iterator iterb;
	bool onlyints;
	onlyints = isdigitsonly(searchstring);

	if (onlyints) {
		//search through isbns
		int searchisbn = stoi(searchstring);
		for (iterb = mybooks.begin(); iterb != mybooks.end(); iterb++) {
			Book tempbook = *iterb;
			if (searchisbn == tempbook.getISBN()) {
				foundbooks.push_back(tempbook);
			}
		}
		return foundbooks;
	}
	else {
		for (iterb = mybooks.begin(); iterb != mybooks.end(); iterb++) {
			Book tempmbook = *iterb;

			if (searchstring == tempmbook.gettitle()) {
				foundbooks.push_back(tempmbook);
			}

			if (searchstring == tempmbook.getauthor()) {
				foundbooks.push_back(tempmbook);
			}

			if (searchstring == tempmbook.getcategory()) {
				foundbooks.push_back(tempmbook);
			}

		}
		return foundbooks;
	}

}


// calls searchbooks to find books, then outputs them and says if there are any copies available
void searchfunction(list<Book>& mybooks, list<Copy>& mycopies) {
	cout << "Please enter search value. (Book's ISBN, title, author, category)..." << endl;
	cout << "-----------------------------------------------------------------------\n" << endl;
	string searchstring;
	//string holdblank;
	getline(cin, searchstring);

	while (searchstring == "") {
		getline(cin, searchstring);
	}

	list<Book> foundbooks;
	// search books function
	foundbooks = searchbooks(searchstring, mybooks);

	if (foundbooks.empty()) {
		cout << "No books found with that search." << endl;
	}
	else if (!foundbooks.empty()) {
		cout << "The following books were found.\n";
		cout << "-----------------------------------------------------------------------\n" << endl;

		//function to rank popularity and map that to found books

		foundbooks.sort(greater<Book>());

		Book::printbooks(foundbooks);

		list<Copy>::iterator copyavailable;
		list<Book>::iterator iteravailable;
		for (iteravailable = foundbooks.begin(); iteravailable != foundbooks.end(); iteravailable++) {
			//Book bookfound;
			//bookfound.setISBN((*iteravailable).getISBN());
			int isbntofindincopy = (*iteravailable).getISBN();

			int numberofreservers = (*iteravailable).getnumreservers();
			int currentcopieswithnoreader(0);
	
			for (copyavailable = mycopies.begin(); copyavailable != mycopies.end(); copyavailable++) {
				if ((*copyavailable).getISBN() == isbntofindincopy && (*copyavailable).getreadername() == "NoReader") {
					//cout << "There is a copy available of " << (*copyavailable).gettitle() << " with ID: " << (*copyavailable).getID() << endl;
					currentcopieswithnoreader++;
				}
			}


			for (copyavailable = mycopies.begin(); copyavailable != mycopies.end(); copyavailable++) {
				if ((*copyavailable).getISBN() == isbntofindincopy && (*copyavailable).getreadername() == "NoReader" && currentcopieswithnoreader>numberofreservers) {
					cout << "There is a copy available of " << (*copyavailable).gettitle() << " with ID: " << (*copyavailable).getID() << endl;
				}
			}

		}

    }
    
    cout << "Would you like to search for another book? (y or n)\n" << endl;
    char answer('f');
    
    
    while (answer!='y' && answer!='n') {
        
        cin >> answer;
        
        switch (answer) {
            case 'y':
                searchfunction(mybooks, mycopies);
                break;
                
            case 'n':
                //optionselect=optionselectlibrarian();
                break;
                
            default:
                cout <<"Invalid entry. Please enter 'y' or 'n'.\n" << endl;
                cin >> answer;
                break;
        }
    }
    cin.ignore();
    
    
    
    return;
}

// add new book to list
void addnewbook(list<Book>& mybooks, list<Copy>& mycopies) {

    Book tempbook;
    list<Book>::iterator iterb;
    int tempISBN;
    string temptitle, tempauthor, tempcategory;
    cout << "Please enter the book's ISBN. Must be an integer less than 99999999.\n" << endl;
    cin >> tempISBN;
    while (tempISBN>99999999) {
        cout << "Invalid integer entered. Please try again" << endl;
        cin >> tempISBN;
    }
    
    bool inuse=true;
    
    while (inuse) {
        
    for (iterb=mybooks.begin(); iterb!=mybooks.end(); iterb++) {
        tempbook = *iterb;
        
            inuse=false;
        
        if (tempISBN==tempbook.getISBN()) {
            cout << "ISBN already in use. Please enter another ISBN." << endl;
            inuse=true;
            cin >> tempISBN;
            break;
        }
        //inuse=false;
    }
        
    }
    //inuse=false;
    //    break;
    //}
    
    cout << "Please enter the book's title." << endl;
    cin.ignore();
    getline(cin, temptitle);
    cout << "Please enter the book's author." << endl;
    getline(cin, tempauthor);
    cout << "Please enter the book's category, capitalizing the first letter. (ex romance ==> Romance)" << endl;
    getline(cin, tempcategory);
    
    Book newbook(tempISBN, temptitle, tempauthor, tempcategory);
    
    mybooks.push_back(newbook);
    
    Copy tempcopy(newbook);
    
    //static int tempid(15);
    
    tempcopy.setID(tempid);
    
    tempid++;
    
    mycopies.push_back(tempcopy);
    
    
    cout << "New book and copy of new book has been added.\n" << endl;
    
    
    //cin.ignore();
    
    return;
    
}


// add copy of existing book to list
void addexistingbookcopy(list<Book>& mybooks, list<Copy>& mycopies) {
    list<Book>::iterator iterb;
    Book tempbook;
    int tempISBN;
    
    
    cout << "Please enter the ISBN of the book you are adding a copy of: " << endl;
    cin >> tempISBN;
    
    bool realISBN = false;
    
    while(!realISBN) {
    
        for (iterb=mybooks.begin(); iterb!=mybooks.end(); iterb++) {
            
            tempbook = *iterb;
            realISBN = false;
            
            //cin >> tempISBN;
            
            if(tempISBN==tempbook.getISBN()) {
                realISBN = true;
                break;
            }
        
        }
        
        if(realISBN) {
            break;
        }
        if (!realISBN) {
            cout << "Not a valid ISBN. Please try entering again." << endl;
            cin >> tempISBN;
        }
        
    }
    
    
    Copy addingcopy(tempbook);
    
    addingcopy.setID(tempid);
    
    tempid++;
    
    mycopies.push_back(addingcopy);
    
    cout << "Copy has been added.\n" << endl;

    cin.ignore();
    
    
    
    
    
    return;
}


// delete copy of a book. can only be deleted if no one is reading it.
void deletecopy(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, int& optionselect) {
    int deleteID;
    list<Book>::iterator iterb;
    list<Copy>::iterator iterc;
    list<Copy>::iterator deleteiterc;
    list<Reader>::iterator iterr;
    Copy tempcopy;
    Book tempbook;
    
    
    cout << "Please enter the ID of the copy you would like to delete.\n" << endl;
    cin >> deleteID;

    bool realID = false;
    
    while (!realID) {
    
        for (iterc=mycopies.begin(); iterc!=mycopies.end(); iterc++) {
            
            tempcopy = *iterc;
            realID = false;
            
            if (deleteID==tempcopy.getID()) {
                realID=true;
                break;
            }
            
        }
        
        if(realID) {
            break;
        }

        if (!realID) {
            cout << "Not a valid ID. Please try entering again." << endl;
            cin >> deleteID;
        }

    }

    
    if(tempcopy.getreadername()=="NoReader") {
            list<Copy>::iterator finditer = find(mycopies.begin(), mycopies.end(), tempcopy);
            
            cout << "Copy to be erased is\n" << endl;
            (*finditer).printCopy();
            
            finditer = mycopies.erase(finditer);
            
            
            cout << "Copy Deleted." << endl;
            
            bool iscopy = false;
            
            for(iterc=mycopies.begin(); iterc!=mycopies.end();iterc++) {
               
                iscopy = false;
                
                if(tempcopy.getISBN()==(*iterc).getISBN()) {
                    iscopy = true;
                    break;
                }
            }
            
            if(!iscopy) {
                
                int tempISBNdeletebook= tempcopy.getISBN();
                Book deletebook;
                deletebook.setISBN(tempISBNdeletebook);
                
                list<Book>::iterator bookdeleteiter = find(mybooks.begin(), mybooks.end(), deletebook);
                
                cout << "\nBook to be erased is\n" << endl;
                (*bookdeleteiter).printbook();
                
                Book booktobedeleted = (*bookdeleteiter);
                
                // function to remove book from reader reservation list. Have to find first?
                
                //for (iterr=myreaders.begin(); iterr!=myreaders.end(); iterr++) {
                
                cout << "Also being erased from reader reserve lists.\n" << endl;
                
                //Reader justusing;
                
                for(list<Reader>::iterator iterr = myreaders.begin(); iterr!=myreaders.end();iterr++) {
                
                    (*iterr).deletebookreserved(booktobedeleted);

                }

                
                bookdeleteiter = mybooks.erase(bookdeleteiter);
                
                //cout << "Will place function here to delete the book." << endl;
            }
        
            else if (iscopy) {
                cout << "There are other copies of the book so book wont be deleted.\n" << endl;
            }
    
    }
    
    else if (tempcopy.getreadername()!="NoReader") {
        cout << "Can't delete this copy as it is currently being read by " << tempcopy.getreadername() << ".\n" << endl;
    }
    
    return;
    
}

// search users
void searchusers(list<Reader>& myreaders, list<Librarian>& mylibrarians) {
    list<Reader>::iterator findreader;
    list<Librarian>::iterator findlibrarian;
    int founduser(0);
    string usernamesearch;
    
    cout << "Please enter the username of the account. Note this search is case-sensitive.\n" << endl;
    //cin.ignore();
    cin >> usernamesearch;
    
    for (findreader=myreaders.begin(); findreader!=myreaders.end(); findreader++) {
        Reader tempreader = *findreader;
        
        if (usernamesearch==tempreader.get_username()) {
            cout << "The following user was found.\n" << endl;
            //tempreader.printReader();
            
            string readertype;
            if (tempreader.getreadertype()=='s') {
                readertype="Student";
            }
            else if (tempreader.getreadertype()=='t') {
                readertype="Teacher";
            }
            
            cout << "Account type: " << readertype << "\nUsername: " << tempreader.get_username() << "\nPassword: " << tempreader.get_password() << "\nCurrently reading: ";
            tempreader.printcopiesborrowed();
            
            cout << endl;
            
            founduser++;
            //return;
            //break;
        }
        
    }
    
    for (findlibrarian=mylibrarians.begin(); findlibrarian!=mylibrarians.end(); findlibrarian++) {
        Librarian templibrarian = *findlibrarian;
        
        if (usernamesearch==templibrarian.get_username()) {
            cout << "The following user was found.\n" << endl;
            templibrarian.printlibrarian();
            founduser++;
            //return;
            //break;
        }
        
        
    }
    
    if (founduser<1) {
        cout << "No user was found.\n" << endl;
    }
    
    //cin.ignore();
    
    return;
    
}

// adds new user. makes sure there arent users with that username already
void addnewuser(list<Reader>& myreaders, list<Librarian>& mylibrarians, list<Teacher>& myteachers, list<Student>& mystudents) {
    //char usertype = 'f';
    char usertype;
    
    cout << "Would you like to add a librarian (enter l), teacher (enter t), or student (enter s)?\n" << endl;
    
    cin >> usertype;
    
    while (usertype!= 't' && usertype!='s' && usertype!='l' && usertype!= 'T' && usertype!='S' && usertype!='L') {
        cout << "Invalid usertype. Please try again. Enter t, l, or s.\n" << endl;
        cin >> usertype;
        if (usertype=='l' || usertype=='s' || usertype=='t' || usertype=='L' || usertype=='S' || usertype=='T') {
            break;
        }
        
    }
    
    cin.ignore();
    
    switch (usertype) {
        case 'l':
        case 'L': {
            string tempusername;
            string temppassword;
            cout << "You will enter a new librarian.\n" << endl;
            cout << "Please enter the username for the account. No spaces" << endl;
            getline(cin, tempusername);

            
            
            bool nospaces = false;
            
            while (!nospaces) {
                
                
                
                bool nameused = true;
                while (nameused) {
                    nameused = false;
                    
                    if (usernameinuse(myreaders, mylibrarians, tempusername)) {
                        nameused = true;
                    }
                    
                    if (nameused == false) {
                        break;
                    }
                    
                    cout << "User name is in use. Please enter a new username.\n" << endl;
                    getline(cin, tempusername);
                    
                }
                
                
                
                
            for (int i=0; i<tempusername.size(); i++) {
                nospaces=true;
                if (tempusername[i] == ' ') {
                    nospaces = false;
                    cout << "Username contains spaces. Please enter a username without spaces." << endl;
                    getline(cin, tempusername);
                    break;
                }
                
                
            }
        
            }
            
            
            
            
            
            
            
            cout << "Please enter the password for the account. No spaces" << endl;
            getline(cin, temppassword);
            
            bool nopasswordspaces = false;
            
            while (!nopasswordspaces) {
                
                for (int i=0; i<temppassword.size(); i++) {
                    nopasswordspaces=true;
                    if (temppassword[i] == ' ') {
                        nopasswordspaces = false;
                        cout << "Password contains spaces. Please enter a password without spaces." << endl;
                        getline(cin, temppassword);
                        break;
                    }
                }
                
            }
            
            Librarian templibrarian = Librarian(tempusername, temppassword);
            
            mylibrarians.push_back(templibrarian);
            
            cout << "Librarian was added successfully.\n" << endl;
        
            
        break;
        }
            
            
        case 's':
        case 'S': {
            string tempusername;
            string temppassword;
            cout << "You will enter a new student.\n" << endl;
            
            cout << "Please enter the username for the account. No spaces" << endl;
            getline(cin, tempusername);
            
            bool nospaces = false;
            
            while (!nospaces) {
                
                bool nameused = true;
                while (nameused) {
                    nameused = false;
                    
                    if (usernameinuse(myreaders, mylibrarians, tempusername)) {
                        nameused = true;
                    }
                    
                    if (nameused == false) {
                        break;
                    }
                    
                    cout << "User name is in use. Please enter a new username.\n" << endl;
                    getline(cin, tempusername);
                    
                }
                
                for (int i=0; i<tempusername.size(); i++) {
                    nospaces=true;
                    if (tempusername[i] == ' ') {
                        nospaces = false;
                        cout << "Username contains spaces. Please enter a username without spaces." << endl;
                        getline(cin, tempusername);
                        break;
                    }
                }
                
            }
            
            cout << "Please enter the password for the account. No spaces" << endl;
            getline(cin, temppassword);
            
            bool nopasswordspaces = false;
            
            while (!nopasswordspaces) {
                
                for (int i=0; i<temppassword.size(); i++) {
                    nopasswordspaces=true;
                    if (temppassword[i] == ' ') {
                        nopasswordspaces = false;
                        cout << "Password contains spaces. Please enter a password without spaces." << endl;
                        getline(cin, temppassword);
                        break;
                    }
                }
                
            }
            
            
            // add reader here. and student, calling populate students more than once will duplicate students
            Reader tempreader(tempusername, temppassword);
            tempreader.setreadertype('s');
            tempreader.setmax_copies(2);
            
            myreaders.push_back(tempreader);
            
            Student tempstudent(tempreader);
            mystudents.push_back(tempstudent);
            
            cout << "Student was added successfully.\n" << endl;
            
            
            break;
            
        }
            
        case 'T':
        case 't': {
            string tempusername;
            string temppassword;
            cout << "You will enter a new teacher.\n" << endl;
            
            cout << "Please enter the username for the account. No spaces" << endl;
            getline(cin, tempusername);
            
            bool nospaces = false;
            
            while (!nospaces) {
                
                
                bool nameused = true;
                while (nameused) {
                    nameused = false;
                    
                    if (usernameinuse(myreaders, mylibrarians, tempusername)) {
                        nameused = true;
                    }
                    
                    if (nameused == false) {
                        break;
                    }
                    
                    cout << "User name is in use. Please enter a new username.\n" << endl;
                    getline(cin, tempusername);
                    
                }
                
                
                for (int i=0; i<tempusername.size(); i++) {
                    nospaces=true;
                    if (tempusername[i] == ' ') {
                        nospaces = false;
                        cout << "Username contains spaces. Please enter a username without spaces." << endl;
                        getline(cin, tempusername);
                        break;
                    }
                }
                
            }
            
            cout << "Please enter the password for the account. No spaces" << endl;
            getline(cin, temppassword);
            
            bool nopasswordspaces = false;
            
            while (!nopasswordspaces) {
                
                for (int i=0; i<temppassword.size(); i++) {
                    nopasswordspaces=true;
                    if (temppassword[i] == ' ') {
                        nopasswordspaces = false;
                        cout << "Password contains spaces. Please enter a password without spaces." << endl;
                        getline(cin, temppassword);
                        break;
                    }
                }
                
            }
            
            
            // add reader, and teacher because calling populate teachers more than once will duplicate teachers
            Reader tempreader(tempusername, temppassword);
            tempreader.setreadertype('t');
            tempreader.setmax_copies(5);
            
            Teacher tempteacher(tempreader);
            myteachers.push_back(tempteacher);
            
            myreaders.push_back(tempreader);
            
            cout << "Teacher was added successfully.\n" << endl;
            
            
            break;
        }
            
            
        default: {
            cout << "Incorrect entry. You will be returned to the menu.\n" << endl;
            break;
        }
    }
    
    
    return;
}


// checks if a username is already being used
bool usernameinuse(list<Reader>& myreaders, list<Librarian>& mylibrarians, string& tempusername) {
    bool nameinuse;
    list<Reader>::iterator findreader;
    list<Librarian>::iterator findlibrarian;
    
    nameinuse = false;
    
    for (findreader=myreaders.begin(); findreader!=myreaders.end(); findreader++) {
        if (tempusername == (*findreader).get_username()) {
            nameinuse = true;
            break;
        }
    }
    
    for (findlibrarian=mylibrarians.begin(); findlibrarian!=mylibrarians.end(); findlibrarian++) {
        if (tempusername==(*findlibrarian).get_username()) {
            nameinuse = true;
            break;
        }
    }
    
    return nameinuse;
}   // returns true if name in use



// deletes a user. cant delete if he is reading a copy. also removed from reservation list
void deleteuser(list<Reader>& myreaders, list<Librarian>& mylibrarians, list<Student>& mystudents, list<Teacher>& myteachers, list<Book>& mybooks) {
    string tempusername;
    char searchagain;
    char usertype='f';
    
    cout << "Please enter the username of the account you want to delete: " << endl;
    //cin >> tempusername;
    
    bool nameused = false;
    
    while (!nameused) {
        nameused = false;
        
        
        getline(cin, tempusername);
        while (tempusername=="") {
            getline(cin, tempusername);
        }
        
        nameused = whoisthisuser(myreaders, mylibrarians, tempusername, usertype);
        if (nameused) {
            break;
        }
        cout << "Username not associated with an account. Search again? (y or n): " << endl;
        searchagain = 'f';
        while(searchagain!='y' && searchagain!='n') {
        cin >> searchagain;
        if (searchagain=='y') {
            cout << "Enter username to search.\n" << endl;
            //getline(cin, tempusername);
        }
        if (searchagain=='n') {
            return;
        }
        //cin >> tempusername;
        }
    
    }
    
    switch (usertype) {
        case 'l': {
            cout << "Will delete a librarian.\n" << endl;
            Librarian templibrarian;
            templibrarian.set_username(tempusername);
            list<Librarian>::iterator finditer = find(mylibrarians.begin(), mylibrarians.end(), templibrarian);
            
            cout << "Librarian to be deleted is: " << endl;
            (*finditer).printlibrarian();
            
            finditer = mylibrarians.erase(finditer);
            
            cout << "Librarian was deleted." << endl;
            
            break;
        }
            
        case 's': {
            cout << "You chose to delete a student.\n" << endl;

            
            
            Reader tempreader;
            tempreader.set_username(tempusername);
            list<Reader>::iterator finditerreader = find(myreaders.begin(), myreaders.end(), tempreader);
            
			if ((*finditerreader).getnumcopiesborrowed() > 0) {
				cout << "Can't delete this reader as they are borrowing a copy.\n" << endl;
				break;
			}

			cout << "Reader to be deleted is: " << endl;
			(*finditerreader).printReader();

            
            // before deleting reader, get their reservation list of books
            // for each book, delete their name off the reserver queue
            list<Book> listbooksreservedof;
            
            listbooksreservedof = (*finditerreader).getlistbooksreserved();
            
            //look through the list and find those books in mybooks
            
            list<Book>::iterator bookinreaderreserve;
            
            if (listbooksreservedof.empty()) {
				finditerreader = myreaders.erase(finditerreader);
                break;
            }
            
            for(bookinreaderreserve=listbooksreservedof.begin();bookinreaderreserve!=listbooksreservedof.end();bookinreaderreserve++) {
                
                Book bookreserved = (*bookinreaderreserve);
                
                list<Book>::iterator findbook = find(mybooks.begin(), mybooks.end(), bookreserved);
                //book found in list
                
                
                (*findbook).deletereserver(tempusername);
                
                
            }
            
        
            
            finditerreader = myreaders.erase(finditerreader);

        
            break;
        }
            
        case 't': {
            cout << "You chose to delete a teacher.\n" << endl;

            Reader tempreader;
            tempreader.set_username(tempusername);
            list<Reader>::iterator finditerreader = find(myreaders.begin(), myreaders.end(), tempreader);
            
			if ((*finditerreader).getnumcopiesborrowed() > 0) {
				cout << "Cannot delete this reader as they are borrowing a copy.\n" << endl;
			}

			cout << "Reader to be deleted is: " << endl;
			(*finditerreader).printReader();

			// before deleting reader, get their reservation list of books
			// for each book, delete their name off the reserver queue
			list<Book> listbooksreservedof;

			listbooksreservedof = (*finditerreader).getlistbooksreserved();

			//look through the list and find those books in mybooks

			list<Book>::iterator bookinreaderreserve;

			if (listbooksreservedof.empty()) {
				finditerreader = myreaders.erase(finditerreader);
				break;
			}
            
            for(bookinreaderreserve=listbooksreservedof.begin();bookinreaderreserve!=listbooksreservedof.end();bookinreaderreserve++) {
            
                Book bookreserved = (*bookinreaderreserve);
                
            list<Book>::iterator findbook = find(mybooks.begin(), mybooks.end(), bookreserved);
            //book found in list
                
                
                (*findbook).deletereserver(tempusername);
       
                
            }
            
            finditerreader = myreaders.erase(finditerreader);
            
            break;
        }
            
        default:
            break;
    }
    
    
    
    
    //cout << "User found and will be deleted" << endl;
    
    return;
    
}

// finds if username is in use
bool whoisthisuser(list<Reader>& myreaders, list<Librarian>& mylibrarians, string& tempusername, char& usertype) {
    bool nameinuse;
    list<Reader>::iterator findreader;
    list<Librarian>::iterator findlibrarian;
    
    nameinuse = false;
    
    for (findreader=myreaders.begin(); findreader!=myreaders.end(); findreader++) {
        if (tempusername == (*findreader).get_username()) {
            nameinuse = true;
            usertype = (*findreader).getreadertype();
            break;
        }
    }
    
    for (findlibrarian=mylibrarians.begin(); findlibrarian!=mylibrarians.end(); findlibrarian++) {
        if (tempusername==(*findlibrarian).get_username()) {
            usertype = 'l';
            nameinuse = true;
            break;
        }
    }
    
    return nameinuse;
}


// allows reader to return books
void returnbooks(list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate, char& readertype) {
    
    Reader readertofind;
    readertofind.set_username(username);
    list<Reader>::iterator findreader = find(myreaders.begin(), myreaders.end(), readertofind);
    int numcopiesborrowed = (*findreader).getnumcopiesborrowed();
    if (numcopiesborrowed == 0) {
        cout << "You have not checked out any book.\n" << endl;
        return;
    }
    // you have the reader in *findreader, above will return user to main if they didnt checkout anything
    
    cout << "\nPlease enter the ID of the book you would like to return: ";
    cin >> tempid;
    
    cout << "\n" << endl;
    
    Copy copytofind;
    copytofind.setID(tempid);
    
    Reader tempreader = *findreader;
    list<Copy> copyofcopiesborrowed = tempreader.getlistcopiesborrowed();
    list<Copy>::iterator findcopy = find(copyofcopiesborrowed.begin(), copyofcopiesborrowed.end(), copytofind);
    
    bool found = (find(copyofcopiesborrowed.begin(),copyofcopiesborrowed.end(), copytofind) !=copyofcopiesborrowed.end());
    
    if (!found) {
        cout << "You have not checked out that copy.\n" << endl;
        return;
    }
    
    Copy copytodelete = *findcopy;
    
    if (found) {
        // code to erase the copy from user account
        (*findreader).deletecopyborrowed(copytodelete);
        // check if overdue, decrease max copies
        list<Copy>::iterator copychangeiter = find(mycopies.begin(),mycopies.end(), copytodelete);

        int expirationdate = (*copychangeiter).getexpirationdate();
        if (currentdate > expirationdate) {
            int currentpenalties = (*findreader).getnumpenalties();
            int updatedpenalties = currentpenalties + 1;
            (*findreader).setnumpenalties(updatedpenalties);
            
            cout << "This book was returned late. Your number of penalties is now " << updatedpenalties << ".\n" << endl;
            (*findreader).decreasemaxcopies();
            (*copychangeiter).copyreturned(currentdate);
            return;
        }
        
        // also set new reservation date, change name to NoReader
        
        (*copychangeiter).copyreturned(currentdate);

        string titlereturned = (*copychangeiter).gettitle();
        
        cout << "Thank you for returning '" << titlereturned << "' on time.\n" << endl;
        
    }
    
    
    
    return;
    
    
    
}


// allow reader to reserve books
void reservebooks(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate, char& readertype) {
    
    // check for overdue copies
    // boolean variable. if true, tell them they cant reserve and return to option select
    bool overdue = overduecopies(mycopies, username, currentdate);
    if (overdue) {
        cout << "Cannot reserve books as you have overdue copies." << endl;
        return;
    }
    
    // if they do not have overdue copies, proceed to adding reservation
    cout << "You will need the Book's ISBN to reserve it." << endl;
    cout << "If you do not know the books ISBN, enter 1 to go back and search for it." << endl;
    cout << "Otherwise, enter any character or number:";
    cout << "\n" << endl;
    
    string knowisbn;
    getline(cin, knowisbn);
    while (knowisbn=="") {
        getline(cin, knowisbn);
    }
    
    cout << "\n" << endl;
    
    if (knowisbn=="1") {
        return;
    }
    
    
    cout << "Please enter the ISBN of the book you would like to reserve: " << endl;
    
    int isbntoreserve;
    cin >> isbntoreserve;
    
    Book booktofind;
    booktofind.setISBN(isbntoreserve);
    
    list<Book>::iterator findbook = find(mybooks.begin(), mybooks.end(), booktofind);
    
    bool found = (find(mybooks.begin(),mybooks.end(), booktofind) !=mybooks.end());
    if (!found) {
        cout << "No book was found with that ISBN.\n" << endl;
        return;
    }
    
    if (found) {
        // code to add user to book reservation list
        // add book to reader list of reservations
        
        // first see if copy with no reader lowest reservation date has been passed
        list<Copy> listofbookcopies;
        list<Copy>::iterator findcopies;
        for (findcopies = mycopies.begin(); findcopies!=mycopies.end(); findcopies++) {
            Copy copyfoundnoreader = *findcopies;
            if ((*findcopies).getISBN() == isbntoreserve && (*findcopies).getreadername()=="NoReader") {
                listofbookcopies.push_back(copyfoundnoreader);
            }
        }
        
        
        if (listofbookcopies.empty()) {
            // reserve book
            
            cout << "You will be added to the Book's reserver list.\n" << endl;
            (*findbook).addreserver(username);
            
            Reader reservingreader;
            reservingreader.set_username(username);
            
            list<Reader>::iterator findreader = find(myreaders.begin(),myreaders.end(),reservingreader);
            
            (*findreader).addbookreserved((*findbook));
            
            return;
        }
        
        
        // find copy with lowest reservation date
        list<Copy>::iterator findlowestreservedatecopy;
        
        Copy setlowestreservedateinital = listofbookcopies.front();
        int lowestreservedate = setlowestreservedateinital.getreservationdate();
        
        for (findlowestreservedatecopy=listofbookcopies.begin(); findlowestreservedatecopy!=listofbookcopies.end(); findlowestreservedatecopy++) {
            
            if ((*findlowestreservedatecopy).getreservationdate() < lowestreservedate) {
                lowestreservedate=(*findlowestreservedatecopy).getreservationdate();
            
            }
            
        }
        
        
        //  update queue
        (*findbook).updatequeue(currentdate, lowestreservedate);
        list<Copy>::iterator updateiter;
        for (updateiter=mycopies.begin(); updateiter!=mycopies.end(); updateiter++) {
            if ((*updateiter).getISBN()==isbntoreserve && (*updateiter).getreadername() == "NoReader") {
                (*updateiter).setreservationdate(lowestreservedate);
            }
        }
        
        
        
        if ((*findbook).getlistofreservers().empty()) {
            cout << "There are currently no reservers for this book. You may borrow it.\n" << endl;
            return;
        }
        
        cout << "\nYou will be added to the reservation list for this book.\n" << endl;

        (*findbook).addreserver(username);
        
        Reader reservingreader;
        reservingreader.set_username(username);
        
        list<Reader>::iterator findreader = find(myreaders.begin(),myreaders.end(),reservingreader);
        
        (*findreader).addbookreserved((*findbook));
        
        return;
        
    }
    
    return;
    
}

// allow user to cancel reservation
void cancelreservation(list<Book>& mybooks, list<Copy>& mycopies, list<Reader>& myreaders, string& username, int& currentdate) {
    
    
    
    cout << "\nPlease enter the ISBN for the book you're cancelling your reservation.\n" << endl;
    
    int cancelisbn;
    cin >> cancelisbn;
    
    Book booktofind;
    booktofind.setISBN(cancelisbn);
    
    list<Book>::iterator findbook = find(mybooks.begin(), mybooks.end(), booktofind);
    
    bool found = (find(mybooks.begin(),mybooks.end(), booktofind) !=mybooks.end());
    if (!found) {
        cout << "No book was found with that ISBN.\n" << endl;
        return;
    }
    
    if (found) {
        // check if copy with no reader
        list<Copy> listofbookcopies;
        list<Copy>::iterator findcopies;
        for (findcopies = mycopies.begin(); findcopies!=mycopies.end(); findcopies++) {
            Copy copyfoundnoreader = *findcopies;
            if ((*findcopies).getISBN() == cancelisbn && (*findcopies).getreadername()=="NoReader") {
                listofbookcopies.push_back(copyfoundnoreader);
            }
        }
        
        Reader readertofind;
        readertofind.set_username(username);
        
        list<Reader>::iterator findreader = find(myreaders.begin(),myreaders.end(),readertofind);
        
        
        if (listofbookcopies.empty()) {

            // could potentiall cancel reservation because the book copies are all being read
            //make sure user reserved that book
            
            list<Book> booksreseveredpoint = (*findreader).getlistbooksreserved();
//
            
            bool bookthere = (find(booksreseveredpoint.begin(), booksreseveredpoint.end(), booktofind) !=booksreseveredpoint.end());
            
            
            if (bookthere) {
                (*findreader).deletebookreserved(booktofind);
            }
            
            if (!bookthere) {
                cout << "You did not reserve this book." << endl;
                return;
            }
            
            cout << "Your reservation was deleted." << endl;
            (*findbook).deletereserver(username);
      
            
            return;
        }
        
        
        
        // if copies with no reader, find copy with lowest reservation date
        list<Copy>::iterator findlowestreservedatecopy;
        
        Copy setlowestreservedateinital = listofbookcopies.front();
        int lowestreservedate = setlowestreservedateinital.getreservationdate();
        
        for (findlowestreservedatecopy=listofbookcopies.begin(); findlowestreservedatecopy!=listofbookcopies.end(); findlowestreservedatecopy++) {
            
            if ((*findlowestreservedatecopy).getreservationdate() < lowestreservedate) {
                lowestreservedate=(*findlowestreservedatecopy).getreservationdate();
                
            }
            
        }
        
    
        //  update queue
        (*findbook).updatequeue(currentdate, lowestreservedate);
        list<Copy>::iterator updateiter;
        for (updateiter=mycopies.begin(); updateiter!=mycopies.end(); updateiter++) {
            if ((*updateiter).getISBN()==cancelisbn && (*updateiter).getreadername() == "NoReader") {
                (*updateiter).setreservationdate(lowestreservedate);
            }
        }
        deque<string> currentqueue = (*findbook).getlistofreservers();
        

        
        
    
        if (currentqueue.empty()) {
            cout << "You are not reserving this book." << endl;
            
            list<Book> readerbooksreserved = (*findreader).getlistbooksreserved();
            
            
            
            bool stillthere = (find(readerbooksreserved.begin(), readerbooksreserved.end(), booktofind) !=readerbooksreserved.end());
            
            
            if (stillthere) {
                (*findreader).deletebookreserved(booktofind);
            }
            return;
        }
        
        
        
        if (currentqueue.front()==username) {
            // user is first in line
            // delte them from list, delete book form their list
            // update reserve date for no readers
            (*findreader).deletebookreserved(booktofind);
            (*findbook).deletefirstinline();
            
            int currentnumreservers = (*findbook).getnumreservers();
            int setreserversto = currentnumreservers-1;
            (*findbook).setnumreservers(setreserversto);
            
            for (findcopies = mycopies.begin(); findcopies!=mycopies.end(); findcopies++) {
                Copy copyfoundnoreader = *findcopies;
                if ((*findcopies).getISBN() == cancelisbn && (*findcopies).getreadername()=="NoReader") {
                    (*findcopies).setreservationdate(currentdate);
                }
            }
            
            cout << "Your reservation has been cancelled. you were first in line" << endl;
            
            return;
        }
        
        
        // user is a reserever but not first in line
        
        cout << "Your reservation has been cancelled. You were not first in line." << endl;
        (*findbook).deletereserver(username);
        (*findreader).deletebookreserved(booktofind);
    
        return;
    
    }
    
    cout << "Dumped at the end of line" << endl;
    return;
    
}
































