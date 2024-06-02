
#include <iostream>

using namespace std;

// a b a b c
// 0 0 1 2 0

// a b a a b a b a b c a
//       x    
//               x 
//                   v


vector<int> build_next(string& pattern) {

	int n = pattern.size();

	vector<int> next(n , 0);

	int i = 1;
	int prefix_len = 0;

	while (i < n) {
		if (pattern[prefix_len] == pattern[i]) {
			prefix_len++;
			next[i] = prefix_len;
			i++;
		} else {
			if (prefix_len == 0) {
				next[i] = 0;
				i++;
			} else {
				prefix_len = next[prefix_len - 1];
			}
			
		}

	}

	return next;

}


vector<int> kmp(string& text, string& pattern) {

	int n = text.size();

	vector<int> next = build_next(pattern);

	vector<int> ans;

	int i = 0;
	int j = 0;

	while (i < n) {

		if (text[i] == pattern[j]) {
			i++;
			j++;
		} else if (j > 0) {
			j = next[j - 1];
		} else {
			i++;
		}

		if (j == pattern.size()) {
			ans.push_back(i - j);
		}

	}


	return ans;
}


int main() {

	string pattern = "ababc";
	string text = "abaabababca";
	

	vector<int> sol = kmp(text, pattern);

	for (int i = 0; i < sol.size(); ++i) {
		cout<<sol[i]<<" ";
	}

	return 0;
}