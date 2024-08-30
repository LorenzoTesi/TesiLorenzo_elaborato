//
// Created by loren on 22/08/2024.
//
#include "Item.h"

Item::Item(const std::string& name, enum Category category, int quantity, const Data& data){
    if(quantity<=0)
        throw std::invalid_argument("Inserire quantità positiva");
    else{
        this->name=name;
        this->category=category;
        this->data=data;
        this->quantity=quantity;
        this->bought=false;
    }
}

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
    if(quantity>0)
    this->quantity = quantity;
    else
        throw std::invalid_argument("Inserire una quantità positiva");
}

std::string Item::GetData() const {
    return data.GetData();
}
bool Item::IsBought() const {
    return bought;
}
std::string Item::GetState() const{
    if(bought)
        return "Già comprato";
    else
        return "Da comprare";
}