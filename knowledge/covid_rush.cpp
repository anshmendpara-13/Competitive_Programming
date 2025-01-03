#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int n, m; // number of patient, no of center
set<int> vacant_centers;
map<int, vector<int>> to_discharge;

void discharge_patients_untill_day(int day)
{
    for (auto it = to_discharge.begin(); it != to_discharge.end(); it++)
    {
        int discharge_day = it->first;
        auto &centers = it->second;
        if (day < discharge_day)
        {
            break;
        }
        for (auto center : centers)
        {
            vacant_centers.insert(center);
        }
        to_discharge.erase(it);
    }
}

int get_vacant_center(int patient_index)
{
    auto available_center_it = vacant_centers.lower_bound(patient_index % m);
    if (available_center_it == vacant_centers.end())
    {
        available_center_it = vacant_centers.begin();
    }
    return *available_center_it;
}

int main()
{
    cin >> n >> m;
    vector<pair<int, int>> timings(n);
    vector<int> treated_count(m, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> timings[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> timings[i].second;
    }

    sort(timings.begin(), timings.end());

    for (int i = 0; i < m; i++)
    {
        vacant_centers.insert(i);
    }

    for (auto &timing : timings)
    {
        int arrival_day = timing.first;
        int treatment_days = timing.second;

        discharge_patients_untill_day(arrival_day);

        if (vacant_centers.size() == 0)
        {
            continue;
        }

        int patient_index = &timing - &timings[0]; // index in array *****************
        int available_center = get_vacant_center(patient_index);

        to_discharge[arrival_day + treatment_days].push_back(available_center);
        treated_count[available_center]++;
        vacant_centers.erase(available_center);
    }

    for (int i = 0; i < m; i++)
    {
        cout << treated_count[i] << " ";
    }
    cout << endl;

    return 0;
}