class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector grid(n, vector(n, 0)); // Initialize the grid
        for (int cur = 1, x = 0, y = 0, dx = 0, dy = 1; cur <= n * n; x += dx, y += dy) {
            // Check boundaries or if cell is already filled
            if (max(x, y) >= n || min(x, y) < 0 || grid[x][y] != 0) {
                x -= dx; // Step back
                y -= dy;
                swap(dx, dy); // Change direction
                dx *= -1; // Rotate clockwise
            } else {
                grid[x][y] = cur++; // Fill the current cell
            }
        }
        return grid;
    }
};