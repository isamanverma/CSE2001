#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string input;

    cout << "Enter a word: ";
    cin >> input;

    sort(input.begin(), input.end());

    cout << "The word in alphabetical order: " << input << endl;

    return 0;
}