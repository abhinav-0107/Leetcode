function longestValidParentheses(s: string): number {
        let maxLen = 0;
    const stack: number[] = [-1]; // Initialize stack with -1 to handle the edge case for the first valid substring

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            // Push the index of the '(' onto the stack
            stack.push(i);
        } else {
            // Pop the stack for the matching '('
            stack.pop();
            if (stack.length > 0) {
                // Calculate the length of the current valid substring
                maxLen = Math.max(maxLen, i - stack[stack.length - 1]);
            } else {
                // If the stack is empty, push the current index as a new base
                stack.push(i);
            }
        }
    }

    return maxLen;
};