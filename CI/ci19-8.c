/*
19.8 Design a method to find the frequency of occurrences of any given word in a book.

SOLUTION
The first question . which you should ask your interviewer . 
is if you¡¯re just asking for a single word (¡°single query¡±) or if you might, 
eventually, use the same method for many different words (¡°repetitive queries¡±)? 
That is, are you simply asking for the frequency of ¡°dog¡±, or might you ask for ¡°dog,¡± and then ¡°cat,¡± ¡°mouse,¡± etc?

Solution: Single Query
In this case, we simply go through the book, word by word, and count the number of times that a word appears. 
This will take O(n) time. We know we can¡¯t do better than that, as we must look at every word in the book.

Solution: Repetitive Queries
In this case, we create a hash table which maps from a word to a frequency. Our code is then like this:
1 Hashtable<String, Integer> setupDictionary(String[] book) {
2 	Hashtable<String, Integer> table =
3 		new Hashtable<String, Integer>();

4 	for (String word : book) {
5 		word = word.toLowerCase();
6 		if (word.trim() != ¡°¡±) {
7 			if (!table.containsKey(word)) table.put(word, 0);
8 			table.put(word, table.get(word) + 1);
9 		}
10 	}
11 
	return table;
12 }
13
14 int getFrequency(Hashtable<String, Integer> table, String word) {
15 	if (table == null || word == null) return -1;
16 	word = word.toLowerCase();

17 	if (table.containsKey(word)) {
18 		return table.get(word);
19 	}
20 	return 0;
21 }

Note: a problem like this is relatively easy. 
Thus, the interviewer is going to be looking heavily at how careful you are. 
Did you check for error conditions?
*/


