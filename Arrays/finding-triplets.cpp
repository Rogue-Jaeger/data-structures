// https://practice.geeksforgeeks.org/problems/triplet-family/1

vector<int> findTriplet(int arr[], int n)
{
    vector<int> result;
    map <int , int> num;

    for(int i = 0; i< n ; i++){
        num[arr[i]]++;
    }

    for(int i = 0; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            int reqsum = arr[i] + arr[j];
            if( num.find(reqsum) != num.end() ) {
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                result.push_back(reqsum);
                goto oops;
            }
        }
    }

    oops : return result;
}
