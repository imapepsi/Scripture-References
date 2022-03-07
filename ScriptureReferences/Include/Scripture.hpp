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
    //chapter String type to make output easier
    std::string chapter;
    //verses vector: int type, to do math if verses are next to eachother for output (1-2, 1,3)
    std::vector<int> verses;
    
public:
    Scripture();
    
    //Show info
    std::string printInfo();
    
    //get book
    std::string getBook();
    
    //set book
    void setBook(std::string b);
    
    //get chapter
    std::string getChapter();
    
    //set chapter
    void setChapter(std::string ch);
    
    //get verses
    std::vector<int> getVerses();
    
    void setVerses(std::vector<int> v);
};

#endif /* ScriptureClass_hpp */
