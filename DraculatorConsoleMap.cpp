// DraculatorConsoleMap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://www.google.com/search?q=map+vs+pair&rlz=1C1RXQR_enUS966US966&sxsrf=AOaemvIONTekUbPLFAkjNC8OdI8HPTtCxg%3A1641249134704&ei=bnnTYa-1Ks6rqtsP26SmuAc&ved=0ahUKEwivpKW90Zb1AhXOlWoFHVuSCXcQ4dUDCA4&uact=5&oq=map+vs+pair&gs_lcp=Cgdnd3Mtd2l6EAMyBQgAEIAEMgUIABCABDIFCAAQgAQyBggAEBYQHjIGCAAQFhAeMgYIABAWEB4yBggAEBYQHjIGCAAQFhAeOgcIABBHELADOgoIABCABBCHAhAUSgQIQRgASgQIRhgAUMwHWKwJYNgJaAFwAngAgAFWiAHzAZIBATOYAQCgAQHIAQjAAQE&sclient=gws-wiz
//http://kengine.sourceforge.net/tutorial/g/stdmap-eng.htm
//https://en.cppreference.com/w/cpp/container/map/map
//https://docs.w3cub.com/cpp/container/map
//https://en.cppreference.com/w/cpp/container/map/operator_at
//https://www.google.com/search?q=std::map&rlz=1C1RXQR_enUS966US966&sxsrf=AOaemvIXYT6P_tqXRF9O3BZH3Ts_3Y_lPA:1641248995469&ei=43jTYb_4G7GwqtsPraGC-Ac&start=30&sa=N&ved=2ahUKEwj_9fL60Jb1AhUxmGoFHa2QAH84FBDy0wN6BAgBEDs&biw=958&bih=927&dpr=1
//https://stackoverflow.com/questions/25311011/how-does-include-bits-stdc-h-work-in-c
//https://www.geeksforgeeks.org/associative-arrays-in-cpp/
//https://salishsea-meopar-docs.readthedocs.io/en/latest/code-notes/dev-notes/cpp_keys.html
//
//
//

#include <iostream>
#include <map>
#include <string>
#include<vector>
typedef std::map<std::string, int> ContentMap;
typedef std::map<std::string, ContentMap> StrVecStrMap;
typedef std::map<std::string, double> StrDouMap;

using namespace std;
class Solution {
private:
    double Volume{ 0 };
    double TotalCost{ 0 };
    double TotalProductCost{ 0 };
    int LoadSize{ 0 };
    ContentMap TotalSolution{};
    StrVecStrMap Partitions{};
    StrDouMap CostMap{};


public:
    
    //double Volume{ 0 };

    int AddToSolution(std::string Name, double Cost, ContentMap Proportions, double Amount) {
        Volume += Amount;
        TotalCost += Cost;

        for (const auto& p : Proportions)// ???
        {
            bool fount = false;
            for (const auto& q : TotalSolution) {
                if (q.first == p.first) {
                    fount = true;
                };
            };
            TotalSolution.insert({p.first, p.second});
            //std::cout << p.first << '\t' << p.second << std::endl;
        }
        //std::cout << Proportions.at("Cbd");
        return 0;
    };
    int SetSize(double Size){  
        LoadSize = Size;
        return (LoadSize == Size);
    };

    
};

int main()
{
    Solution Base;
    Base.AddToSolution("poop", 0, { {"Cbd",50},{"THC",20} }, 9);
    Base.SetSize(1100); // mg/Cart
    //std::cout << Base.Volume;
}
