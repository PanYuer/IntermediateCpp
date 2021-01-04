#include <iostream>
using namespace std;
// Less efficient using nested loop
// We consider everyone as a candiate, for each candidate:
// we ask around people, if you know him & if he knows you.

const int MAX 100;
int get_super_star_idx(int table[][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        // i is the candiate
        bool is_ss = true;
        // we ask around, i.e. person j for every possible j
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            // if he knows you or you don't know him ==> he's not a ss
            if (table[i][j] == 1 || table[j][i] == 0)
            {
                is_ss = false;
                break;
            }
        }
        if (is_ss)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    // fill value yourself
    int table[][MAX] = {};
    int ss_idx = get_super_star_idx(table);
    if (ss_idx == -1)
    {
        cout << "no superstar" << endl;
    }
    else
    {
        cout << "ss idx = " << ss_idx << endl;
    }
}