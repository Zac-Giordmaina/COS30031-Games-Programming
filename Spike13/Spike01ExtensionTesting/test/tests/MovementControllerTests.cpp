#include <gtest/gtest.h>
#include <Player/Player.h>
#include <Map/Map.h>
#include <MovementController/MovementController.h>

TEST(When_a_valid_move_is_made, it_should_return_direction_value) {
    Player player;
    Map map;
    MovementController movementController;

    string userInput = "n";
    map.initialisePlayerPosition(player);

    EXPECT_EQ(movementController.performMovement(userInput, player, map), "North");
}

TEST(When_a_invalid_move_is_made, it_should_return_error_value) {
    Player player;
    Map map;
    MovementController movementController;

    string userInput = "w";
    map.initialisePlayerPosition(player);

    EXPECT_EQ(movementController.performMovement(userInput, player, map), "Wall");
}

TEST(When_a_move_is_out_of_map, it_should_return_error_value) {
    Player player;
    Map map;
    MovementController movementController;

    string userInput = "s";
    map.initialisePlayerPosition(player);

    EXPECT_EQ(movementController.performMovement(userInput, player, map), "Offmap");
}

TEST(When_a_valid_move_is_checked, it_should_return_true) {
    MovementController movementController;

    const string EAST = "East";

    EXPECT_EQ(movementController.validMovement(EAST), true);
}

TEST(When_an_invalid_move_is_checked, it_should_return_false) {
    MovementController movementController;

    EXPECT_EQ(movementController.validMovement("EYYYY"), false);
}
