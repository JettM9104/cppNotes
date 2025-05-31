#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

// Levenshtein Distance function
int levenshtein_distance(const string& s1, const string& s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) dp[i][0] = i;
    for (int j = 0; j <= n; j++) dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
        }
    }
    return dp[m][n];
}

// Load dictionary from file into a set
unordered_set<string> load_dictionary(const string& filename) {
    unordered_set<string> dict;
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open dictionary file.\n";
        exit(1);
    }
    string word;
    while (file >> word) {
        dict.insert(word);
    }
    return dict;
}

// Autocorrect function: find closest words by Levenshtein distance
vector<string> autocorrect(const string& input, const unordered_set<string>& dict, int max_distance = 2) {
    vector<string> suggestions;
    int min_distance = numeric_limits<int>::max();

    for (const string& word : dict) {
        int dist = levenshtein_distance(input, word);
        if (dist < min_distance && dist <= max_distance) {
            suggestions.clear();
            suggestions.push_back(word);
            min_distance = dist;
        }
        else if (dist == min_distance) {
            suggestions.push_back(word);
        }
    }
    return suggestions;
}

int main() {
    string input;
    cout << "Enter a word to autocorrect: ";
    cin >> input;

    auto dictionary = load_dictionary("words.txt");
    auto suggestions = autocorrect(input, dictionary);

    if (suggestions.empty()) {
        cout << "No close matches found.\n";
    } else {
        cout << "Did you mean:\n";
        for (const string& w : suggestions) {
            cout << " - " << w << '\n';
        }
    }
    return 0;
}
