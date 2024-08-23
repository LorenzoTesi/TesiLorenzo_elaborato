//
// Created by loren on 23/08/2024.
//

#ifndef ELABORATO12_USER_H
#define ELABORATO12_USER_H

#include <string>
#include <map>
#include <memory>
#include "List.h"



class User{
private:
    std::string name;
    std::map<std::string, std::shared_ptr<List>> lists;


public:
    User(const std::string& name) : name(name) {}

    void CreateShoppingList(const std::string& listName);
    void AddItemToList(const std::string& listName, const Item& item);
    void RemoveItemFromList(const std::string& listName, const std::string& itemName);
    void ShowShoppingLists() const;

    void AttachToList(std::shared_ptr<List> list);
    void DetachFromList(std::shared_ptr<List> list);
    std::shared_ptr<List> GetList(const std::string& listName) const;

    std::string GetName() const;
    void update(const std::string& listname) const;
};

#endif //ELABORATO12_USER_H
