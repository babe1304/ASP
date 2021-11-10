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
                        str.erase(str.begin() + i);
                        i--;
                    }
                }
            }
        }

        void removeNonAlphaChars() {
            for (int i = 0; i < str.size(); i++) {
                if (!(isalpha(str[i]) || str[i] == ' ')) {
                    str.erase(str.begin() + i);
                    i--;
                }
            }
        }
 
        friend ostream &operator<<(ostream &os, const SanitizedString &str);
};

ostream &operator<<(ostream &os, const SanitizedString &str) {
            os << str.str;
            return os;
}

int main(void) {
    SanitizedString s1("Sunce     nam      dolazi!");
    SanitizedString s2("M~ir4ko&");
    s1.removeDuplicateWhitespace();
    s2.removeNonAlphaChars();

    cout << s1 << endl << s2 << endl;

    return EXIT_SUCCESS;
}