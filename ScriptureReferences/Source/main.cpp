//
//  main.cpp
//  NewTestamentProject
//
//  Created by Mia Seppi on 1/9/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Library.hpp"
#include "Scripture.hpp"
#include "Tag.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Library myLibrary;
    int userCommand = 1;
    
    //Greeting Message
    cout << "Welcome to the " << myLibrary.getName() << "!" << endl;
    
    //User Picks an option
    cout << "Options" << endl;
    for (int i = 0; i < myLibrary.getCommands().size(); i++) {
        cout << i+1 << ") " << myLibrary.getCommands().at(i) << endl;
    }
    cout << endl << "Please enter an option or press (0) to quit: ";
    cin >> userCommand;
    
    while (userCommand != 0) {
        while (userCommand < 0 || userCommand > myLibrary.getCommands().size()) {
            cout << endl << "Please enter an option or press (0) to quit: ";
            cin >> userCommand;
        }
        
        if (userCommand == 0) {
            break;
        }
        else if (userCommand == 1) {
            myLibrary.searchTags();
        }
        else if (userCommand == 2) {
            myLibrary.addToPersonalList();
        }
        else if (userCommand == 3) {
            myLibrary.printPersonalList();
        }
        
        //Display options again
        cout << endl << "Options" << endl;
        for (int i = 0; i < myLibrary.getCommands().size(); i++) {
            cout << i+1 << ") " << myLibrary.getCommands().at(i) << endl;
        }
        cout << endl << "Please enter an option or press (0) to quit: ";
        cin >> userCommand;
    }
    
    
    return 0;
}
