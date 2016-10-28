#include <iostream>

template <typename T>

class UniquePtr {
    
  public:
    UniquePtr(T* ptr) : ptr_(ptr) {
    }
    ~UniquePtr() {
        if (ptr_) {
            delete ptr_;
        }
    }
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr& operator = (const UniquePtr &) = delete;

    T& operator *() {
        return *ptr_;
    }

    const T& operator *() const {
        return *ptr_;
    }

    T& operator ->() {
        return ptr_;
    }

    const T& operator ->() const {
        return ptr_;
    }

    operator T* () {
        return ptr_;
    }

  private:
    T* ptr_;
};

int main() {

    UniquePtr<int> a(new int(1));
    UniquePtr<int> b(new int(1));

}
