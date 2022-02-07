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

int main(int argc, const char * argv[]) {
    //Vector of Tags
    vector<Tag> tags;
    int userPick;
    
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
    
    
    // Ask user
    cout << "Welcome to the Scripture Reference Library!" << endl;
    cout << "We have a collection of scriptures under various tags." << endl << endl;
    cout << "Tag List" << endl;
    for (int i = 0; i < tags.size(); i++) {
        Tag tag = tags.at(i);
        cout << i << ") " << tag.getName() << endl;
    }
    cout << endl << "Please enter the number of the tag you'd like to see: ";
    cin >> userPick;
    
    while (userPick < 0 || userPick > tags.size()) {
        cout << endl << "Please enter the number of the tag you'd like to see: ";
        cin >> userPick;
    }
    
    Tag tag = tags.at(userPick);
    cout << tag.getName() << endl;
    tag.printList();
    
    cout << endl;
    
    return 0;
}
