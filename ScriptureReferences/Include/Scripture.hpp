//
//  ScriptureClass.hpp
//  NewTestamentProject
//
//  Created by Mia Seppi on 1/9/22.
//

#ifndef ScriptureClass_hpp
#define ScriptureClass_hpp

#include <string>
#include <vector>

class Scripture {
private:
    //Book
    std::string book;
    //chapter
    std::string chapter;
    //verses vector?
    std::vector<std::string> verses;
    
public:
    Scripture();
    
    //Show info
    std::string printInfo();
    
    //get book
    std::string getBook();
    
    //get chapter
    std::string getChapter();
    
    //get verses
    std::vector<std::string> getVerses();
};



#endif /* ScriptureClass_hpp */
