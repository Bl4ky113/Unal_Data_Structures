
#include <iostream>

#include <stack>

#include <bits/stdc++.h>
#include <string>

#define DELIMITER ' '

using namespace std;

int main (int args, char **vargs) {
    string line;
    char input_delimiter = DELIMITER;

    while (getline(cin, line)) {
        multiset<int> *urn;
        int num_days, total_price;

        total_price = 0;

        num_days = atoi(line.c_str());
        urn = new multiset<int>;

        if (num_days == 0) {
            break;
        }

        for (int i = 0; i < num_days; i++) {
            int i_data, num_day_data, lst_bill, fst_bill;
            string s_data, day_line; 

            getline(cin, day_line);
            num_day_data = atoi(day_line.substr(0,1).c_str());

            if (num_day_data > 0) {
                stringstream day_stream(day_line.substr(2, day_line.length()));
                
                while(getline(day_stream, s_data, input_delimiter)) {
                    i_data = atoi(s_data.c_str());
                    
                    urn->insert(i_data);
                }
            }
            
            if (urn->size() >= 2) {
                fst_bill = *(urn->begin());
                lst_bill = *(urn->rbegin());
                
                total_price += lst_bill - fst_bill;

                urn->erase(urn->find(fst_bill));
                urn->erase(urn->find(lst_bill));
            }

        }

        cout << total_price << endl;
    }

    return 0;
}
