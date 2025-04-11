#include "node.h"

using namespace std;

Node::Node(int key, string value)
{
    this->key = key;
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

bool Node::has_right() const
{
    return (right != nullptr) ? true : false;
}

bool Node::has_left() const
{
    return (left != nullptr) ? false : true;
}
