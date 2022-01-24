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

Scripture::Scripture(): book("Nephi"), chapter("1") {
    std::vector<std::string> v = {"1", "2"};
    verses = v;
}

std::string Scripture::printInfo() {
    std::string info = book + " " + chapter + ":" + verses.front() + "-" + verses.back();
    
    return info;
}

std::string Scripture::getBook() {
    return book;
}

void Scripture::setBook(std::string b) {
    book = b;
}

std::string Scripture::getChapter() {
    return chapter;
}

std::vector<std::string> Scripture::getVerses() {
    return verses;
}


