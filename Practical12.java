import java.util.Scanner;
import java.util.ArrayList;

class Practical12{

    public static void merge(int arr[],int low,int mid,int high){
        int left = low;
        int right = mid+1;
        ArrayList<Integer> list = new ArrayList<>();
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                list.add(arr[left]);
                left++;
            }
            else{
                list.add(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            list.add(arr[left]);
            left++;
        }
        while(right <= high){
            list.add(arr[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            arr[i] = list.get(i-low);
        }
    }

    public static void mergeSort(int arr[],int low,int high){
        if(low == high){
            return;
        }
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr,low,mid,high);
    }
    public static void main(String[] args) {
        int n;
        System.out.println("Entre the length of array");
        Scanner ip = new Scanner(System.in);
        n = ip.nextInt();
        int arr[] = new int[n];
        System.out.println("Entre elements in the array");
        for(int i=0;i<n;i++){
            arr[i] = ip.nextInt();
        }

        mergeSort(arr,0,n-1);

        System.out.println("Sorted array is :");
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+"  ");
        }
        ip.close();
    }
}