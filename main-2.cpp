/*
Name: Ahmed Mohamed
ID: 23015
*/

#include <iostream>
using namespace std;

void readScores(int scores[], const int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }
}

double computeAverage(const int scores[], const int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += scores[i];
    }
    return static_cast<double>(sum) / n;
}

void analyzeResults(const int scores[], const int n,
                    int &maxScore, int &minScore,
                    int &passedCount, int &failedCount)
{
    maxScore = scores[0];
    minScore = scores[0];
    passedCount = 0;
    failedCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] > maxScore)
            maxScore = scores[i];

        if (scores[i] < minScore)
            minScore = scores[i];

        if (scores[i] >= 50)
            passedCount++;
        else
            failedCount++;
    }
}

int main()
{
    int n;
    cin >> n;

    int scores[100];

    readScores(scores, n);

    double average = computeAverage(scores, n);

    int maxScore, minScore;
    int passedCount, failedCount;

    analyzeResults(scores, n, maxScore, minScore, passedCount, failedCount);

    cout << "Average score: " << average << endl;
    cout << "Maximum score: " << maxScore << endl;
    cout << "Minimum score: " << minScore << endl;
    cout << "Passed students: " << passedCount << endl;
    cout << "Failed students: " << failedCount << endl;

    cout << "Scores above average: ";
    for (int i = 0; i < n; i++)
    {
        if (scores[i] > average)
            cout << scores[i] << " ";
    }
    cout << endl;

    return 0;
}
