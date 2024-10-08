//
// Created by loren on 23/08/2024.
//

#ifndef ELABORATO12_LIST_H
#define ELABORATO12_LIST_H
#include "Item.h"
#include <list>
#include <map>
#include <memory>
#include "Subject.h"
#include"Observer.h"
class List: public Subject{
private:
    std::map<std::string, Item> items;
    std::string name;
    std::list<Observer*> observers;
public:
    List(const std::string&listname ):name(listname){};
    void AddItem(const Item& item);
    void RemoveItem(const std::string& itemName);
    void UpdateItemQuantity(const std::string& itemName, int quantity);
    void ListItems() const;
    std::string GetListName()const;
    void attach(Observer*o) override;
    void detach(Observer*o)override;
    void notify() override;
    int GetTotalItems() const;
    int GetItemstoBuy()const;
    void SetItemBought(const std::string &itemName);
};
#endif //ELABORATO12_LIST_H