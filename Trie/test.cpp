#include <iostream>
#include <cstdlib>

#include "Trie.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

TEST_CASE("Testing Trie") {
    SECTION("Search an existent word.") {
        Trie *t = new Trie();
        string word = "abadon";
        t->insert(word);
        REQUIRE(t->search(word) == true);
        delete t;
    }

    SECTION("Search a nonexistent word.") {
        Trie *t = new Trie();
        string word = "abadon";
        REQUIRE(t->search(word) == false);
        delete t;
    }
}

