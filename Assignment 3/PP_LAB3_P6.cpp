#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Set {
private:
    int *set;
    int size;
public:
    Set(int s);
    ~Set();
    void add(int item);
    void remove(int item);
    Set* union_set(Set *s);
    Set* intersection_set(Set *s);
    Set* complement_set(Set *s);
    Set* difference_set(Set *s);
    bool equals(Set *s);
    void display();
    void cartesian_product(Set *s);
    void power_set();
    bool is_distinct();
    float mean();
    float variance();
    float std_dev();
    float median();
};

Set::Set(int s) {
    size = s;
    set = new int[size];
    for (int i = 0; i < size; i++) {
        set[i] = 0;
    }
}

Set::~Set() {
    delete [] set;
}

void Set::add(int item) {
    if (item >= 0 && item < size) {
        set[item] = 1;
    }
}

void Set::remove(int item) {
    if (item >= 0 && item < size) {
        set[item] = 0;
    }
}

Set* Set::union_set(Set *s) {
    Set *result = new Set(size);
    for (int i = 0; i < size; i++) {
        result->set[i] = (set[i] || s->set[i]);
    }
    return result;
}

Set* Set::intersection_set(Set *s) {
    Set *result = new Set(size);
    for (int i = 0; i < size; i++) {
        result->set[i] = (set[i] && s->set[i]);
    }
    return result;
}

Set* Set::complement_set(Set *s) {
    Set *result = new Set(size);
    for (int i = 0; i < size; i++) {
        result->set[i] = (!s->set[i]);
    }
    return result;
}

Set* Set::difference_set(Set *s) {
    Set *result = new Set(size);
    for (int i = 0; i < size; i++) {
        result->set[i] = (set[i] && !s->set[i]);
    }
    return result;
}

bool Set::equals(Set *s) {
    for (int i = 0; i < size; i++) {
        if (set[i] != s->set[i]) {
            return false;
        }
    }
    return true;
}

void Set::display() {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        if (set[i]) {
            cout << i << " ";
        }
    }
    cout << "}" << endl;
}

void Set::cartesian_product(Set *s) {
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < s->size; j++) {
            cout << "(" << i << ", " << j << ") ";
        }
    }
    cout << "}" << endl;
}

void Set::power_set() {
    vector<int> v;
    for (int i = 0; i < size; i++) {
        if (set[i]) {
            v.push_back(i);
        }
    }
    int n = v.size();
    int p = pow(2, n);
    cout << "{ ";
    for (int i = 0; i < p; i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                cout << v[j] << " ";
            }
        }
        cout << "}, ";
    }
    cout << "}" << endl;
}

bool Set::is_distinct() {
    int distinct_count = 0;
    for (int i = 0; i < size; i++) {
        if (set[i]) {
            distinct_count++;
        }
    }
    return (distinct_count == size);
}

float Set::mean() {
    int sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
        if (set[i]) {
            sum += i;
            count++;
        }
    }
    return (float) sum / count;
}

float Set::variance() {
    float mu = mean(), var = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (set[i]) {
            var += pow(i - mu, 2);
            count++;
        }
    }
    return var / count;
}

float Set::std_dev() {
    return sqrt(variance());
}

float Set::median() {
    vector<int> v;
    for (int i = 0; i < size; i++) {
        if (set[i]) {
            v.push_back(i);
        }
    }
    int n = v.size();
    sort(v.begin(), v.end());
    if (n % 2 == 0) {
        return (float) (v[n/2 - 1] + v[n/2]) / 2;
    } else {
        return (float) v[n/2];
    }
}

int main() {
    Set *s1 = new Set(10);
    s1->add(1);
    s1->add(4);
    s1->add(7);
    s1->add(8);
    s1->display(); // output: { 1 4 7 8 }
    std::cout << std::endl;

    Set *s2 = new Set(10);
    s2->add(2);
    s2->add(4);
    s2->add(5);
    s2->add(7);
    s2->display(); // output: { 2 4 5 7 }
    std::cout << std::endl;

    std::cout << "Uninon Set: ";
    Set *s3 = s1->union_set(s2);
    s3->display(); // output: { 1 2 3 4 5 6 8 }
    std::cout << std::endl;

    std::cout << "Intersection Set: ";
    Set *s4 = s1->intersection_set(s2);
    s4->display();
    std::cout << std::endl;

    std::cout << "Complement Set: ";
    Set *s5 = s1->complement_set(s1);
    s5->display();
    std::cout << std::endl;

    std::cout << "Difference Set: ";
    Set *s6 = s1->difference_set(s2);
    s6->display();
    std::cout << std::endl;

    std::cout << "Power Set: ";
    s1->power_set();
    std::cout << std::endl;

    std::cout << "Cartesian Product: ";
    s1->cartesian_product(s2);
    std::cout << std::endl;

    std::cout << "Is distinct: ";
    if(s1->is_distinct())
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    
    std::cout << "Mean: " << s1->mean() << std::endl;
    std::cout << "Variance: " << s1->variance() << std::endl;
    std::cout << "Standard Deviation: " << s1->std_dev() << std::endl;
    std::cout << "Median: " << s1->median() << std::endl;
    

}