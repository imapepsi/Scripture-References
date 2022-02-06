//
//  Tag.cpp
//  NewTestamentProject
//
//  Created by Mia Seppi on 1/23/22.
//

#include "Tag.hpp"
#include "Scripture.hpp"

#include <iostream>
#include <string>


//Contructors
Tag::Tag() : name("Tag") {};
Tag::Tag(std::string newName): name(newName) {};

//get name
std::string Tag::getName() {
    return name;
};

//get list
std::vector<Scripture> Tag::getList() {
    return scripturelist;
};

void Tag::setName(std::string n) {
    name = n;
}

//Add to list
void Tag::addToList(Scripture s) {
    scripturelist.push_back(s);
}

//print list
void Tag::printList() {
    for (int i = 0; i < scripturelist.size(); i++) {
        Scripture scripture = scripturelist.at(i);
        std::cout << i+1 << ". " << scripture.printInfo() << std::endl; //Print 1. Book 00:00
    }
}

//Return a specific scripture in the list
Scripture Tag::findScripture(int num) {
    return scripturelist.at(num);
};
