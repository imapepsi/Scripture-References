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

#include "Scripture.hpp"
#include "Tag.hpp"

using namespace std;

vector<int> findVerses(string s, char delim) {
    vector<int> verses;
    
    stringstream ss(s);
    string verse; //Hold the verses
    while (getline(ss, verse, delim)) {
        int v;
        istringstream (verse) >> v;
        verses.push_back(v);
    }
    
    return verses;
}

vector<Tag> createTags() {
    //Vector of Tags
    vector<Tag> tags;
    
    //Read in file of scriptures
    ifstream myFile;
    string line;
    myFile.open ("references.txt");
    
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            //Create tag is marked in reference file by a #
            
            char firstChar = line.front();
            if (firstChar == '#') {
                Tag newTag;
                string name = line.substr(1);
                newTag.setName(name);
                tags.push_back(newTag);
            }
            else {
                Scripture newScripture;
                //Find the book and stop at space save that string in book
                auto book = line.substr(0, line.find(' '));
                //Find the chapter and stop at space save that string in chapter -1 to exclude :
                auto chapter = line.substr(line.find(' ')+1, line.find(':')-line.find(' ')-1);
                //Find the verses
                auto versesString = line.substr(line.find(':')+1, line.find(' ')-line.find(':')-1);
                vector<int> verses = findVerses(versesString, ',');
                //Set values for scripture
                newScripture.setBook(book);
                newScripture.setChapter(chapter);
                newScripture.setVerses(verses);
                tags.at(tags.size()-1).addToList(newScripture);
            }
        }
          myFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
    
    return tags;
}

void searchTags(vector<Tag> t) {
    int userPick = 1;

    cout << "We have a collection of scriptures under various tags." << endl << endl;
    cout << "Tag List" << endl;
    for (int i = 0; i < t.size(); i++) {
        Tag tag = t.at(i);
        cout << i+1 << ") " << tag.getName() << endl;
    }
    
    cout << endl << "Please enter the number of the tag you'd like to see or press (0) to quit: ";
    cin >> userPick;
    while (userPick != 0) {
        while (userPick < 0 || userPick > t.size()) {
            cout << endl << "Please enter the number of the tag you'd like to see: ";
            cin >> userPick;
        }
        
        if (userPick == 0) {
            break;
        }
        
        Tag tag = t.at(userPick-1);
        cout << endl << tag.getName() << endl;
        tag.printList();
        cout << endl;
        
        cout << endl << "Please enter the number of the tag you'd like to see or press (0) to quit: ";
        cin >> userPick;
    }
}


int main(int argc, const char * argv[]) {
    vector<string> commands = {"Search Tags", "Create Personal List", "View Personal List"};
    vector<Tag> tags = createTags();
    int userCommand = 1;
    
    // Ask user
    cout << "Welcome to the Scripture Reference Library!" << endl;
    
    cout << "Options" << endl;
    for (int i = 0; i < commands.size(); i++) {
        cout << i+1 << ") " << commands.at(i) << endl;
    }
    cout << endl << "Please enter an option or press (0) to quit: ";
    cin >> userCommand;
    
    while (userCommand != 0) {
        while (userCommand < 0 || userCommand > commands.size()) {
            cout << endl << "Please enter an option or press (0) to quit: ";
            cin >> userCommand;
        }
        
        if (userCommand == 0) {
            break;
        }
        else if (userCommand == 1) {
            searchTags(tags);
        }
        
        cout << endl << "Options" << endl;
        for (int i = 0; i < commands.size(); i++) {
            cout << i+1 << ") " << commands.at(i) << endl;
        }
        cout << endl << "Please enter an option or press (0) to quit: ";
        cin >> userCommand;
    }
    
    
    
    cout << endl << "Thank you for using the Scripture Reference Library!" << endl << endl;
    
    return 0;
}
