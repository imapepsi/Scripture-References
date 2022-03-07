//
//  Library.hpp
//  ScriptureReferences
//
//  Created by Mia Seppi on 3/6/22.
//

#ifndef Library_hpp
#define Library_hpp

#include <string>
#include <vector>

#include "Scripture.hpp"
#include "Tag.hpp"

class Library {
private:
    std::string name;
    
    std::vector<std::string> commands = {"Search Tags", "Add to Personal List", "View Personal List"};
    std::vector<Tag> tags;
    std::vector<Scripture> personalList;
    
    std::vector<Tag> createTags();
    int convertStringtoInt(std::string str);
    std::string convertIntToString(int num);
    std::vector<int> findVerses(std::string s, char delim);
    
public:
    Library();
    
    //Get functions
    std::string getName();
    std::vector<std::string> getCommands();
    
    //Commands
    void searchTags();
    void addToPersonalList();
    void printPersonalList();
    
    
};

#endif /* Library_hpp */
