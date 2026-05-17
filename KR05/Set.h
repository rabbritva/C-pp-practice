using namespace std;

template <class type = double> class set {
private:
    type* data;
    size_t count;
    size_t ssize;

    bool sfind(const type& elem) {
        for (size_t i = 0; i < count; i++) {
            if (elem == data[i]) return false;
        }
        return true;
    }
    void resize(size_t new_ssize) {
        if (new_ssize == 0) {
            delete[] data;
            data = nullptr;
            ssize = new_ssize;
            count = 0;
        }
        else {
            size_t elements = min(new_ssize, count);
            type* new_data = new type[new_ssize];
            for (size_t i = 0; i < elements; i++) new_data[i] = data[i];
            delete[] data;
            data = new_data;
            ssize = new_ssize;
            count = elements;
        }
    }
public:
    set() : data(nullptr), count(0), ssize(1) {}
    set(const type* arr, size_t size) : data(nullptr), count(0), ssize(1) {
        if (size > 0) {
            ssize = size;
            data = new type[ssize];
            for (size_t i = 0; i < size; i++) {
                if (sfind(arr[i])) {
                    if (count >= ssize) resize(ssize * 2);
                    data[count++] = arr[i];
                }
            }
        }
    }
    set(const set& oset) : data(nullptr), ssize(oset.ssize), count(oset.count) {
        if (oset.data != nullptr) {
            data = new type[ssize];
            for (size_t i = 0; i < count; i++) {
                data[i] = oset.data[i];
            }
        }
        else data = nullptr;

    }
    ~set() { delete[]data; }

    void add(const type& val) {
        if (data == nullptr) data = new type[ssize];
        if (sfind(val)) {
            if (count >= ssize) resize(ssize * 2);
            data[count++] = val;
        }
    }
    set& operator=(const set& oset) {
        if (this != &oset) {
            delete[] data;
            ssize = oset.ssize;
            count = 0;
            data = new type[ssize];
            for (size_t i = 0; i < oset.count; i++) {
                data[count++] = oset.data[i];
            }
        }
        return *this;
    }
    set operator+(const set& oset) {
        set result(*this);
        for (size_t i = 0; i < oset.count; i++) {
            result.add(oset.data[i]);
        }
        return result;
    }
    bool operator<=(const set& oset) {
        for (size_t i = 0; i < count; i++) {
            bool flag = false;
            for (size_t j = 0; j < oset.count; j++) {
                if (data[i] == oset.data[j]) { flag = true; break; }
            }
            if (!flag) return false;
        }
        return true;
    }
    type& operator[](const size_t index) {
        if (index < count) {
            return data[index];
        }
        else {
            cout << "Index out of range\n";
            throw out_of_range("Index out of range");
        }
    }
    void print() {
        cout << "{";
        for (size_t i = 0; i < count; ++i) {
            cout << data[i];
            if (i < count - 1) cout << "; ";
        }
        cout << "}" << std::endl;
    }
    size_t size() { return count; }
};