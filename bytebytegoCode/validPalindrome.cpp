#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsValidPalindromeStringMatch(const string& str) {
    string filtered;
    for (char c : str) {
        if (isalnum(c)) {
            filtered += tolower(c);
        }
    }
    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());
    return filtered == reversed;
}

bool IsValidPalindrome(const string&str){
    string filtered;
    int left = 0, right = str.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(str[left])) left++;
        while (left < right && !isalnum(str[right])) right--;
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool IsValidPalindrome(const vector<string>& words) {
    string combined;
    for (const string& word : words) {
        combined += word;
    }
    return IsValidPalindrome(combined);
}
int main (){
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    if(IsValidPalindrome(input)) {
        cout << "The string is a valid palindrome." << endl;
    } else {
        cout << "The string is not a valid palindrome." << endl;
    }
    return 0;
}