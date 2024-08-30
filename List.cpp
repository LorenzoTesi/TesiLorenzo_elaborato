//
// Created by loren on 23/08/2024.
//
#include "List.h"
#include <algorithm>
#include <iostream>
#include"User.h"

void List::notify() {
    for (const auto& itr : observers) {
        itr->Update(GetListName());
    }
}
void List::AddItem(const Item& item) {
    auto key=item.GetName();
    items[key]=item;
    notify();
}

void List::RemoveItem(const std::string& itemName) {
    auto item=items.find(itemName);
    items.erase(item);
    notify();
}

void List::UpdateItemQuantity(const std::string& itemName, int quantity) {
    for (auto& item : items) {
        if (item.second.GetName() == itemName) {
            item.second.SetQuantity(quantity);
            notify();
            break;
        }
    }
}

void List::ListItems() const {
    std::cout<<"Oggetti totali: "<<GetTotalItems()<<std::endl;
    std::cout<<"Oggetti non comprati"<<GetItemstoBuy()<<std::endl;
    for (const auto& item : items) {
        std::cout << "Oggetto: " << item.second.GetName()
                  << ", Categoria: "<<item.second.GetCategory()
                  << ", Quantità: " << item.second.GetQuantity()
                  << ", Da consumare entro: " << item.second.GetData()
                  << item.second.GetState()
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
    auto obs=observers.find(o);
    observers.erase(obs);
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
