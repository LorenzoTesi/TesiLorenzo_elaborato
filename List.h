//
// Created by loren on 23/08/2024.
//

#ifndef ELABORATO12_LIST_H
#define ELABORATO12_LIST_H

#include "Item.h"
#include <vector>
#include <memory>


class List{
private:
    std::vector<Item> items;
    std::string name;
public:
    List(const std::string&listname ):name(listname){};
    void AddItem(const Item& item);
    void RemoveItem(const std::string& itemName);
    void UpdateItemQuantity(const std::string& itemName, int quantity);
    void ListItems() const;
    std::string GetListName()const;
};

#endif //ELABORATO12_LIST_H
