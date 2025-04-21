#include "Map.hpp"
#include "unit_test_framework.hpp"

TEST(map_big_three) {
    Map<std::string, int> map1; 
    ASSERT_TRUE(map1.empty()); 
    map1.insert({"a", 1}); 
    map1.insert({"b", 2}); 
    map1.insert({"c", 3}); 
    Map<std::string, int> map2; 
    ASSERT_TRUE(map2.empty()); 
    map2 = map1; 
    ASSERT_TRUE(map2.size() == map1.size() && map2.size() == 3); 
    Map<std::string, int> map3(map2); 
    ASSERT_TRUE(map2.size() == map3.size() && map3.size() == 3); 
}

TEST(map_find) {
    Map<std::string, int> map1;
    map1.insert({"a", 1}); 
    map1.insert({"b", 2}); 
    map1.insert({"c", 3}); 
    ASSERT_TRUE((*map1.find("a")).second==1); 
    ASSERT_TRUE((*map1.find("b")).second==2); 
    ASSERT_TRUE((*map1.find("c")).second==3); 
}

TEST(map_bracket_operator) {
    Map<std::string, int> map1;
    map1.insert({"a", 1}); 
    map1.insert({"b", 2}); 
    map1.insert({"c", 3}); 
    ASSERT_TRUE(map1["a"]==1); 
    ASSERT_TRUE(map1["b"]==2);
    ASSERT_TRUE(map1["c"]==3);
    map1["d"]=4; 
    map1["e"]; 
    ASSERT_TRUE((*map1.find("d")).second = 4); 
    ASSERT_TRUE(map1["e"]==0); 
}

TEST(map_insert) {
    Map<std::string, int> map1;
    map1.insert({"a", 1}); 
    map1.insert({"b", 2}); 
    map1.insert({"c", 3}); 
    ASSERT_TRUE(map1.size()==3); 
    Map<std::string, int> map2; 
    map2.insert({"a", 1}); 
    map2.insert({"a", 2}); 
    ASSERT_TRUE(map2.size()==1); 
}

TEST(map_find_missing) {
    Map<std::string, int> map;
    map.insert({"a", 1});
    ASSERT_EQUAL(map.find("z"), map.end());
}

TEST(map_insert_duplicate) {
    Map<std::string, int> map;
    map.insert({"x", 42});
    map.insert({"x", 99}); // Should not insert or change
    ASSERT_EQUAL(map.size(), 1);
    ASSERT_EQUAL(map["x"], 42); // Original value preserved
}

TEST(map_insertion_order_independence) {
    Map<std::string, int> m1, m2;
    m1.insert({"b", 2});
    m1.insert({"a", 1});
    m1.insert({"c", 3});

    m2.insert({"a", 1});
    m2.insert({"b", 2});
    m2.insert({"c", 3});

    ASSERT_EQUAL(m1.size(), m2.size());
    ASSERT_EQUAL(m1["a"], m2["a"]);
    ASSERT_EQUAL(m1["b"], m2["b"]);
    ASSERT_EQUAL(m1["c"], m2["c"]);
}

TEST(map_bracket_adds_default) {
    Map<std::string, int> map;
    ASSERT_EQUAL(map.size(), 0);
    int val = map["new_key"]; // should insert with default `int() = 0`
    ASSERT_EQUAL(val, 0);
    ASSERT_EQUAL(map.size(), 1);
}

TEST(map_self_assignment) {
    Map<std::string, int> map;
    map.insert({"self", 1});
    map = map; // Should not crash or corrupt
    ASSERT_EQUAL(map.size(), 1);
    ASSERT_EQUAL(map["self"], 1);
}

TEST(map_large_destruction) {
    Map<int, int> map;
    for (int i = 0; i < 10000; ++i)
        map.insert({i, i * i});
    ASSERT_EQUAL(map.size(), 10000);
    // Automatically destroyed at end of test — check with valgrind for leaks
}

TEST(map_inorder_traversal) {
    Map<int, std::string> map;
    map.insert({2, "b"});
    map.insert({1, "a"});
    map.insert({3, "c"});

    std::vector<int> keys;
    for (auto it = map.begin(); it != map.end(); ++it)
        keys.push_back(it->first);
    
    ASSERT_EQUAL(keys.size(), 3);
    ASSERT_EQUAL(keys[0], 1);
    ASSERT_EQUAL(keys[1], 2);
    ASSERT_EQUAL(keys[2], 3);
}

TEST_MAIN()
