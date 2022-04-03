
#include <iostream>
#include <vector>
using std::string;
using namespace std;


class Content {
public:
    
};

class Solution
{
private:
    double StartupCost, Cost = 0;
    double Volume;
    std::vector<int> ContentAmount{};
    std::vector<string> ContentName{};
    std::vector<double> ContentCost{};

    std::vector<string> ProductName{};
    std::vector<double> ProductProportions{};
    int AddToProduct(std::vector<string> Names, std::vector<double> Proportions, double Volume) {
        for (int i = 0; i < Names.size(); i++) {
            bool fount = false;
            for (int k = 0; k < ProductName.size() and not fount; k++) {
                if (Names.at(i) == ProductName.at(k)) {
                    fount = true;
                    ProductName.at(k) += Proportions.at(k) * Volume;
                    return 1;
                }
            }
            if (not fount) {
                //cout << "Faj";
                ProductName.push_back(Names.at(i));
                ProductProportions.push_back(Proportions.at(i) * Volume);
            }
        }
        return 0;
    };
    double FindPrice(string Name) {
        for (int i = 0; i < ContentName.size(); i++) {
            if (Name == ContentName.at(i)) {
                return ContentCost.at(i);
            }
        }
        return 0;
    };
    double Total() {

        return 0;
    }
public:


    int Add(string Name, double Amount, double SCost, std::vector<string> SolutionNames, std::vector<double> SolutionProportions) {
        if (Amount > 0) {
            ContentAmount.push_back(Amount);
            ContentCost.push_back(SCost * Amount);
            ContentName.push_back(Name);

            Volume += Amount;
            Cost += SCost * Amount;

            AddToProduct(SolutionNames, SolutionProportions,Amount);

            std::cout << Name << ": " << Amount << "ml" << endl;

            return SolutionProportions.at(0);
        }
        else { return 0; };
    }
    int Startup(double Cost) {
        StartupCost = Cost * Volume;
        return 0;
    }
    int Print(string ObscureString, bool debug) {
        cout << endl << "Contents Cost(" << Volume << "/each): $" << Cost << " / $" << (double)(Cost / Volume) << std::endl;
        cout << "Startup Costs(" << ObscureString << "): $" << StartupCost << std::endl;
        cout << "Total Costs: $" << (StartupCost + Cost) << " / $" << ((StartupCost + Cost)*1.1 / Volume)/1.1 << " each cart" << std::endl;
        for (int i = 0; (i < ContentName.size() and debug); i++) {
            std::cout << ContentName.at(i) << "/";
            std::cout << ContentCost.at(i) << "$" << endl;
        };
        std::cout << endl << "Product: " << endl;
        for (int i = 0; i < ProductName.size(); i++) {
            std::cout << ProductName.at(i) << endl;
            std::cout << ProductProportions.at(i) / Volume << "/ml $" << std::floor(FindPrice(ProductName.at(i))/Volume * 100+.5)/100 << endl;
        }

        return 0;
    };
};



int main()
{
    std::cout << "Ingredients" << endl;
    Solution Base;
    // HHC pure vvv
    Base.Add("9R-HHC", 0, 11, {"9R-HHC","9S-HHC","CBN"}, {47.6,53.2,.101}); // {"9R-HHC","9S-HHC","D8-THC"},{49.40,44.58,.305}
    // HHC Cut CBN vvv
    Base.Add("9R-HHC", 0, 8, {"9R-HHC","9S-HHC", "CBn"}, {23.09,35.37, 29.16});
    // (23.46) volume mix cut hhc + cbc vvvv
    Base.Add("9S-HHC", 0, 8, { "9r-HHC","9s-HHC","cBN","cBC" }, { 20.2037,30.9487,25.515,12.399 });
    // (5) volume mix vvvvv
    Base.Add("CbC", 0, 0, { "9r-hhc","9s-hhc","cbn","cbc","cbg","cbd" }, {25.8912,16.7032,21.6184,23.894,1.853, 0.61});
    // (7 volume mix)
    Base.Add("v", 0, 10.2, {"9R-HHC","9S-HHC","CBN","D9THCV","CBDV","CBCV","CBG","CBD"}, {18.1759,27.8425,22.95,2.24961,3.67896,.191029,.163368,3.67896});


    Base.Add("CRD", 0, 5, {"CBc","CBD","CBDV","CBE","CBG","CBL","CBn","CBT"}, {6.45,39.6,.776,5.53,2.32,.53,4.61,8.65});
    Base.Add("TERPS", 0, 68, { "TERPS" }, { 100 });
    Base.Add("d9thcv", 0, 30, { "d9thcv","cbdv","cbcv","cbn","cbg","d9thc","cbd" }, { 22.4138,36.655,1.9033,.1289,1.6277,.2492,36.655 });

    // Old Info VVVVVV
    Base.Add("CBC", 0, 12, { "CBc" }, { 99.192 });
    Base.Add("D9-THC", 0, 6, { "D9-THC" }, { 85 });
    Base.Add("HHC", 0, 13, { "HHC" }, { 100 });
    Base.Add("D8THC", 0, 4, { "D8THC" }, { 94.5 });
    Base.Add("CBN", 0, 3, { "CBN" }, { 100 });
    Base.Add("CBT", 0, 30, { "CBT" }, { 97 });

    Base.Add("Rosin", .841, 30, { "d9thca" }, { 100 });
    Base.Add("hhcp", .08, 30, { "hhcp" }, { 100 });

    Base.Startup(0);
    Base.Print("Carts", false);
};
