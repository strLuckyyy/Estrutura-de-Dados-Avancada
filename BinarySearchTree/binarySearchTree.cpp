#include "binarySearchTree.h"
#include "node.h" // Ensure the Node class is fully defined

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

string BinarySearchTree::str() const
{
    if (!root) return "[empty]";
            
    string tree;
    stack<pair<const Node*, pair<string, bool>>> stack;
    stack.push({root.get(), {"", false}});
    
    while (!stack.empty()) {
        auto [current, state] = stack.top();
        auto [indent, is_right] = state;
        stack.pop();
        
        if (current->right) {
            stack.push({current->right.get(), 
                        {indent + (is_right ? "        " : " |      "), true}});
        }
        
        tree += indent + (is_right ? " /" : " \\") + "----- " + current->toString() + "\n";
        
        if (current->left) {
            stack.push({current->left.get(),
                        {indent + (is_right ? " |      " : "        "), false}});
        }
    }
    
    // Adiciona a raiz no meio da representação
    tree = tree.insert(tree.find('\n') + 1, root->toString() + "\n");
    return tree;
}

bool BinarySearchTree::is_empty() const
{
    return (root == nullptr) ? true : false;
}

string BinarySearchTree::search(int key) const
{
    Node* current = root.get();

    while (current) {
        if (key == current->key) return current->value;
        current = (key < current->key) ? current->left.get() : current->right.get();
    }

    return "";
}

void BinarySearchTree::insert(int key, string value)
{
    if (!root) {
        root = make_unique<Node>(key, value);
        return;
    }

    Node* current = root.get();
    Node* parent = nullptr;

    // Encontra a posição de inserção
    while (current != nullptr) {
        parent = current;
        if (key > current->key) {
            current = current->right.get();
        
        } else if (key < current->key) {
            current = current->left.get();
        
        } else {
            // Chave já existe - atualiza o valor (opcional)
            current->value = value;
            return;
        }
    }

    // Insere o novo nó na posição correta
    if (key > parent->key) {
        parent->right = make_unique<Node>(key, value);
    
    } else {
        parent->left = make_unique<Node>(key, value);
    }
}

bool BinarySearchTree::delete_by_copying(int key)
{
    auto [parent, current] = get_parent(key);

    if (current == nullptr) { return false; }

    else if (current->left && current->right) {
        Node* at_the_right = current->left.get();

        while (at_the_right->right) { at_the_right = at_the_right->right.get(); }

        delete_by_copying(at_the_right->key);
        current->key = at_the_right->key;
        current->value = at_the_right->value;
    }

    else {
        unique_ptr<Node> next_node = current->left ? 
            move(current->left) : move(current->right);

        if (!parent) {
            root = move(next_node);  // Removendo a raiz
        } else if (parent->left.get() == current) {
            parent->left = move(next_node);
        } else {
            parent->right = move(next_node);
        }
    }
    return true;
}

bool BinarySearchTree::delete_by_merging(int key)
{
    auto [parent, current] = get_parent(key);

    if (current == nullptr) { return false; }

    else if (current->left && current->right) {
        Node* at_the_right = current->left.get();

        while (at_the_right->right) 
        { at_the_right = at_the_right->right.get(); }
        at_the_right->right = move(current->right);

        if (current == root.get()) {
            root = move(current->left);
        
        } else if (parent->left.get() == current) {
            parent->left = move(current->left);
        
        } else {
            parent->right = move(current->left);
        }
    }

    else {
        unique_ptr<Node> next_node = move(current->left ? 
            current->left : current->right);

        if (current == root.get()) {
            root = move(next_node);  // Removendo a raiz
        } 
        
        else if (parent->left.get() == current) {
            parent->left = move(next_node);
        } 
        
        else {
            parent->right = move(next_node);
        }
    }

    return true;
}

void BinarySearchTree::in_order_traversal() const
{
    std::stack<Node*> stack;
    Node* current = root.get();

    while (current || !stack.empty()) {
        while (current) {
            stack.push(current);
            current = current->left.get();
        }

        current = stack.top();
        stack.pop();
        cout << current->toString() << " ";
        current = current->right.get();
    }
}

void BinarySearchTree::pre_order_traversal() const {
    if (!root) return;
    
    std::stack<Node*> stack;
    stack.push(root.get());
    
    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();
        
        cout << current->toString() << " ";
        
        if (current->right) stack.push(current->right.get());
        if (current->left) stack.push(current->left.get());
    }
}

