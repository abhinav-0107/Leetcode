class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        """
        Time: O(n) where n is len(s2)
        Space: O(1) because s1Counter & s2Counter can have a maximum size of 26 characters (A - Z)
        """
        
        # Base case
        if len(s2) < len(s1):
            return False
        
        s1Counter, s2Counter = {}, {}
        
        # Create a counter dictionary to keep track of whatever that is in s1
        # This will be used directly to compare with the character in the window (s2Counter)
        for char in s1:
            if char not in s1Counter:
                s1Counter[char] = 0
            s1Counter[char] += 1
        
        # Starting of the window
        start = 0
        
        for end, char in enumerate(s2):
            
            # We will keep track of the characters in the window in s2Counter
            if char not in s2Counter:
                s2Counter[char] = 0
            s2Counter[char] += 1
            
            # We will only start comparing when the len(s1) fits the windowSize
            windowSize = end - start + 1
            if windowSize == len(s1):
                
                # If s1Counter == s2Counter, we have found our answer
                if s1Counter == s2Counter:
                    return True
                
                # If the current character, s2Counter[s2[start]], is equals to 1, we do not want to remove the character from our dict because the character is still in the window
                # E.g: s1 = "adc", s2 = "dcda", when the window is at "dcd", we have 2 "d"s inside the window. Hence, deleting s2Counter[s2[start]] is wrong here, we should just minus its count
                if s2Counter[s2[start]] == 1:
                    del s2Counter[s2[start]]
                else:
                    s2Counter[s2[start]] -= 1
                    
                # Move the window
                start += 1
				
        # If we have yet to find any matches, we shall return False at the end of iterating through s2
        return False
                