#ifndef NODE_H
#define NODE_H

#include <memory>
#include <string>

class Node {
public:
    Node(int key, std::string value)
        : key(key), value(value), left(nullptr), right(nullptr) {}
    ~Node() = default;

    std::string toString() const {
        return "(" + std::to_string(key) + ": " + value + ")";
    }

    int key;
    std::string value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;

    Node* next(int key) const {
        return (key < this->key) ? left.get() : right.get();
    }

    bool has_left() const { return left != nullptr; }
    bool has_right() const { return right != nullptr; }
};

#endif // NODE_H