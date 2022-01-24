//
//  ScriptureClass.cpp
//  NewTestamentProject
//
//  Created by Mia Seppi on 1/9/22.
//

#include "Scripture.hpp"
#include <iostream>
#include <string>
#include <vector>

Scripture::Scripture() {}

std::string Scripture::printInfo() {
    std::string info = book + " " + chapter + ":" + verses.at(0) + "-" + verses.back();
    
    return info;
}

std::string Scripture::getBook() {
    return book;
}

std::string Scripture::getChapter() {
    return chapter;
}

std::vector<std::string> Scripture::getVerses() {
    return verses;
}


