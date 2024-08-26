//
// Created by loren on 26/08/2024.
//
#include "gtest/gtest.h"
#include "../User.h"
#include "../List.h"

TEST(UserTest, ConstructorAndGetName) {
User user("Luca");
EXPECT_EQ(user.GetName(), "Luca");
}

TEST(UserTest, CreateShoppingList) {
User user("Luca");
user.CreateShoppingList("Spesa");

auto list = user.GetList("Spesa");
ASSERT_NE(list, nullptr);
EXPECT_EQ(list->GetListName(), "Spesa");
}

TEST(UserTest, AddItemToList) {
User user("Luca");
user.CreateShoppingList("Spesa");

Item item("Latte", Category::latticini, 2, Data(25, 8, 2024));
user.AddItemToList("Spesa", item);

auto list = user.GetList("Spesa");
ASSERT_NE(list, nullptr);
EXPECT_EQ(list->GetTotalItems(), 1);
}

TEST(UserTest, RemoveItemFromList) {
User user("Luca");
user.CreateShoppingList("Spesa");

Item item("Latte", Category::latticini, 2, Data(25, 8, 2024));
user.AddItemToList("Spesa", item);
user.RemoveItemFromList("Spesa", "Latte");

auto list = user.GetList("Spesa");
ASSERT_NE(list, nullptr);
EXPECT_EQ(list->GetTotalItems(), 0);
}

