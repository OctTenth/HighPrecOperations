#include <iostream>
#include <string>
#include <vector>

using namespace std;

string eraseZero(string str) {

	for (auto iter = str.begin(); *iter == '0'; iter = str.erase(iter))
		continue;

	return str;
}

string hp_multiply(string a, string b) {

	auto len = a.size() + b.size();

	vector<int> x(a.size(), 0), y(b.size(), 0);

	for (int i = 0; i < a.size(); i++) {
		x[i] = a[a.size() - i - 1] - '0';
	}
	for (int i = 0; i < b.size(); i++) {
		y[i] = b[b.size() - i - 1] - '0';
	}

	vector<int> ans(len, 0);

	for (int i = 0, carry = 0; i < x.size(); i++) {
		carry = 0;
		for (int j = 0; j < y.size(); j++) {
			ans[i + j] += x[i] * y[j] + carry;
			carry = ans[i + j] / 10;
			ans[i + j] %= 10;
		}
		ans[y.size() + i] += carry;
	}

	string result(ans.size(), '0');

	for (int i = 0; i < ans.size(); i++) {
		result[i] = ans[len - i - 1] + '0';
	}

	return eraseZero(result);
}

int main(void) {
	string a, b;
	cin >> a >> b;

	cout << "\n" << hp_multiply(a, b) << endl;
	return 0;
}