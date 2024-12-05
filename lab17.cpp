#include "funcs.hpp"


void direct_traversal(const tr::Node* head) {
    stc::stack<const tr::Node*> prev;
    prev.push_back(head);

}

void rec_straight(const tr::Node* head) {
    std::cout << head->value << ":  " << head << '\t';
    if (head->left != nullptr) rec_straight(head->left);
    if (head->right != nullptr) rec_straight(head->right);
}

int main() {
    const char* s = "8 (3 (1, 6 (4, 7)), 10 (, 18(13, )))";

    char* new_s = tr::no_spaces(s);
    tr::Node* head = tr::create_bin_tree(new_s, strlen(new_s));

    //tr::add_element(head, 11);
    //tr::represent_bin_tree(head);

    std::cout << '\n'<< tr::in_tree(head, 7)->value << '\n';

    tr::delete_element(head, 10);
    tr::represent_bin_tree(head);
    std::cout << tr::papa(head, 7)->value << '\n';


    tr::destroy_bin_tree(head);
    delete[] new_s;
}