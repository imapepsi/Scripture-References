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
            //Create tag is #
            Tag newTag;

            char firstChar = line.front();
            if (firstChar == '#') {
                string name = line.substr(1);
                newTag.setName(name);
            }
            else {
                Scripture newScripture;
                newScripture.setBook(line);
                newTag.addToList(newScripture);
            }
            
            tags.push_back(newTag);

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
