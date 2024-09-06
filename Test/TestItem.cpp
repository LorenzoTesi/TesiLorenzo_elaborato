//
// Created by loren on 26/08/2024.
//
#include "gtest/gtest.h"
#include "../Item.h"
TEST(ItemTest, SetBought){
    Item torta("Torta",Category::dolci,5,Data(3,5,2025));
    EXPECT_EQ(torta.IsBought(), false);
    torta.SetBought();
    EXPECT_EQ(torta.IsBought(),true);
}
TEST(ItemTest, Creation) {
    Data data(27, 8, 2024);
    Item latte("Latte", Category::latticini, 2, data);
    EXPECT_EQ(latte.GetName(), "Latte");
    EXPECT_EQ(latte.GetCategory(), "Latticini");
    EXPECT_EQ(latte.GetQuantity(), 2);
    EXPECT_EQ(latte.GetData(), "27/8/2024");
}
TEST(ItemTest, InvalidDay){
    EXPECT_THROW(Item pane("Pane",Category::confezionati, 3,Data(50,2,2025)),std::invalid_argument);
}
TEST(ItemTest, InvalidMonth){
    EXPECT_THROW(Item pane("Pane",Category::confezionati, 3,Data(5,200,2025)),std::invalid_argument);
}
TEST(ItemTest, InvalidYear){
    EXPECT_THROW(Item pane("Pane",Category::confezionati, 3,Data(5,2,1900)),std::invalid_argument);
}
TEST(ItemTest, UpdateQuantity) {
    Data data(27, 8, 2024);
    Item pane("Pane", Category::confezionati, 3, data);
    EXPECT_EQ(pane.GetQuantity(),3);
    pane.SetQuantity(5);
    EXPECT_EQ(pane.GetQuantity(), 5);
}
TEST(ItemTest, UpdateToInvalidQuantity){
    Item pane("Pane", Category::confezionati, 3, Data(27,8,2024));
    EXPECT_EQ(pane.GetQuantity(),3);
    EXPECT_THROW(pane.SetQuantity(-10), std::invalid_argument);
}
TEST(ItemTest, GetCategory) {
    Data data(27, 8, 2024);
    Item carne("Carne", Category::carne, 1, data);
    EXPECT_EQ(carne.GetCategory(), "Carne");
}
TEST(ItemTest, GetData) {
    Data data(1, 9, 2024);
    Item mela("Mela", Category::frutta, 5, data);
    EXPECT_EQ(mela.GetData(), "1/9/2024");
}
TEST(ItemTest, MultipleItems) {
    Data data1(27, 8, 2024);
    Data data2(1, 9, 2024);
    Item latte("Latte", Category::latticini, 2, data1);
    Item mela("Mela", Category::frutta, 5, data2);
    EXPECT_EQ(latte.GetName(), "Latte");
    EXPECT_EQ(mela.GetName(), "Mela");
    EXPECT_EQ(latte.GetData(), "27/8/2024");
    EXPECT_EQ(mela.GetData(), "1/9/2024");
}