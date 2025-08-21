#include <iostream>
using namespace std;

bool canSplitIntoThree(string s) {
    int n = s.length();
    for (int len = 1; len < n; len++) {
        string part = s.substr(0, len);
        string rest = s.substr(len);
        bool isSubstring(const string &str, const string &part) {
    int n = str.size();
    int m = part.size();
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (str[i + j] != part[j])
                break;
        }
        if (j == m)  
            return true;
    }
    return false;
}

int main() {
    string s;
    cout << "enter string: ";
    cin >> s;

    if (canSplitIntoThree(s)) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}

}
}

