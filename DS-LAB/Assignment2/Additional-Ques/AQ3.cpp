nclude <iostream>
using namespace std;

bool areAnagrams(string str1, string str2) {
    if (str1.length() != str2.length()) return false;

    int count1[26] = {0};
    int count2[26] = {0};

    for (int i = 0; i < str1.length(); i++) {
        count1[str1[i] - 'a']++;
        count2[str2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) return false;
    }

    return true;
}

int main() {
    string str1, str2;
    cout << "enter first string: ";
    cin >> str1;
    cout << "enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2)) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}