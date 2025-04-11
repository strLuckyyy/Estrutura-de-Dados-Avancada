#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <memory>
#include <stack>
#include <utility>
#include <queue>

// Forward declaration of Node class to ensure it is recognized
class Node;

struct NodePair {
    Node* parent;
    Node* current;
};

class BinarySearchTree
{
    public:
        BinarySearchTree();
        ~BinarySearchTree() = default;

        std::unique_ptr<Node> root;

        std::string str() const;
        
        friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree& bst);

        void clear() { root = nullptr; };
        bool is_empty() const;

        std::string search(int key) const;
        void insert(int key, std::string value);
        bool delete_by_copying(int key);
        bool delete_by_merging(int key);
        void in_order_traversal() const;
        void pre_order_traversal() const;
        void post_order_traversal() const;
        void level_order_traversal() const;

        int count_internal() const;
        int degree(int key) const;
        int height(int key) const;
        int level(int key) const;
        std::string ancestor(int key) const;

    private:
        NodePair get_parent(const int key);
};

#endif 