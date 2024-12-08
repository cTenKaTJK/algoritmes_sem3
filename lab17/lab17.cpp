#include "funcs.hpp"


void direct_traversal(const tr::Node* head) {
    stc::stack<const tr::Node*> prev;
    prev.push_back(head);

}

void rec_straight(const tr::Node* head) {
    std::cout << head->value << ' ';
    if (head->left != nullptr)
        rec_straight(head->left);
    if (head->right != nullptr)
        rec_straight(head->right);
}

int main() {
    const char* s = "8 (3 (1, 6 (4, 7)), 10 (, 18(13, )))";

    char* new_s = tr::no_spaces(s);
    tr::Node* head = tr::create_bin_tree(new_s, strlen(new_s));
    tr::represent_bin_tree(head); std::cout << std::endl;

    tr::add_element(head, 9);
    tr::add_element(head, 21);
    tr::represent_bin_tree(head); std::cout << std::endl;

    tr::delete_element(head, 13);
    tr::represent_bin_tree(head); std::cout << std::endl;
    tr::delete_element(head, 10);
    tr::represent_bin_tree(head); std::cout << std::endl;
    tr::delete_element(head, 7);
    tr::represent_bin_tree(head); std::cout << std::endl;

    std::cout << get_cell(head, 6)->value << '\n';
    std::cout << get_cell(head, 2)->value << '\n';

    tr::destroy_bin_tree(head);
    delete[] new_s;
}