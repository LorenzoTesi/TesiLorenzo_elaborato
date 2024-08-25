//
// Created by loren on 23/08/2024.
//
#include "User.h"
#include <iostream>
#include "List.h"

void User::CreateShoppingList(const std::string& listName) {
    auto list = std::make_shared<List>(listName);
    lists[listName] = list;
}

void User::AddItemToList(const std::string& listName, const Item& item) {
    if (lists.find(listName) != lists.end()) {
        lists[listName]->AddItem(item);
    } else {
        std::cerr << "Lista non trovata: " << listName << std::endl;
    }
}

void User::RemoveItemFromList(const std::string& listName, const std::string& itemName) {
    if (lists.find(listName) != lists.end()) {
        lists[listName]->RemoveItem(itemName);
    } else {
        std::cerr << "Lista non trovata: " << listName << std::endl;
    }
}

void User::ShowShoppingLists() const {
    std::cout << "User: " << name << " ha le seguenti liste:" << std::endl;
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
void User::update(List* list)const{
    std::cout<<"La lista: "<<list->GetListName()<<" è stata modificata, ora è:"<<std::endl;
    std::cout<<"Oggetti da comprare: "<<list->GetTotalItems()<<std::endl;
    list->ListItems();

}
void User::ShareListWithUser(std::shared_ptr<User> user, std::shared_ptr<List> list){
    user->AttachToList(list);
    std::cout<<"Lista: "<<list->GetListName()<<" condivisa con "<<user->GetName()<<std::endl;
}