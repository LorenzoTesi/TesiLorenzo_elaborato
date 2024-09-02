//
// Created by loren on 23/08/2024.
//
#include "List.h"
#include <iostream>
#include"User.h"

void List::notify() {
    for (const auto& itr : observers) {
        itr->Update(GetListName());
    }
}
void List::AddItem(const Item& item) {
    if(items.find(item.GetName()) == items.end()) {
        items[item.GetName()] = item;
        notify();
    } else {
        throw std::invalid_argument("Un oggetto con questo nome è già presente nella lista");
    }
}


void List::RemoveItem(const std::string& itemName) {
    if(items.find(itemName)!=items.end()) {
        auto item = items.find(itemName);
        items.erase(item);
        notify();
    }
    else
        throw std::invalid_argument("Non esiste un oggetto con questo nome nella lista");
}

void List::UpdateItemQuantity(const std::string& itemName, int quantity) {
    if(items.find(itemName)!=items.end()) {
        for (auto &item: items) {
            if (item.second.GetName() == itemName) {
                item.second.SetQuantity(quantity);
                notify();
                break;
            }
        }
    }
    else
        throw std::invalid_argument("Non esiste un oggetto con questo nome nella lista");
}

void List::ListItems() const {
    std::cout<<"Oggetti totali: "<<GetTotalItems()<<std::endl;
    std::cout<<"Oggetti non comprati: "<<GetItemstoBuy()<<std::endl;
    for (const auto& item : items) {
        std::cout << "Oggetto: " << item.second.GetName()
                  << ", Categoria: "<<item.second.GetCategory()
                  << ", Quantità: " << item.second.GetQuantity()
                  << ", Da consumare entro: " << item.second.GetData()
                  << " "<<item.second.GetState()
                  << std::endl;
    }
}
std::string List::GetListName() const{
    return name;
}
void List::attach(Observer*o) {
    observers.push_back(o);
}
void List::detach(Observer *o) {
   observers.remove(o);
}

int List::GetTotalItems()const{
    int count=0;
    for(auto itr:items)
        count++;
    return count;
}
int List::GetItemstoBuy()const{
    int count=0;
    for(auto itr:items){
        if (!itr.second.IsBought())
            count++;
    }
    return count;
}
void List::SetItemBought(const std::string &itemName) {
    auto it = items.find(itemName);
    if (it != items.end()) {
        it->second.SetBought();
        notify();
    } else {
        throw std::invalid_argument("Non esiste un oggetto con questo nome nella lista");
    }
}
