#include <cstring>
#include <iostream>



struct Node {
    int value;
    Node* left;
    Node* right;
};

char* no_spaces(const char* s) {
    char* new_s = new char[strlen(s) + 1];
    size_t len = 0;
    for (size_t i = 0; i < strlen(s); ++i) {
        if (s[i] != ' ') {
            new_s[len] = s[i];
            ++len;
        }
    }
    new_s[len] = '\0';
    return new_s;
}

int str_to_int(const char* s) {

    size_t i = 0;
    bool is_negative = false;
    if (s[0] == '-') {
        ++i;
        is_negative = true;
    }
    while (s[i] >= '0' && s[i] <= '9') {
        ++i;
    }
    --i;

    size_t start = is_negative ? 1 : 0;
    int num = 0;
    int rank = 1;
    for (i; i + 1 >= start + 1; --i) {

        num += (s[i] - '0') * rank;
        rank *= 10;
    }
    if (is_negative) return -num;
    return num;
}

bool is_digit(const char* s, size_t sz) {
    for (size_t i = 0; i < sz; ++i) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

void print(const char* s, size_t sz) {
    for (size_t i = 0; i < sz; ++i) {
        std::cout << s[i];
    }
    std::cout << '\n';
}

Node* create_bin_tree(const char* s, size_t size) {
    if (!size) return nullptr;
    Node* root = new Node;
    if (is_digit(s, size)) {
        root->value = str_to_int(s);
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    root->value = str_to_int(s);
    size_t first_br = 0;

    while (s[first_br] != '(') ++first_br;

    size_t current = first_br;
    size_t br_level = 0;

    while (s[current] != ',' || br_level != 1) {
        if (s[current] == '(') ++br_level;
        else if (s[current] == ')') --br_level;
        ++current;
    }
    root->left = create_bin_tree(s + first_br + 1, current - first_br - 1);
    root->right = create_bin_tree(s + current + 1, size - current - 2);
    return root;
}

void destroy_bin_tree(const Node* root) {
    if (root->left != nullptr) destroy_bin_tree(root->left);
    if (root->right != nullptr) destroy_bin_tree(root->right);
    delete root;
}
