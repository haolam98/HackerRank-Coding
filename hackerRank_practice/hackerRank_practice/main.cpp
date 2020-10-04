//
//  main.cpp
//  hackerRank_practice
//
//  Created by Hao Lam on 5/25/20.
//  Copyright © 2020 Hao Lam. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void printArray(vector<int>a)
{
    cout<<"Array: ";
    for (int i =0; i<a.size();i++)
    {
        cout<<a.at(i)<<" ; ";
    }
    cout<<endl;
}
/*
 ------------------------
  Max Min
 ------------------------
    *You will be given a list of integers - arr, and a single integer - k .
    *You must create an array of length k from elements of  such that its unfairness is minimized.
    *Call that array -subarr. Unfairness of an array is calculated as  MAX(subarr) - MIN(subarr)
 Where:
 - MAX denotes the largest integer in
 - MIN denotes the smallest integer in
 
 FUNCTION DESCRIPTION:
 #Complete the maxMin function in the editor below. It must return an integer that denotes the minimum possible value of unfairness.

 maxMin function has the following parameter(s):

 - k: an integer, the number of elements in the array to create
 - arr: an array of integers .

EXAMPLES:
 
EX:
 given array with elements:
 1
 2
 1
 2
 1
and k=2
=> subarr = [2,2] or [1,1] given the minimun unfairness = 0
EX2:
 given array with elements
 1
 2
 3
 4
 10
 20
 30
 40
 100
 200
 and k=4
 => max(1,2,3,4) - min(1,2,3,4) = 4 - 1 = 3
 */
// Complete the maxMin function below.
int maxMin(int k, vector<int> arr) {
    int min;
    int minIndex;
    //selection sort from pos 0 upto k-1
    for (int i=0; i< k; i++)
    {
        //reset
        min = arr[i];
        minIndex = i;
        for (int x=i+1; x< arr.size(); x++ )
        {
            if (min > arr[x])
            {
                min = arr[x];
                minIndex = x;
            }
        }
        //swap min with i pos
        arr[minIndex] = arr[i];
        arr[i]= min;
    }
    int result= arr[k-1]-arr[0];
    printArray(arr);
    return result;

}

// Complete the largestPermutation function below.

vector<int> largestPermutation(int k, vector<int> arr) {
    

    int size = arr.size();
    
    if ( k > (size-1))
    {
        // sort array
        
    }
    int count = 0;
    int max = arr[0];
    int m_pos = 0; // max value 's postition
    // find max and its pos
    for ( int i=0; i <size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            m_pos = i;
        }
    }
    // swap max with count pos
    int next_pos_max=0;
    if (m_pos !=0 )
    {
        arr[m_pos]= arr[0];
        arr[0]= max;
        count++;
    }

    //check k and do while loop
    while (count < k && next_pos_max!= size)
    {
        max--; // next max
        next_pos_max ++;
        if (arr[next_pos_max]==max)
        {
            max--;
            next_pos_max ++;
        }
        // find next max' position
        for (int i = next_pos_max; i<size; i++)
        {
            if (arr[i]==max)
            {
                // swap next max
                arr[i] = arr[next_pos_max];
                arr[next_pos_max] = max;
                count++;
                break;
            }
        }
    }

    return arr;
}
/*
------------------------
 Priyanka and Toys
------------------------
 Priyanka works for an international toy company that ships by container. Her task is to the determine the lowest cost way to combine her orders for shipping. She has a list of item weights. The shipping company has a requirement that all items loaded in a container must weigh less than or equal to 4 units plus the weight of the minimum weight item. All items meeting that requirement will be shipped in one container.

 What is the smallest number of containers that can be contracted to ship the items based on the given list of weights?
 Input:
 Array contains weights w= { w[0], w[1], w[2]... w[n-1] }
 
 Example:
    w = {1,2,3,21,7, 12, 14,21}
    output =4
 => because :
    1st container holds 1,2,3 (weights in range 1...5)
    2nd container holds 21 (21...25)
    3rd container holds 7 (7...11)
    4th container holds 12, 14 (12...16)
*/
// Complete the toys function below.
int toys(vector<int> w) {
    int count=1;
    int min = w.at(0);
    int max = w.at(0)+4;
    //sort array
    sort (w.begin(), w.end());
    // to sort in decendent order
    // sort(v.begin(), v.end(), greater<int>()); 
    
    // check
    for (int i =1 ; i<w.size();  i++)
    {
        if (w.at(i)>max || w.at(i)<min)
        {
            count++;
            min= w.at(i);
            max = w.at(i)+4;
        }

    }
    return count;

}

/*
------------------------
 Permuting Two Arrays
------------------------
    Array A = { A[0], A[1], ... A[n-1] } -> permute to A'
    Array B = { B[0], B[1], ... B[n-1] } -> permute to B'
 where A'[i] + B'[i] >=k holds for all i where 0<=i<=n
 
 =>You are given  queries consisting of q queries consisting array A, array B and K.For each query, print 'YES' on a new line if some permutation ,  satisfying the relation above exists. Otherwise, print 'NO'.

 */
