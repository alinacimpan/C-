
#include <cassert>
#include <iostream>

#include "tests.h"
#include "multiDictionar.h"
#include "list.h"

void test_multi_dictionary() {
    MultiDictionary<int, int> multi_dictionary;

    multi_dictionary.put(1, 1);
    assert(multi_dictionary.get(1)[0] == 1);
    assert(multi_dictionary.contains(1));

    multi_dictionary.put(1, 2);
    assert(multi_dictionary.get(1)[0] == 2);
    assert(multi_dictionary.get(1)[1] == 1);
    assert(multi_dictionary.contains(1));

    assert(multi_dictionary.get(2) == std::vector<int>());

    multi_dictionary.remove(1, 1);
    assert(multi_dictionary.get(1)[0] == 2);

    multi_dictionary.remove(1);
    assert(multi_dictionary.get(1) == std::vector<int>());

    assert(!multi_dictionary.contains(1));
}

void test_list() {
    List<int> lst;

    lst.add(1);
    assert(lst.contains(1));

    lst.add(2);
    assert(lst.contains(2));

    lst.add(1);
    assert(lst.contains(1));

    lst.remove(5);
    assert(!lst.contains(5));

    lst.remove(1);
    assert(!lst.contains(1));

    assert(lst.size() == 1);

}

void tests() {
    test_multi_dictionary();
    test_list();

    cout << "Toate testele au trecut. "<<endl;;
}
