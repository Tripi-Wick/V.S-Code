#include <iostream>
using namespace std;

class Array {
    private:
        int* array;
        int size,length,index;
    public:
        Array();
        Array(int,int);
        ~Array();
        void insert(int);
        void display();
        void sum_pair(int);
};

Array ::Array(void){
    size = 0;
    length = 0;
    index = 0;
}
Array :: Array(int s,int l){
    size = s;
    array = new int[s];
    length = l;
    index = 0;
}
Array :: ~Array(){
    delete[] array;
}
void Array :: insert(int elem){
    array[index] = elem;
    index++;
}
void Array :: display(){
    for(int i=0; i<length;i++){
        cout<<"The "<<i+1<<" element of the Array : "<<array[i]<<endl;
    }
}

void Array :: sum_pair(int req_sum){
    for(int i=0; i<length; i++){
        for(int j=i; j<length; j++){
            if(array[i]+array[j]==req_sum){
                cout<<"This pair has sum equal to "<<req_sum<<" : ["<<array[i]<<","<<array[j]<<"]"<<endl;
            }
        }
    }
}


int main()
{
    Array arr1;  

    int size,length,sum;

    cout<<"Enter the size of your array : ";
    cin>>size;
    cout<<"Enter the length of your array : ";
    cin>>length;
    cout<<"Enter the sum required  : ";
    cin>>sum;

    arr1 = Array(size,length);


    for(int i=0; i<length; i++){
        int temp;
        cout<<"Enter "<<i+1<<" Element of the Array : ";
        cin>>temp;
        arr1.insert(temp);
    }
    
    arr1.display();
    
    arr1.sum_pair(sum);

    arr1.~Array();

    return 0;
}