#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

// 定义两个栈用于存储整数和浮点数
stack<int> intnum;      // 存储整数操作数
stack<double> floatnum; // 存储浮点数操作数
stack<char> op;         // 存储运算符

// 定义运算符优先级映射
unordered_map<char, int> cmp = {
    {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} // '+' 和 '-' 的优先级为1，'*' 和 '/' 的优先级为2
};

// 整数计算函数
void calculate(void)
{
    // 从操作数栈中弹出两个整数
    int b = intnum.top();
    intnum.pop();
    int a = intnum.top();
    intnum.pop();

    // 从运算符栈中弹出一个运算符
    char opr = op.top();
    op.pop();

    // 根据运算符进行计算
    int x;
    if (opr == '+')
        x = a + b; // 加法
    else if (opr == '-')
        x = a - b; // 减法
    else if (opr == '*')
        x = a * b; // 乘法
    else
        x = a / b; // 除法

    // 将计算结果压入操作数栈
    intnum.push(x);
}

// 浮点数计算函数
void floatcalculate(void)
{
    // 从操作数栈中弹出两个浮点数
    double b = floatnum.top();
    floatnum.pop();
    double a = floatnum.top();
    floatnum.pop();

    // 从运算符栈中弹出一个运算符
    char opr = op.top();
    op.pop();

    // 根据运算符进行计算
    double x;
    if (opr == '+')
        x = a + b; // 加法
    else if (opr == '-')
        x = a - b; // 减法
    else if (opr == '*')
        x = a * b; // 乘法
    else
        x = a / b; // 除法

    // 将计算结果压入操作数栈
    floatnum.push(x);
}

int main()
{
    // 输入表达式字符串
    string str;
    cin >> str;

    // 判断表达式是否为整数表达式
    bool isAllIntegers = true; // 默认为整数表达式
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '.') // 如果发现小数点，则为浮点数表达式
        {
            isAllIntegers = false;
            break;
        }
    }

    // 处理负数的情况（例如 "-3"）
    if (str[0] == '-')
    {
        intnum.push(-1);   // 将 -1 压入整数栈
        floatnum.push(-1); // 将 -1 压入浮点数栈
        str[0] = '*';      // 将负号替换为乘号
    }

    // 根据表达式类型（整数或浮点数）进行处理
    if (isAllIntegers) // 整数表达式
    {
        for (size_t i = 0; i < str.size(); i++)
        {
            char c = str[i];
            if (isdigit(c)) // 如果是数字
            {
                size_t j = i, x = 0;
                // 解析多位数字
                while (j < str.size() && isdigit(str[j]))
                {
                    x = x * 10 + str[j++] - '0'; // 将字符转换为整数
                }
                intnum.push(x); // 将解析的整数压入栈
                i = j - 1;      // 更新索引，由于大循环是i++，
                                // 因此需要 j - 1 迭代到下一个字符
            }
            else if (c == '(') // 如果是左括号
            {
                op.push(c);            // 压入运算符栈
                if (str[i + 1] == '-') // 处理括号内的负数
                {
                    intnum.push(-1);  // 将 -1 压入栈
                    str[i + 1] = '*'; // 将负号替换为乘号
                }
            }
            else if (c == ')') // 如果是右括号
            {
                // 弹出运算符并计算，直到遇到左括号
                while (op.size() && op.top() != '(')
                    calculate();
                op.pop(); // 弹出左括号
            }
            else // 如果是运算符
            {
                // 如果栈顶运算符优先级大于等于当前运算符，先计算栈顶运算符
                while (op.size() && cmp[op.top()] >= cmp[c])
                    calculate();
                op.push(c); // 将当前运算符压入栈
            }
        }

        // 计算剩余的运算符
        while (op.size())
            calculate();

        // 输出最终结果
        cout << intnum.top() << endl;
    }
    else // 浮点数表达式
    {
        for (size_t i = 0; i < str.size(); i++)
        {
            char c = str[i];
            if (isdigit(c)) // 如果是数字
            {
                size_t j = i;
                double x = 0; // 整数部分
                // 解析整数部分
                while (j < str.size() && isdigit(str[j]))
                {
                    x = x * 10 + str[j++] - '0';
                }

                double xx = 0;     // 小数部分
                if (str[j] == '.') // 如果有小数点
                {
                    j++;
                    // 解析小数部分
                    while (j < str.size() && isdigit(str[j]))
                    {
                        xx = xx * 10 + str[j++] - '0';
                    }
                    // 调整小数部分的值
                    while (xx >= 1)
                    {
                        xx /= 10;
                    }
                }
                x += xx;          // 将整数部分和小数部分相加
                floatnum.push(x); // 将解析的浮点数压入栈

                i = j - 1; // 更新索引
            }
            else if (c == '(') // 如果是左括号
            {
                op.push(c);            // 压入运算符栈
                if (str[i + 1] == '-') // 处理括号内的负数
                {
                    intnum.push(-1);  // 将 -1 压入整数栈
                    str[i + 1] = '*'; // 将负号替换为乘号
                }
            }
            else if (c == ')') // 如果是右括号
            {
                // 弹出运算符并计算，直到遇到左括号
                while (op.size() && op.top() != '(')
                    floatcalculate();
                op.pop(); // 弹出左括号
            }
            else // 如果是运算符
            {
                // 如果栈顶运算符优先级大于等于当前运算符，先计算栈顶运算符
                while (op.size() && cmp[op.top()] >= cmp[c])
                    floatcalculate();
                op.push(c); // 将当前运算符压入栈
            }
        }

        // 计算剩余的运算符
        while (op.size())
            floatcalculate();

        // 输出最终结果，保留3位小数
        printf("%.3f\n", floatnum.top());
    }

    return 0;
}