#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class KeepProcess
{
public:
    int data, processtime, arrived;

    KeepProcess() {}
    KeepProcess(int d, int p, int a)
    {
        data = d;
        processtime = p;
        arrived = a;
    }
};

class stack
{
public:
    KeepProcess arr[10];
    int sizeOf = 9;
    int top = 0;
    bool full()
    {
        if (top == 9)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool empty()
    {
        if (top == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(KeepProcess D)
    {
        if (!full())
        {
            arr[++top] = D;
        }
    }

    KeepProcess pop()
    {
        if (!empty())
        {
            return arr[top--];
        }
        return KeepProcess();
    }
};

bool compartsort(KeepProcess a, KeepProcess b){
    if(a.arrived < b.arrived){
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    int TIME = 0;
    int TIMEMUSTUSE = 0;
    int size;
    cin >> size;
    stack s;
    KeepProcess process[size];
    int data, IN, OUT;
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        cin >> IN;
        cin >> OUT;
        process[i] = KeepProcess(data, OUT, IN);
        TIMEMUSTUSE += OUT;
    }
    // sort
    sort(process,process+size,compartsort);

    while (TIME < TIMEMUSTUSE)
    {
        for (int i = 0; i < size; i++)
        {
            if (process[i].arrived <= TIME && process[i].arrived != -1)
            {
                s.push(process[i]);
                process[i].arrived = -1;
            }
        }
        while (!s.empty())
        {
            KeepProcess temp = s.pop();
            for (int i = temp.processtime; i > 0; i--)
            {
                cout << temp.data << ":" << temp.processtime << endl;
                temp.processtime--;
                TIME++;
            }
        }
    }
}