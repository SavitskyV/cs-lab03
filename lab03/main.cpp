#include <iostream>
#include <vector>

using namespace std;

vector<double>
input_numbers(size_t count) {
    vector<double> result(count);
    cerr << "Enter massiv:\n";
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

void find_minmax(const vector<double>& numbers, double& min, double& max) {
    min = numbers[0];
    for (double number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
        
        if (number > max)
        {
            max = number;
        }
    }
}


vector<size_t> make_histogram (const vector<double>& numbers, size_t bin_count) {
    vector <size_t> bins(bin_count, 0);
    double min=numbers[0], max=numbers[0];
    find_minmax(numbers, min, max);
    
    for (double number : numbers)
    {
        size_t bin_index = bin_count * (number - min) / (max - min);
        if (bin_index==bin_count)
        {
            bin_index = bin_index - 1;
        }
        bins[bin_index] ++;
    }
    return bins;
}



void show_histogram_text(const vector<size_t>& bins, size_t bins_count) {
    const size_t max_zvezdochki = 76;
    
  /*  cerr << "Vvedite simvol risunok:\n";
    string risunok;
    getline(cin, risunok);
    
    cerr << "Vvedite simvol linii osi:\n";
    string liniya_osi;
    getline(cin, liniya_osi);
   
    cerr << "Vvedite simvol viravnivaniya podpisey:\n";
    string viravnivanie_podpisei;
    getline(cin, viravnivanie_podpisei);
   */
    cerr << "Histogram:\n";
    bool koef;
    
    koef = false;
    
    for (size_t i = 0; i < bins_count; i++)
    {
        if (bins[i] >  max_zvezdochki)
        {
            koef = true;                                                                                                                                                   //невылез
        }
        
    }
    
    vector<size_t> height(bins_count);
    if (koef == true)
    {
        size_t maxbin = bins[0];
        for (size_t i = 0; i < bins_count; i++)
        {
            if (bins[i] > maxbin)
            {
                maxbin = bins[i];
            }
        }
        for (size_t i = 0; i < bins_count; i++)
        {
            height[i] = max_zvezdochki * (static_cast<double>(bins[i]) / maxbin);
        }
    }
    
    for (size_t i = 0; i < bins_count; i++)
    {
        if (bins[i] < 100 && bins[i] >= 10)
        {
            cout << ' ';
        }
        
        if (bins[i] < 10)
        {
            cout << ' ' << ' ';
        }
        
        cout << bins[i] << '|';
        
        if (koef == true)
        {
            for (size_t j = 0; j < height[i]; j++)
            {
                cout << '*';
            }
        }
        
        else
        {
            for (size_t j = 0; j < bins[i]; j++)
            {
                cout << '*';
            }
        }
        cout << '\n';
        
    }
    
}

int main()

{
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    
    const auto numbers = input_numbers(number_count);

    size_t bins_count;
    cerr << "Enter bins_count:\n";
    cin >> bins_count;
    
    double min, max;
    find_minmax(numbers, min, max);
    
    const vector<size_t>  bins = make_histogram(numbers, bins_count);
    
    show_histogram_text(bins, bins_count);
}
