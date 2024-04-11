class Solution {
public:
    bool isNumber(string s) {
                int i = 0;
        int n = s.length();

        // Trim leading whitespace
        while (i < n && isspace(s[i])) i++;

        // Check for optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        bool hasDigits = false; // Flag if any digits are present
        bool hasDot = false; // Flag if a decimal point is present

        // Check for digits before the decimal point
        while (i < n && isdigit(s[i])) {
            i++;
            hasDigits = true;
        }

        // Check for decimal point
        if (i < n && s[i] == '.') {
            i++;
            hasDot = true;

            // Check for digits after the decimal point
            while (i < n && isdigit(s[i])) {
                i++;
                hasDigits = true;
            }
        }

        // If no digits were present before and after the decimal point, return false
        if (!hasDigits) return false;

        // Check for exponent part
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            hasDigits = false; // Reset for exponent digits

            // Check for optional sign in exponent
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;

            // Check for digits in exponent
            while (i < n && isdigit(s[i])) {
                i++;
                hasDigits = true;
            }

            // If no digits in exponent, return false
            if (!hasDigits) return false;
        }

        // Trim trailing whitespace
        while (i < n && isspace(s[i])) i++;

        // If we reached the end of the string, it's a valid number
        return i == n;
    }
};