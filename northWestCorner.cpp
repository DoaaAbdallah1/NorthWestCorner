#include <bits/stdc++.h>
using namespace std;

void northWestCorner()
{
    cout << "<<-----------------North West Corner Method------------------>>" << endl;
    long long r, c, sumSupply = 0, sumDemand = 0;
    cout << "How many row? : ";
    cin >> r;
    cout << "How many column? : ";
    cin >> c;

    vector<vector<pair<int, int>>> matrix(r + 1, vector<pair<int, int>>(c + 1));
    vector<int> vecSupply(r), vecDemand(c);

    cout << "Enter the matrix items : " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j].first;
        }
    }
    cout << "Enter vector supply : " << endl;
    for (int i = 0; i < r; i++)
    {
        cin >> vecSupply[i];
        sumSupply += vecSupply[i];
    }
    cout << "Enter vector Demand : " << endl;
    for (int i = 0; i < c; i++)
    {
        cin >> vecDemand[i];
        sumDemand += vecDemand[i];
    }

    if (sumSupply > sumDemand)
    {
        cout << "\nSum Demand :" << sumDemand << ", Sum Supply : " << sumSupply << endl;
        cout << "Not Balance Transportation.\nUse Dummy Destination >>\n";
        vecDemand.push_back(sumSupply - sumDemand);
        for (int i = 0; i < r; i++)
        {
            matrix[i][c].first = 0;
        }
        c = c + 1;
        sumDemand = sumSupply;
    }
    if (sumSupply < sumDemand)
    {
        cout << "\nSum Demand :" << sumDemand << ", Sum Supply : " << sumSupply << endl;
        cout << "Not Balance Transportation.\nUse Dummy Source >>\n";
        vecSupply.push_back(sumDemand - sumSupply);
        for (int i = 0; i < c; i++)
        {
            matrix[r][i].first = 0;
        }
        r = r + 1;
        sumSupply = sumDemand;
    }

    long long minValue = 1e8;
    int j = 0, i = 0, res = 0;
    while (j < c && i < r)
    {
        if (vecSupply[i] >= vecDemand[j])
        {
            matrix[i][j].second = vecDemand[j];

            vecSupply[i] -= vecDemand[j];
            vecDemand[j] = 0;
            res += matrix[i][j].second * matrix[i][j].first;
            j++;
        }
        if (vecSupply[i] < vecDemand[j])
        {
            matrix[i][j].second = vecSupply[i];

            vecDemand[j] -= vecSupply[i];
            vecSupply[i] = 0;
            res += matrix[i][j].second * matrix[i][j].first;
            i++;
        }
    }

    cout << "\nSum Damond :" << sumDemand << ", Sum Supply : " << sumSupply << endl;
    cout << "Balance Transportation :\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "C" << i + 1 << j + 1 << "=" << matrix[i][j].first << ",X" << i + 1 << j + 1 << "=" << matrix[i][j].second << "\t\t";
        }
        cout << endl;
    }
    cout << "\nThe initial feasible basic solution = " << res << endl;
    cout << "Number of Basic variables = " << r + c - 1;
}

int main()
{
    northWestCorner();
}
