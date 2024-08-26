#include <iostream>
#include"Item.h"
#include"List.h"
#include"User.h"

int main() {

    Item latte("Latte", Category::latticini, 2, Data(27,8,2024));
    Item mela("Mela", Category::frutta, 5, Data(1, 9, 2024));
    Item pane("Pane", Category::confezionati, 3, Data(28, 8, 2024));


    auto shoppingList = std::make_shared<List>("Spesa");

    shoppingList->AddItem(latte);
    shoppingList->AddItem(mela);
    shoppingList->AddItem(pane);


    auto Luca=std::make_shared<User>("Luca");

    Luca->CreateShoppingList("Casa");
    Luca->AddItemToList("Casa", Item("Yogurt", Category::latticini, 12, Data(30, 8, 2024)));
    Luca->AddItemToList("Casa", Item("Macinato", Category::carne, 1, Data(10, 9, 2024)));

    Luca->AttachToList(Luca,shoppingList);
    Luca->ShowShoppingLists();

    auto Mario=std::make_shared<User>("Mario");

    Luca->ShareListWithUser(Mario, "Casa");
    Mario->RemoveItemFromList("Casa","Yogurt");
    Mario->UpdateQuantity("Casa","Macinato",30);

    return 0;
}