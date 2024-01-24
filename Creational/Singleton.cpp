#include <iostream>

using namespace std;

class Singleton {
private:
    Singleton() {};
    vector<int> container;
public:
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(const Singleton&&) = delete;
    Singleton(const Singleton&) = delete;
    Singleton(const Singleton&&) = delete;

    static Singleton& getSingleton() {
        static Singleton s;
        return s;
    };
    void addValue(int x) {
        container.push_back(x);
    }
    
    int getValue(int i) const {
        return i < getSize() ? container[i] : -1;
    }

    int getSize() const {
        return container.size();
    }
};

class SingletonDynamic {
private:
    static SingletonDynamic* sInst;
    SingletonDynamic() {};
    vector<int> container;
    static mutex m;
public:

    SingletonDynamic& operator=(const SingletonDynamic&) = delete;
    SingletonDynamic& operator=(const SingletonDynamic&&) = delete;
    SingletonDynamic(const SingletonDynamic&) = delete;
    SingletonDynamic(const SingletonDynamic&&) = delete;

    static SingletonDynamic* getInstance() {
        if(!sInst){
            lock_guard<mutex> lock(m);
            sInst = new SingletonDynamic();
        }
        return sInst;
    }
    void addValue(int x) {
        container.push_back(x);
    }

    int getValue(int i) const {
        return i < getSize() ? container[i] : -1;
    }

    int getSize() const {
        return container.size();
    }

    ~SingletonDynamic() {
        delete sInst;
    }
};

SingletonDynamic* SingletonDynamic::sInst = nullptr;
mutex SingletonDynamic::m;

int main() {
    Singleton& s = Singleton::getSingleton();

    s.addValue(2);
    s.addValue(3);
    cout << s.getValue(4) << endl;

    Singleton& t = Singleton::getSingleton();
    t.addValue(4);
    t.addValue(5);

    cout<< t.getValue(3)<< endl;

    return 0;
}