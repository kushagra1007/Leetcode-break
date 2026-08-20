class Solution {
  public:
    void quickSort(vector<int>& arr, int st, int end) {
        // code here
        if(st<end){
            int pivIdx = partition(arr,st,end);
            
            quickSort(arr,st,pivIdx-1);// left half
            quickSort(arr,pivIdx,end);// right half
        }
        
    }

    int partition(vector<int>& arr, int st, int end) {
        // code here
        int idx = st-1;
        int pivot = arr[end];
        for(int j=st;j<end;j++){
            if(arr[j] <= pivot){
                idx++;
                swap(arr[j],arr[idx]);
            }
        }
        idx++;
        swap(arr[end],arr[idx]);
        return idx;
        }
};