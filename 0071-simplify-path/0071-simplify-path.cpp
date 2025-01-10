class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size(), i = 0;
        stack<string> s;

        // Traverse the input path
        while (i < n) {
           
            // Handle '.' (current directory)
            if (path[i] == '.' && (path[i + 1] == '/' || i + 1 == n)) {
                i++;
                continue;
            }

            // Handle '..' (parent directory)
            if (path[i] == '.' && path[i + 1] == '.' && (path[i + 2] == '/' || i + 2 == n)) {
                if (!s.empty()) s.pop(); 
                i += 2;
                continue;
            }

            // Skip redundant slashes
            if (path[i] == '/') {
                i++;
                continue;
            }

            // Collect valid directory names
            string st = "";
            while (i < n && path[i] != '/') {
                st += path[i++];
            }
            s.push(st);  // Add directory to the stack
        }

       
        string ans = "";
        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        
        return ans == "" ? "/" : ans;
    }
};