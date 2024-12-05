#include <string>
#include <iostream>


namespace tr {
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
        while (s[i] >= '0' && s[i] <= '9') ++i;

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
        for (size_t i = 0; i < sz; ++i)
            if (s[i] < '0' || s[i] > '9') return false;
        return true;
    }

    void print(const char* s, size_t sz) {
        for (size_t i = 0; i < sz; ++i)
            std::cout << s[i];
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

        size_t current = first_br, br_level = 0;

        while (s[current] != ',' || br_level != 1) {
            if (s[current] == '(')
                ++br_level;
            else if (s[current] == ')')
                --br_level;
            ++current;
        }
        root->left = create_bin_tree(s + first_br + 1, current - first_br - 1);
        root->right = create_bin_tree(s + current + 1, size - current - 2);
        return root;
    }

    void destroy_bin_tree(const Node* root) {
        if (root->left)
            destroy_bin_tree(root->left);
        if (root->right)
            destroy_bin_tree(root->right);
        delete root;
    }

    void represent_bin_tree(const Node* root) {
        if (!root->left && !root->right) {
            std::cout << root->value;
            return;
        }
        std::cout << root->value << '(';
        if (root->left) represent_bin_tree(root->left);
        std::cout << ',';
        if (root->right) represent_bin_tree(root->right);
        std::cout << ')';
    }

    Node* papa(Node* root, int el) {
        if ((root->left && root->left->value == el) || (root->right && root->right->value == el))
            return root;

        if ((el > root->value) && root->right)
            return papa(root->right, el);

        if ((el < root->value) && root->left)
            return papa(root->left, el);
        return nullptr;
    }


    Node* in_tree(Node* root, int el) {
        if (el == root->value)
            return root;
        else {
            if ((el > root->value) && (root->right != nullptr))
                return in_tree(root->right, el);

            if ((el < root->value) && (root->left != nullptr))
                return in_tree(root->left, el);
        }
        return nullptr;
    }

    Node* min_in_tree(Node* root) {
        if (root->left) return min_in_tree(root->left);
        return root;
    }

    void add_element(Node* root, int el) {
        if (root->value > el) {
            if (root->left == nullptr) {
                Node* new_node = new Node;
                new_node->value = el;
                new_node->left = nullptr;
                new_node->right = nullptr;
                root->left = new_node;
                return;
            }
            add_element(root->left, el);
        }
        else if (el > root->value) {
            if (root->right == nullptr) {
                Node* new_node = new Node;
                new_node->value = el;
                new_node->left = nullptr;
                new_node->right = nullptr;
                root->right = new_node;
                return;
            }
            add_element(root->right, el);
        }
    }

    void delete_element(Node* root, int el) {
        if (!in_tree(root, el)) return;
        auto del_root = in_tree(root, el);
        auto parent = papa(del_root, el);
        std::cout << del_root->left << ' ' << del_root->right << '\n';
        if (!del_root->right && !del_root->left) {
            std::cout << "11111111111\n";
            if (parent->value < el)
                parent->right = nullptr;
            else if (parent->value > el)
                parent->left = nullptr;
            delete del_root;
        }
        else if ((del_root->right == nullptr) != (del_root->left == nullptr)) {
            std::cout << "22222222222\n";
            if (parent) {
                if (parent->value < el) {
                    if (del_root->right)
                        parent->right = del_root->right;
                    else
                        parent->right = del_root->left;
                }
                else if (parent->value > el) {
                    if (del_root->right)
                        parent->left = del_root->right;
                    else
                        parent->left = del_root->left;
                }
            }
            delete del_root;
        }
        else if ((del_root->right != nullptr) && (del_root->left != nullptr)) {
            std::cout << "3333333333\n";
            auto min = min_in_tree(del_root->right);
            auto m = min->value;
            delete_element(min, min->value);
            del_root->value = m;
        }
    }
}


namespace stc {
    template <typename T>
    class stack {
    private:
        int sz;
        int cap;
        T* value;
    public:
        stack() : sz(0), cap(0), value(0) {}

        ~stack() { delete[] value; }

        void reserve(int new_cap) {
            if (cap > new_cap)
                return;
            T* new_value = new T[new_cap];
            if (value != nullptr)
                memcpy(new_value, value, sizeof(T) * sz);
            value = new_value;
            cap = new_cap;
        }

        void push_back(const T& el) noexcept {
            if (sz == cap) reserve(cap * 2 + 1);
            new(value + sz) T(el);
            ++sz;
        }

        void push_back(T&& el) noexcept {
            if (sz == cap)
                reserve(cap * 2 + 1);
            new(value + sz) T(el);
            ++sz;
        }

        T pop_back() noexcept { return value[--sz]; }

        T& operator[](int ind) const noexcept { return value[ind]; }

        T& last() { return value[sz - 1]; }

        int size() { return sz; }
    };
}