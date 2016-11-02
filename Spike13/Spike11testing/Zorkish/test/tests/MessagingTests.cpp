#include <gtest/gtest.h>
#include <LocationGraph/LocationGraph.h>
#include <Player/Player.h>


TEST(When_I_send_a_message_to_reduce_player_energy, it_should_reduce_player_energy) {
    Player player = Player();
    LocationGraph locationGraph = LocationGraph();
    HasMessaging * playerPointer = &player;
    HasMessaging * locationGraphPointer = &locationGraph;
    Messaging messaging = Messaging(playerPointer, locationGraphPointer);
    player.addMessenger(messaging);
    locationGraph.addMessenger(messaging);

    EXPECT_EQ(player.getEnergy(), 100);

    messaging.reducePlayerEnergy(-20);

    EXPECT_EQ(player.getEnergy(), 80);
}

TEST(When_I_send_a_message_to_increase_player_energy, it_should_increase_player_energy) {
    Player player = Player();
    LocationGraph locationGraph = LocationGraph();
    HasMessaging * playerPointer = &player;
    HasMessaging * locationGraphPointer = &locationGraph;
    Messaging messaging = Messaging(playerPointer, locationGraphPointer);
    player.addMessenger(messaging);
    locationGraph.addMessenger(messaging);

    EXPECT_EQ(player.getEnergy(), 100);

    messaging.reducePlayerEnergy(20);

    EXPECT_EQ(player.getEnergy(), 120);
}
