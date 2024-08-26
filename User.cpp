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
void User::update(const std::string&listname)const{
    auto list= GetList(listname);
    std::cout<<"La lista: "<<list->GetListName()<<" è stata modificata, ora è:"<<std::endl;
    list->ListItems();

}
void User::AttachToList(std::shared_ptr<User> self,std::shared_ptr<List> list) {
    lists[list->GetListName()] = list;
    list->attach(self);
}

void User::UpdateQuantity(const std::string& listname, const std::string &itemname, const int &quantity) {
    auto list= GetList(listname);
    list->UpdateItemQuantity(itemname,quantity);
}

void User::ShareListWithUser(std::shared_ptr<User> user, const std::string &listname){
    auto list= GetList(listname);
    user->AttachToList(user,list);
    std::cout<<"Lista: "<<list->GetListName()<<" , condivisa con "<<user->GetName()<<std::endl;
}
