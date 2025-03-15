#include <iostream>
using namespace std;

void convertFahrenheit(int c)
{
    float f = (9 * c) / 5;
    f += 32;
    cout << "Temperature in Fahrenheit: " << f;
}

int main()
{
    float c;
    cout << "Enter temperature in Celsius: ";
    cin >> c;
    convertFahrenheit(c);
    return 0;
}