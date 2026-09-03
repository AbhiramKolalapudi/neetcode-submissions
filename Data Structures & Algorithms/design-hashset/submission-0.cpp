class MyHashSet {
private:
    vector<bool> data = vector<bool>(1000001, false);
public:
    MyHashSet()
    {}

    void add(int key) {
        data[key] = true;
    }

    void remove(int key) {
        data[key] = false;
    }

    bool contains(int key) {
        return data[key];
    }
};