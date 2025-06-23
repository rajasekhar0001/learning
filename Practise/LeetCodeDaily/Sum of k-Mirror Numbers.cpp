// Focus on undersyanding the generatePalindromes function, which is required to generate,
// k shortest palindromes from 1 to n

class Solution {
    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res = char('0' + num % k) + res;
            num /= k;
        }
        return res;
    }

    // Generates palindromes in base 10 by mirroring half the number
    void generatePalindromes(int len, vector<long long>& pals) {
        int start = pow(10, (len - 1) / 2);
        int end = pow(10, (len + 1) / 2);

        for (int i = start; i < end; i++) {
            string s = to_string(i);
            string rev = s;
            if (len % 2 == 1) rev.pop_back();
            reverse(rev.begin(), rev.end());
            string palStr = s + rev;
            pals.push_back(stoll(palStr));
        }
    }

public:
    long long kMirror(int k, int n) {
        long long sum = 0;
        int len = 1;
        int count = 0;

        while (count < n) {
            vector<long long> palindromes;
            generatePalindromes(len, palindromes);

            for (long long val : palindromes) {
                if (isPalindrome(toBaseK(val, k))) {
                    sum += val;
                    count++;
                    if (count == n) return sum;
                }
            }
            len++;
        }

        return sum;
    }
};