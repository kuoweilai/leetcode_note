
#include <iostream>

using namespace std;

// a a b c a a b x a a z
// a a b c a a b x a a z
// 0 1 0 0 3 1 0 0 2 1 0

vector<int> z_algo (string& text) {

	int n = text.size();

	vector<int> z_array(n);

	int l = 0;
	int r = 0;

	for (int i = 1; i < n; ++i) {

		if (i > r) {

			l = i;
			r = i;

			while (r < n && text[r] == text[r - l]) {
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
				while (r < n && text[r] == text[r - l]) {
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


	vector<int> sol = z_algo(cand);

	for (int i = 0; i < sol.size(); ++i) {
		cout<<sol[i]<<" ";
	}

	return 0;
}

