// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    const int maxWidth=70;
    const int centerTitleWidth=((maxWidth-tours.title.length())/2)+tours.title.length();
    const int countryTitleWidth=20;
    const int cityTitleWidth=20;
    const int populationWidth=15;
    const int priceWidth=15; 
    // Unformatted display so you can see how to access the vector elements
    std::cout<<std::setprecision(2)<<std::fixed;
    std::cout << std::setw(centerTitleWidth)<< tours.title << std::endl;
    std::cout<< "--------------------------------------------------------------------------------"<<std::endl;
    std::cout<<std::setw(countryTitleWidth)<<std::left<<"Country"<<std::setw(cityTitleWidth)<<"City"<<std::setw(populationWidth)<<std::right<<"Population"<<std::setw(priceWidth)<<"Price"<<std::endl;
    std::cout<< "--------------------------------------------------------------------------------"<<std::endl;
    for(auto country : tours.countries) {   // loop through the countries
        std::cout << std::setw(countryTitleWidth)<<std::left<<country.name;
        for(int i=0; i<country.cities.size(); i++){
            if(i!=0){
                std::cout<<std::setw(countryTitleWidth)<<std::left<<"";
            }
            std::cout<<std::setw(cityTitleWidth)<<country.cities[i].name<<std::setw(populationWidth)<<std::right<<country.cities[i].population<<std::setw(priceWidth)<<country.cities[i].cost<<"\n";
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}