#include <iostream>
using namespace std;

int main() {
    int n;
    freopen("asc_chr_78.txt", "r", stdin);
    clock_t start = clock();
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        char key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    clock_t end = clock();
    double elapsed = double(end - start)/CLOCKS_PER_SEC;
    cout<<elapsed;
    /*for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }*/
    return 0;
}