//
// Created by loren on 23/08/2024.
//
#include "User.h"
#include <iostream>
#include "List.h"

void User::CreateShoppingList(const std::string& listName) {
    if(lists.find(listName)!=lists.end()) {
        throw std::invalid_argument("Esiste già una lista con questo nome, per favore sceglierne un altro");
    }
    else {
        auto list = std::make_shared<List>(listName);
        lists[listName] = list;
        list->attach(this);
    }
}

void User::AddItemToList(const std::string& listName, const Item& item) {
    if (lists.find(listName) != lists.end()) {
        lists[listName]->AddItem(item);
    } else {
        throw std::invalid_argument("Lista non trovata");
    }
}

void User::RemoveItemFromList(const std::string& listName, const std::string& itemName) {
    if (lists.find(listName) != lists.end()) {
        lists[listName]->RemoveItem(itemName);
    } else {
        throw std::invalid_argument("Lista non trovata");
    }
}

void User::ShowShoppingLists() const {
    std::cout << "User: " << name << " ha le seguenti liste:" << std::endl;
    for (const auto& itr : lists) {
        std::cout << "- " << itr.first << std::endl;
        itr.second->ListItems();
    }
}

std::shared_ptr<List> User::GetList(const std::string& listName) const {
    auto it = lists.find(listName);
    if (it != lists.end()) {
        return it->second;
    }
    else {
        throw std::invalid_argument("Non esiste una lista con questo nome");
    }
}
std::string User::GetName() const{
    return name;
}
void User::Update(const std::string &listname){
    auto list= GetList(listname);
    std::cout<<"La lista: "<<list->GetListName()<<" è stata modificata, ora è:"<<std::endl;
    list->ListItems();

}

void User::UpdateQuantity(const std::string& listname, const std::string &itemname, const int &quantity) {
    auto list= GetList(listname);
    list->UpdateItemQuantity(itemname,quantity);
}

void User::AttachToList(User*self,std::shared_ptr<List> list) {
    auto listname=list->GetListName();
    if(lists.find(listname)==lists.end()){
        lists[listname] = list;
        list->attach(self);
    }
    else{
        throw std::invalid_argument("Esiste già una lista con questo nome");
    }

}

void User::ShareListWithUser(User*user, const std::string &listname){
    auto list= GetList(listname);
    user->AttachToList(user,list);
    std::cout<<"Lista: "<<list->GetListName()<<" , condivisa con "<<user->GetName()<<std::endl;
}
void User::SetItemBought(const std::string &listname, const std::string &itemname) {
    auto list= GetList(listname);
    list->SetItemBought(itemname);
}
