#include <iostream>
#include <vector>
#include <memory>

//:-1: ошибка: cannot find -lasan
//потому могу только догадываться. Деструктор вызывается только у root а под остальные объекты нет! либо как тут

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
            delete child;
            //child->~TreeNode();
         }
         printf("удалился %d\n",value);
    }
};
// либо делать умные указатели
class TreeNode2 {
private:
    int value;
    TreeNode2* root = nullptr;
    std::vector<std::shared_ptr<TreeNode2>> children;
public:
    TreeNode2(int val): value(val) { }
    TreeNode2(const TreeNode2&) = delete;
    TreeNode2& operator=(const TreeNode2&) = delete;
    std::shared_ptr<TreeNode2> AddChild(int child_value) {
        auto node=std::make_shared<TreeNode2>(child_value);
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
    //возможно надо что то типо того
    ~TreeNode2()
    {
         printf("удалился %d\n",value);
    }
};

int task4()
{
    TreeNode root(1);
    auto left_son = root.AddChild(10);
    auto middle_son = root.AddChild(20);
    auto right_son = root.AddChild(30);
    left_son->AddChild(100);
    left_son->AddChild(200);
    root.Print();
    return 1;
}