void BinarySearchTree::post_order_traversal() const {
    if (!root) return;
    
    std::stack<Node*> stack;
    Node* current = root.get();
    Node* last_visited = nullptr;
    
    while (current || !stack.empty()) {
        if (current) {
            stack.push(current);
            current = current->left.get();
        } else {
            Node* peek = stack.top();
            if (peek->right && peek->right.get() != last_visited) {
                current = peek->right.get();
            } else {
                cout << peek->toString() << " ";
                last_visited = peek;
                stack.pop();
            }
        }
    }
}

void BinarySearchTree::level_order_traversal() const {
    if (!root) return;
    
    queue<const Node*> q; // Fila de nós constantes
    q.push(root.get());
    
    while (!q.empty()) {
        const Node* current = q.front();
        q.pop();
        
        cout << current->toString() << " ";
        
        if (current->left) q.push(current->left.get());
        if (current->right) q.push(current->right.get());
    }
}

int BinarySearchTree::count_internal() const {
    if (!root) return 0;

    int count = 0;
    queue<const Node*> q;
    q.push(root.get());

    while (!q.empty()) {
        const Node* current = q.front();
        q.pop();

        if (current->left) {
            count++;
            q.push(current->left.get());
        }
        if (current->right) {
            count++;
            q.push(current->right.get());
        }
    }

    return count;
}

int BinarySearchTree::degree(int key) const {
    const Node* current = root.get();
    
    // Busca iterativa pelo nó
    while (current != nullptr && key != current->key) {
        current = (key < current->key) ? current->left.get() : current->right.get();
    }
    
    // Se o nó não foi encontrado
    if (current == nullptr) {
        return -1;
    }
    
    // Calcula o grau do nó encontrado
    if (current->left && current->right) {
        return 2;

    } else if (current->left || current->right) {
        return 1;

    } else {
        return 0;
    }
}

int BinarySearchTree::height(int key) const {
    // 1. Encontra o nó iterativamente (sem recursão)
    const Node* target = root.get();
    while (target && key != target->key) {
        target = (key < target->key) ? target->left.get() : target->right.get();
    }
    
    if (!target) return -1; // Nó não encontrado
    
    // 2. Calcula a altura usando uma abordagem iterativa com queue
    queue<const Node*> q;
    q.push(target);
    int height = -1; // A altura de uma árvore vazia é -1
    
    while (!q.empty()) {
        int level_size = q.size();
        height++;
        
        for (int i = 0; i < level_size; ++i) {
            const Node* current = q.front();
            q.pop();
            
            if (current->left) q.push(current->left.get());
            if (current->right) q.push(current->right.get());
        }
    }
    
    return height;
}

int BinarySearchTree::level(int key) const {
    if (!root) return -1;
    
    queue<pair<const Node*, int>> q; // <nó, nível>
    q.push({root.get(), 0});
    
    while (!q.empty()) {
        auto [current, current_level] = q.front();
        q.pop();
        
        if (key == current->key) {
            return current_level;
        }
        
        if (current->left) {
            q.push({current->left.get(), current_level + 1});
        }
        if (current->right) {
            q.push({current->right.get(), current_level + 1});
        }
    }
    
    return -1; // Nó não encontrado
}

string BinarySearchTree::ancestor(int key) const {
    if (!root) return "";

    vector<pair<const Node*, string>> stack;
    stack.push_back({root.get(), ""});

    while (!stack.empty()) {
        auto [current, ancestors] = stack.back();
        stack.pop_back();

        if (current->key == key) {
            return ancestors;
        }

        if (current->right) {
            string new_ancestors = ancestors;
            if (!new_ancestors.empty()) new_ancestors += " ";
            new_ancestors += to_string(current->key);
            stack.push_back({current->right.get(), new_ancestors});
        }

        if (current->left) {
            string new_ancestors = ancestors;
            if (!new_ancestors.empty()) new_ancestors += " ";
            new_ancestors += to_string(current->key);
            stack.push_back({current->left.get(), new_ancestors});
        }
    }

    return ""; // Retorna string vazia se não encontrado
}

ostream &operator<<(std::ostream &os, const BinarySearchTree &bst)
{
    return os << bst.str();
}

NodePair BinarySearchTree::get_parent(const int key)
{
    Node* parent = nullptr;
    Node* current = root.get();

    while (current && key != current->key) {
        parent = current;
        current = current->next(key);
    }

    return {parent, current};
}
