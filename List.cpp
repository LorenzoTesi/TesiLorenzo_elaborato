//
// Created by loren on 23/08/2024.
//
#include "List.h"
#include <algorithm>
#include <iostream>

void List::AddItem(const Item& item) {
    items.push_back(item);
}

void List::RemoveItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
                               [&](const Item& item) { return item.GetName() == itemName; }),
                items.end());
}

void List::UpdateItemQuantity(const std::string& itemName, int quantity) {
    for (auto& item : items) {
        if (item.GetName() == itemName) {
            item.SetQuantity(quantity);
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