string twoArrays(int k, vector<int> A, vector<int> B)
{
    // A & B must same size
    if (A.size() != B.size())
    {
        return "NO";
    }
    // sort array A & B
    
    //
    for (int x=0; x< A.size(); x++)
    {
        for (int y=0; y <B.size(); y++)
        {
           // if A[1] + B[1] > k =>return YES
            if ((A[1]+ B[1]) > k)
            {
                return "YES"; //total of any element of A + B will >=k
            }
            if ( (A.at(x)+B.at(y)) >= k)
            {
                // erase y pos in B
                B.erase(B.begin()+y);
                break;
            }
        }
        // check B size
        if (B.size() != (A.size()-x-1))
        {
            return "NO";
            // if B.size() == A.size()-x-1 means
                // found match pair A <--> B, and delete B
        }
    }
    return "YES";

}
/*
 ------------------------
 Find Max Toys Purchase in Array
 ------------------------
 Mark and Jane are very happy after having their first child. Their son loves toys, so Mark wants to buy some. There are a number of different toys lying in front of him, tagged with their prices. Mark has only a certain amount to spend, and he wants to maximize the number of toys he buys with this money.
  --
  --maximumToys has the following parameter(s):
        + prices: an array of integers representing toy prices
        + k: an integer, Mark's budget
 
 */
// Complete the maximumToys function below.

int maximumToys_c2(vector<int> prices, int k) {
     int temp;
    // sort array
  
    for (int i=0; i < prices.size()-1; i++)
    {
        for (int x=i+1; x<prices.size();x++)
        {
            if (prices.at(i)>prices.at(x))
            {
                //swap
                temp= prices[i];
                prices[i]=prices[x];
                prices[x]=temp;
            }
        }
    }
    //printArray(prices);
    int moneyLeft=k;
    int count=0;
    // find max toys can purchase
    for (int i=0; i<prices.size(); i++)
    {
        moneyLeft-= prices.at(i);
        count++;
        if (moneyLeft<0)
        {
             return count-1;
        }
    }
    return count;
}

int maximumToys(vector<int> prices, int k) {
       int count=0;
       int max=0;
       int size = prices.size();
       int moneyLeft = k;
      
       
           for (int  i =0; i < size; i++)
           {
               if (prices.at (i)< moneyLeft)
               {
                   moneyLeft= moneyLeft - prices.at(i);
                   count++;
               }
                   for(int x = i+1; x < size; x++)
                   {
                        if (prices.at (x)< moneyLeft)
                        {
                            moneyLeft= moneyLeft - prices.at(x);
                            count++;
                        }
                   }
               
               
               // check count
               if (count > max)
               {
                   max= count;
               }
               // reset count, moneyLeft
               count=0;
               moneyLeft=k;
           }
       return max;
}
/*
 ------------------------
 Bubble sort
 ------------------------
 Apply Buble sort and count number of s 
 */
void countSwaps(vector<int> a)
{
    int numSwaps=0;
    for (int i=0; i<a.size()-1; i++)
    {
        if (a[i]> a[i+1])
        {
            for (int x=0;x<=i;x++)
            {
                if (a[x]> a[i+1])
                {
                    //swap
                    int temp;
                    temp= a[i+1];
                    a[i+1]=a[x];
                    a[x]=temp;
                    numSwaps++;
                }
            }
        }
       
    }
    cout<<"Array is sorted in "<< numSwaps<< " swaps."<<endl;
    cout<<"First Element: "<<a[0]<<endl;
    cout<<"Last Element: "<<a[a.size()-1]<<endl;

}
int main(int argc, const char * argv[]) {
    /* bubble sort */
    vector<int> a;
    a.push_back(4);
    a.push_back(3);
    a.push_back(2);
    a.push_back(1);
    //countSwaps(a);
    
    /* count max toy can purchase */
    vector<int> b;
    b.push_back(1);
    b.push_back(12);
    b.push_back(5);
    b.push_back(111);
    b.push_back(200);
    b.push_back(1000);
    b.push_back(10);
    //cout <<maximumToys_c2(b, 50)<<endl;
    
    /* Prianka and Toys */
    vector<int> c;
    c.push_back(16);
    c.push_back(18);
    c.push_back(10);
    c.push_back(13);
    c.push_back(2);
    c.push_back(9);
    c.push_back(17);
    c.push_back(17);
    c.push_back(0);
    c.push_back(19);
    //cout << toys(c)<<endl;
    
    /*largest permutation */
    vector<int> d;
    d.push_back(2);
    d.push_back(1);
    d= largestPermutation(1, d);
   // printArray(d);
    cout<< endl;
    
    /*min max*/
    vector<int> e;
    e.push_back(10);
    e.push_back(100);
    e.push_back(300);
    e.push_back(200);
    e.push_back(1000);
    e.push_back(20);
    e.push_back(30);
    cout<<maxMin(3, e)<<endl;
   
    
    
}
