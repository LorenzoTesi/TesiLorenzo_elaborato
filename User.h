//
// Created by loren on 23/08/2024.
//

#ifndef ELABORATO12_USER_H
#define ELABORATO12_USER_H


#include <string>
#include <map>
#include <memory>
#include "Item.h"

class List;

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

    void AttachToList(std::shared_ptr<User> self,std::shared_ptr<List> list);
    std::shared_ptr<List> GetList(const std::string& listName) const;
    void UpdateQuantity(const std::string& listname,const std::string& itemname,const int &quantity);

    std::string GetName() const;
    void update(const std::string& listname) const;
    void ShareListWithUser(std::shared_ptr<User> user, const std::string&name);
};

#endif //ELABORATO12_USER_H
