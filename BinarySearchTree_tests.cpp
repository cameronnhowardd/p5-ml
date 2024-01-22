#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"

TEST(emptynonodes) {
BinarySearchTree<int> b;
    ASSERT_TRUE(b.empty());
}

TEST(emptywnodes) {
BinarySearchTree<int> b;
b.insert(1);
b.insert(0);
    ASSERT_FALSE(b.empty());
}

TEST(sizenonodes) {
BinarySearchTree<int> b;
    ASSERT_TRUE(b.size() == 0);
}

TEST(smallnodes) {
BinarySearchTree<int> b;
b.insert(1);
b.insert(0);
    ASSERT_TRUE(b.size() == 2);
}

TEST(mediumnodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
    ASSERT_TRUE(b.size() == 25);
}

TEST(largenodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 1000; i++){
    b.insert(i);
}
    ASSERT_TRUE(b.size() == 1000);
}

TEST(rightheavynodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 1000; i++){
    b.insert(i);
    
}
b.insert(-1);
    ASSERT_TRUE(b.size() == 1001);
}

TEST(leftheavynodes) {
BinarySearchTree<int> b;
for (int i = 1000; i > 0; i--){
    b.insert(i);
    
}
b.insert(1001);
    ASSERT_TRUE(b.size() == 1001);
}

TEST(heightnonodes) {
BinarySearchTree<int> b;
    ASSERT_TRUE(b.height() == 0);
}

TEST(heightonenodes) {
BinarySearchTree<int> b;
b.insert(1);
    ASSERT_TRUE(b.height() == 1);
}

TEST(heightthreenodes) {
BinarySearchTree<int> b;
b.insert(1);
b.insert(-1);
b.insert(2);
    ASSERT_TRUE(b.height() == 2);
}

TEST(height8nodes) {
BinarySearchTree<int> b;
b.insert(4);
b.insert(3);
b.insert(5);
b.insert(2);
b.insert(6);
b.insert(7);
ASSERT_EQUAL(b.height(), 4);
}

TEST(copynonodes) {
BinarySearchTree<int> b;
BinarySearchTree<int> a = b;
ASSERT_TRUE(a.size() == 0);
ASSERT_TRUE(a.empty() == true);

}

TEST(copywnodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int> a = b;
ASSERT_TRUE(a.size() == 25);
ASSERT_TRUE(a.empty() == false);
ASSERT_TRUE(*a.min_element() == 0);

}

TEST(copywnodesdeep) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int> a = b;
a.insert(26);
ASSERT_TRUE(a.size() == 26);
ASSERT_TRUE(a.empty() == false);
ASSERT_TRUE(b.size() == 25);
ASSERT_TRUE(*b.max_element() == 24);
ASSERT_TRUE(*a.min_element() == 0);

}

TEST(findwnodes) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int>::Iterator found = b.find(23);
ASSERT_TRUE(found != b.end());
ASSERT_TRUE(*found == 23); 
}

TEST(finddne) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int>::Iterator found = b.find(27);
ASSERT_TRUE(found == b.end());

}

TEST(findmultiple) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
BinarySearchTree<int>::Iterator found = b.find(0);
BinarySearchTree<int>::Iterator found2 = b.find(1);
BinarySearchTree<int>::Iterator found3 = b.find(20);
ASSERT_TRUE(found == b.begin());
ASSERT_TRUE(*found2 == 1);
ASSERT_TRUE(*found3 == 20);

}

TEST(findempty) {
BinarySearchTree<int> b;
BinarySearchTree<int>::Iterator found = b.find(1);
ASSERT_TRUE(found == b.end());
}

TEST(insertmultiple) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
b.insert(26);
ASSERT_TRUE(b.size() == 26);
}

TEST(minmaxempty) {
BinarySearchTree<int> b;
ASSERT_TRUE(b.max_element() == b.end());
ASSERT_TRUE(b.min_element() == b.end());
}

TEST(minmaxone) {
BinarySearchTree<int> b;
b.insert(1);
ASSERT_TRUE(*b.max_element() == 1);
ASSERT_TRUE(*b.min_element() == 1);
}

TEST(sortempty) {
BinarySearchTree<int> b;
ASSERT_TRUE(b.check_sorting_invariant());
}

TEST(sortcorrect) {
BinarySearchTree<int> b;
for (int i = 0; i < 25; i++){
    b.insert(i);
}
ASSERT_TRUE(b.check_sorting_invariant());
}

TEST(sortincorrect) {
BinarySearchTree<int> b;
b.insert(1);
b.insert(0);

*b.begin() = 2;
ASSERT_FALSE(b.check_sorting_invariant());
}
TEST(mingreaterall) {
BinarySearchTree<int> b;
ASSERT_TRUE(b.min_greater_than(2) == b.end());
for (int i = 0; i < 25; i++){
    b.insert(i);
}

}

TEST(insertionheigh) {
    BinarySearchTree<int> b;
    b.insert(9);
    b.insert(4);
    b.insert(14);
    b.insert(1);
    b.insert(7);
    ASSERT_TRUE(b.height() == 3);
}

TEST(copypoppy) {
    BinarySearchTree<int> a;
    a.insert(9);
    a.insert(4);
    BinarySearchTree<int> poppy = a;
    poppy.insert(19);
    ASSERT_TRUE(a.find(19) == a.end());
    ASSERT_TRUE(poppy.find(19) != poppy.end());
    
    
}

TEST(traverserOrderWrong) {
    BinarySearchTree<int> b;
    b.insert(11);
    b.insert(6);
    b.insert(16);
    std::ostringstream os;
    for(auto iterator = b.begin(); iterator != b.end(); ++iterator) {
        os << *iterator << " ";
    }
    ASSERT_EQUAL(os.str(), "6 11 16 ");
}

TEST(TraverserOrderRight) {
    BinarySearchTree<int> b;
    for (int i = 0; i < 5; i++){
        b.insert(i);
    }
    std::ostringstream os;
    b.traverse_inorder(os);
    ASSERT_EQUAL(os.str(), "0 1 2 3 4 ");
}


TEST_MAIN()