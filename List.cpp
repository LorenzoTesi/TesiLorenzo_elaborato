//
// Created by loren on 23/08/2024.
//
#include "List.h"
#include <algorithm>
#include <iostream>
#include"User.h"

void List::notify() {
    for (const auto& itr : observers) {
        itr->update(GetListName());
    }
}
void List::AddItem(const Item& item) {
    items.push_back(item);
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
void List::attach(std::shared_ptr<User> observer) {
    observers.push_back(observer);
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
std::string List::Buy()const{

}