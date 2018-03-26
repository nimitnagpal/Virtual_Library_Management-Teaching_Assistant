//
//  main.cpp
//

#include <iostream>
#include "User.h"
#include "Reader.h"
#include "Book.h"
#include <string>
#include <fstream>
#include <vector>
#include "Copy.h"
#include "Student.h"
#include "Teacher.h"
#include "Librarian.h"
#include "functions.h"
#include <ctime>
using namespace std;


int main(int argc, const char * argv[]) {
    Book iobook;
    Copy iocopy;
    Reader ioreader;
    Librarian iolibrarian;
    
	ifstream timein;
	ofstream timeout;

    list<Book> mybooks;
    list<Book>::iterator iterb;
    list<Copy> mycopies;
    list<Copy>::iterator iterc;
    list<Reader> myreaders;
    list<Reader>::iterator iterr;
    list<Student> mystudents;
    list<Student>::iterator iters;
    list<Teacher> myteachers;
    list<Teacher>::iterator itert;
    list<Librarian> mylibrarians;
    list<Librarian>::iterator iterl;
    
	// populate lists from input files
    iobook>>mybooks;
    iocopy>>mycopies;
    ioreader>>myreaders;
    iolibrarian>>mylibrarians;

	int currentdate;

    // get current date from time file
	timein.open("time.dat");
	if (timein.fail()) {
		cerr << "Error opening time-keeping file." << endl;
		return 0;
	}
	timein >> currentdate;
	timein.close();

    int usertype;

    // finds usertype, and outputs to different sign ins
    usertype = checkusertype();
    
    switch (usertype) {
        case 1: {
            string username;
            loginlibrarian(mylibrarians, username);
            //above checks if librarian, if are, outputs you below
            //do rest of librarian stuff
            cout << "\nCorrect Passworld Entered\n" << endl;
            cout << "Welcome Librarian!" << endl;
            
            
            int optionselect;
            
            // find out what the librarian wants to do, then go to the switch case for it
            optionselect=optionselectlibrarian();
            
            cin.ignore();

			clock_t initialtime = clock();
            
            while (optionselect!=0) {
                // all librarian functions
                switch (optionselect) {
                        
                    case 1: {
                        
                        // search books

						clock_t searchtime = clock();
						currentdate = ((searchtime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to search time
						cout << "Current Date: " << currentdate << endl;


                        searchfunction(mybooks, mycopies);
                        
                        optionselect = optionselectlibrarian();
                        break;
                    }
                        
                        
                    case 2: {

                        // add books

						clock_t addbooktime = clock();
						currentdate = ((addbooktime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to add book
						cout << "Current Date: " << currentdate << endl;

                        int answer;
                        cout << "Enter a new book (enter 1), or add copy of existing book (enter 2) ? \n" << endl;

                        cin >> answer;
                        
                            switch (answer){
                                    
                                    case 1:
                                    addnewbook(mybooks, mycopies);
                                    
                                    cout << "im back from adding a new book" << endl;
                                    
                                    break;
                                    
                                    case 2:
                                    addexistingbookcopy(mybooks, mycopies);
                                    break;
                                    
                                    default:
                                    cout << "Invalid entry. Please enter 1 or 2.\n" << endl;
                                    cin >> answer;
                                    break;
                            
                            }
                        

                            
                        optionselect=optionselectlibrarian();
                        
                        break;
                    
                    
                        
                    }
                        
                        
                    case 3: {

                        // delete books
                                               
						clock_t deletetime = clock();
						currentdate = ((deletetime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to delete book
                        
						cout << "Current Date: " << currentdate << endl;

                        deletecopy(mybooks, mycopies, myreaders, optionselect);
                        
                        
                        
                        
                        
                        optionselect=optionselectlibrarian();
                        
                        break;
                        
                    }
                        
                        
                    case 4: {

                        // search users

						clock_t searchusertime = clock();
						currentdate = ((searchusertime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to search users
                        
						cout << "Current Date: " << currentdate << endl;

                        searchusers(myreaders, mylibrarians);
                        
                        
                        
                        optionselect=optionselectlibrarian();
                        
                        break;
                        
                    }
                        
                        
                    case 5: {
                        
                        // add new user

						clock_t addusertime = clock();
						currentdate = ((addusertime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to add user
                        
						cout << "Current Date: " << currentdate << endl;

                        addnewuser(myreaders, mylibrarians, myteachers, mystudents);
                        
                        optionselect = optionselectlibrarian();
                        break;
                        
                        
                    }
                    
                    case 6: {

                        // delete a user
                        
						clock_t deletetime = clock();
						currentdate = ((deletetime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to delete user

						cout << "Current Date: " << currentdate << endl;

                        deleteuser(myreaders, mylibrarians, mystudents, myteachers, mybooks);
                        
                        
                        optionselect = optionselectlibrarian();
                        break;
                    }
                        
                        
                        
                    case 7: {

                        // print info of librarian


						clock_t infotime = clock();
						currentdate = ((infotime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to display info
                        
						cout << "Current Date: " << currentdate << endl;

                        Librarian templibrarian;
                        templibrarian.set_username(username);
                        
                        list<Librarian>::iterator findlibrarian = find(mylibrarians.begin(),mylibrarians.end(), templibrarian);
                        
                        (*findlibrarian).printlibrarian();
                        
                        
                        optionselect=optionselectlibrarian();
                        break;
                        
                    }
                        
                        
                        
                    case 8: {


                        // change librarian password

						cout << "Current Date: " << currentdate << endl;

                        Librarian templibrarian;
                        templibrarian.set_username(username);
                        string temppassword;
                        
						clock_t changepasswordtime = clock();
						currentdate = ((changepasswordtime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to change password

                        list<Librarian>::iterator findlibrarian = (find(mylibrarians.begin(),mylibrarians.end(), templibrarian));
                        
                        cout << "Please enter your new password. No spaces" << endl;
                       
						getline(cin, temppassword);
						while (temppassword == "") {
							getline(cin, temppassword);
						}

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
                        
                        
                        
                        (*findlibrarian).set_password(temppassword);
                        
                        cout << "Your password has been changed successfully.\n" << endl;
                        
                        
                        optionselect = optionselectlibrarian();
                        break;
                    }
                    
                        
                        
                    default:{
                        cout << "Invalid entry." << endl;
                        break;
                    }
                }
                
                
                
            
                
            }

        
            break;
        }
        
        
        case 2: {
           // loginreader();
            char readertype;
            string username;

            // login reader and welcome based on type (Student or teacher)

            loginreader(myreaders, readertype, username);
            string readertypefull;
            if (readertype=='s') {
                readertypefull = "Student";
            }
            if (readertype=='t') {
                readertypefull= "Teacher";
            }
            
            cout << "\n\nWelcome " << readertypefull << "!" << endl;
            
			clock_t initialtime = clock();
            
            int optionselect;
            
            optionselect=optionselectreader();
            
            cin.ignore();
            
            while (optionselect!=0) {
				
                switch (optionselect) {
					
                    case 1: {

                        // search books

						clock_t searchtime = clock();
						currentdate = ((searchtime - initialtime) / ( 5*CLOCKS_PER_SEC)) + currentdate;
						// time elapsed since logging in and choosing to search time

						cout << "Current Date: " << currentdate << endl;

                        searchfunction(mybooks, mycopies);
                        
		


                        optionselect = optionselectreader();
                        
                        break;
                    }
                        
                        
                    case 2: {

                        // borrow a book

						clock_t borrowbooktime = clock();
						currentdate = ((borrowbooktime - initialtime) / (5*CLOCKS_PER_SEC)) + currentdate;
						//Time elapsed since logging in and choosing to borrow for student
                        
						cout << "Current Date: " << currentdate << endl;

                        if (readertype == 's') {
                            borrowbookstudent(mybooks, mycopies, myreaders, username, currentdate);
                        }
                        
                        
                        
                        if (readertype == 't') {
                            // borrow for teachers
                            borrowbookteacher(mybooks, mycopies, myreaders, username, currentdate);
                        }
                        
                        
                        
                        
                        optionselect = optionselectreader();

                        break;
                    }
                        
                    case 3: {

                        // return a book
                        
						clock_t returnbooktime = clock();
						currentdate = ((returnbooktime - initialtime) / (5*CLOCKS_PER_SEC)) + currentdate;
						//Time elapsed since logging in and choosing to return book

						cout << "Current Date: " << currentdate << endl;

                        returnbooks(mycopies, myreaders, username, currentdate, readertype);
                        
                        

                        optionselect = optionselectreader();
                        
                        break;
                    }
                        
                    
                    case 4: {

                        // reserve a book

						clock_t reservebooktime = clock();
						currentdate = ((reservebooktime - initialtime) / (5*CLOCKS_PER_SEC)) + currentdate;
						//Time elapsed since logging in and choosing to reserve
						
						cout << "Current Date: " << currentdate << endl;


                        reservebooks(mybooks, mycopies, myreaders, username, currentdate, readertype);
                        
						

                        optionselect = optionselectreader();
                        break;
                    }
                        
                        
                    case 5: {
                        
                        // cancel a reservation

						clock_t cancelreservetime = clock();
						currentdate = ((cancelreservetime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						//Time elapsed since logging in and cancel reservation
						
						cout << "Current Date: " << currentdate << endl;

                        cancelreservation(mybooks, mycopies, myreaders, username, currentdate);
                        
						

                        optionselect = optionselectreader();
                        
                        break;
                    }
                        
                    case 6: {

                        // print reader info

						clock_t printinfotime = clock();
						currentdate = ((printinfotime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						//Time elapsed since logging in and choosing to print info
						
						cout << "Current Date: " << currentdate << endl;

                        Reader tempreader;
                        tempreader.set_username(username);
                        
                        list<Reader>::iterator findreader = (find(myreaders.begin(),myreaders.end(), tempreader));
                        
                        (*findreader).printReader();
                        
						

                        optionselect = optionselectreader();
                        break;
                    }
                        
                    case 7: {

                        // change user password

                        Reader tempreader;
                        tempreader.set_username(username);
                        string temppassword;
                        
						clock_t changepasswordtime = clock();
						currentdate = ((changepasswordtime - initialtime) / (5 * CLOCKS_PER_SEC)) + currentdate;
						// Time elapsed since logging in and choosing change password
						
						cout << "Current Date: " << currentdate << endl;


                        list<Reader>::iterator findreader = (find(myreaders.begin(),myreaders.end(), tempreader));
                        
                        cout << "Please enter your new password. No spaces" << endl;
                       
						getline(cin, temppassword);
						while (temppassword == "") {
							getline(cin, temppassword);
						}


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
                        
                        
                        
                        (*findreader).set_password(temppassword);
                        
                        cout << "Your password has been changed successfully.\n" << endl;
                        
						
                        optionselect = optionselectreader();
                        
                        break;
                    }
                    
                        
                    default: {
                        break;
                    }
                }
                
                
                
                
            }
            
            
            break;
            
        }

        default:
            break;
    }
    
    
    // output lists back into file
    outputlists(mybooks, mycopies, myreaders, mylibrarians);


    // update time to file
	timeout.open("time.dat");
	if (timeout.fail()) {
		cerr << "Error opening time-keeping file for output." << endl;
		return 0;
	}

	timeout << currentdate;
	timeout.close();

    return 0;
    }








