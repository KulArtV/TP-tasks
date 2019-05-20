#include <iostream>
#include <exception>
#include <limits>

#ifndef VECTOR_H
#define VECTOR_H


#include <iterator>

// IMPLEMENT SORT ALGORITHM
// bonus: implement sort algorithm which works with any type of iterator
//        (at least O(nlogn) for random access and O(n^2) for forward iterator
// tip: use iterator tag

template <class ValueType, class Iterator, class Comparator = std::greater<ValueType>>
std::pair<Iterator, Iterator> Partition(Iterator begin, Iterator end, Comparator Compare = Comparator()) {
    auto pivot_iterator = std::prev(end);

    auto i = begin;
    auto j = begin;

    while (j != pivot_iterator) {
        if (Compare(*j, *pivot_iterator)) {
            j = std::next(j);
        } else {
            if (i != j) {
                std::swap(*i, *j);
            }
            i = std::next(i);
            j = std::next(j);
        }
    }

    std::swap(*i, *pivot_iterator);
    std::pair<Iterator, Iterator> ans_pair;
    ans_pair.second = i;

    for (; i != begin && *std::prev(i) == *i; i = std::prev(i));

    ans_pair.first = i;

    return ans_pair;
}

template <class ValueType, class Iter>
void Sort(Iter begin, Iter end) {
    if (std::distance(begin, end) < 2) {
        return;
    }

    auto iter_pairs = Partition<ValueType>(begin, end);
    Sort<ValueType>(iter_pairs.second, end);
    Sort<ValueType>(begin, iter_pairs.first);
}



class IncorrectIndex : public std::exception {
    const char* what() const noexcept override {
        return "Incorrect index";
    }
};

class IncorrectLength : public std::exception {
    const char* what() const noexcept override {
        return "You try get more memory than it's possible";
    }
};

template <class T>
class Vector {
public:
    typedef T ValueType;
    typedef size_t SizeType;
    typedef std::ptrdiff_t DifferenceType;
    typedef T& Reference;
    typedef const T& ConstReference;
    typedef T* Pointer;
    typedef const T* ConstPointer;

    class VectorIterator : public std::iterator<std::random_access_iterator_tag, T> {

        Pointer ptr_ = nullptr;
    public:
        VectorIterator() = default;
        explicit VectorIterator(const Pointer& ptr) : ptr_(ptr) {}
        bool operator==(const VectorIterator& other) const {
            return ptr_ == other.ptr_;
        }

        bool operator!=(const VectorIterator& other) const {
            return !(*this == other);
        }

        bool operator<(const VectorIterator& other) const {
            return ptr_ < other.ptr_;
        }

        T& operator*() {
            return *ptr_;
        }

        const T& operator*() const {
            return *ptr_;
        }

        T* operator->() {
            return ptr_;
        }
        const T* operator->() const {
            return ptr_;
        }

        VectorIterator& operator++() {
            ++ptr_;
            return *this;
        }
        VectorIterator operator++(int) {
            ++ptr_;
            return --(*this);
        }

        VectorIterator& operator--() {
            --ptr_;
            return *this;
        }
        VectorIterator operator--(int) {
            --ptr_;
            return ++(*this);
        }

        VectorIterator operator+(DifferenceType n) const {
            VectorIterator new_iter (ptr_ + n);
            return new_iter;
        }
        VectorIterator operator-(DifferenceType n) const {
            VectorIterator new_iter (ptr_ - n);
            return new_iter;
        }

        VectorIterator& operator+=(DifferenceType n) {
            ptr_ += n;
            return *this;
        }
        VectorIterator& operator-=(DifferenceType n) {
            ptr_ -= n;
            return *this;
        }

        DifferenceType operator-(const VectorIterator& other) const {
            return ptr_ - other.ptr_;
        }

        T& operator[](DifferenceType n) {
            return *(ptr_ + n);
        }
        const T& operator[](DifferenceType n) const {
            return *(ptr_ + n);
        }
    };

    VectorIterator Begin() {
        return VectorIterator(&(this->At(0)));
    }

    VectorIterator End() {
        return VectorIterator(&(*this)[size_]);
    }


private:
    Pointer buffer_ = nullptr;
    SizeType capacity_ = 0;
    SizeType size_ = 0;
    void CopyBuffer(T* CopyToBuffer, const T* CopyFromBuffer, const SizeType size) {
        for (size_t i = 0; i < size; ++i) {
            CopyToBuffer[i] = CopyFromBuffer[i];
        }
    }


public:
    explicit Vector() = default;
    explicit Vector(SizeType count, ConstReference value = ValueType()) {
        if (count > this->MaxSize()) {
            throw IncorrectLength();
        } else {
            size_ = capacity_ = count;
            buffer_ = new ValueType[count];
            for (SizeType i = 0; i < count; ++i) {
                buffer_[i] = value;
            }
        }
    }
    Vector(const Vector& other) {
        size_ = other.size_;
        capacity_ = other.capacity_;
        buffer_ = new ValueType[capacity_];
        for (SizeType i = 0; i < size_; ++i) {
            buffer_[i] = other.buffer_[i];
        }
    }
    Vector(Vector&& other) noexcept {
        size_ = other.size_;
        capacity_ = other.capacity_;
        std::swap(buffer_, other.buffer_);
        other.buffer_ = nullptr;
    }
    ~Vector() {
        delete[] buffer_;
    }

