#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <exception>
using namespace std;

class heap {

    public:
        heap(vector<int> data_) : data {data_} {
            make_heap();
        }

        void insert(int value);
        void pop();
        int search(int key);
        void remove_key(int key);
        void change_key(int key, int value);
        void change_pos(int pos, int value);
        void print();

        int top() const { return data[0];}
        int size() const { return data.size();}

    private:
        vector<int> data;

        void make_heap() {
            for(int i = parent(last()); i >= 0; --i)
                down(i);
        }

        void remove(int pos);
        void down(int);
        void up(int);
        int last() const { return size() - 1;}
        int parent(int i) const { return (i-1)>>1;}
        int left(int i) const { return (i<<1) + 1;}
        int right(int i) const { return (i<<1) + 2;}
        bool valid(int i) const { return i < size() and i >= 0;}
};

void heap::insert(int value) {
    data.push_back(value);
    up(last());
}

void heap::change_pos(int pos, int value) {
    if(valid(pos)) {
        data[pos] = value;
        down(pos);
        up(pos);
    }
}
void heap::change_key(int key, int value) {
    change_pos(search(key), value);
}

void heap::remove_key(int key) {
    int pos = search(key);
    if(valid(pos))
        remove(pos);
}

int heap::search(int key) {
    for(int i = 0; i < size(); ++i) {
        if(data[i] == key)
            return i;
    }
    return -1;
}

void heap::remove(int pos) {
    if(!valid(pos))
        return;
    swap(data[pos], data[last()]);
    data.pop_back();
    down(pos);
    up(pos);
}

void heap::pop() {
    remove(0);
}

void heap::down(int i) {
    int l = left(i);
    int r = right(i);
    int mn = i;
    if(l < size() and data[l] < data[i])
        mn = l;
    if(r < size() and data[r] < data[mn])
        mn = r;
    if(mn != i) {
        swap(data[mn],data[i]);
        down(mn);
    }
}

void heap::up(int i) {
    int p = parent(i);
    if(p >= 0 and data[i] < data[p]) {
        swap(data[i],data[p]);
        up(p);
    }
}

void heap::print() {
    cout << "HEAP: ";
    for(auto x: data)
        cout << x << " ";
    cout << endl;
}

vector<int> parse_numbers(string & input) {
    stringstream s { input};
    int val;
    vector<int> result;
    while(s >> val) {
        result.push_back(val);
    }
    return result;
}


class menu {
    vector<pair<string,function<void()>>> data;
    public:
    void add(string name,function<void()> f) {
        data.emplace_back(name,f);
    }
    void print(bool banner = true) {
        if(banner) {
            cout << "MENU: " << endl;
        }
        int idx = 0;
        for(auto &x: data) {
            cout << idx + 1 << ". " << x.first << endl;
            idx++;
        }
    }

    bool run(int choice) {
        if(choice >= 0 and choice < (int)data.size()) {
            data[choice].second();
            return true;
        }
        else
            return false;
    }

    void interact() {
        while(true) {
            print();
            int choice;
            cout<< "Choice (default: exit) = ";
            cin >> choice;
            if(!run(choice-1))
                break;
        }
    }
};

int main() {
    cout << "Make heap : ";
    string input;
    getline(cin, input);
    heap h(parse_numbers(input));

    menu m;
    m.add("Print",[&](){
                h.print();
            });
    m.add("Top",[&](){
                cout << "Top is = " << h.top() <<endl;
            });
    m.add("Pop Minimum",[&](){
                h.pop();
            });

    m.add("Insert Element", [&]() {
                cout << "Element to insert = ";
                int item;
                cin >> item;
                h.insert(item);
            });

    m.add("Change key",[&](){
                cout << "1.Item 2.Pos : ";
                int choice;
                cin >> choice;
                int key;
                cout << "Key/pos : ";
                cin >> key;
                cout << "Value : ";
                int value;
                cin >> value;
                switch(choice) {
                    case 1: h.change_key(key,value);
                        break;
                    case 2: h.change_pos(key,value);
                }
            });
    m.add("Search Item",[&](){
                cout << "Item : ";
                int item;
                cin >> item;
                cout << "Result : " << h.search(item) << endl;
            });

    m.add("Remove",[&]{
                int item;
                cout << "Item to remove : ";
                cin >> item;
                h.remove_key(item);
            });
    m.interact();
}
