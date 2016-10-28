template <typename T>
class SharedPtr {

public:
    SharedPtr():
        ptr_(nullptr),
        cnt_(nullptr) {
    }
    SharedPtr(T* ptr):
        ptr_(ptr),
        cnt_(new int(1)) {
    }
    SharedPtr(const SharedPtr &other):
        ptr_(other.ptr_),
        cnt_(other.cnt_) {
            (*cnt_)++;
        }

    ~SharedPtr() {
        delete ptr_;
        delete cnt_;
    }
    
    SharedPtr operator = (const SharedPtr &other) const;

    T& operator * ();
    const T& operator * () const;

    T& operator -> ();
    const T& operator -> () const;

    T* Get();
    const T* Get() const;
    
    operator bool () const;
private:
    T* ptr_;
    size_t* cnt_;
};
