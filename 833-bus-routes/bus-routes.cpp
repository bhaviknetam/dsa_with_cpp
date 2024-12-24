class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.size();  // Number of bus routes
        unordered_map<int, vector<int>> stopToRoutes; // Map stops to routes

        // Build the stop-to-routes map
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        // Perform BFS over bus routes
        queue<pair<int, int>> q; // {routeIndex, busesTaken}
        vector<bool> visitedRoutes(n, false);
        unordered_set<int> visitedStops; // To prevent revisiting stops

        // Add all routes passing through the source stop
        for (int route : stopToRoutes[source]) {
            q.push({route, 1});
            visitedRoutes[route] = true;
        }
        visitedStops.insert(source);

        while (!q.empty()) {
            int route = q.front().first;
            int busesTaken = q.front().second;
            q.pop();

            for (int stop : routes[route]) {
                if (stop == target) return busesTaken;

                // For each stop in this route, process its connecting routes
                if (visitedStops.find(stop) == visitedStops.end()) {
                    visitedStops.insert(stop);

                    for (int nextRoute : stopToRoutes[stop]) {
                        if (!visitedRoutes[nextRoute]) {
                            q.push({nextRoute, busesTaken + 1});
                            visitedRoutes[nextRoute] = true;
                        }
                    }
                }
            }
        }

        return -1; // Target is unreachable
    }
};
