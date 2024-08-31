//
// Created by loren on 22/08/2024.
//

#ifndef ELABORATO12_ITEM_H
#define ELABORATO12_ITEM_H

#include <string>
#include"Data.h"

enum class Category{
  latticini,
  frutta,
  verdura,
  carne,
  pesce,
  confezionati,
  dolci
};


class Item {
private:
    std::string name;
    Category category;
    int quantity;
    Data data;
    bool bought;

public:
    Item(const std::string& name, enum Category category, int quantity, const Data& data);
    Item() : name(""), category(Category::confezionati), quantity(0), data(Data(1, 1, 2000)), bought(false) {}

    std::string GetName() const;
    std::string GetCategory() const;
    int GetQuantity() const;
    void SetQuantity(int quantity);
    std::string GetData()const;
    bool IsBought()const;
    std::string GetState()const;
    void SetBought();
};

#endif //ELABORATO12_ITEM_H
