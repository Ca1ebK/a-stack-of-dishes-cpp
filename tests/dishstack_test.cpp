#include <catch2/catch_test_macros.hpp>
#include "../src/dishstack.hpp"

TEST_CASE("New stack is empty") {
    DishStack stack;
    REQUIRE(stack.size() == 0);
    REQUIRE(stack.isEmpty() == true);
}

TEST_CASE("Push single dish") {
    DishStack stack;
    Dish dish = Dish("Blue plate");
    stack.push(dish);
    REQUIRE(stack.size() == 1);
}

TEST_CASE("Peek returns top dish") {
    DishStack stack;
    stack.push(Dish("Blue plate"));
    Dish peeked = stack.peek();
    REQUIRE(peeked.get_description() == "Blue plate");
    REQUIRE(stack.size() == 1);
}

TEST_CASE("Stack follows LIFO order") {
    DishStack stack;
    stack.push(Dish("First"));
    stack.push(Dish("Second"));
    stack.push(Dish("Third"));
    REQUIRE(stack.pop().get_description() == "Third");
    REQUIRE(stack.pop().get_description() == "Second");
}

TEST_CASE("Full stack cannot accept more dishes") {
    DishStack stack;
    stack.push(Dish("1"));
    stack.push(Dish("2"));
    stack.push(Dish("3"));
    stack.push(Dish("4"));
    stack.push(Dish("5"));
    REQUIRE(stack.isFull() == true);
    stack.push(Dish("6"));
    REQUIRE(stack.size() == 5);
}

TEST_CASE("Push and pop work together") {
    DishStack stack;
    Dish original = Dish("Original dish");
    stack.push(original);
    Dish retrieved = stack.pop();
    REQUIRE(retrieved.get_description() == "Original dish");
    REQUIRE(stack.isEmpty() == true);
}

TEST_CASE("Pop from empty stack") {
    DishStack stack;
    stack.pop();
    REQUIRE(stack.size() == 0);
    REQUIRE(stack.isEmpty() == true);
}

TEST_CASE("Stack can be reused after emptying") {
    DishStack stack;
    stack.push(Dish("First"));
    stack.pop();
    stack.push(Dish("Second"));
    REQUIRE(stack.peek().get_description() == "Second");
    REQUIRE(stack.size() == 1);
}