    Vector& operator=(const Vector& other) {
        if (this->buffer_ != other.buffer_) {
            size_ = other.size_;
            capacity_ = other.capacity_;
            buffer_ = new ValueType[capacity_];
            CopyBuffer(buffer_, other.buffer_, size_);
        }
        return *this;
    }
    Vector& operator=(Vector&& other) noexcept {
        if (this->buffer_ != other.buffer_) {
            size_ = other.size_;
            capacity_ = other.capacity_;
            std::swap(buffer_, other.buffer_);
        }
        return *this;
    }

    void Assign(SizeType count, ConstReference value) {
        this->Reserve(count);
        size_ = capacity_;
        for (SizeType i = 0; i < size_; ++i) {
            this->At(i) = value;
        }
    }

    Reference At(SizeType pos) {
        if (pos < 0 || size_<= pos) {
            throw IncorrectIndex();
        } else {
            return buffer_[pos];
        }
    }
    ConstReference At(SizeType pos) const {
        if (pos < 0 || size_<= pos) {
            throw IncorrectIndex();
        } else {
            return buffer_[pos];
        }
    }

    Reference operator[](SizeType pos) {
        return buffer_[pos];
    }
    ConstReference operator[](SizeType pos) const {
        return buffer_[pos];
    }

    Reference Front() {
        return buffer_[0];
    }
    ConstReference Front() const {
        return buffer_[0];
    }

    Reference Back() {
        return buffer_[size_ - 1];
    }
    ConstReference Back() const {
        return buffer_[size_ - 1];
    }

    Pointer Data() {
        return buffer_;
    }
    ConstPointer Data() const {
        return buffer_;
    }

    bool Empty() const {
        return size_ == 0;
    }

    SizeType Size() const {
        return size_;
    }
    SizeType MaxSize() const {
        return std::numeric_limits<SizeType>::max();
    }
    SizeType Capacity() const {
        return capacity_;
    }

    void Reserve(SizeType size) {
        if (size > this->MaxSize()) {
            throw IncorrectLength();
        } else {
            if (capacity_ < size) {
                try {
                    Pointer newBuffer = new ValueType[size];
                    capacity_ = size;
                    CopyBuffer(newBuffer, buffer_, size_);
                    std::swap(buffer_, newBuffer);
                    delete[] newBuffer;
                }
                catch (std::bad_alloc& ex) {
                    std::cout << "You don't have enough memory" << '\n';
                }
            }
        }
    }

    void ShrinkToFit() {
        Pointer newBuffer = new ValueType[size_];
        capacity_ = size_;
        for (SizeType i = 0; i < size_; ++i) {
            newBuffer[i] = buffer_[i];
        }
        std::swap(buffer_, newBuffer);
        delete[] newBuffer;
    }

    void Resize(SizeType count) {
        if (count > capacity_) {
            this->Reserve(count);
        }
        size_ = count;
    }
    void Resize(SizeType count, ConstReference value) {
        if (count > capacity_) {
            this->Reserve(count);
        }
        if (count > size_) {
            for (SizeType i = size_; i < count; ++i) {
                buffer_[i] = value;
            }
        }
        size_ = count;
    }

    void PushBack(ConstReference value) {
        if (size_ == 0) {
            this->Reserve(1);
        } else if (size_ == capacity_) {
            this->Reserve(capacity_ * 2);
        }
        buffer_[size_] = value;
        ++size_;
    }
    void PushBack(ValueType&& value) {
        if (size_ == 0) {
            this->Reserve(1);
        } else if (size_ == capacity_) {
            this->Reserve(capacity_ * 2);
        }
        buffer_[size_] = value;
        ++size_;
    }

    void PopBack() {
        if (!this->Empty()) {
            --size_;
        }
    }

    void Swap(Vector& other) {
        std::swap(this->capacity_, other.capacity_);
        std::swap(this->size_, other.size_);
        std::swap(this->buffer_, other.buffer_);
    }

    void Clear() {
        delete[] buffer_;
        buffer_ = nullptr;
        size_ = 0;
        capacity_ = 0;
    }
};



#endif