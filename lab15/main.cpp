#include "funcs.hpp"


void rec_straight(const Node* head) {
    std::cout << head->value << '\t';
    if (head->left != nullptr) rec_straight(head->left);
    if (head->right != nullptr) rec_straight(head->right);
}

void rec_central(const Node* head) {
    if (head->left != nullptr) rec_central(head->left);
    std::cout << head->value << '\t';
    if (head->right != nullptr) rec_central(head->right);
}

void rec_reverse(const Node* head) {
    if (head->left != nullptr) rec_reverse(head->left);
    if (head->right != nullptr) rec_reverse(head->right);
    std::cout << head->value << '\t';
}

int main() {
    const char* s = "8 (3 (1, 6 (4,7)), 10 (, 18(13,)))";

    auto ns = no_spaces(s);
    Node* head = create_bin_tree(ns, strlen(ns));

    std::cout << str_to_int(ns) << '\n';

    rec_straight(head);
    std::cout << std::endl;
    rec_central(head);
    std::cout << std::endl;
    rec_reverse(head);

    destroy_bin_tree(head);
    delete[] ns;
}