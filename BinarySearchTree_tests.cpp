#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"
#include <sstream>

using namespace std;

TEST(bst_public_test) {
    BinarySearchTree<int> tree;
  
    tree.insert(5);
    tree.insert(6);
    tree.insert(8);
    tree.insert(4);

  
    ASSERT_TRUE(tree.size() == 4);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_TRUE(tree.check_sorting_invariant() == true);
  
    ASSERT_TRUE(tree.find(5) != tree.end());
  
    tree.insert(7);
    tree.insert(3);
    tree.insert(2);
  
    ASSERT_TRUE(tree.check_sorting_invariant());
    ASSERT_TRUE(*tree.max_element() == 8);
    ASSERT_TRUE(*tree.min_element() == 3);
    ASSERT_TRUE(*tree.min_greater_than(7) == 8);
    ASSERT_TRUE(*tree.min_greater_than(3) == 8);
    ASSERT_TRUE(*tree.find(4) == 4);
    ASSERT_TRUE(tree.find(1) == nullptr);
    ASSERT_TRUE(tree.size() == 7);
    ASSERT_TRUE(tree.height() == 4);
  
    cout << "cout << tree.to_string()" << endl;
    cout << tree.to_string() << endl << endl;
  
    cout << "cout << tree" << endl << "(uses iterators)" << endl;
    cout << tree << endl << endl;
  
    ostringstream oss_preorder;
    tree.traverse_preorder(oss_preorder);
    cout << "preorder" << endl;
    cout << oss_preorder.str() << endl << endl;
    ASSERT_TRUE(oss_preorder.str() == "5 4 3 2 6 8 7 ");
  
    ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    cout << "inorder" << endl;
    cout << oss_inorder.str() << endl << endl;
    ASSERT_TRUE(oss_inorder.str() == "2 3 4 5 6 7 8 ");
  }

TEST_MAIN()
