#include "sharedptr.h"
#include <iostream>
#include <vector>

class Resource {
public:
    Resource() { std::cout << "Создан ресурс\n"; }
    ~Resource() { std::cout << "Уничтожен ресурс\n"; }
    void print() const { std::cout << "Ресурс используется\n"; }
};

class TreeNode2 {
private:
    int value;
    TreeNode2* root = nullptr;
    std::vector<SharedPTR<TreeNode2>> children;
public:
    TreeNode2(){};
    TreeNode2(int val): value(val) { }
    TreeNode2(const TreeNode2&) = delete;
    TreeNode2& operator=(const TreeNode2&) = delete;
    SharedPTR<TreeNode2> AddChild(int child_value)
    {
        auto node(SharedPTR<TreeNode2>(new TreeNode2(child_value)));
        node->root=this;
        children.push_back(node);
        return node;
    }
    void Print(int depth = 0) const {
        for (int i = 0; i < depth; ++i) {
            std::cout << " ";
        }
        std::cout << "- " << value << "\n";
        for (const auto& child : children) {
            child->Print(depth + 1);
        }
    }
    ~TreeNode2()
    {
        printf("удалился %d\n",value);
    }
};
int task4()
{
    TreeNode2 root(1);
    auto left_son = root.AddChild(10);
    auto left_son2=left_son;
    auto middle_son = root.AddChild(20);
    auto right_son = root.AddChild(30);
    left_son->AddChild(100);
    left_son->AddChild(200);
     root.Print();
    return 1;
}
