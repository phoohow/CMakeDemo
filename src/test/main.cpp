#include "myadd.h"
#include "mysub.h"
#include "mymul.h"
#include "mydiv.h"
#include "myPrint.h"
#include <iostream>

using namespace std;

int main()
{
    myPrint();
    cout << "Add: 3 + 3 = " << myadd(3, 3) << endl;
    cout << "Sub: 3 - 3 = " << mysub(3, 3) << endl;
    cout << "Mul: 3 * 3 = " << mymul(3, 3) << endl;
    cout << "Div: 3 / 3 = " << mydiv(3, 3) << endl;

    return 0;
}