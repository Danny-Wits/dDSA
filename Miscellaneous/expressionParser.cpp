#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
const vector<char> operators = {'+', '-', '*', '/', '%'};
const bool debug = true;
float solve(string);
// Helpers :
bool isOperator(char c)
{
    for (auto &o : operators)
    {
        if (c == o)
            return true;
    }
    return false;
}
int isBrace(char c)
{
    return (c == '(' ? 1 : (c == ')' ? -1 : 0));
}
void print(vector<string> v)
{
    for (auto &&i : v)
    {
        cout << i << ", ";
    }
    cout << "\n";
}
string join(vector<string> v, int start, int end)
{
    string s;
    for (int i = start; i < end; i++)
    {
        s += v[i];
    }
    return s;
}
float calculate(float op1, float op2, char op)
{
    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        if (op2 == 0)
            throw runtime_error("Division by zero");
        return op1 / op2;
    case '%':
        return (int)op1 % (int)op2;
    default:
        return 0;
    }
}
// Parser :
vector<string> parse(string expression)
{
    vector<string> parsedList;
    string operand;
    for (char c : expression)
    {
        if (c == ' ')
        {
            continue;
        }
        if (isBrace(c))
        {
            if (operand.size() > 0)
                parsedList.push_back(operand);
            parsedList.push_back(string(1, c));
            operand.clear();
        }
        else if (isOperator(c))
        {
            if (c == '-' && operand.size() == 0)
            {
                operand.push_back(c);
            }
            else
            {
                if (operand.size() > 0)
                    parsedList.push_back(operand);
                parsedList.push_back(string(1, c));
                operand.clear();
            }
        }
        else
        {
            operand.push_back(c);
        }
    }
    if (operand.size() > 0)
        parsedList.push_back(operand);
    return parsedList;
}
// Solver:
void resolveBraces(vector<string> &parsedList)
{
    vector<int> stack;

    for (int i = 0; i < parsedList.size(); i++)
    {
        string &s = parsedList[i];
        if (isBrace(s[0]) == 1)
        {
            stack.push_back(i);
        }
        else if (isBrace(s[0]) == -1)
        {
            if (stack.size() != 0)
            {
                int j = stack.back();
                stack.pop_back();
                string inner_expression = join(parsedList, j + 1, i);
                float result = solve(inner_expression);
                parsedList[j] = to_string(result);
                parsedList.erase(parsedList.begin() + j + 1, parsedList.begin() + i + 1);
                i = j;
                if (debug)
                {
                    cout << "resolving () :" << inner_expression << "\n";
                    cout << "Evaluated it to " << result << "\n";
                    cout << "List : ";
                    print(parsedList);
                }
            }
        }
    }
}
float compute(vector<string> parsedList)
{

    if (debug)
        print(parsedList);
    resolveBraces(parsedList);
    int precedence = operators.size() - 1;
    for (int p = precedence; p >= 0; p--)
    {
        for (int i = 0; i < parsedList.size(); i++)
        {
            const string op = parsedList[i];
            if (op.size() == 1 && op[0] == operators[p])
            {
                float op1 = stof(parsedList[i - 1]);
                float op2 = stof(parsedList[i + 1]);
                float result = calculate(op1, op2, op[0]);
                parsedList[i - 1] = to_string(result);
                parsedList.erase(parsedList.begin() + i);
                parsedList.erase(parsedList.begin() + i);
                i--;
                if (debug)
                    print(parsedList);
            }
        }
    }
    return stoi(parsedList[0]);
}
float solve(string s)
{
    return compute(parse(s));
}

