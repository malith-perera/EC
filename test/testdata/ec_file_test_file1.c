#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 1; i < 5000; i++) {
        // loop through each digit in i
        // e.g. for 1000 we get 0, 0, 0, 1.
        int sum = 0;
        for (int number = i; number > 0; number /= 10) {
            int digit = number % 10;
            // find the sum of the digits
            // raised to themselves
            sum += pow(digit, digit);
        }
        if (sum == i) {
            // the sum is equal to the number
            // itself; thus it is a
            // munchausen number
            printf("%i\n", i);
        }
    }
    return 0;
}

/*# python*/
/*for i in range(5000):*/
    /*if i == sum(int(x) ** int(x) for x in str(i)):*/
        /*print(i)*/


/*function isMunchausen (n)*/
    /*local sum, nStr, digit = 0, tostring(n)*/
    /*for pos = 1, #nStr do*/
        /*digit = tonumber(nStr:sub(pos, pos))*/
        /*sum = sum + digit ^ digit*/
    /*end*/
    /*return sum == n*/
/*end*/

/*-- alternative, faster version based on the C version, */
/*-- avoiding string manipulation, for Lua 5.3 or higher*/
/*local function isMunchausen (n)*/
    /*local sum, digit, acc = 0, 0, n*/
    /*while acc > 0 do*/
        /*digit = acc % 10.0*/
        /*sum = sum + digit ^ digit*/
        /*acc = acc // 10 -- integer div*/
    /*end*/
    /*return sum == n*/
/*end*/

/*for i = 1, 5000 do*/
    /*if isMunchausen(i) then print(i) end*/
/*end*/

// code lines 11
// comment lines 37
// empty lines 12
// total lines 60
