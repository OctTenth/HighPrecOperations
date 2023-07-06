#include <iostream>
#include <string>
#include <vector>

using namespace std;

string eraseZero(string str) {
	for (auto iter = str.begin(); *iter == '0'; iter = str.erase(iter))
		continue;

	return str;
}

string hp_minus(string a, string b) {

	auto len = a.size() > b.size() ? a.size() : b.size();
	bool isNegative = false;

	vector<int> x(len, 0), y(len, 0);

	for (int i = 0; i < a.size(); i++) {
		x[i] = a[a.size() - i - 1] - '0';
	}
	for (int i = 0; i < b.size(); i++) {
		y[i] = b[b.size() - i - 1] - '0';
	}

	if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
		swap(x, y);
		isNegative = true;
	}

	x.resize(len + 1);

	for (int i = 0; i < len; i++) {

		x[i] = x[i] - y[i];

		if (x[i] < 0) {
			x[i + 1]--;
			x[i] += 10;
		}
	}

	string result(x.size(), '0');

	for (int i = 0; i < x.size(); i++) {
		result[i] = x[len - i] + '0';
	}

	if (isNegative)
		return "-" + eraseZero(result);
	else
		return eraseZero(result);
}

int main(void) {
	string a, b;
	cin >> a >> b;

	cout << "\n" << hp_minus(a, b) << endl;
	return 0;
}