#include<set>


set<int> s;
s.insert(3);
s.insert(4);

s.erase(3);


set<int> s = {2,5,6,8};
cout << s.size() << "\n"; // 4
for (auto x : s) {
    cout << x << "\n";
}


s.count(<element>)// this is used to get whether element is in set or not , note that count can not go above 1 as element unique


sort(v.begin(), v.end());
reverse(v.begin(), v.end());
random_shuffle(v.begin(), v.end());



// iterators:

for (auto it = s.begin(); it != s.end(); it++) {
cout << *it << "\n";
}


// The function find(x) returns an iterator that points to an element whose
// value is x. However, if the set does not contain x, the iterator will be end.

auto it = s.find(x);
if (it == s.end()) {
// x is not found
}



// similar multiset can be used  and unordered_set