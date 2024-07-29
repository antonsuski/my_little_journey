#include<iostream>
#include<iomanip>

// here we get reference to pointer for seeing actual pointer address
// instaed local local pointer coppy address
bool print_ptr(int* ref_ptr){
    using namespace std;

    cout << "printed with function:\n";
    cout << setw(10) << "address:" << ref_ptr << '\n';
    cout << setw(10) << "value:" << *ref_ptr << '\n';

    return cout.good();
}

int main(int argc, char**argv){
    using std::cout;
    using std::setw;
    using std::endl;

    int one {1};
    void * ptr_to_int{&one};
    // you can't dereference void pointers, it's illegal
    //cout << *ptr_to_int << endl;
    // before derefernce of void pointer you have to cast it to target type
    cout << *static_cast<int*>(ptr_to_int) << endl;

    // you can invode direct or uniform or any kind of initialization.
    int *lenth = new int{};
    *lenth = 10;

    cout << setw(10) << "address:" << lenth << '\n';
    // be carefull while dereferecing deleted or dungling pointer it's undefined behaivor
    cout << setw(10) << "value:" << *lenth << '\n';
    print_ptr(lenth);

    int* null_ptr {new int{7}};

    // by default new can throw an expetion std::bad_alloc to stop it you have to pass std::nothrow
    // object, then new will return nullptr in case of fail.
    int *squares = new(std::nothrow) int[4]{1,2,4,8};

    if(squares){
        for(size_t i {}; i < 4; i++){
            cout << '[' << i << ']';
        }
        cout << '\n';
    }

    cout << "\nmatrix 2 x 2:\n";
    // one way to alloc 2 dementional memmory is to allocate array of pointers and then go through all
    // of them and alllcate arry for each pointer
    double** mat2x2 = new(std::nothrow) double*[2];
    if(mat2x2){
        for(size_t i {}; i < 2; i++){
            mat2x2[i] = new(std::nothrow) double[2]{i,i + 1};
        }
    }
    for(size_t i {}; i < 2; i++){
        for(size_t j{}; j < 2; j++){
            cout << '[' << mat2x2[i][j] << ']' ;
        }
        cout << '\n';
    }

    // delete part
    delete lenth;

    delete null_ptr;
    null_ptr = nullptr;
    // deletting nullptr is safety unlike making double delete it is undefined behaivor
    delete null_ptr;

    delete[] squares;

    // for deleteing multi dementional structures you have to make it
    // from the last dementional to the first one
    for(size_t i {}; i < 2; i++){
        delete[] mat2x2[i];
    }
    delete[] mat2x2;
}
