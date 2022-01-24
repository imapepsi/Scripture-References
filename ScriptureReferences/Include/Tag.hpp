//
//  Tag.hpp
//  NewTestamentProject
//
//  Created by Mia Seppi on 1/23/22.
//

#ifndef Tag_hpp
#define Tag_hpp

#include <string>
#include "Scripture.hpp"
 
class Tag {
private:
    std::string name;
    
    std::vector<Scripture> scripturelist;
    
public:
    Tag();
    Tag(std::string name);
    
    //get name
    std::string getName();
    
    //set name
    void setName(std::string n);
    
    //get list
    std::vector<Scripture> getList();
    
    //print list
    void printList();
    
    //Find specific scripture
    Scripture findScripture(int num);
};


#endif /* Tag_hpp */
