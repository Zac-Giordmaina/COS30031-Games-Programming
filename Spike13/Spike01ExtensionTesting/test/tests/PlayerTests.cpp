#include <gtest/gtest.h>
#include <Player/Player.h>

TEST(When_I_set_the_current_player_coordinates, it_should_change_the_appropriate_player_attributes) {
    Player player = Player();

    player.setPlayerCurrentPosition(10, 4);

    EXPECT_EQ(player.getCurrentXPosition(), 4);
    EXPECT_EQ(player.getCurrentYPosition(), 10);
}

TEST(When_I_set_the_current_player_x_coordinate, it_should_change_the_appropriate_player_attribute) {
    Player player = Player();

    player.setPlayerCurrentPosition(10, 4);
    player.setCurrentXPosition(13);

    EXPECT_EQ(player.getCurrentXPosition(), 17);
    EXPECT_EQ(player.getCurrentYPosition(), 10);
}

TEST(When_I_set_the_current_player_y_coordinate, it_should_change_the_appropriate_player_attribute) {
    Player player = Player();

    player.setPlayerCurrentPosition(10, 4);
    player.setCurrentYPosition(-3);

    EXPECT_EQ(player.getCurrentXPosition(), 4);
    EXPECT_EQ(player.getCurrentYPosition(), 7);
}

TEST(When_I_set_the_previous_player_coordinates, it_should_change_the_appropriate_player_attribute) {
    Player player = Player();

    player.setPlayerCurrentPosition(14, 23);
    player.setPlayerPreviousPosition();

    EXPECT_EQ(player.getCurrentXPosition(), 23);
    EXPECT_EQ(player.getPreviousYPosition(), 14);
}
