#include <iostream>
using namespace std;

void func2(int *a, int *b){
        //PAss by reference
        int temp = *a;
        *a = *b;
        *b = temp;
    }

void func(int a, int b){
        // No change in value of a and b outside x as only copy of a and b are passed
    int temp = b; b = a; a = a = temp;
    }

int main()
{
    int x = 10, y = 5;
    
    cout << x << " " << y << "\n";
    func2(&x, &y);
    cout << x << " " << y;
    return 0;
}