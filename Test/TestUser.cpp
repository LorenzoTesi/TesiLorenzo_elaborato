//
// Created by loren on 26/08/2024.
//
#include "gtest/gtest.h"
#include "../User.h"
#include "../List.h"

TEST(UserTest, SettingBoughtAlreadyBoughtItem){
    User Luca("Luca");

    Luca.CreateShoppingList("Casa");
    Luca.AddItemToList("Casa",Item("Tonno",Category::pesce, 4,Data(2,2,2024)));
    Luca.AddItemToList("Casa",Item("Sgombro",Category::pesce, 4,Data(2,2,2024)));
    Luca.AddItemToList("Casa",Item("Merluzzo",Category::pesce, 4,Data(2,2,2024)));

    EXPECT_EQ(Luca.GetList("Casa")->GetItemstoBuy(),3);

    Luca.SetItemBought("Casa","Tonno");
    EXPECT_EQ(Luca.GetList("Casa")->GetItemstoBuy(),2);

    EXPECT_THROW(Luca.SetItemBought("Casa","Tonno"), std::invalid_argument);
}



TEST(UserTest, UpdatingNoExistentItem){
    User Luca("Luca");

    Luca.CreateShoppingList("Casa");
    Luca.AddItemToList("Casa",Item("Tonno",Category::pesce, 4,Data(2,2,2024)));
    Luca.AddItemToList("Casa",Item("Sgombro",Category::pesce, 4,Data(2,2,2024)));
    Luca.AddItemToList("Casa",Item("Merluzzo",Category::pesce, 4,Data(2,2,2024)));

    EXPECT_EQ(Luca.GetList("Casa")->GetItemstoBuy(),3);
    Luca.SetItemBought("Casa","Tonno");

    EXPECT_EQ(Luca.GetList("Casa")->GetItemstoBuy(),2);

    EXPECT_THROW(Luca.SetItemBought("Casa","Sardine"),std::invalid_argument);
    Luca.ShowShoppingLists();
}

TEST(UserTest, SharingListWithSameName){
    User* Luca=new User("Luca");
    User* Mario= new User("Mario");
    Luca->CreateShoppingList("Spesa");
    Luca->AddItemToList("Spesa",Item("Macinato",Category::carne,1,Data(10,10,2024)));

    Mario->CreateShoppingList("Spesa");
    EXPECT_THROW(Luca->ShareListWithUser(Mario,"Spesa"),std::invalid_argument);

}


TEST(UserTest, AddingAndRemovingToNonExistentList){
    User luca("Luca");
    luca.CreateShoppingList("Spesa");
    Item fragole("Fragole",Category::frutta,5,Data(3,4,2025));
    EXPECT_NE(luca.GetList("Spesa"),nullptr);
    luca.AddItemToList("Spesa",fragole);

    EXPECT_THROW(luca.AddItemToList("Casa",fragole),std::invalid_argument);
    EXPECT_THROW(luca.RemoveItemFromList("Casa","Fragole"),std::invalid_argument);

}

TEST(UserTest,CreateListWithSameName){
    User luca("Luca");
    luca.CreateShoppingList("Spesa");
    EXPECT_THROW(luca.CreateShoppingList("Spesa"), std::invalid_argument);
}

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
EXPECT_EQ(user.GetList("Spesa")->GetTotalItems(),1);

user.RemoveItemFromList("Spesa", "Latte");
ASSERT_NE(user.GetList("Spesa"), nullptr);
EXPECT_EQ(user.GetList("Spesa")->GetTotalItems(), 0);
}

TEST(UserTest, ShareListWithUser) {
    User *Luca=new User("Luca");
    User*Mario=new User("Mario");
    Luca->CreateShoppingList("Spesa");
    Luca->AddItemToList("Spesa",Item("Salsiccia",Category::carne,10,Data(3,3,2024)));
    Luca->AddItemToList("Spesa",Item("Pane",Category::confezionati,5,Data(2,2,2024)));
    Luca->ShareListWithUser(Mario, "Spesa");
    EXPECT_NE(Mario->GetList("Spesa"), nullptr);
    EXPECT_EQ(Mario->GetList("Spesa")->GetTotalItems(),2);

    Mario->AddItemToList("Spesa", Item("Brioche", Category::confezionati, 1, Data(28, 8, 2024)));
    EXPECT_EQ(Luca->GetList("Spesa")->GetTotalItems(), 3);
    Mario->ShowShoppingLists();
    Mario->RemoveItemFromList("Spesa","Pane");
    EXPECT_EQ(Mario->GetList("Spesa")->GetTotalItems(),2);

}

TEST(UserTest, ShowMultipleLists){
    User Luca("Luca");
    Luca.CreateShoppingList("Spesa");
    Luca.CreateShoppingList("Casa");
    Item Cavolo("Cavolo rosso",Category::verdura, 1,Data(10,9,2024));

    Luca.AddItemToList("Casa",Cavolo);
    Luca.AddItemToList("Spesa",Cavolo);
    Luca.AddItemToList("Spesa",Item("Cioccolata",Category::dolci,4,Data(12,12,2024)));
    Luca.ShowShoppingLists();
    Luca.SetItemBought("Spesa","Cioccolata");

}