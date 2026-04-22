#include <gtest/gtest.h>

#include "greeter.h"

TEST(GreeterTest, DefaultGreeting) {
    Greeter greeter;
    EXPECT_EQ(greeter.get_greeting(), "Hello, World!");
}

TEST(GreeterTest, CustomNameGreeting) {
    Greeter greeter("Handson13Homwork");
    EXPECT_EQ(greeter.get_greeting(), "Hello, Handson13Homwork!");
}
