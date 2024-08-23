//
// Created by loren on 23/08/2024.
//
#include "User.h"
#include <iostream>

void User::CreateShoppingList(const std::string& listName) {
    auto list = std::make_shared<List>(listName);
    lists[listName] = list;
}

void User::AddItemToList(const std::string& listName, const Item& item) {
    if (lists.find(listName) != lists.end()) {
        lists[listName]->AddItem(item);
    } else {
        std::cerr << "List not found: " << listName << std::endl;
    }
}

void User::RemoveItemFromList(const std::string& listName, const std::string& itemName) {
    if (lists.find(listName) != lists.end()) {
        lists[listName]->RemoveItem(itemName);
    } else {
        std::cerr << "List not found: " << listName << std::endl;
    }
}

void User::ShowShoppingLists() const {
    std::cout << "User: " << name << " has the following shopping lists:" << std::endl;
    for (const auto& pair : lists) {
        std::cout << "- " << pair.first << std::endl;
        pair.second->ListItems();
    }
}

std::shared_ptr<List> User::GetList(const std::string& listName) const {
    auto it = lists.find(listName);
    if (it != lists.end()) {
        return it->second;
    }
    return nullptr;
}
std::string User::GetName() const{
    return name;
}