//
// Created by loren on 26/08/2024.
//
#include "gtest/gtest.h"
#include "../List.h"

TEST(ListTest, RemovingNoExistingItem){
    List list("spesa");
    Item mozzarella("Mozzarella",Category::latticini,5,Data(3,7,2024));
    list.AddItem(mozzarella);
    EXPECT_EQ(list.GetTotalItems(),1);
    list.RemoveItem("Bufala");
    EXPECT_EQ(list.GetTotalItems(),1);
}

TEST(ListTest, AddingSameNameItem){
    List list("spesa");
    Item mozzarella("Mozzarella",Category::latticini,5,Data(3,7,2024));
    list.AddItem(mozzarella);
    Item mozzarella2("Mozzarella",Category::latticini, 2,Data(11,11,2024));
    list.AddItem(mozzarella2);
    EXPECT_EQ(list.GetTotalItems(),1);
}

TEST(ListTest, GetItemsToBuyAndSetBought){
    List list("spesa");
    Item mozzarella("Mozzarella",Category::latticini,5,Data(3,7,2024));
    list.AddItem(mozzarella);

    Item bufala("Bufala",Category::latticini, 2,Data(11,11,2024));
    list.AddItem(bufala);

    Item bistecca("Bistecca",Category::carne,7,Data(3,10,2024));
    list.AddItem(bistecca);

    EXPECT_EQ(list.GetItemstoBuy(),3);
    list.SetItemBought("Mozzarella");
    EXPECT_EQ(list.GetItemstoBuy(),2);
    list.RemoveItem("Bistecca");
    EXPECT_EQ(list.GetItemstoBuy(),1);

}

TEST(ListTest, ConstructorAndGetListName) {
List shoppingList("Spesa");
EXPECT_EQ(shoppingList.GetListName(), "Spesa");
}

TEST(ListTest, AddItem) {
List shoppingList("Spesa");
Item item("Latte", Category::latticini, 2, Data(25, 8, 2024));
EXPECT_EQ(shoppingList.GetTotalItems(),0);
shoppingList.AddItem(item);
EXPECT_EQ(shoppingList.GetTotalItems(), 1);
}

TEST(ListTest, RemoveItem) {
List shoppingList("Spesa");
Item item("Latte", Category::latticini, 2, Data(25, 8, 2024));

shoppingList.AddItem(item);
EXPECT_EQ(shoppingList.GetTotalItems(),1);
shoppingList.RemoveItem("Latte");
EXPECT_EQ(shoppingList.GetTotalItems(), 0);
}




