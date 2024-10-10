// Vector object with dynamic dimensions
// static variables, static member variables
// Generic Programming = Templates in C++
// const keyword
// curly bracket usage for deeper lower scopes

// auto, AAA rule (almost always auto)

#include <iostream>


template <typename T>
struct Vector {
    T* data;
    const int size;

    Vector(int size) : size(size), data(new T[size]) {
        for(int i=0; i<size; i++) {
            // *(data + i) = i;
            // *(i + data) = i;
            // i[data] = i;
            data[i] = i * 1.1f;
        }
    }

    ~Vector() {
        delete[] data;
    }

    void print(/*const IntVector* iv*/) const {
        for(int i=0; i<this->size; i++) {
            std::cout << this->data[i];
            if(i != this->size-1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }
};


template<typename T>
void print(const Vector<T>* iv) {

    for(int i=0; i<iv->size; i++) {
        std::cout << iv->data[i];
        if(i != iv->size-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}



template<typename T>
void print_cppway(const Vector<T>& iv) {
    static int print_cppway_counter = 0;
    if(print_cppway_counter == 0)
        std::cout << "I will be printing my first thing, heyoo" << std::endl;
    print_cppway_counter++;

    for(int i=0; i<iv.size; i++) {
        std::cout << iv.data[i];
        if(i != iv.size-1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}


int main(int argc, char* argv[])
{
    // iv is on stack memory
    // the object is already the iv itself!
    // its content data is on heap
    auto iv = Vector<int>(5);

    // iv_heap is on stack memory
    // the object is on heap
    // its content data is on heap
    auto* iv_heap = new Vector<float>(7);

    // print(iv_heap);

    iv.print();
    print(&iv);
    print_cppway(iv);
    print_cppway(iv);
    print_cppway(iv);
    print_cppway(iv);
    iv_heap->print();


    delete iv_heap; // calls the destructor automatically
    // there is 1 IntVector live

    return 0;
}
