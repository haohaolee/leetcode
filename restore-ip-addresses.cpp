#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(const string &s) {
        size_t length = s.length();
        startParseFirst(&s[0], 0, length);

        return ips_;
    }

    void startParseFirst(const char* c, size_t start, size_t length)
    {
        if (length - start < 4 || length - start > 12)
            return;

        parts_[0] = 1;
        startParseSecond(c, 1 + start, length);

        parts_[0] = 2;
        startParseSecond(c, 2 + start, length);

        if (checkSection(c, 3))
        {
            parts_[0] = 3;
            startParseSecond(c, 3 + start, length);
        }
    }

    void startParseSecond(const char* c, size_t start, size_t length)
    {
        if (length - start < 3 || length - start > 9)
            return;

        parts_[1] = 1;
        startParseThird(c, 1 + start, length);

        parts_[1] = 2;
        startParseThird(c, 2 + start, length);

        if (checkSection(c + start, 3))
        {
            parts_[1] = 3;
            startParseThird(c, 3 + start, length);
        }
    }

    void startParseThird(const char* c, size_t start, size_t length)
    {
        if (length - start < 3 || length - start > 6)
            return;

        parts_[2] = 1;
        startParseFourth(c, 1 + start, length);

        parts_[2] = 2;
        startParseFourth(c, 2 + start, length);
        
        if (checkSection(c + start, 3))
        {
            parts_[2] = 3;
            startParseFourth(c, 3 + start, length);
        }
    }

    void startParseFourth(const char* c, size_t start, size_t length)
    {
        if (length - start == 0 || length - start > 3)
            return;

        if (length - start == 3 && !checkSection(c, 3))
            return;

        parts_[3] = length;

        addAddress(c);
    }

    void addAddress(const char* c)
    {
        string s;
        s.reserve(16);
        char const *f = c;  char const *l = f + parts_[0];
        s += string(f, l);
        s += '.';

        f = l; l = f + parts_[1];
        s += string(f, l);
        s += '.';

        f = l; l = f + parts_[2];
        s += string(f, l);
        s += '.';

        f = l; l = f + parts_[3];
        s += string(f, l);

        ips_.push_back(s);
    }

    bool checkSection(const char* s, size_t num)
    {
        size_t re = 0;
        for (size_t i = num; i > 0; --i, ++s)
        {
            int d = *s - '0';
            re += d * num * 10;
        }
        return re <= 255;
    }

private:
    size_t parts_[4];
    vector<string> ips_;
};


int main()
{
    string s = "255255254253";
    vector<string> v = Solution().restoreIpAddresses(s);

    for(auto const &s : v)
    {
        cout << s << '\n';
    }
    cout.flush();
}

