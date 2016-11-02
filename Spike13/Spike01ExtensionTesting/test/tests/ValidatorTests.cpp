#include <gtest/gtest.h>
#include <Validator/Validator.h>

TEST(When_a_valid_input_is_checked, it_should_return_true) {
    Validator validator = Validator();

    EXPECT_EQ(validator.validCharacter("n"), true);
}

TEST(When_an_invalid_input_is_checked, it_should_return_true) {
    Validator validator = Validator();

    EXPECT_EQ(validator.validCharacter("y"), false);
}
