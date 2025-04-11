#include "node.h"

using namespace std;

// Constructor definition removed as it is already defined inline in the header.

bool Node::has_right() const
{
    return (right != nullptr) ? true : false;
}

bool Node::has_left() const
{
    return (left != nullptr) ? true : false;
}
