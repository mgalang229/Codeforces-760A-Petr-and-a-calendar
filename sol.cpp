#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, d;
	cin >> m >> d;
	vector<vector<int>> table(7, vector<int>(7));
	int cnt = 1;
	int last_day = 0;
	// Assume that the year is non-leap.
	// then, assign the last day to its corresponding month
	if (m == 2) {
		last_day = 28;
	} else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		last_day = 31;
	} else {
		last_day = 30;
	}
	int day = 1;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (cnt >= d && day <= last_day) {
				// start the days depending on the value of 'd'
				// then store the current day in every cell of the table 2-d array
				// stop storing once the 'day' variable is greater than the last day
				table[j][i] = day++;
			} else {
				// otherwise, store 0
				table[j][i] = 0;
			}
			// increment the 'cnt' variable
			cnt++;
		}
	}
	int ans = 0;
	for (int i = 0; i < 7; i++) {
		int sum = 0;
		// get the sum of every column to see if there is a day on it
		for (int j = 0; j < 7; j++) {
			sum += table[j][i];
		}
		// increment the 'ans' variable if the sum is greater than 0
		ans = (sum > 0 ? ans + 1 : ans);
	}
	cout << ans << '\n';
	return 0;
}
