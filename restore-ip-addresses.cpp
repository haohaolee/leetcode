#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(const string &s) {
		size_t length = s.length();
		startParse<0>(&s[0], 0, length);

		return ips_;
	}

	template<int I>
	void startParse(const char* c, size_t start, size_t length)
	{
		if (length - start < 4 - I || length - start >(4 - I) * 3)
			return;

		if (checkSection(c + start, 1))
		{
			parts_[I] = 1;
			startParse<I + 1>(c, 1 + start, length);
		}

		if (checkSection(c + start, 2))
		{
			parts_[I] = 2;
			startParse<I + 1>(c, 2 + start, length);
		}

		if (checkSection(c + start, 3))
		{
			parts_[I] = 3;
			startParse<I + 1>(c, 3 + start, length);
		}

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
		if (*s == '0')
		{
			if (num == 1)
				return true;
			else
				return false;
		}

		size_t re = 0;
		size_t base = 1;
		for (const char *c = s + num - 1; c >= s; --c)
		{
			int d = *c - '0';
			re += d * base;
			base *= 10;
		}
		return re <= 255;
	}

private:
	size_t parts_[4];
	vector<string> ips_;
};

template <>
void Solution::startParse<3>(const char* c, size_t start, size_t length)
{
	if (length - start < 1 || length - start > 3)
		return;

	if (checkSection(c + start, length - start))
	{
		parts_[3] = length - start;
		addAddress(c);
	}
}

int main()
{
	string s = "255255254253";
	vector<string> v = Solution().restoreIpAddresses(s);

	for (auto const &s : v)
	{
		cout << s << '\n';
	}
	cout.flush();
}

