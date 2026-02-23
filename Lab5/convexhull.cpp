#include <iostream>
#include <vector>
using namespace std;

struct Coord
{
    double x, y;
};

double findTurn(const Coord &p1, const Coord &p2, const Coord &p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) -
           (p2.y - p1.y) * (p3.x - p1.x);
}

bool isInside(const Coord &p1, const Coord &p2,
              const Coord &p3, const Coord &check)
{

    double t1 = findTurn(p1, p2, check);
    double t2 = findTurn(p2, p3, check);
    double t3 = findTurn(p3, p1, check);

    bool positive = (t1 > 0) || (t2 > 0) || (t3 > 0);
    bool negative = (t1 < 0) || (t2 < 0) || (t3 < 0);

    return !(positive && negative);
}

int main()
{
    int total;
    cout << "Enter total points: ";
    cin >> total;

    vector<Coord> arr(total);

    cout << "Enter coordinates (x y):\n";
    for (int i = 0; i < total; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    vector<bool> hullPoint(total, true);

    for (int a = 0; a < total; a++)
    {

        for (int b = 0; b < total; b++)
        {
            if (b == a)
                continue;

            for (int c = b + 1; c < total; c++)
            {
                if (c == a)
                    continue;

                for (int d = c + 1; d < total; d++)
                {
                    if (d == a)
                        continue;

                    if (isInside(arr[b], arr[c], arr[d], arr[a]))
                    {
                        hullPoint[a] = false;
                        break;
                    }
                }
                if (!hullPoint[a])
                    break;
            }
            if (!hullPoint[a])
                break;
        }
    }

    cout << "\nPoints on Convex Hull:\n";
    for (int i = 0; i < total; i++)
    {
        if (hullPoint[i])
        {
            cout << arr[i].x << " " << arr[i].y << endl;
        }
    }

    return 0;
}