//
// Created by loren on 23/08/2024.
//

#ifndef ELABORATO12_USER_H
#define ELABORATO12_USER_H
#include <string>
#include <map>
#include <memory>
#include "Item.h"
#include "Observer.h"

class List;
class User:public Observer{
private:
    std::string name;
    std::map<std::string, std::shared_ptr<List>> lists;
public:
    User(const std::string& name) : name(name) {}
    void CreateShoppingList(const std::string& listName);
    void AddItemToList(const std::string& listName, const Item& item);
    void RemoveItemFromList(const std::string& listName, const std::string& itemName);
    void ShowShoppingLists() const;
    void AttachToList(User*self,std::shared_ptr<List> list);
    std::shared_ptr<List> GetList(const std::string& listName) const;
    void UpdateQuantity(const std::string& listname,const std::string& itemname,const int &quantity);
    std::string GetName() const;
    void Update(const std::string &listname)override;
    void ShareListWithUser(User*user, const std::string&name);
    void SetItemBought(const std::string& listname, const std::string&itemname);
};

#endif //ELABORATO12_USER_H