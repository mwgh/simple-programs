class Trie {
    private TrieNode root;

    class TrieNode {
        private final static int ALPHABET_SIZE = 26;
        private TrieNode[] children = new TrieNode[ALPHABET_SIZE];
        private boolean isEnd;

        public TrieNode get(char c) {
            return children[c - 'a'];
        }

        public void put(char c, TrieNode node) {
            children[c - 'a'] = node;
        }
        
        public boolean isEnd() {
            return isEnd;
        }
        
        public void setEnd(boolean isEnd) {
            this.isEnd = isEnd;
        }
    }

    public Trie() {
        root = createNode();
    }

    public static void main(String[] args) {
        String key = "word";
        String p = "wi";

        Trie obj = new Trie();
        obj.insert(key);
        boolean param_2 = obj.search(key);
        boolean param_3 = obj.startsWith(p);
        System.out.println("Inserted '" + key + "' in the trie");
        System.out.println("Found the key '" + key + "' in the trie: " 
                + param_2);
        System.out.println("Found the prefix '" + p + "' in the trie: " 
                + param_3);
    }
    
    public void insert(String word) {
        TrieNode current = root;
        
        for (int i = 0; i < word.length(); ++i) {
            char c = word.charAt(i);
            TrieNode next = current.get(c);

            if (next == null) {
                next = createNode();
                current.put(c, next);
            }
            current = next;
        }

        current.setEnd(true);
    }
    
    public boolean search(String word) {
        TrieNode node = searchPrefix(word);
        return node != null && node.isEnd();
    }
    
    public boolean startsWith(String prefix) {
        return searchPrefix(prefix) != null;
    }
    
    private TrieNode searchPrefix(String word) {
        TrieNode current = root;
        
        for (int i = 0; i < word.length(); ++i) {
            TrieNode next = current.get(word.charAt(i));
            
            if (next != null) {
                current = next;
            } else {
                return null;
            }
        }
        
        return current;
    }
    
    private TrieNode createNode() {
        TrieNode node = new TrieNode();
        node.setEnd(false);
        return node;
    }
}

