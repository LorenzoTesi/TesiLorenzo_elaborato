//
// Created by loren on 23/08/2024.
//

#ifndef ELABORATO12_LIST_H
#define ELABORATO12_LIST_H

#include "Item.h"
#include <vector>
#include <memory>
#include "Subject.h"
#include "Observer.h"

class List: public Subject{
private:
    std::vector<Item> items;
    std::string name;
    std::vector<std::shared_ptr<Observer>> observers;
public:
    List(const std::string&listname ):name(listname){};
    void AddItem(const Item& item);
    void RemoveItem(const std::string& itemName);
    void UpdateItemQuantity(const std::string& itemName, int quantity);
    void ListItems() const;
    std::string GetListName()const;
    void attach(std::shared_ptr<Observer> observer) override;
    void detach(std::shared_ptr<Observer> observer) override;
    void notify() override;
};

#endif //ELABORATO12_LIST_H
