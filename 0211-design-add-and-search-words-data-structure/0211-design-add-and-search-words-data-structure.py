class WordDictionary:

    def __init__(self):
        self.trie = dict()

    def addWord(self, word: str) -> None:
        node = self.trie
        for ch in word + '\U0001f33b':
            if ch not in node:
                node[ch] = dict()

            node = node[ch]

    def search(self, word: str) -> bool:
        nodes = [self.trie]
        for ch in word + '\U0001f33b':
            newNodes = []
            for node in nodes:
                if ch == '.': 
                    newNodes += [v for v in node.values()]
                elif ch in node: 
                    newNodes.append(node[ch])

            if not newNodes:
                return False

            nodes = newNodes
            
        return True
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)