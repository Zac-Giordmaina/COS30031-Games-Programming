#include <gtest/gtest.h>
#include <Inventory/Inventory.h>


TEST(When_I_try_to_add_an_item, it_should_be_added_to_the_inventory) {
    Inventory inventory = Inventory("test");
    Gem * gem = new Gem("testGem", "testGem");

    inventory.add(gem);

    EXPECT_EQ(inventory.itemIsInInventory(gem, "gem"), true);

    delete gem;
}

TEST(When_I_try_to_remove_an_item, it_should_removed_from_the_inventory) {
    Inventory inventory = Inventory("test");
    Gem * gem = new Gem("testGem", "testGem");

    inventory.add(gem);

    EXPECT_EQ(inventory.itemIsInInventory(gem, "gem"), true);

    inventory.remove(gem, "gem");

    EXPECT_EQ(inventory.itemIsInInventory(gem, "gem"), false);

    delete gem;
}

TEST(When_the_inventory_is_empty, it_should_print_the_appr) {

}
