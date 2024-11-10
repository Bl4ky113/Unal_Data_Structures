
#include <iostream>
#include <vector>

using namespace std;

void print_vector (vector<int> v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) {
            cout << " ";
        }

        cout << v.at(i);
    }
    cout << "]" << endl;
    return;
}

void bubble_sort (vector<int> *v) {
    int sorted_index = v->size();

    while (sorted_index > 0) {
        int changed_index = 0;

        for (int i = 1; i < sorted_index; i++) {
            if (v->at(i - 1) > v->at(i)) {
                int temp = v->at(i);
                (*v)[i] = v->at(i - 1);
                (*v)[i - 1] = temp;

                changed_index = i;
            }
        }

        sorted_index = changed_index;
    }

    return;
}

int main (void) {
    int num_input = 0;
    vector<int> num_vector;

    cin >> num_input;

    while (num_vector.size() < num_input) {
        int usr_input = 0;
        cin >> usr_input;

        num_vector.push_back(usr_input);
    }

    print_vector(num_vector);

    bubble_sort(&num_vector);

    print_vector(num_vector);

    return 0;
}
