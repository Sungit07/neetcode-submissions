class Solution {

    public String foreignDictionary(String[] words) {

        Map<Character, List<Character>> graph = new HashMap<>();
        Map<Character, Integer> indegree = new HashMap<>();

        for (String word : words) {
            for (char c : word.toCharArray()) {
                graph.putIfAbsent(c, new ArrayList<>());
                indegree.putIfAbsent(c, 0);
            }
        }

        for (int i = 0; i < words.length - 1; i++) {

            String a = words[i];
            String b = words[i + 1];

            int len = Math.min(a.length(), b.length());
            boolean found = false;

            for (int j = 0; j < len; j++) {

                if (a.charAt(j) != b.charAt(j)) {

                    char u = a.charAt(j);
                    char v = b.charAt(j);

                    graph.get(u).add(v);
                    indegree.put(v, indegree.get(v) + 1);

                    found = true;
                    break;
                }
            }

            if (!found && a.length() > b.length()) {
                return "";
            }
        }

        Queue<Character> q = new LinkedList<>();

        for (char c : indegree.keySet()) {
            if (indegree.get(c) == 0) {
                q.offer(c);
            }
        }

        StringBuilder ans = new StringBuilder();

        while (!q.isEmpty()) {

            char c = q.poll();
            ans.append(c);

            for (char next : graph.get(c)) {

                indegree.put(next, indegree.get(next) - 1);

                if (indegree.get(next) == 0) {
                    q.offer(next);
                }
            }
        }

        if (ans.length() != indegree.size()) {
            return "";
        }

        return ans.toString();
    }
}