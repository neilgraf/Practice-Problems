// Count Dropped Requests
// Learn this problem
// ● EasyJPMorgan Chase logoJPMorgan Chase
// FULLTIME
// OA
// Problem statement
// A server maintains a pool of processing threads. The input array describes events in chronological order.
// A positive value adds that many threads to the pool.
// -1 means a request arrives.
// Each thread can serve at most one request and is then destroyed. If a request arrives when no threads are available, that request is dropped.
// Return the number of dropped requests.
// Function
// countDroppedRequests
// (server: int[]) → int
// Examples
// Example 1
// server = [1, -1, -1, 1]
// return
//  = 1
// The first request consumes the only available thread. The second request arrives when the pool is empty, so it is dropped.
// Constraints
// 1 <= n <= 10^5
// server[i] = -1 or 1 <= server[i] <= 10^4

// Completed

class Solution {
public:
  int countDroppedRequests(vector<int> server) {
    int thread = 0;
    int droppedRequest = 0;

    for(size_t i = 0; i < server.size(); ++i){
      if(server[i] > 0){
        thread += server[i];
      }
      else if (server[i] == -1 && thread == 0){
        droppedRequest++;
      }
      else{
        thread--;
      }
    }
    return droppedRequest;
  }
};
