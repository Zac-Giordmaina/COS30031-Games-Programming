#include <gtest/gtest.h>
#include <Player/Player.h>
#include <Map/Map.h>
#include <GameController/GameController.h>

TEST(When_game_controller_is_ititialied, it_should_set_play_to_true) {
    GameController gameController = GameController();

    EXPECT_EQ(gameController.play(), true);
}

TEST(When_quit_is_called, it_should_set_play_to_false) {
    GameController gameController = GameController();

    EXPECT_EQ(gameController.play(), true);

    gameController.quit();

    EXPECT_EQ(gameController.play(), false);
}

TEST(When_user_force_quits, it_should_return_true) {
    GameController gameController = GameController();
    string input = "q";
    EXPECT_EQ(gameController.forceQuit(input), true);
}

TEST(When_user_does_not_force_quit, it_should_return_false) {
    GameController gameController = GameController();
    string input = "yo";
    EXPECT_EQ(gameController.forceQuit(input), false);
}

TEST(When_movements_are_checked_initially, it_should_appropriate_string) {
    Player player;
    Map map;
    GameController gameController = GameController();

    map.initialisePlayerPosition(player);

    EXPECT_EQ(gameController.findValidMovements(player, map), "N");
}
