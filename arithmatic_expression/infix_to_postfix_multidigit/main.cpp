#include "operation.h"
#include <iostream>
using std::cout;

int main()
{
    std::string postfix = Operation::to_postfix("(12+34)*56-78/9");
    cout << postfix << '\n'; // 12 34 + 56 * 78 9 / -

    double value = Operation::evaluate_postfix(postfix);
    cout << value << '\n'; // 2567.33 (for double)

    return 0;
}

// (A+B/C*(D+E)-F) | (5+6/2*(8+4)-7)