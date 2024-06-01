
#include <iostream>

using namespace std;

vector<int> z_algo (string& text, string& pattern) {

	int n = text.size();

	vector<int> z_array(n);

	int l = 0;
	int r = 0;

	for (int i = 1; i < n; ++i) {

		if (i > r) {

			l = i;
			r = i;

			while (r < n && text[r] == pattern[r - l]) {
				r++;
			}
			z_array[i] = r - l;
			r--;

		} else {
			int k = i - l;

			if (z_array[k] < r - i + 1) {
				z_array[i] = z_array[k];
			} else {
				l = i;
				while (r < n && text[r] == pattern[r - l]) {
					r++;
				}
				z_array[i] = r - l;
				r--;
			}
		}

	}



	return z_array;
}

int main() {

	string pattern = "aab";
	string text = "baabaa";
	string cand = pattern + '$' + text;


	vector<int> sol = z_algo(cand, pattern);

	for (int i = 0; i < sol.size(); ++i) {
		cout<<sol[i]<<" ";
	}

	return 0;
}

