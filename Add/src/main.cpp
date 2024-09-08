#include <iostream>
#include <string>
#include <vector>

using namespace std;

string eraseZero(string str) {

	for (auto iter = str.begin(); *iter == '0'; iter = str.erase(iter))
		continue;

	return str;
}

string hp_add(string a, string b) {

	auto len = a.size() > b.size() ? a.size() : b.size();

	vector<int> x(len, 0), y(len, 0);

	for (int i = 0; i < a.size(); i++) {
		x[i] = a[a.size() - i - 1] - '0';
	}
	for (int i = 0; i < b.size(); i++) {
		y[i] = b[b.size() - i - 1] - '0';
	}

	vector<int> ans(len + 1, 0);

	for (int i = 0; i < len; i++) {

		ans[i] += x[i] + y[i];

		if (ans[i] >= 10) {
			ans[i + 1]++;
			ans[i] %= 10;
		}
	}

	string result(ans.size(), '0');

	for (int i = 0; i < ans.size(); i++) {
		result[i] = ans[len - i] + '0';
	}

	return eraseZero(result);
}

int main(void) {
	string a, b;
	cin >> a >> b;

	cout << "\n" << hp_add(a, b) << endl;
	return 0;
} 