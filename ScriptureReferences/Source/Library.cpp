//
//  Library.cpp
//  ScriptureReferences
//
//  Created by Mia Seppi on 3/6/22.
//

#include "Library.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>


Library::Library() {
    name = "Scripture Reference Library";
    tags = createTags();
}

std::string Library::getName() {
    return name;
}

std::vector<std::string> Library::getCommands() {
    return commands;
}


//Option 1: Search tags
void Library::searchTags() {
    int userPick = 1;

    std::cout << "We have a collection of scriptures under various tags." << std::endl << std::endl;
    std::cout << "Tag List" << std::endl;
    for (int i = 0; i < tags.size(); i++) {
        Tag tag = tags.at(i);
        std::cout << i+1 << ") " << tag.getName() << std::endl;
    }
    
    std::cout << std::endl << "Please enter the tag number you'd like to see or press (0) to return: ";
    std::cin >> userPick;
    while (userPick != 0) { //If not zero continue program
        while (userPick < 0 || userPick > tags.size()) { //Check valid input from user
            std::cout << std::endl << "Please enter the tag number you'd like to see press (0) to return: ";
            std::cin >> userPick;
        }
        
        if (userPick == 0) { // If zero exit
            break;
        }
        
        Tag tag = tags.at(userPick-1);
        std::cout << std::endl << tag.getName() << std::endl;
        tag.printList();
        std::cout << std::endl;
        
        std::cout << std::endl << "Please enter the tag number you'd like to see or press (0) to return: ";
        std::cin >> userPick;
    }
}

//Option 2: Add to Personal List
void Library::addToPersonalList() {
    Scripture scripture = Scripture();
    std::string book;
    int chapter;
    std::vector<int> verses;
    int numVerses = 1;
    
    std::cin.ignore(); //getline will use the last cin with is usually ""/enter ignore allows to get new input
    std::cout << "Enter Book: ";
    std::getline (std::cin, book);
    scripture.setBook(book);
    
    std::cout << "Enter Chapter: ";
    std::cin >> chapter;
    while (chapter <= 0) { //No negative chpaters or chapter 0
        std::cout << "Enter the chapter: ";
        std::cin >> chapter;
    }
    scripture.setChapter(chapter);
    
    std::cout << "Enter Number of Verses: ";
    std::cin >> numVerses;
    
    std::cout << "Please enter one verse at a time and press enter." << std::endl;
    for (int i = 0; i < numVerses; i++) {
        int v;
        std::cout << "Enter the verse: ";
        std::cin >> v;
        while (v <= 0) { //No negative verses or verse 0
            std::cout << "Enter the verse: ";
            std::cin >> v;
        }
        verses.push_back(v);
    }
    scripture.setVerses(verses);
    
    personalList.push_back(scripture);
}

//Option 3: View Personal List
void Library::printPersonalList() {
    std::cout << std::endl; //For viewing
    
    for (int i = 0; i < personalList.size(); i++) {
        std::cout << i+1 << ". " << personalList.at(i).printInfo() << std::endl;
    }
}

//Private CreateTags function
std::vector<Tag> Library::createTags() {
    //Vector of Tags
    std::vector<Tag> tags;
    
    //Read in file of scriptures
    std::ifstream myFile;
    std::string line;
    myFile.open ("references.txt");
    
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            //Create tag is marked in reference file by a #
            
            char firstChar = line.front();
            if (firstChar == '#') {
                Tag newTag;
                std::string name = line.substr(1);
                newTag.setName(name);
                tags.push_back(newTag);
            }
            else {
                Scripture newScripture;
                //Find the book and stop at space save that string in book
                auto book = line.substr(0, line.find(' '));
                //Find the chapter and stop at space save that string in chapter -1 to exclude :
                auto chapter = line.substr(line.find(' ')+1, line.find(':')-line.find(' ')-1);
                int chapterNum = convertStringtoInt(chapter);
                //Find the verses
                auto versesString = line.substr(line.find(':')+1, line.find(' ')-line.find(':')-1);
                std::vector<int> verses = findVerses(versesString, ',');
                //Set values for scripture
                newScripture.setBook(book);
                newScripture.setChapter(chapterNum);
                newScripture.setVerses(verses);
                tags.at(tags.size()-1).addToList(newScripture);
            }
        }
          myFile.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }
    
    return tags;
}

//Helper function convert string to int
int Library::convertStringtoInt(std::string str) {
    return stoi(str);
}

//Helper function for createTags
std::vector<int> Library::findVerses(std::string s, char delim) {
    std::vector<int> verses;
    
    std::stringstream ss(s);
    std::string verse; //Hold the verses
    while (getline(ss, verse, delim)) {
        int v;
        std::istringstream (verse) >> v;
        verses.push_back(v);
    }
    
    return verses;
}
