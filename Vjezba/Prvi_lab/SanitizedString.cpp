#include <iostream>

using namespace std;

class SanitizedString {
    private:
        string str;
    public:

        SanitizedString(string str) {
            this->str = str;
        }

        void removeDuplicateWhitespace() {
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == ' ') {
                    if (str[i - 1] == ' ') {
                        str.remove(str.begin() + i);
                        i--;
                    }
                }
            }
        }

        void removeNonAlphaChars() {
            for (int i = 0; i < str.size(); i++) {
                if (!(isalpha(str[i]) || str[i] == ' ')) {
                    str.remove(str.begin() + i);
                    i--;
                }
            }
        }

        friend ostream &operator<<(ostream &os, const string str) {
            os << str;
            return os;
        }
};

int main(void) {
    string str;
    cin >> str;

    while (str != 'quit') {
        SanitizedString s1(str);
        SanitizedString s2(str);
        cout << s1.removeDuplicateWhitespace() << endl << s2.removeNonAlphaChars();
    }

    return EXIT_SUCCESS;
}