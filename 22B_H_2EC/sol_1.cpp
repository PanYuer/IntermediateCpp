#include <iostream>
using namespace std;
// Efficient solution according to professor's comment

const int MAX 100;
int get_super_star_idx(int table[][MAX], int n)
{
    int i = 0, j = 1, next = 2;
    while (next <= n + 1)
    {
        // i knows j ==> i is not SS
        if (table[i][j] == 1)
        {
            i = next++;
        }
        else
        {
            j = next++;
        }
    }
    // who's the final candiate for SS? we don't know, but we know the final loser got n;
    int cand = (i == n) ? j : i;

    // now let's check if cand is really a SS
    // we ask around 1, if you know him, 2, if he knows you
    for (int i = 0; i < n; i++)
    {
        // you don't know him or he knows you ==> he's a fake SS
        if (table[i][cand] == 0 || table[cand][i] == 0)
        {
            return -1;
        }
    }
    return cand;
}

int main()
{
    // fill value yourself
    int table[][MAX] = {};
    int n = 10; // table size
    int ss_idx = get_super_star_idx(table, n);
    if (ss_idx == -1)
    {
        cout << "no superstar" << endl;
    }
    else
    {
        cout << "ss idx = " << ss_idx << endl;
    }
}