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
    std::vector<int> v = {};
    verses = v;
}

std::string Scripture::printInfo() {
    std::string info = book + " " + chapter + ":";
    if (verses.size() == 1) {
        if (verses.front() == 0) {
            return info = book + " " + chapter;
        }
        else {
            return info = info + std::to_string(verses.front());
        }
    }
    else {
        std::vector<int> section = {verses.front()};
        for (int i=0; i<verses.size(); i++) {
            if (i == 0) { //At the begining of all verses do nothing
                continue;
            }
            else if (verses.at(i)-1 == verses.at(i-1)) { //Verses are next to eachother
                section.push_back(verses.at(i));
            }
            else { //Verses skip: We're starting a new section
                if (section.size() == 1) { // Section is only 1 verse
                    info = info + std::to_string(section.front()) + ",";
                }
                else {
                    info = info + std::to_string(section.front()) + "-" + std::to_string(section.back()) + ","; //add last verse to info string
                }
                section = {verses.at(i)}; //Create new section
            }
            
            if (i == verses.size()-1 && section.size() > 1) { //The end is a section
                info = info + std::to_string(section.front()) + "-" + std::to_string(section.back());
            }
            else if (i == verses.size()-1 && section.size() == 1) { //The end is a single verse
                info = info + std::to_string(section.back());
            }
        }
    }
    
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

void Scripture::setChapter(std::string ch) {
    chapter = ch;
}

std::vector<int> Scripture::getVerses() {
    return verses;
}

void Scripture::setVerses(std::vector<int> v) {
    verses = v;
}
