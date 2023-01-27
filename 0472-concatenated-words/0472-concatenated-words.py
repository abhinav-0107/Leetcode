class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.is_end = False

class Solution:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, root, key):
        curr = root
        for i in range(len(key)):
            idx = ord(key[i]) - ord('a')
            if not curr.children[idx]:
                curr.children[idx] = TrieNode()
            curr = curr.children[idx]
        curr.is_end = True

    def dfs(self, root, key, index, count):
        if index >= len(key):
            return count > 1
        curr = root
        for i in range(index, len(key)):
            p = ord(key[i]) - ord('a')
            if not curr.children[p]:
                return False
            curr = curr.children[p]
            if curr.is_end:
                if self.dfs(root, key, i+1, count+1):
                    return True
        return False

    def findAllConcatenatedWordsInADict(self, words):
        for i in range(len(words)):
            self.insert(self.root, words[i])
        ans = []
        for i in range(len(words)):
            if self.dfs(self.root, words[i], 0, 0):
                ans.append(words[i])
        return ans