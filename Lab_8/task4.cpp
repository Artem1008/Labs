#include <iostream>
#include <vector>
//:-1: ошибка: cannot find -lasan
//потому могу только догадываться. Деструктор вызывается только у root а под остальные объекты нет, либо делать умные указатели либо как тут

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<TreeNode*> children;
public:
    TreeNode(int val): value(val) { }
    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;
    TreeNode* AddChild(int child_value) {
        auto node = new TreeNode(child_value);
        node->root = this;
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
    //возможно надо что то типо того
    ~TreeNode()
    {
         for (const auto& child : children)
         {
            child->~TreeNode();
         }
    }
};
int task4()
{
    TreeNode root(1);
    auto left_son = root.AddChild(10);
    root.AddChild(20);
    root.AddChild(30);
    left_son->AddChild(100);
    left_son->AddChild(200);
    root.Print();
    return 1;
}
