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
}
 
TEST_MAIN()
