//   int maxProf = 0;
//         int profit = 0;
//         int n = prices.size();
//         for(int i=0; i<n-1; i++){
//             int buy = prices[i];
//             for(int j=i+1; j<n; j++){
//                 profit = prices[j] - buy;
//                 maxProf = max(maxProf, profit);
//             }
//         }

//         return maxProf;