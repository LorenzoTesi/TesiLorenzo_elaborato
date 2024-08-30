//
// Created by loren on 22/08/2024.
//
#include "Item.h"

Item::Item(const std::string& name, enum Category category, int quantity, const Data& data)
        : name(name), category(category), quantity(quantity), data(data), bought(false) {}

std::string Item::GetName() const {
    return name;
}

std::string Item::GetCategory() const {
    switch (category) {
        case Category::latticini:    return "Latticini";
        case Category::frutta:       return "Frutta";
        case Category::verdura:      return "Verdura";
        case Category::carne:        return "Carne";
        case Category::pesce:        return "Pesce";
        case Category::confezionati: return "Confezionati";
        case Category::dolci:        return "Dolci";
        default:                     return "Unknown";
    }
}

int Item::GetQuantity() const {
    return quantity;
}

void Item::SetQuantity(int quantity) {
    this->quantity = quantity;
}

std::string Item::GetData() const {
    return data.GetData();
}
bool Item::IsBought() const {
    return bought;
}
std::string Item::GetState() const{
    return bought?"Già comprato","Da comprare";
}