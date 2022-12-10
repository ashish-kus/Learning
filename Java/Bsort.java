public class Bsort{

  public static void bubblesort(int array[], int size){
    for(int i=0; i<size-1; i++){

      for(int j=0; j<size-i-1;j++){
        if(array[j+1]<array[j]){
        int temp=array[j+1];
        array[j+1]=array[j];
        array[j]=temp;
      }
      }
    }
  }


  public static void main(String[] arg){
    int array[]={1, 5,2,6,3,4,8,7,0,9};
    int size= array.length;
bubblesort(array,size);

    for(int i = 0; i<size; ++i){
            System.out.print(array[i] + " ");
        }

  }
}
