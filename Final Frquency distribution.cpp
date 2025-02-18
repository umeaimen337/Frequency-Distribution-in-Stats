#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    // Declare variables
    const int MAX_VALUES = 1000;
    double data[MAX_VALUES];
    int freq_table[MAX_VALUES] = {0};
    double min_val, max_val, range, class_width;
    int num_classes, num_values;

    // Get user input
    cout << "Enter the number of values: ";
    cin >> num_values;

    // Get the values
    for (int i = 0; i < num_values; i++) {
        cout << "Enter value " << i+1 << ": ";
        cin >> data[i];
    }

    // Sort the data in ascending order
    for (int i = 0; i < num_values; i++) {
        for (int j = i+1; j < num_values; j++) {
            if (data[j] < data[i]) {
                swap(data[i], data[j]);
            }
        }
    }

    // Calculate range
    min_val = data[0];
    max_val = data[num_values-1];
    range = max_val - min_val;
    
    // Calculate number of classes
    num_classes = ceil(1 + 3.310 * log10(num_values));
    
    // Calculate class width
    class_width = ceil(range / num_classes); 
 
    // Populate the frequency table
    for (int i = 0; i < num_values; i++) {
        int class_num = (data[i] - min_val) / class_width;
        freq_table[class_num]++;
    }

    // Print the results
    cout << "Range: " << range << endl;
    cout << "Class width: " << class_width << endl;
    cout << "Number of classes: " << num_classes << endl;
    cout << left << setw(10) << "Data" << "|" << setw(15) << "Observations" << "|" << setw(10) << "Frequency" << endl;
    cout << setfill('-') << setw(10) << "-" << "+" << setw(15) << "-" << "+" << setw(10) << "-" << setfill(' ') << endl;
    for (int i = 0; i < num_classes; i++) {
        double lower_bound = min_val + i*class_width;
        double upper_bound = min_val + (i+1)*class_width;
        cout << left << setw(10) << "[" << lower_bound << "-" << upper_bound << ")" << "|" << setw(15) << "";
        for (int j = 0; j < num_values; j++) {
            if (data[j] >= lower_bound && data[j] < upper_bound) {
                cout << data[j] << ", ";
            }
        }
        cout << "|" << setw(10) << freq_table[i] << endl;
    }

    return 0;
}
