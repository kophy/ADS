#include <iostream>
#include <cstdlib>

#include "Trie.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("Testing Trie") {
    // set up
    Trie *t = new Trie();

    // different sections
    SECTION("Search an existent word.") {
        string word = "abandon";
        t->insert(word);
        REQUIRE(t->search(word) == true);
    }
    SECTION("Search a nonexistent word.") {
        string word = "abandon";
        REQUIRE(t->search(word) == false);
    }

    // tear down
    delete t;
}