//? Old version :
vector<string> parserPostOrder(string expression)
{
    vector<string> parsedList;
    string operand;
    for (char c : expression)
    {
        if (c == ' ')
        {
            continue;
        }

        if (isOperator(c))
        {
            parsedList.push_back(string(1, c));
            parsedList.push_back(operand);
            operand.clear();
            continue;
        }
        operand.push_back(c);
    }
    parsedList.push_back(operand);
    reverse(parsedList.begin(), parsedList.end());
    return parsedList;
}
int computeWithoutPrecedence(vector<string> parsedListPostOrder)
{
    float op1, op2;
    bool op1Used = false;
    for (auto &&op : parsedListPostOrder)
    {
        if (isOperator(op[0]))
        {
            op1 = calculate(op1, op2, op[0]);
        }
        else if (!op1Used)
        {
            op1 = stoi(op);
            op1Used = true;
        }
        else
            op2 = stoi(op);
    }
    return op1;
}
int main()
{
    // cout << computeWithoutPrecedence(parserPostOrder("1+2+3*2+1"));
    struct TestCase
    {
        const char *expr;
        int expected;
    };

    // Test cases are AI generated to save time;
    vector<TestCase> testCases = {

        // ---- Literals ----
        {"0", 0},
        {"5", 5},
        {"10", 10},

        // ---- Addition ----
        {"1+2", 3},
        {"1+2+3", 6},
        {"10+20+30", 60},

        // ---- Subtraction ----
        {"5-2", 3},
        {"10-3-2", 5}, // left associativity: (10-3)-2
        {"20-5-5-5", 5},

        // ---- Multiplication ----
        {"2*3", 6},
        {"2*3*4", 24},
        {"5*4*3", 60},

        // ---- Division ----
        {"4/2", 2},
        {"20/5", 4},
        {"100/10/2", 5}, // left associativity: (100/10)/2

        // ---- Mixed precedence ----
        {"1+2*3", 7},
        {"2+3*4", 14},
        {"10-2*3", 4},
        {"20/5+3", 7},
        {"20-10/5", 18},

        // ---- Mixed * and / ----
        {"8/2*2", 8},  // left assoc: (8/2)*2
        {"16/4/2", 2}, // left assoc
        {"10*2/5", 4},

        // ---- Full mixed expressions ----
        {"1+2+3*2+1", 10},
        {"1+2*3+4*2+1", 16},
        {"1+2+3*2+4*2+5*3+6*2+1", 45},
        {"10+20/5*3-4", 18}, // 20/5=4 → 4*3=12 → 10+12-4

        // ---- Edge behavior ----
        {"1/1", 1},
        {"0+5*3", 15},
        {"50-20/2", 40},
        // ---- Single negative values ----
        {"-1", -1},
        {"-5", -5},
        {"-10", -10},

        {"-4/2", -2},
        {"4/-2", -2},
        {"-4/-2", 2},
        {"-10/5+1", -1},

        {"-1+2+3*2+-1", 6},   // 3*2=6 → -1+2+6-1
        {"1+-2*3+4", -1},     // -2*3=-6
        {"-1+-2*-3", 5},      // -2*-3=6
        {"-10+20/-5*2", -18}, // 20/-5=-4 → -4*2=-8
        {"5*-2+-3*4", -22},   // -10 + -12
        {"2*(2+-3)+(3+2)*2", 8},

        {"(2+3)*4", 20},
        {"2*(3+4)", 14},
        {"(2+3)*(4+5)", 45},
        {"((2+3)*4)+5", 25},
        {"2+((3+4)*5)", 37},
        {"(2+(3*4))*5", 70},
        {"((2+3)+(4+5))*2", 28},
        {"2*((3+4)*5)", 70},

        {"(-1*(2+3))*4", -20},
        {"2*(-1*(3-4))", 2},
        {"(-1*2)*(3+4)", -14},
        {"(-1*(2+(-1*3)))*4", 4},

        {"2*(2+-3)", -2},
        {"2*(-1*(3-5))", 4},
        {"(2+-3)*(4+-5)", 1},
        {"((2+-3)+4)*5", 15},

        {"(2*(3+4))+(5*(6-2))", 34},
        {"((2+3)*4)-(6/(1+2))", 18},
        {"(2+3)*(4-(1+1))", 10},

        {"(((((2)))))", 2},
        {"((2+3))*(4)", 20},
        {"((2+3)*(4+1))", 25},

        {"(2+(3+(4+(5))))", 14},
        {"(((2+3)+4)+5)", 14},
        {"2*(3+(4*(5-2)))", 30},

    };
    for (auto &t : testCases)
    {
        cout << "------------------------\n";
        assert(solve(t.expr) == t.expected && "Failed");
        cout << "------------------------\n";
    }
    cout << "All tests passed\n";
    // cout << compute(parse("-1"));
    // cout << compute(parse("2*(2+-3)+(3+2)*2"));

    // print(parse("-1"));
    return 0;
}