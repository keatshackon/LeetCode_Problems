//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    
        vector<int> topoSort(int n, vector<int>g[]) {
    
        	vector<int>indegree(n, 0);
        
        	for (int i = 0; i < n; i++) {
        		for (auto q : g[i]) {
        			indegree[q]++;
        		}
        	}
        
        	// CAN USE PRIORITY QUEUE IF WE WANT LEXOGRAPHICAL ORDER.
        	queue<int>q;
        	for (int i = 0; i < n; i++) {
        		if (indegree[i] == 0) {
        			q.push(i);
        		}
        	}
        
        	vector<int>ans;
        
        	while (!q.empty()) {
        		int temp = q.front();
        		q.pop();
        		ans.push_back(temp);
        
        		for (auto it : g[temp]) {
        			indegree[it]--;
        			if (indegree[it] == 0) {
        				q.push(it);
        			}
        		}
        	}
        	
        	return ans;
        }
    
    string findOrder(string dict[], int N, int K) {
        
        
        vector<int>g[K];
        
        for(int i = 0;i < N-1 ;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            
            int len = min(s1.length(),s2.length());
            
            for(int k = 0;k < len;k++){
                if(s1[k] != s2[k]){
                    g[s1[k] - 'a'].push_back(s2[k] - 'a');
                    break;
                }
            }
        }
        
        vector<int>res = topoSort(K,g);
        string ans = "";
        
        for(auto q:res){
            ans += char(q + 'a');
        }
        
        return ans;
    
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends