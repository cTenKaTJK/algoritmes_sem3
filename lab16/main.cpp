#include "funcs.hpp"


void direct_traversal(const tr::Node* head) {
    stc::stack<const tr::Node*> prev;
    prev.push_back(head);

}

int main() {
    const char* s = "8 (3 (1, 6 (4, 7)), 10 (, 18(13, )))";

    char* new_s = tr::no_spaces(s);
    tr::Node* head = tr::create_bin_tree(new_s, strlen(new_s));
    tr::represent_bin_tree(head);

    tr::destroy_bin_tree(head);
    delete[] new_s;
}