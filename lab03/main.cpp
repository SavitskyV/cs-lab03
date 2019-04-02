#include <iostream>
#include <vector>

using namespace std;

int main()

{
    
    const size_t max_zvezdochki = 76;
    size_t number_count;
    cerr << "Enter number_count:\n";
    cin >> number_count;
    
    vector <double> numbers(number_count);
    
    cerr << "Enter massiv:\n";
    for (size_t i = 0; i < number_count; i++)
    {
        cin >> numbers[i];
    }
    
    size_t bins_count;
    cerr << "Enter bins_count:\n";
    cin >> bins_count;
    
    string dummy;
    getline(cin, dummy);
    
    cerr << "Vvedite simvol risunka:\n";
    char risunok;
    cin >> risunok;
    if (risunok == '\t' || risunok == '\n')
    {
        cout << "ERROR";
        return 1;
    }
    
    
    cerr << "Vvedite simvol linii osi:\n";
    string liniya_osi;
    getline(cin, liniya_osi);
    if (liniya_osi == "\t" || liniya_osi == "\n")
    {
        cout << "ERROR";
        return 1;
    }
    
    cerr << "Vvedite simvol viravnivaniya podpisey:\n";
    string viravnivanie_podpisei;
    getline(cin, viravnivanie_podpisei);
    if (viravnivanie_podpisei == "\t" || viravnivanie_podpisei == "\n")
    {
        cout << "ERROR";
        return 1;
    }
    
    double min, max;
    
    min = max = numbers[0];
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
    
    vector <size_t> bins(bins_count, 0);
    
    for (double number : numbers)
    {
        size_t bin_index = bins_count * (number - min) / (max - min);
        if (number == max)
        {
            bin_index = bin_index - 1;
        }
        bins[bin_index] ++;
    }
    
    cerr << "Histogram:\n";
    bool koef;
    
    koef = false;
    
    for (size_t i = 0; i < bins_count; i++)
    {
        if (bins[i] > max_zvezdochki)
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
            cout << viravnivanie_podpisei;
        }
        
        if (bins[i] < 10)
        {
            cout << viravnivanie_podpisei << viravnivanie_podpisei;
        }
        
        cout << bins[i] << liniya_osi;
        
        if (koef == true)
        {
            for (size_t j = 0; j < height[i]; j++)
            {
                cout << risunok;
            }
        }
        
        else
        {
            for (size_t j = 0; j < bins[i]; j++)
            {
                cout << risunok;
            }
        }
        cout << '\n';
        
    }
}
