class Graph {
    private Map<String, List<String>> adjList;

    public Graph() {
        this.adjList = new HashMap<>();
    }

    public void addNode(String node) {
        adjList.putIfAbsent(node, new ArrayList<>());
    }

    public void addEdge(String source, String destination) {
        adjList.get(source).add(destination);
        adjList.get(destination).add(source); 
    }

    public List<String> getNeighbors(String node) {
        List<String> neighbors = adjList.get(node);
        return neighbors != null ? neighbors : Collections.emptyList();
    }

    public void printGraph() {
        for (Map.Entry<String, List<String>> entry : adjList.entrySet()) {
            System.out.print(entry.getKey() + " -> ");
            System.out.println(entry.getValue());
        }
    }

    public List<String> shortestPathBFS(String source, String destination) {
        Map<String, String> parentMap = new HashMap<>();
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.add(source);
        visited.add(source);

        while (!queue.isEmpty()) {
            String current = queue.poll();

            for (String neighbor : getNeighbors(current)) {
                if (!visited.contains(neighbor)) {
                    queue.add(neighbor);
                    visited.add(neighbor);
                    parentMap.put(neighbor, current);

                    if (neighbor.equals(destination)) {
                        // Destination reached, reconstruct the path
                        List<String> path = new ArrayList<>();
                        String reconstructNode = destination;

                        while (reconstructNode != null) {
                            path.add(reconstructNode);
                            reconstructNode = parentMap.get(reconstructNode);
                        }

                        Collections.reverse(path);
                        return path;
                    }
                }
            }
        }

        // No path found
        return Collections.emptyList();
    }
}
