//
// Created by loren on 23/08/2024.
//
#include "List.h"
#include <algorithm>
#include <iostream>
#include"User.h"

void List::notify() {
    for (const auto& itr : observers) {
        itr->update(this);
    }
}
void List::AddItem(const Item& item) {
    items.push_back(item);
    notify();
}

void List::RemoveItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
                               [&](const Item& item) { return item.GetName() == itemName; }),
                items.end());
    notify();
}

void List::UpdateItemQuantity(const std::string& itemName, int quantity) {
    for (auto& item : items) {
        if (item.GetName() == itemName) {
            item.SetQuantity(quantity);
            notify();
            break;
        }
    }
}

void List::ListItems() const {
    for (const auto& item : items) {
        std::cout << "Oggetto: " << item.GetName()
                  << ", Categoria: "<<item.GetCategory()
                  << ", Quantità: " << item.GetQuantity()
                  << ", Da consumare entro: " << item.GetData() << std::endl;
    }
}
std::string List::GetListName() const{
    return name;
}
void List::attach(std::shared_ptr<User> observer) {
    observers.push_back(observer);
}

void List::detach(std::shared_ptr<User> observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}
int List::GetTotalItems()const{
    int count=0;
    for(auto itr:items)
        count++;
    return count;
}
