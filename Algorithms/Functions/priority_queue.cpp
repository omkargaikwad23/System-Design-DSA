#include <bits/stdc++.h>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

/*
first element of the queue is the greatest of all elements in 
the queue and elements are in nonincreasing order (hence we 
can see that each element of the queue has a priority {fixed order}).
*/

void showpq(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout << " " << g.top();
        g.pop();
    }
    cout << '\n';
}

void pdMethod(){
    // By default, C++ creates a max-heap for priority queue.
    priority_queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
 
    cout << "The priority queue gquiz is : ";
    showpq(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
 
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpq(gquiz);
}
/*
The priority queue gquiz is :  30 20 10 5 1  

gquiz.size() : 5
gquiz.top() : 30
gquiz.pop() :  20 10 5 1
*/

/*min-heap for the priority queue? */
void showpq(priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>, greater<int> > g = gq;
    while (!g.empty()) {
        cout << " " << g.top();
        g.pop();
    }
    cout << '\n';
}
void minHipPriorityQueue(){
    priority_queue<int, vector<int>, greater<int> > gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);
 
    cout << "The priority queue gquiz is : ";
    showpq(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();
 
    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpq(gquiz);
}
/*
The priority queue gquiz is :  1 5 10 20 30  

gquiz.size() : 5
gquiz.top() : 1
gquiz.pop() :  5 10 20 30
*/

void pqWithPairs(){
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({26, 90});
    pq.push({18, 100});
    pq.push({29, 80});
    pq.push({45, 150});
    pq.push({45, 0});

    while(!pq.empty()){
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }
}

int main(){
    pdMethod();
    cout << "\n";
    minHipPriorityQueue();
    cout << "\n";
    pqWithPairs();
}

int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> q;
        int sum = 0;
        for(auto i : courses) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }