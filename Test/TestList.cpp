//
// Created by loren on 26/08/2024.
//
#include "gtest/gtest.h"
#include "../List.h"



TEST(ListTest, ConstructorAndGetListName) {
List shoppingList("Spesa");
EXPECT_EQ(shoppingList.GetListName(), "Spesa");
}

TEST(ListTest, AddItem) {
List shoppingList("Spesa");
Item item("Latte", Category::latticini, 2, Data(25, 8, 2024));

shoppingList.AddItem(item);
EXPECT_EQ(shoppingList.GetTotalItems(), 1);
}

TEST(ListTest, RemoveItem) {
List shoppingList("Spesa");
Item item("Latte", Category::latticini, 2, Data(25, 8, 2024));

shoppingList.AddItem(item);
shoppingList.RemoveItem("Latte");
EXPECT_EQ(shoppingList.GetTotalItems(), 0);
}

TEST(ListTest, UpdateItemQuantity) {
List shoppingList("Spesa");
Item item("Latte", Category::latticini, 2, Data(25, 8, 2024));

shoppingList.AddItem(item);
shoppingList.UpdateItemQuantity("Latte", 5);

const auto items = shoppingList.GetTotalItems();
EXPECT_EQ(items, 1);
}

TEST(ListTest, ListItems) {
List shoppingList("Spesa");
Item item1("Latte", Category::latticini, 2, Data(25, 8, 2024));
Item item2("Pane", Category::confezionati, 1, Data(26, 8, 2024));

shoppingList.AddItem(item1);
shoppingList.AddItem(item2);

testing::internal::CaptureStdout();
shoppingList.ListItems();
std::string output = testing::internal::GetCapturedStdout();

EXPECT_NE(output.find("Oggetto: Latte"), std::string::npos);
EXPECT_NE(output.find("Oggetto: Pane"), std::string::npos);
}



