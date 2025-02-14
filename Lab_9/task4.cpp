#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <set>

//не работает 
bool checkSyntax(const std::string& code) {
    std::stack<char> brackets;
    std::set<char> openBrackets = {'(', '[', '{'};
    std::set<char> closeBrackets = {')', ']', '}'};
    std::set<std::string> declaredVariables;

    for (size_t i = 0; i < code.size(); ++i) {
        char ch = code[i];

        // Проверка скобок
        if (openBrackets.count(ch)) {
            brackets.push(ch);
        } else if (closeBrackets.count(ch)) {
            if (brackets.empty()) {
                std::cerr << "Unmatched closing bracket at position " << i << std::endl;
                return false;
            }
            char opening = brackets.top();
            brackets.pop();
            if ((ch == ')' && opening != '(') ||
                (ch == ']' && opening != '[') ||
                (ch == '}' && opening != '{')) {
                std::cerr << "Mismatched brackets at position " << i << std::endl;
                return false;
            }
        }

        // Проверка точек с запятой
        if (ch == ';') {
            // Здесь можно добавить дополнительную логику для проверки корректности использования точки с запятой
        }

        // Проверка объявлений переменных
        if (code.substr(i, 6) == "int var") {
            size_t varNameStart = i + 6;
            while (isspace(code[varNameStart])) ++varNameStart;
            size_t varNameEnd = varNameStart;
            while (isalnum(code[varNameEnd]) || code[varNameEnd] == '_') ++varNameEnd;
            std::string varName = code.substr(varNameStart, varNameEnd - varNameStart);
            declaredVariables.insert(varName);
        }
    }

    if (!brackets.empty()) {
        std::cerr << "Unmatched opening brackets" << std::endl;
        return false;
    }

    // Здесь можно добавить проверку использования переменных

    return true;
}

int task4() {
    std::ifstream file("main2.cpp");
    std::string code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    if (checkSyntax(code)) {
        std::cout << "The code is syntactically correct." << std::endl;
    } else {
        std::cout << "The code has syntax errors." << std::endl;
    }

    return 0;
}
