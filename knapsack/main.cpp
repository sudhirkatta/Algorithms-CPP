#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int KnapSackBottomUpDP(vector<pair<int,int>> &WeightValue, const int &totalweight, int &optimumValue,vector<pair<int,int>> &optimumItems)
{
    vector<vector<int>> table;

    for(int i =0; i<WeightValue.size()+1; i++)
    {
        vector<int> row(totalweight+1);
        table.push_back(row);
    }

    for(int row =0; row< table.size(); row++)
    {
        for(int weight=0; weight <totalweight+1; weight++ )
        {
            if(row == 0 || weight == 0)
            {
                table[row][weight] = 0;
            }
            else if (WeightValue[row-1].first <= weight)
            {
                table[row][weight] = max(WeightValue[row-1].second+table[row-1][weight-WeightValue[row-1].first],table[row-1][weight]);
            }
            else
            {
                table[row][weight] = table[row-1][weight];
            }
        }
    }

    optimumValue = table[table.size()-1][totalweight];

    int rowindex = table.size()-1;
    int Colindex = totalweight;

    while(rowindex)
    {
        if(table[rowindex][Colindex] == table[rowindex-1][Colindex])
        {
            rowindex--;
        }
        else
        {
            optimumItems.push_back(WeightValue[rowindex-1]);
            rowindex--;
            Colindex = Colindex - WeightValue[rowindex].first;
        }
    }
    return 0;
}

//Szudzik's function, alternatively use Cantor pairing function
template <class T, class U>
T GetHashKey(T a, U b)
{
    auto A = (unsigned long)((a >= 0) ? (2 * (long)a) : (-2 * (long)a - 1));
    auto B = (unsigned long)((b >= 0) ? (2 * (long)b) : (-2 * (long)b - 1));
    auto C = (long)(((A >= B) ? (A * A + A + B) : (A + B * B)) / 2);
    return a < 0 && b < 0 || a >= 0 && b >= 0 ? C : -C - 1;
}

int KnapScakReccur(vector<pair<int,int>> &WeightValue, int remainingWeight,int currentItem, map<int, int> optimumValueMap)
{

    cout << remainingWeight << "(" << currentItem << "," << WeightValue[currentItem].first << ")" << endl ;
    if((remainingWeight <=0) || (currentItem >= WeightValue.size()))
    {
        return 0;
    }

    int key = GetHashKey <int,int> (remainingWeight,WeightValue.size()-currentItem);
    if(optimumValueMap.find(key)!= optimumValueMap.end())
    {
        return optimumValueMap.at(key);
    }

    int maxvalue = 0;

    if(remainingWeight >= WeightValue[currentItem].first)
    {
        int A = WeightValue[currentItem].second + KnapScakReccur(WeightValue, (remainingWeight- WeightValue[currentItem].first),(currentItem+1),optimumValueMap);
        cout << A << endl;
        int B = KnapScakReccur(WeightValue, remainingWeight,currentItem+1,optimumValueMap);
        cout << B << endl;
        maxvalue = max(A, B);
        /*maxvalue = max(WeightValue[currentItem].second+
                       KnapScakReccur(WeightValue, (remainingWeight- WeightValue[currentItem].first),(currentItem+1),optimumValueMap),
                       KnapScakReccur(WeightValue, remainingWeight,currentItem+1,optimumValueMap));
                               */
    }
    else
    {
        maxvalue =KnapScakReccur(WeightValue, remainingWeight,currentItem+1,optimumValueMap);
    }

    optimumValueMap.insert(make_pair(key,maxvalue));
    return maxvalue;
}

int KnapSackTopDownDP(vector<pair<int,int>> &WeightValue, const int &totalweight, int &optimumValue,vector<pair<int,int>> &optimumItems)
{
    map<int, int> optimumValueMap;
    optimumValue = KnapScakReccur(WeightValue, totalweight,0,optimumValueMap);
    return 0;
}

int main(int argc, char *argv[])
{

    const int totalweight = 8;
    vector<pair<int,int>> WeightValue = {{2,2},{2,4},{4,6},{5,9}};
    vector<pair<int,int>> optimumItems;
    int optimumValue;
    //KnapSackBottomUpDP(WeightValue, totalweight, optimumValue,optimumItems);
    KnapSackTopDownDP(WeightValue, totalweight, optimumValue,optimumItems);
    cout << optimumValue << "  " << "\n";

    //    int numberOfTests, numberOfItems;
    //    //cout << "Enter number of tests:" << endl;
    //    cin >> numberOfTests;
    //    vector<vector<pair<int,int>>> listOfTests(numberOfTests);
    //    vector<int> maxCapacity(numberOfTests);

    //    for (int i = 0; i < numberOfTests; i++)
    //    {
    //        //cout << "\n" << "Enter number of Items: ";
    //        cin >> numberOfItems ;
    //        //cout << "\n" << "Enter maximum capacity: ";
    //        cin >> maxCapacity[i];

    //        vector<pair<int,int>> weightValue(numberOfItems);

    //        string rawInput;
    //        /*while( getline( cin, rawInput, ' ') )
    //        {
    //          bool isNum = true;
    //          for(int i = 0; i < rawInput.length() && isNum; ++i)
    //          {
    //            isNum = isdigit( rawInput[i]);
    //          }

    //          if(isNum)
    //          {
    //            values[j] = atoi( rawInput.c_str() );
    //            j++;
    //          }
    //          else
    //            cout << rawInput << " is not a number!" << endl;
    //        }*/

    //        cin.ignore();
    //        //cout << "\n" << "Enter space separated positive integers values: ";
    //        int j = 0;
    //        string values;
    //        getline(cin, values);
    //        istringstream iss1(values);
    //        int temp1;
    //        while(iss1 >> temp1)
    //        {
    //            weightValue[j].second = temp1;
    //             j++;
    //        }

    //        cin.ignore();
    //        j=0;
    //        //cout << "\n" << "Enter space separated positive integers weights: ";
    //        string weights;
    //        getline(cin, weights);
    //        istringstream iss2(weights);
    //        int temp2;
    //        while(iss2 >> temp2)
    //        {
    //            weightValue[j].first = temp2;
    //            j++;
    //        }
    //        cin.ignore();

    //        listOfTests[i] = weightValue;
    //    }

    //    vector<pair<int,int>> optimumItems;
    //    int optimumValue;

    //    for (int i = 0; i < numberOfTests; i++)
    //    {
    //        KnapSackBottomUpDP(listOfTests[i], maxCapacity[i], optimumValue,optimumItems);
    //        cout << optimumValue << endl;
    //    }

    return 0;
}
