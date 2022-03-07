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
    int chapter;
    //verses vector: int type, to do math if verses are next to eachother for output (1-2, 1,3)
    std::vector<int> verses;
    
    //Helper function convert int to string
    std::string convertIntToString(int num);
    
public:
    Scripture();
    
    //Show info
    std::string printInfo();
    
    //get book
    std::string getBook();
    
    //set book
    void setBook(std::string b);
    
    //get chapter
    int getChapter();
    
    //set chapter
    void setChapter(int ch);
    
    //get verses
    std::vector<int> getVerses();
    
    void setVerses(std::vector<int> v);
};

#endif /* ScriptureClass_hpp */
