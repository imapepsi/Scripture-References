//
//  main.cpp
//  NewTestamentProject
//
//  Created by Mia Seppi on 1/9/22.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Scripture.hpp"
#include "Tag.hpp"


using namespace std;

int main(int argc, const char * argv[]) {
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
                
                //Set values for scripture
                newScripture.setBook(book);
                newScripture.setChapter(chapter);
                tags.at(tags.size()-1).addToList(newScripture);
            }
        }
          myFile.close();
    }
    else {
        cout << "Unable to open file" << endl;
    }
    
    //create scripture
    //add scriptures to tag

    for (int i = 0; i < tags.size(); i++) {
        Tag tag = tags.at(i);
        cout << tag.getName() << endl;
        tag.printList();
    }
    
    
    // Ask user
    
    cout << endl;
    
    return 0;
}
